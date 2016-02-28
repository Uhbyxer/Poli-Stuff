#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <time.h>
#include <windows.h>

using namespace std;
//==============================================================
//�������� ���������
const int N = 30; //�-��� �������� ������

int a[N]; //������� ����� 


//==============================================================
//���� ������������ ������ �� ����� 
void show(int arr[], int n) {
	for(int i = 0; i < n; i++)
		printf("%d\t", arr[i]);
}

//==============================================================
//������� ����������
void sort(int arr[], int n) {
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
}

//==============================================================
int main() {
	char *p;  //�������� �� ��������� �-� itoa()
	char foo[2];

	setlocale(LC_ALL,"Ukrainian");
	
	//��������� ������� ����� ����������� ������� 0 <= a[i] < N*10  
	srand((unsigned)time(NULL));
	
	int size = 0; //��������� ����� ����� � ������
	for(int i = 0; i < N; i++) { 
		a[i] = rand()%(N*10);

		//����'��� ����� �� ����� char[] � ��������� �-��� �������
		//p - �������� �� ����� �����
		for(p = itoa(a[i], foo, 10); *p; p++, size++);
	}
	size += N; //������� N ���� ��� '\t' ����  ������� �����

	printf("����� a[%d] �� ����������:\n", N);
	show(a, N);

	//������� �����
	sort(a, N);

	HANDLE hFile, hMap; //������������ ����� �� ���� �������� 
	LPBYTE pData = NULL; //�������� �� ������� �����

	//³�������� ����, ������������� ���� ����
	hFile = CreateFile(L"d:\\MMFTest.txt", GENERIC_WRITE | GENERIC_READ, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL); 
	if (hFile != INVALID_HANDLE_VALUE) { 
		
		//��������� �������� ������ ����� 
		hMap = CreateFileMapping(hFile, NULL, PAGE_READWRITE, 0, size, NULL); 
		if (hMap) {
			//�������� ���� ����� �� ��������� ���������� 
			DWORD dwSize = GetFileSize(hFile, NULL); 
			CloseHandle(hFile); 
			
			//��������� ���� ���� � �������� ������ 
			pData = (LPBYTE)MapViewOfFile(hMap, FILE_MAP_WRITE, 0, 0, 0); 
			if (pData) {
				//������� � ������ �� ������� ������ �����
				int offset = 0; 
				for(int i = 0; i < N; i++, offset++) { //������ ��� '\t' ����  ������� ����� 
					
					for(p = itoa(a[i], foo, 10); *p; p++, offset++) 
						*(pData+offset) = *p; //�������� ������� ����� ����� � ����			
					
					*(pData+offset) = '\t'; //�������� ��������� �� ������� � ����
				}
  				//��������� �������� ����� � ��������� ������� 
				UnmapViewOfFile(pData); 
			} 
			//��������� ���������� �������� ����� 
			CloseHandle(hMap); 
		} 
	}
	printf("\n������������ ����� ����������� � ����i: d:\\MMFTest.txt");
	_getch();
	return 0;
}