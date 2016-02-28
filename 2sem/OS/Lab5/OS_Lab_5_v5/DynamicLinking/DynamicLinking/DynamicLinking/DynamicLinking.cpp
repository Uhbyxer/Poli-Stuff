#include <windows.h> 
#include <stdio.h> 
#include <conio.h> 
#include <iostream>

using namespace std;
 
//��� ��������� �� �������
typedef int (__cdecl *MYPROC)(LPVOID); 
 
int main() { 
    HINSTANCE hinstLib; 
    MYPROC ProcFromDLL; //�������� �� ���� �������
 
    //�������� ���������� ���� dll
    hinstLib = LoadLibrary(TEXT("MathFuncsDll.dll")); 
    if (hinstLib != NULL) { 
		//�������� ������ ����������� ������� 
        ProcFromDLL = (MYPROC) GetProcAddress(hinstLib, "_OutputScreen@16"); 
 
        //������ �������
        if (NULL != ProcFromDLL) (ProcFromDLL)((LPVOID)0);
        
		//�������� ���'��� ���� dll
        FreeLibrary(hinstLib); 
    } else {
		setlocale(LC_ALL,"Ukrainian");
		printf("������� ������������ MathFuncsDll.dll\n");
	}
    return 0;
}