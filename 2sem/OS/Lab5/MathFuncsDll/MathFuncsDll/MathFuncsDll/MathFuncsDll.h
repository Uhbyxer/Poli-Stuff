#include <windows.h>

namespace MathFuncs {
	//прототипи функцій, що експортуються
	__declspec(dllexport) int mainDLL();
	extern "C"  __declspec(dllexport) void CALLBACK OutputFile(HWND hwnd, HINSTANCE hinst, LPSTR pszCmdLine, int nCmdShow);
	extern "C"  __declspec(dllexport) void CALLBACK OutputScreen(HWND hwnd, HINSTANCE hinst, LPSTR pszCmdLine, int nCmdShow);
}