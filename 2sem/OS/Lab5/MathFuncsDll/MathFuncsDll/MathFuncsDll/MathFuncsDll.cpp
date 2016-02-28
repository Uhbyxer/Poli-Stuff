#include "MathFuncsDll.h"
#include <stdexcept>
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <stdio.h>
#include <cstdlib>
#include <string>
#include <math.h>
#include <time.h>


using namespace std;
//==============================================================
int toScreen = 0; //1 - вивід на екран, інакше  - у файл
FILE *A; //файл для виводу результатів

//глобальні константи
const int N = 30; //к-сть елементів масиву
const int K = 8; //к-сть потоків

int a[N]; //вхідний масив 
int b[K][N]; //вихідний масив розбитий на потоки
int size[K]; //к-сть елементів в рядках масиву b[K][N]

//масив порядку завершення потоків
int threadFinals[K]; 
//індекс цього масиву
LONG threadFinalsIndex = 0;

//загальна к-сть ітерацій алгоритму сортування
long itersNum;
//поточна к-сть ітерацій, яка вже виконана програмою
LONG itersCur = 0;

//"прапорець" для спін-блокування
LONG resourceInUse = FALSE;
//критичні секції
CRITICAL_SECTION cs, cs2;
//дескриптор семафора
HANDLE hSemaphore;
//дескриптор мютекса
HANDLE hMutex;

//==============================================================
//функція виводу прогресу на екран
void progress(int value) {
	if(toScreen) {
		system("cls");
		printf("Сортування... %d %%\n\n", value);
	} else
		fprintf(A, "Сортування... %d %%\n\n", value);
	for(int i = 0; i < threadFinalsIndex; i++) 
		if(toScreen) printf("Потiк %d завершено. /К-сть елементiв = %d/\n", threadFinals[i]+1, size[threadFinals[i]]);
		else fprintf(A, "Потiк %d завершено. /К-сть елементiв = %d/\n", threadFinals[i]+1, size[threadFinals[i]]);
}

//==============================================================
//функція сортування
void sort(int arr[], int n, int threadNum) {
	for (int i = 0; i < n; i++) {
		// Знайдемо мінімальний елемент на
		// проміжку індексів [i; n);
		// спочатку його індекс рівний i
		int minValueIndex = i;
		// Перебираємо елементи, що залишилися на проміжку
		for (int j = i + 1; j < n; j++) {
			// Якщо елемент в позиції j менший
			// елемента в позиції minValueIndex, то
			// необхідно обновити значення індекса
			if (arr[j] < arr[minValueIndex]) {
				minValueIndex = j;
			}
			
			//Спін-блокування:
			//чекаємо доступу до ресурсу 
			while (InterlockedExchange(&resourceInUse, (long)TRUE)) Sleep(0);
			
			//...отримали доступ: 
			//Interlocked-функція додавання
			InterlockedExchangeAdd(&itersCur, 1);
			
			//виводимо поточний прогрес
			progress((int)ceil(100.0*itersCur/itersNum)); Sleep(5);
			
			//доступ вже не потрібен
			InterlockedExchange(&resourceInUse, (long)FALSE);
		}
		// Міняємо поточний елемент з мінімальним в критичній секції
		int temp = arr[i];
		//входимо в критичну секцію
		EnterCriticalSection(&cs);
		arr[i] = arr[minValueIndex];
		arr[minValueIndex] = temp;
		//покидаємо критичну секцію
		LeaveCriticalSection(&cs);
	}	
	//Зберігаємо індекс потоку, який завершився 
	//в глобальний масив в критичній секції
	//входимо в критичну секцію
	EnterCriticalSection(&cs2);
	threadFinals[threadFinalsIndex] = threadNum;
	//Interlocked-інкремент
	InterlockedIncrement(&threadFinalsIndex);
	//покидаємо критичну секцію
	LeaveCriticalSection(&cs2);
}

//==============================================================
//функція ініціалізації вхідного масиву випадковими числами в потоці
DWORD WINAPI InitArray(LPVOID Param) {
	//заповнимо вхідний масив випадковими числами 0 <= a[i] < N*10  
	srand((unsigned)time(NULL));
	for(int i = 0; i < N; i++) {
		a[i] = rand()%(N*10);
		//відмічаємо, що одини елемент "готовий"
		ReleaseSemaphore(hSemaphore,1,NULL);
		Sleep(250);
	}
	return 0;
}

