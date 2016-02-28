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
int toScreen = 0; //1 - ���� �� �����, ������  - � ����
FILE *A; //���� ��� ������ ����������

//�������� ���������
const int N = 30; //�-��� �������� ������
const int K = 8; //�-��� ������

int a[N]; //������� ����� 
int b[K][N]; //�������� ����� �������� �� ������
int size[K]; //�-��� �������� � ������ ������ b[K][N]

//����� ������� ���������� ������
int threadFinals[K]; 
//������ ����� ������
LONG threadFinalsIndex = 0;

//�������� �-��� �������� ��������� ����������
long itersNum;
//������� �-��� ��������, ��� ��� �������� ���������
LONG itersCur = 0;

//"���������" ��� ���-����������
LONG resourceInUse = FALSE;
//������� ������
CRITICAL_SECTION cs, cs2;
//���������� ��������
HANDLE hSemaphore;
//���������� �������
HANDLE hMutex;

//==============================================================
//������� ������ �������� �� �����
void progress(int value) {
	if(toScreen) {
		system("cls");
		printf("����������... %d %%\n\n", value);
	} else
		fprintf(A, "����������... %d %%\n\n", value);
	for(int i = 0; i < threadFinalsIndex; i++) 
		if(toScreen) printf("���i� %d ���������. /�-��� �������i� = %d/\n", threadFinals[i]+1, size[threadFinals[i]]);
		else fprintf(A, "���i� %d ���������. /�-��� �������i� = %d/\n", threadFinals[i]+1, size[threadFinals[i]]);
}

//==============================================================
//������� ����������
void sort(int arr[], int n, int threadNum) {
	for (int i = 0; i < n; i++) {
		// �������� ��������� ������� ��
		// ������� ������� [i; n);
		// �������� ���� ������ ����� i
		int minValueIndex = i;
		// ���������� ��������, �� ���������� �� �������
		for (int j = i + 1; j < n; j++) {
			// ���� ������� � ������� j ������
			// �������� � ������� minValueIndex, ��
			// ��������� �������� �������� �������
			if (arr[j] < arr[minValueIndex]) {
				minValueIndex = j;
			}
			
			//���-����������:
			//������ ������� �� ������� 
			while (InterlockedExchange(&resourceInUse, (long)TRUE)) Sleep(0);
			
			//...�������� ������: 
			//Interlocked-������� ���������
			InterlockedExchangeAdd(&itersCur, 1);
			
			//�������� �������� �������
			progress((int)ceil(100.0*itersCur/itersNum)); Sleep(5);
			
			//������ ��� �� �������
			InterlockedExchange(&resourceInUse, (long)FALSE);
		}
		// ̳����� �������� ������� � ��������� � �������� ������
		int temp = arr[i];
		//������� � �������� ������
		EnterCriticalSection(&cs);
		arr[i] = arr[minValueIndex];
		arr[minValueIndex] = temp;
		//�������� �������� ������
		LeaveCriticalSection(&cs);
	}	
	//�������� ������ ������, ���� ���������� 
	//� ���������� ����� � �������� ������
	//������� � �������� ������
	EnterCriticalSection(&cs2);
	threadFinals[threadFinalsIndex] = threadNum;
	//Interlocked-���������
	InterlockedIncrement(&threadFinalsIndex);
	//�������� �������� ������
	LeaveCriticalSection(&cs2);
}

//==============================================================
//������� ����������� �������� ������ ����������� ������� � ������
DWORD WINAPI InitArray(LPVOID Param) {
	//��������� ������� ����� ����������� ������� 0 <= a[i] < N*10  
	srand((unsigned)time(NULL));
	for(int i = 0; i < N; i++) {
		a[i] = rand()%(N*10);
		//�������, �� ����� ������� "�������"
		ReleaseSemaphore(hSemaphore,1,NULL);
		Sleep(250);
	}
	return 0;
}

