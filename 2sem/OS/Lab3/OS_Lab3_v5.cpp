#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <time.h>
#include <windows.h>

using namespace std;
//==============================================================
//�������� ���������
const int N = 30; //�-��� �������� ������
const int K = 8; //�-��� ������

int a[N]; //������� ����� 
int b[K][N]; //�������� ����� �������� �� ������
int size[K]; //�-��� �������� � ������ ������ b[K][N]

//����� ������� ���������� ������
int threadFinals[K]; 
//������ ����� ������
int threadFinalsIndex = 0;

//==============================================================
//���� ������������ ������ �� ����� 
void show(int arr[], int n) {
	for(int i = 0; i < n; i++)
		printf("%d\t", arr[i]);
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
		}
		// ̳����� �������� ������� � ���������
		int temp = arr[i];
		arr[i] = arr[minValueIndex];
		arr[minValueIndex] = temp;
	}	
	//�������� ������ ������, ���� ���������� 
	//� ���������� �����
	threadFinals[threadFinalsIndex++] = threadNum;
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

//==============================================================
int main() {
	setlocale(LC_ALL,"Ukrainian");
	
	//��������� ������� ����� ����������� ������� 0 <= a[i] < N*10  
	srand((unsigned)time(NULL));
	for(int i = 0; i < N; i++) a[i] = rand()%(N*10);
	
	printf("����� a[%d] �� ����������:\n", N);
	show(a, N);

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

	printf("\n������ �� ���������� � �������:\n");
	for(int i = 0; i < K; i++){
		printf("���i� %d:\n", i+1);
		show(b[i], size[i]);
		printf("\n");
		//������������ �������� ������:
		//�� ������ - ������� ��������, ������ - �������
		SetThreadPriority(hThread[i], i%2 ?  THREAD_PRIORITY_HIGHEST : THREAD_PRIORITY_LOWEST);
		//������ ������
		ResumeThread(hThread[i]);
	}

	//������ �� ���������� ��� ������
	WaitForMultipleObjects(K, hThread, TRUE,INFINITE);	
	
	//��������� �� ������ � ������� �� ����������
	DWORD ExitCode[K];
	for(int j = 0; j < K; j++) {
		int i = threadFinals[j];
		printf("\n���������� � �����i %d ���������... ��i������ ������: %d", i+1, GetThreadPriority(hThread[i]));
		
		//�������� ��� ���������� ������
		GetExitCodeThread(hThread[i], &ExitCode[i]);
		//���������� ������
		TerminateThread(hThread[i], ExitCode[i]);
		//�������� ����������� ������
		CloseHandle(hThread[i]);
	}

	printf("\n\n����� a[%d] �i��� ����������:\n", N);
	for(int i = 0; i < K; i++)
		show(b[i], size[i]);

	_getch();
	return 0;
}