#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <time.h>
#include <windows.h>

using namespace std;
//==============================================================
//глобальні константи
const int N = 30; //к-сть елементів масиву

int a[N]; //вхідний масив 


//==============================================================
//вивід одновимірного масиву на екран 
void show(int arr[], int n) {
	for(int i = 0; i < n; i++)
		printf("%d\t", arr[i]);
}

//==============================================================
//функція сортування
void sort(int arr[], int n) {
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
}

//==============================================================
int main() {
	char *p;  //вказівник на результат ф-ї itoa()
	char foo[2];

	setlocale(LC_ALL,"Ukrainian");
	
	//заповнимо вхідний масив випадковими числами 0 <= a[i] < N*10  
	srand((unsigned)time(NULL));
	
	int size = 0; //розрахуємо розмір файлу в байтах
	for(int i = 0; i < N; i++) { 
		a[i] = rand()%(N*10);

		//розіб'ємо число на масив char[] і розрахуємо к-сть символів
		//p - вказівник на першу цифру
		for(p = itoa(a[i], foo, 10); *p; p++, size++);
	}
	size += N; //потрібно N байт для '\t' після  кожного числа

	printf("Масив a[%d] до сортування:\n", N);
	show(a, N);

	//сортуємо масив
	sort(a, N);

	HANDLE hFile, hMap; //дескрипотори файлу та його проекції 
	LPBYTE pData = NULL; //вказівник на початок файлу

	//Відкриваємо файл, перезаписуючи його вміст
	hFile = CreateFile(L"d:\\MMFTest.txt", GENERIC_WRITE | GENERIC_READ, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL); 
	if (hFile != INVALID_HANDLE_VALUE) { 
		
		//Створюємо проекцію всього файлу 
		hMap = CreateFileMapping(hFile, NULL, PAGE_READWRITE, 0, size, NULL); 
		if (hMap) {
			//Отримуємо його розмір та закриваємо дескриптор 
			DWORD dwSize = GetFileSize(hFile, NULL); 
			CloseHandle(hFile); 
			
			//Проектуємо весь файл в адресний простір 
			pData = (LPBYTE)MapViewOfFile(hMap, FILE_MAP_WRITE, 0, 0, 0); 
			if (pData) {
				//зміщення в байтах від першого запису файла
				int offset = 0; 
				for(int i = 0; i < N; i++, offset++) { //зміщуємо для '\t' після  кожного числа 
					
					for(p = itoa(a[i], foo, 10); *p; p++, offset++) 
						*(pData+offset) = *p; //записуємо чергову цифру числа у файл			
					
					*(pData+offset) = '\t'; //записуємо розділювач між числами у файл
				}
  				//Закриваємо проекцію файла у адресному просторі 
				UnmapViewOfFile(pData); 
			} 
			//Закриваємо дескриптор проекції файла 
			CloseHandle(hMap); 
		} 
	}
	printf("\nРезультуючий масив знаходиться у файлi: d:\\MMFTest.txt");
	_getch();
	return 0;
}