//==============================================================
//������� ��������� ������������� ������ b � ������� ����� �
DWORD WINAPI FinalArray(LPVOID Param) {
	int p = 0;
	for(int i = 0; i < K; i++)
		for(int j = 0; j < size[i]; j++, p++) {
			//������ �� ��������� �������
			WaitForSingleObject(hMutex, INFINITE);
			*(a+p) = b[i][j]; 
			Sleep(250);
			//��������� ������
			ReleaseMutex(hMutex);	
		}
	return 0;
}

//==============================================================
//������� ����������� 1-�� ������
DWORD WINAPI Output0(LPVOID Param) {
	sort(b[0], size[0], 0);
	return 0;
}

//==============================================================
//������� ����������� 2-�� ������
DWORD WINAPI Output1(LPVOID Param) {
	sort(b[1], size[1], 1);
	return 0;
}

//==============================================================
//������� ����������� 3-�� ������
DWORD WINAPI Output2(LPVOID Param) {
	sort(b[2], size[2], 2);
	return 0;
}

//==============================================================
//������� ����������� 4-�� ������
DWORD WINAPI Output3(LPVOID Param) {
	sort(b[3], size[3], 3);
	return 0;
}

//==============================================================
//������� ����������� 5-�� ������
DWORD WINAPI Output4(LPVOID Param) {
	sort(b[4], size[4], 4);
	return 0;
}

//==============================================================
//������� ����������� 6-�� ������
DWORD WINAPI Output5(LPVOID Param) {
	sort(b[5], size[5], 5);
	return 0;
}

//==============================================================
//������� ����������� 7-�� ������
DWORD WINAPI Output6(LPVOID Param) {
	sort(b[6], size[6], 6);
	return 0;
}

