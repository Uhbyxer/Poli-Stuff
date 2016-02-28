#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <windows.h>

using namespace std;
//==============================================================
//глобальні константи
const int N = 4; //к-сть потоків
//масив тривалості роботи потоків
double ThreadTime[N]; 
//пріоритет з яким виконується процес
const DWORD PROCESS_PRIORITY = HIGH_PRIORITY_CLASS;
/* Варіанти пріоритетів процесу: 
	REALTIME_PRIORITY_CLASS - реальний час
	HIGH_PRIORITY_CLASS - високий
	NORMAL_PRIORITY_CLASS - середнiй
	IDLE_PRIORITY_CLASS - низький */

//==============================================================
//клас для розрахунку часу роботи потоків
class Timing2 {
public:
  //запуск таймера
  void StartTiming();
  //стоп таймера
  void StopTiming();
  //отримання значення таймера
  double GetUserSeconds() const {
    return value;
  }
private:
  DWORD_PTR oldmask;
  double value;
  LARGE_INTEGER time1;
};

void Timing2::StartTiming() {         
  //команда компілятору -
  //не оптимізовувати код отримання значення даної змінної
  volatile int warmingUp = 1;
  //виконуємо паралельно в декількох потоках
  #pragma omp parallel for
  
  /*
  Даний цикл виводить процесор на максимальну швидкість роботи і тим самим трохи 
  підвищує точність вимірювання швидкості. 
  При цьому ми "прогріваємо" всі доступні ядра. */
  for (int i=1; i<10000000; i++) {
    #pragma omp atomic
    warmingUp *= i;
  }
  //виконання поточного потоку на першому процесорі
  oldmask = SetThreadAffinityMask(::GetCurrentThread(), 1);
  //засікаємо к-сть імпульсів процесора
  //до початку роботи таймера
  QueryPerformanceCounter(&time1);
}

void Timing2::StopTiming() {  
  LARGE_INTEGER performance_frequency, time2;
  //тактова частота
  QueryPerformanceFrequency(&performance_frequency);
  
  //засікаємо к-сть імпульсів процесора
  //при завершенні роботи таймера
  QueryPerformanceCounter(&time2);  
  //виконуємо потік на першому процесорі
  SetThreadAffinityMask(::GetCurrentThread(), oldmask);
  //різниця в тактах між завершенням та початком
  value = (double)(time2.QuadPart - time1.QuadPart);
  //поділимо на к-сть тактів в секуду - 
  //отримаємо значення в секундах
  value /= performance_frequency.QuadPart;
}

//==============================================================
//функція табулювання
void tabulation(int threadNum) { //threadNum - номер потоку
	const double a = -1, b = 1.0; //(a;b) - проміжок табулювання
	const int n = 1000; //кількість точок табулювання
	const double eps = 0.0001; //точність обчислення
	int i;
	double x, s, si, y;

	Timing2 t;
	//засікаєм час початку роботи потоку
	t.StartTiming();

	for(int j = 1; j <= n; j++){
		//отримуємо наступне значення x на проміжку табуляції
		x = a+j*(b-a)/(double) n;
		//перший елемент ряду
		si = x; s = si; 
		i = 2; 
		//виконуємо, поки не досягнуто бажаної точності
		while(fabs(si)>eps) {
			//обчислимо i-ий елемент ряду Тейлора
			si *= -x*(i-1)/i;
			//збільшимо суму ряду
			s += si;
			//збільшимо лічильник
			i++;
		}
		//отримаємо значення ф-ї штатними методами
		y=log(1+x); 
		printf("Потiк %d Крок %d: x=%f y=%f s=%f\n", threadNum+1, j, x, y, s);
	}

	//засікаєм час завершення потоку
	t.StopTiming();
	//...і зберігаємо його в глобальний масив
	ThreadTime[threadNum] = t.GetUserSeconds();
}

//==============================================================
//функція опрацювання 1-го потоку
DWORD WINAPI Output0(LPVOID Param) {
	tabulation(0);
	return 0;
}

//==============================================================
//функція опрацювання 2-го потоку
DWORD WINAPI Output1(LPVOID Param) {
	tabulation(1);
	return 0;
}

//==============================================================
//функція опрацювання 3-го потоку
DWORD WINAPI Output2(LPVOID Param) {
	tabulation(2);
	return 0;
}

//==============================================================
//функція опрацювання 4-го потоку
DWORD WINAPI Output3(LPVOID Param) {
	tabulation(3);
	return 0;
}

//==============================================================
//функція опрацювання 5-го потоку
DWORD WINAPI Output4(LPVOID Param) {
	tabulation(4);
	return 0;
}

//==============================================================
//функція опрацювання 6-го потоку
DWORD WINAPI Output5(LPVOID Param) {
	tabulation(5);
	return 0;
}

