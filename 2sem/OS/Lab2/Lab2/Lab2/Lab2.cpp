#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <windows.h>

using namespace std;
//==============================================================
//�������� ���������
const int N = 4; //�-��� ������
//����� ��������� ������ ������
double ThreadTime[N]; 
//�������� � ���� ���������� ������
const DWORD PROCESS_PRIORITY = HIGH_PRIORITY_CLASS;
/* ������� ��������� �������: 
	REALTIME_PRIORITY_CLASS - �������� ���
	HIGH_PRIORITY_CLASS - �������
	NORMAL_PRIORITY_CLASS - ������i�
	IDLE_PRIORITY_CLASS - ������� */

//==============================================================
//���� ��� ���������� ���� ������ ������
class Timing2 {
public:
  //������ �������
  void StartTiming();
  //���� �������
  void StopTiming();
  //��������� �������� �������
  double GetUserSeconds() const {
    return value;
  }
private:
  DWORD_PTR oldmask;
  double value;
  LARGE_INTEGER time1;
};

void Timing2::StartTiming() {         
  //������� ���������� -
  //�� ������������� ��� ��������� �������� ���� �����
  volatile int warmingUp = 1;
  //�������� ���������� � �������� �������
  #pragma omp parallel for
  
  /*
  ����� ���� �������� �������� �� ����������� �������� ������ � ��� ����� ����� 
  ������ ������� ���������� ��������. 
  ��� ����� �� "���������" �� ������� ����. */
  for (int i=1; i<10000000; i++) {
    #pragma omp atomic
    warmingUp *= i;
  }
  //��������� ��������� ������ �� ������� ��������
  oldmask = SetThreadAffinityMask(::GetCurrentThread(), 1);
  //������� �-��� �������� ���������
  //�� ������� ������ �������
  QueryPerformanceCounter(&time1);
}

void Timing2::StopTiming() {  
  LARGE_INTEGER performance_frequency, time2;
  //������� �������
  QueryPerformanceFrequency(&performance_frequency);
  
  //������� �-��� �������� ���������
  //��� ��������� ������ �������
  QueryPerformanceCounter(&time2);  
  //�������� ���� �� ������� ��������
  SetThreadAffinityMask(::GetCurrentThread(), oldmask);
  //������ � ������ �� ����������� �� ��������
  value = (double)(time2.QuadPart - time1.QuadPart);
  //������� �� �-��� ����� � ������ - 
  //�������� �������� � ��������
  value /= performance_frequency.QuadPart;
}

//==============================================================
//������� �����������
void tabulation(int threadNum) { //threadNum - ����� ������
	const double a = -1, b = 1.0; //(a;b) - ������� �����������
	const int n = 1000; //������� ����� �����������
	const double eps = 0.0001; //������� ����������
	int i;
	double x, s, si, y;

	Timing2 t;
	//������ ��� ������� ������ ������
	t.StartTiming();

	for(int j = 1; j <= n; j++){
		//�������� �������� �������� x �� ������� ���������
		x = a+j*(b-a)/(double) n;
		//������ ������� ����
		si = x; s = si; 
		i = 2; 
		//��������, ���� �� ��������� ������ �������
		while(fabs(si)>eps) {
			//��������� i-�� ������� ���� �������
			si *= -x*(i-1)/i;
			//�������� ���� ����
			s += si;
			//�������� ��������
			i++;
		}
		//�������� �������� �-� �������� ��������
		y=log(1+x); 
		printf("���i� %d ���� %d: x=%f y=%f s=%f\n", threadNum+1, j, x, y, s);
	}

	//������ ��� ���������� ������
	t.StopTiming();
	//...� �������� ���� � ���������� �����
	ThreadTime[threadNum] = t.GetUserSeconds();
}

//==============================================================
//������� ����������� 1-�� ������
DWORD WINAPI Output0(LPVOID Param) {
	tabulation(0);
	return 0;
}

//==============================================================
//������� ����������� 2-�� ������
DWORD WINAPI Output1(LPVOID Param) {
	tabulation(1);
	return 0;
}

//==============================================================
//������� ����������� 3-�� ������
DWORD WINAPI Output2(LPVOID Param) {
	tabulation(2);
	return 0;
}

//==============================================================
//������� ����������� 4-�� ������
DWORD WINAPI Output3(LPVOID Param) {
	tabulation(3);
	return 0;
}

//==============================================================
//������� ����������� 5-�� ������
DWORD WINAPI Output4(LPVOID Param) {
	tabulation(4);
	return 0;
}

//==============================================================
//������� ����������� 6-�� ������
DWORD WINAPI Output5(LPVOID Param) {
	tabulation(5);
	return 0;
}

