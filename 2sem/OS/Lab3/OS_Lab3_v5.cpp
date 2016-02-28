#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <time.h>
#include <windows.h>

using namespace std;
//==============================================================
//глобальні константи
const int N = 30; //к-сть елементів масиву
const int K = 8; //к-сть потоків

int a[N]; //вхідний масив 
int b[K][N]; //вихідний масив розбитий на потоки
int size[K]; //к-сть елементів в рядках масиву b[K][N]

//масив порядку завершення потоків
int threadFinals[K]; 
//індекс цього масиву
int threadFinalsIndex = 0;

//==============================================================
//вивід одновимірного масиву на екран 
void show(int arr[], int n) {
	for(int i = 0; i < n; i++)
		printf("%d\t", arr[i]);
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
		}
		// Міняємо поточний елемент з мінімальним
		int temp = arr[i];
		arr[i] = arr[minValueIndex];
		arr[minValueIndex] = temp;
	}	
	//Зберігаємо індекс потоку, який завершився 
	//в глобальний масив
	threadFinals[threadFinalsIndex++] = threadNum;
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

//==============================================================
int main() {
	setlocale(LC_ALL,"Ukrainian");
	
	//заповнимо вхідний масив випадковими числами 0 <= a[i] < N*10  
	srand((unsigned)time(NULL));
	for(int i = 0; i < N; i++) a[i] = rand()%(N*10);
	
	printf("Масив a[%d] до сортування:\n", N);
	show(a, N);

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

	printf("\nМасиви до сортування в потоках:\n");
	for(int i = 0; i < K; i++){
		printf("Потiк %d:\n", i+1);
		show(b[i], size[i]);
		printf("\n");
		//Встановлюємо пріоритет потоків:
		//не парним - високий пріоритет, парним - низький
		SetThreadPriority(hThread[i], i%2 ?  THREAD_PRIORITY_HIGHEST : THREAD_PRIORITY_LOWEST);
		//запуск потоків
		ResumeThread(hThread[i]);
	}

	//чекаємо на завершення всіх потоків
	WaitForMultipleObjects(K, hThread, TRUE,INFINITE);	
	
	//завершуємо всі потоки в порядку їх завершення
	DWORD ExitCode[K];
	for(int j = 0; j < K; j++) {
		int i = threadFinals[j];
		printf("\nСортування в потоцi %d завершено... Прiоритет потоку: %d", i+1, GetThreadPriority(hThread[i]));
		
		//отримуємо код завершення потоків
		GetExitCodeThread(hThread[i], &ExitCode[i]);
		//завершення потоку
		TerminateThread(hThread[i], ExitCode[i]);
		//закриття дексриптора потоку
		CloseHandle(hThread[i]);
	}

	printf("\n\nМасив a[%d] пiсля сортування:\n", N);
	for(int i = 0; i < K; i++)
		show(b[i], size[i]);

	_getch();
	return 0;
}