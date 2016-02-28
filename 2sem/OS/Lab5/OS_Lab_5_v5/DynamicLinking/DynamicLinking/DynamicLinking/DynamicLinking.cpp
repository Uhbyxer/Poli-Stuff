#include <windows.h> 
#include <stdio.h> 
#include <conio.h> 
#include <iostream>

using namespace std;
 
//тип вказівника на функцію
typedef int (__cdecl *MYPROC)(LPVOID); 
 
int main() { 
    HINSTANCE hinstLib; 
    MYPROC ProcFromDLL; //вказівник на нашу функцію
 
    //отримуємо дескриптор нашої dll
    hinstLib = LoadLibrary(TEXT("MathFuncsDll.dll")); 
    if (hinstLib != NULL) { 
		//отримуємо адресу імпортованої функції 
        ProcFromDLL = (MYPROC) GetProcAddress(hinstLib, "_OutputScreen@16"); 
 
        //виклик функції
        if (NULL != ProcFromDLL) (ProcFromDLL)((LPVOID)0);
        
		//очистимо пам'ять після dll
        FreeLibrary(hinstLib); 
    } else {
		setlocale(LC_ALL,"Ukrainian");
		printf("Помилка завантаження MathFuncsDll.dll\n");
	}
    return 0;
}