//==============================================================
//������� ����������� 7-�� ������
DWORD WINAPI Output6(LPVOID Param) {
	tabulation(6);
	return 0;
}

//==============================================================
//������� ����������� 8-�� ������
DWORD WINAPI Output7(LPVOID Param) {
	tabulation(7);
	return 0;
}

//==============================================================
int main() {
	setlocale(LC_ALL,"Ukrainian");

	HANDLE hThread[N]; //����� ����������� ������
    DWORD ThreadId[N]; //������� �������������� ������

	//������������ �������� �������
	SetPriorityClass(GetCurrentProcess(), PROCESS_PRIORITY);

	Timing2 t;
	//������� ��� ������� �������
	t.StartTiming();

	//��������� ������
    hThread[0] = CreateThread(NULL, 0, Output0, NULL, 0, &ThreadId[0]);
	if(N > 1) hThread[1] = CreateThread(NULL, 0, Output1, NULL, CREATE_SUSPENDED, &ThreadId[1]);
	if(N > 2) hThread[2] = CreateThread(NULL, 0, Output2, NULL, CREATE_SUSPENDED, &ThreadId[2]);
	if(N > 3) hThread[3] = CreateThread(NULL, 0, Output3, NULL, CREATE_SUSPENDED, &ThreadId[3]);
	if(N > 4) hThread[4] = CreateThread(NULL, 0, Output4, NULL, CREATE_SUSPENDED, &ThreadId[4]);
	if(N > 5) hThread[5] = CreateThread(NULL, 0, Output5, NULL, CREATE_SUSPENDED, &ThreadId[5]);
	if(N > 6) hThread[6] = CreateThread(NULL, 0, Output6, NULL, CREATE_SUSPENDED, &ThreadId[6]);
	if(N > 7) hThread[7] = CreateThread(NULL, 0, Output7, NULL, CREATE_SUSPENDED, &ThreadId[7]);
	/*
	������������ �������� ������:
		��������� �������� �������� ��������� ������:";
                THREAD_PRIORITY_TT.ME_CRITT.CAL = 15
                THREAD_PRIORITY_HIGHEST = 2
                THREAD_PRIORITY_ABOVE_NORMAL = 1
                THREAD_PRIORITY_NORMAL  = 0
                THREAD_PRIORITY_BELOW_NORMAL = -1
                THREAD_PRIORITY_LOWEST = -2
                THREAD_PRIORITY_IDLE = -15 */
    for(int i = 0; i < N; i++) 
		//�� ������ - ������i� ��������, ������ - �������
		SetThreadPriority(hThread[i], i%2 ?  THREAD_PRIORITY_NORMAL : THREAD_PRIORITY_LOWEST);

	//������ ������
	for(int i = 0; i < N; i++) ResumeThread(hThread[i]);

	//���� ������� �� ����-��� ������ - 
	//������������ ������ ��� ������
	_getch();
	for(int i = 0; i < N; i++) SuspendThread(hThread[i]);

	//���������� ������ ��� ������
	//���� ���������� ������� �� ��������
	_getch();
	for(int i = 0; i < N; i++) ResumeThread(hThread[i]);
	
	//������ �� ���������� ��� ������
	WaitForMultipleObjects(N, hThread, TRUE,INFINITE);	
	
	//������� ��� ���������� ������ �������
	t.StopTiming();
	printf("\n");
	for(int i = 0; i < N; i++)
		printf("��� ������ ������ %d: %.3G ������. ��i������ ������: %d\n", i+1, ThreadTime[i], GetThreadPriority(hThread[i]));

	printf("(�������� ��i������i� ������: HIGHEST = 2, NORMAL  = 0, LOWEST = -2)\n");
	printf("\n��������� ��� ������ �������: %.3G ������. ��i������ �������: %d\n", t.GetUserSeconds(), GetPriorityClass(GetCurrentProcess()));
	printf("(�������� ��i������i� �������: NORMAL = %d, HIGH = %d, REALTIME = %d)\n", NORMAL_PRIORITY_CLASS, HIGH_PRIORITY_CLASS, REALTIME_PRIORITY_CLASS);
	printf("\n��� ���������� ������ �������� - ������i�� �� ����-��� ����i��...\n");
	
	//��������� �� ������
	DWORD ExitCode[N];
	for(int i = 0; i < N; i++) {
		//�������� ��� ���������� ������
		GetExitCodeThread(hThread[i], &ExitCode[i]);
		//���������� ������
		TerminateThread(hThread[i], ExitCode[i]);
		//�������� ����������� ������
		CloseHandle(hThread[i]);
	}
	
	//���� ������� �� ����-��� ������ - ����� � ��������
	_getch();
	return 0;
}