//==============================================================
//функція копіювання посортованого масиву b у вхідний масив а
DWORD WINAPI FinalArray(LPVOID Param) {
	int p = 0;
	for(int i = 0; i < K; i++)
		for(int j = 0; j < size[i]; j++, p++) {
			//чекаємо на отримання мютекса
			WaitForSingleObject(hMutex, INFINITE);
			*(a+p) = b[i][j]; 
			Sleep(250);
			//відпускаємо мютекс
			ReleaseMutex(hMutex);	
		}
	return 0;
}

//==============================================================
//функція опрацювання 1-го потоку
DWORD WINAPI Output0(LPVOID Param) {
	sort(b[0], size[0], 0);
	return 0;
}

//==============================================================
//функція опрацювання 2-го потоку
DWORD WINAPI Output1(LPVOID Param) {
	sort(b[1], size[1], 1);
	return 0;
}

//==============================================================
//функція опрацювання 3-го потоку
DWORD WINAPI Output2(LPVOID Param) {
	sort(b[2], size[2], 2);
	return 0;
}

//==============================================================
//функція опрацювання 4-го потоку
DWORD WINAPI Output3(LPVOID Param) {
	sort(b[3], size[3], 3);
	return 0;
}

//==============================================================
//функція опрацювання 5-го потоку
DWORD WINAPI Output4(LPVOID Param) {
	sort(b[4], size[4], 4);
	return 0;
}

//==============================================================
//функція опрацювання 6-го потоку
DWORD WINAPI Output5(LPVOID Param) {
	sort(b[5], size[5], 5);
	return 0;
}

//==============================================================
//функція опрацювання 7-го потоку
DWORD WINAPI Output6(LPVOID Param) {
	sort(b[6], size[6], 6);
	return 0;
}

//==============================================================
//функція опрацювання 8-го потоку
DWORD WINAPI Output7(LPVOID Param) {
	sort(b[7], size[7], 7);
	return 0;
}