//==============================================================
//функція опрацювання 7-го потоку
DWORD WINAPI Output6(LPVOID Param) {
	tabulation(6);
	return 0;
}

//==============================================================
//функція опрацювання 8-го потоку
DWORD WINAPI Output7(LPVOID Param) {
	tabulation(7);
	return 0;
}

//==============================================================
int main() {
	setlocale(LC_ALL,"Ukrainian");

	HANDLE hThread[N]; //масив дескрипторів потоків
    DWORD ThreadId[N]; //унікальні ідентифікатори потоків

	//встановлюємо пріотитет процесу
	SetPriorityClass(GetCurrentProcess(), PROCESS_PRIORITY);

	Timing2 t;
	//засікаємо час початку процесу
	t.StartTiming();

	//створюємо потоки
    hThread[0] = CreateThread(NULL, 0, Output0, NULL, 0, &ThreadId[0]);
	if(N > 1) hThread[1] = CreateThread(NULL, 0, Output1, NULL, CREATE_SUSPENDED, &ThreadId[1]);
	if(N > 2) hThread[2] = CreateThread(NULL, 0, Output2, NULL, CREATE_SUSPENDED, &ThreadId[2]);
	if(N > 3) hThread[3] = CreateThread(NULL, 0, Output3, NULL, CREATE_SUSPENDED, &ThreadId[3]);
	if(N > 4) hThread[4] = CreateThread(NULL, 0, Output4, NULL, CREATE_SUSPENDED, &ThreadId[4]);
	if(N > 5) hThread[5] = CreateThread(NULL, 0, Output5, NULL, CREATE_SUSPENDED, &ThreadId[5]);
	if(N > 6) hThread[6] = CreateThread(NULL, 0, Output6, NULL, CREATE_SUSPENDED, &ThreadId[6]);
	if(N > 7) hThread[7] = CreateThread(NULL, 0, Output7, NULL, CREATE_SUSPENDED, &ThreadId[7]);
	/*
	Встановлюємо пріоритет потоків:
		Стандартні значення констант пріоритету потоків:";
                THREAD_PRIORITY_TT.ME_CRITT.CAL = 15
                THREAD_PRIORITY_HIGHEST = 2
                THREAD_PRIORITY_ABOVE_NORMAL = 1
                THREAD_PRIORITY_NORMAL  = 0
                THREAD_PRIORITY_BELOW_NORMAL = -1
                THREAD_PRIORITY_LOWEST = -2
                THREAD_PRIORITY_IDLE = -15 */
    for(int i = 0; i < N; i++) 
		//не парним - серелнiй пріоритет, парним - низький
		SetThreadPriority(hThread[i], i%2 ?  THREAD_PRIORITY_NORMAL : THREAD_PRIORITY_LOWEST);

	//запуск потоків
	for(int i = 0; i < N; i++) ResumeThread(hThread[i]);

	//після натиску на будь-яку клавішу - 
	//призупиняємо роботу всіх потоків
	_getch();
	for(int i = 0; i < N; i++) SuspendThread(hThread[i]);

	//продовжуємо роботу всіх потоків
	//після наступного натиску на клавіатурі
	_getch();
	for(int i = 0; i < N; i++) ResumeThread(hThread[i]);
	
	//чекаємо на завершення всіх потоків
	WaitForMultipleObjects(N, hThread, TRUE,INFINITE);	
	
	//засікаємо час завершення роботи процесу
	t.StopTiming();
	printf("\n");
	for(int i = 0; i < N; i++)
		printf("Час роботи потоку %d: %.3G секунд. Прiоритет потоку: %d\n", i+1, ThreadTime[i], GetThreadPriority(hThread[i]));

	printf("(значення прiоритетiв потоку: HIGHEST = 2, NORMAL  = 0, LOWEST = -2)\n");
	printf("\nЗагальний час роботи процесу: %.3G секунд. Прiоритет процесу: %d\n", t.GetUserSeconds(), GetPriorityClass(GetCurrentProcess()));
	printf("(значення прiоритетiв процесу: NORMAL = %d, HIGH = %d, REALTIME = %d)\n", NORMAL_PRIORITY_CLASS, HIGH_PRIORITY_CLASS, REALTIME_PRIORITY_CLASS);
	printf("\nДля завершення роботи програми - натиснiть на будь-яку клавiшу...\n");
	
	//завершуємо всі потоки
	DWORD ExitCode[N];
	for(int i = 0; i < N; i++) {
		//отримуємо код завершення потоків
		GetExitCodeThread(hThread[i], &ExitCode[i]);
		//завершення потоку
		TerminateThread(hThread[i], ExitCode[i]);
		//закриття дексриптора потоку
		CloseHandle(hThread[i]);
	}
	
	//після натиску на будь-яку клавішу - вихід з програми
	_getch();
	return 0;
}