//==============================================================
//������� ����������� 8-�� ������
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
	//��������� �������
	hSemaphore = CreateSemaphore(NULL, 0, 10, NULL);
	//��������� ����, ���� ���� �������� �������� ������
	HANDLE hInitThread;
	DWORD IDInitThread;
	hInitThread = CreateThread(NULL, 0, InitArray, NULL, 0, &IDInitThread);
	// ���� main �������� �������� ������
	// ����� ���� �� ��������� � InitArray()
	if(toScreen)
		printf("\nI�i�i��i���i� ������ a[%d]:\n", N);
	else
		fprintf(A, "\nI�i�i��i���i� ������ a[%d]:\n", N);
	
	for(int i = 0; i < N; i++) {
		//������ �� ��������� ��������
		WaitForSingleObject(hSemaphore, INFINITE);
		//...� �������� ������� �� �����
		if(toScreen)
			printf("%d\t", a[i]);
		else
			fprintf(A, "%d\t", a[i]);
	}
	//��������� ����������� �������� �� ������
	CloseHandle(hSemaphore);
	CloseHandle(hInitThread);
	if(toScreen) {
		printf("\n��� ����������� - ������i�� ����i��...");
		_getch();
	} else { 
		fprintf(A, "\n��� ����������� - ������i�� ����i��...");
		system("pause");
	}

	//������� ����. �� ��. �������� ������
	int max = a[0];
	int min = a[0];
	for(int i = 1; i < N; i++) {
		if(a[i] > max) max = a[i];
		if(a[i] < min) min = a[i];
	}
	//�������� ����� size
	for(int i = 0; i < K; i++) size[i] = 0;
	//���� � ���� ������ �������� ��� ������� 
	int step = int((max - min + 1)/K);
	//��������� ������� ����� �� ��������
	//��� ���������� �� � ����������� �������
	for(int j = 0; j < N; j++) 
		for(int i = 0; i < K; i++) {
			//������ ���� ��������
			int right = (i == K-1) ? (max+1) : (min+step*(i+1));	
			//���� �������� �������� ������� � ������� i-�� �������� -
			//�������� ���� ����
			if(a[j] < right) {
				b[i][size[i]++] = a[j];
				break;
			}
		}
	
	//��������� �������� �-��� �������� ��������� ���������� 
	itersNum = 0;
	for (int s = 0; s < K; s++)
		for (int i = 0; i < size[s]; i++)
			for (int j = i + 1; j < size[s]; j++, itersNum++);
	
	HANDLE hThread[K]; //����� ����������� ������
    DWORD ThreadId[K]; //������� �������������� ������

	//��������� ������
    hThread[0] = CreateThread(NULL, 0, Output0, NULL, 0, &ThreadId[0]);
	if(K > 1) hThread[1] = CreateThread(NULL, 0, Output1, NULL, CREATE_SUSPENDED, &ThreadId[1]);
	if(K > 2) hThread[2] = CreateThread(NULL, 0, Output2, NULL, CREATE_SUSPENDED, &ThreadId[2]);
	if(K > 3) hThread[3] = CreateThread(NULL, 0, Output3, NULL, CREATE_SUSPENDED, &ThreadId[3]);
	if(K > 4) hThread[4] = CreateThread(NULL, 0, Output4, NULL, CREATE_SUSPENDED, &ThreadId[4]);
	if(K > 5) hThread[5] = CreateThread(NULL, 0, Output5, NULL, CREATE_SUSPENDED, &ThreadId[5]);
	if(K > 6) hThread[6] = CreateThread(NULL, 0, Output6, NULL, CREATE_SUSPENDED, &ThreadId[6]);
	if(K > 7) hThread[7] = CreateThread(NULL, 0, Output7, NULL, CREATE_SUSPENDED, &ThreadId[7]);
	
	//����������� ��������� ������
	InitializeCriticalSection(&cs); 
	InitializeCriticalSection(&cs2);
	
	//������ ������
	for(int i = 0; i < K; i++) ResumeThread(hThread[i]);

	//������ �� ���������� ��� ������
	WaitForMultipleObjects(K, hThread, TRUE,INFINITE);	
	progress(100);
	
	//�������� ��������� ������
	DeleteCriticalSection(&cs);
	DeleteCriticalSection(&cs2);

	//��������� �� ������ � ������� �� ����������
	DWORD ExitCode[K];
	for(int i = 0; i < K; i++) {
		//�������� ��� ���������� ������
		GetExitCodeThread(hThread[i], &ExitCode[i]);
		//���������� ������
		TerminateThread(hThread[i], ExitCode[i]);
		//�������� ����������� ������
		CloseHandle(hThread[i]);
	}

	if(toScreen) {
		//��������� ������
		hMutex = CreateMutex(NULL, FALSE, NULL);
		//��������� ����, ���� ����� ������������ ����� b � ������� ����� �
		HANDLE hFinalThread;
		DWORD IDFinalThread;
		hFinalThread = CreateThread(NULL, 0, FinalArray, NULL, 0, &IDFinalThread);
		//��������� ���� main, ��� ���� FinalArray() ������ ������� ������
		Sleep(200);
	
		printf("\n\n����� a[%d] �i��� ����������:\n", N);
		for(int i = 0; i < N; i++) {
			//�������� ������
			WaitForSingleObject(hMutex, INFINITE);
			printf("%d\t", a[i]);
			//��������� ������
			ReleaseMutex(hMutex);
		}
		//��������� ����������� ������� �� ������
		CloseHandle(hMutex);
		CloseHandle(hFinalThread);

		printf("\n��� ���������� �������� - ������i�� ����i��...");
		_getch();

	} else {
		fprintf(A, "\n\n����� a[%d] �i��� ����������:\n", N);
		for(int i = 0; i < K; i++)
			for(int j = 0; j < size[i]; j++) 
				fprintf(A, "%d\t", b[i][j]); 
	}

	return 0;
}

//�������, �� �������������
namespace MathFuncs {
	//��� �������, ��� �������� ��'�������
	int mainDLL() {
		toScreen = 1;
		return main();
	}

	//��� ������� � rundll32
	void CALLBACK OutputFile(HWND hwnd, HINSTANCE hinst, LPSTR pszCmdLine, int nCmdShow){
		toScreen = 0;
		main();
	}

	//��� �������, ��� ������� ��'�������
	void CALLBACK OutputScreen(HWND hwnd, HINSTANCE hinst, LPSTR pszCmdLine, int nCmdShow){
		toScreen = 1;
		main();
	}
}