int main() {
	if(toScreen)
		setlocale(LC_ALL,"Ukrainian");
	else if((A = fopen("d:\\output.txt", "w")) == NULL) {
			return -1;
		}
	//створюємо семафор
	hSemaphore = CreateSemaphore(NULL, 0, 10, NULL);
	//створюємо потік, який готує елементи вхідного масиву
	HANDLE hInitThread;
	DWORD IDInitThread;
	hInitThread = CreateThread(NULL, 0, InitArray, NULL, 0, &IDInitThread);
	// потік main виводить елементи масиву
	// тільки після їх підготовки в InitArray()
	if(toScreen)
		printf("\nIнiцiалiзацiя масиву a[%d]:\n", N);
	else
		fprintf(A, "\nIнiцiалiзацiя масиву a[%d]:\n", N);
	
	for(int i = 0; i < N; i++) {
		//чекаємо на включення семафора
		WaitForSingleObject(hSemaphore, INFINITE);
		//...і виводимо елемент на екран
		if(toScreen)
			printf("%d\t", a[i]);
		else
			fprintf(A, "%d\t", a[i]);
	}
	//закриваємо дескриптори семафору та потоку
	CloseHandle(hSemaphore);
	CloseHandle(hInitThread);
	if(toScreen) {
		printf("\nДля продовження - натиснiть клавiшу...");
		_getch();
	} else { 
		fprintf(A, "\nДля продовження - натиснiть клавiшу...");
		system("pause");
	}

	//знайдем макс. та мін. елементи масиву
	int max = a[0];
	int min = a[0];
	for(int i = 1; i < N; i++) {
		if(a[i] > max) max = a[i];
		if(a[i] < min) min = a[i];
	}
	//обнулимо масив size
	for(int i = 0; i < K; i++) size[i] = 0;
	//крок з яким будемо рахувати межі проміжків 
	int step = int((max - min + 1)/K);
	//розбиваємо вхідний масив на підмасиви
	//для сортування їх в паралельних потоках
	for(int j = 0; j < N; j++) 
		for(int i = 0; i < K; i++) {
			//верхня межа підмасиву
			int right = (i == K-1) ? (max+1) : (min+step*(i+1));	
			//якщо значення елементу входить у проміжок i-го підмасиву -
			//записуємо його туди
			if(a[j] < right) {
				b[i][size[i]++] = a[j];
				break;
			}
		}
	
	//розрахуємо загальну к-сть ітерацій алгоритму сортування 
	itersNum = 0;
	for (int s = 0; s < K; s++)
		for (int i = 0; i < size[s]; i++)
			for (int j = i + 1; j < size[s]; j++, itersNum++);
	
	HANDLE hThread[K]; //масив дескрипторів потоків
    DWORD ThreadId[K]; //унікальні ідентифікатори потоків

	//створюємо потоки
    hThread[0] = CreateThread(NULL, 0, Output0, NULL, 0, &ThreadId[0]);
	if(K > 1) hThread[1] = CreateThread(NULL, 0, Output1, NULL, CREATE_SUSPENDED, &ThreadId[1]);
	if(K > 2) hThread[2] = CreateThread(NULL, 0, Output2, NULL, CREATE_SUSPENDED, &ThreadId[2]);
	if(K > 3) hThread[3] = CreateThread(NULL, 0, Output3, NULL, CREATE_SUSPENDED, &ThreadId[3]);
	if(K > 4) hThread[4] = CreateThread(NULL, 0, Output4, NULL, CREATE_SUSPENDED, &ThreadId[4]);
	if(K > 5) hThread[5] = CreateThread(NULL, 0, Output5, NULL, CREATE_SUSPENDED, &ThreadId[5]);
	if(K > 6) hThread[6] = CreateThread(NULL, 0, Output6, NULL, CREATE_SUSPENDED, &ThreadId[6]);
	if(K > 7) hThread[7] = CreateThread(NULL, 0, Output7, NULL, CREATE_SUSPENDED, &ThreadId[7]);
	
	//ініціалізація критичних секцій
	InitializeCriticalSection(&cs); 
	InitializeCriticalSection(&cs2);
	
	//запуск потоків
	for(int i = 0; i < K; i++) ResumeThread(hThread[i]);

	//чекаємо на завершення всіх потоків
	WaitForMultipleObjects(K, hThread, TRUE,INFINITE);	
	progress(100);
	
	//знищення критичних секцій
	DeleteCriticalSection(&cs);
	DeleteCriticalSection(&cs2);

	//завершуємо всі потоки в порядку їх завершення
	DWORD ExitCode[K];
	for(int i = 0; i < K; i++) {
		//отримуємо код завершення потоків
		GetExitCodeThread(hThread[i], &ExitCode[i]);
		//завершення потоку
		TerminateThread(hThread[i], ExitCode[i]);
		//закриття дексриптора потоку
		CloseHandle(hThread[i]);
	}

	if(toScreen) {
		//створюємо мютекс
		hMutex = CreateMutex(NULL, FALSE, NULL);
		//створюємо потік, який копіює посортований масив b у вхідний масив а
		HANDLE hFinalThread;
		DWORD IDFinalThread;
		hFinalThread = CreateThread(NULL, 0, FinalArray, NULL, 0, &IDFinalThread);
		//затримаємо потік main, щоб потік FinalArray() першим отримав мютекс
		Sleep(200);
	
		printf("\n\nМасив a[%d] пiсля сортування:\n", N);
		for(int i = 0; i < N; i++) {
			//отримаємо мютекс
			WaitForSingleObject(hMutex, INFINITE);
			printf("%d\t", a[i]);
			//відпускаємо мютекс
			ReleaseMutex(hMutex);
		}
		//закриваємо дескриптори мютекса та потоку
		CloseHandle(hMutex);
		CloseHandle(hFinalThread);

		printf("\nДля завершення програми - натиснiть клавiшу...");
		_getch();

	} else {
		fprintf(A, "\n\nМасив a[%d] пiсля сортування:\n", N);
		for(int i = 0; i < K; i++)
			for(int j = 0; j < size[i]; j++) 
				fprintf(A, "%d\t", b[i][j]); 
	}

	return 0;
}

//функції, що експортуються
namespace MathFuncs {
	//для виклику, при ранньому зв'язуванні
	int mainDLL() {
		toScreen = 1;
		return main();
	}

	//для виклику з rundll32
	void CALLBACK OutputFile(HWND hwnd, HINSTANCE hinst, LPSTR pszCmdLine, int nCmdShow){
		toScreen = 0;
		main();
	}

	//для виклику, при пізньому зв'язуванні
	void CALLBACK OutputScreen(HWND hwnd, HINSTANCE hinst, LPSTR pszCmdLine, int nCmdShow){
		toScreen = 1;
		main();
	}
}