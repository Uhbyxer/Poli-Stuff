#include <iostream>
#include <conio.h>
#include <clocale>
#include <math.h>
#include <cmath>

using namespace std;
	
int const N = 3;
const double eps = 0.001;

//якщо 0 - то ввід вхідних даних з клавіатури
int const testMode = 1; 

double A[N][N], X[N], F[N];

//зчитування масиву з клавіатури
void input(double a[N][N], int n,  int m) {
	for(int i=0; i < n; i++)
		for(int j = 0; j < m; j++) {
			cout << "a[" << i << "][" << j << "]: ";	
			cin >> a[i][j];
		}
}

//виведення матриці на екран
void display(double a[N][N], int n,  int m) {
	for(int i=0; i < n; i++) {
		for(int j = 0; j < m; j++) 
			cout << a[i][j] << "\t";
		if(m > 1) cout<<endl;	
	}
}

void inputVector(double a[N], int m) {
	for(int j = 0; j < m; j++) {
		cout << "f[" << j << "]: ";	
		cin >> a[j];
	}
}

void displayVector(double X[N], int n) {
	for(int j = 0; j < n; j++) 
		cout << X[j] << "\t";
}

//перевірка на евклідову норму матриці
int EvklidTest(double a[N][N]) {
	double alpha[N][N];

	for(int i=0; i < N; i++)
		for(int j = 0; j < N; j++) 
			if(i!=j) alpha[i][j] = (-a[i][j])/(a[i][i]);
			else alpha[i][j] = 0; 
   
	double Ek = 0;
	for(int i=0; i < N; i++) {
		for(int j = 0; j < N; j++) 
			Ek += alpha[i][j] * alpha[i][j];
	}
	Ek = pow(Ek,0.5);
	if(Ek > 1.0) { 
		cout<<"\n\n\nЕвклiдова норма матрицi "<<Ek<<" > 1; Програму буде завершено !\n";
		_getch();
		return 0;
	} 
	return 1;
}

void main()	{
	setlocale(LC_ALL, "Ukrainian");
	if(testMode) {
		A[0][0] = 1.0;
		A[0][1] = 3.9;
		A[0][2] = 1.0;
		
		A[1][0] = 1.0;
		A[1][1] = 2.7;
		A[1][2] = -2.0;

		A[2][0] = 2.0;
		A[2][1] = -4.4;
		A[2][2] = 1.0;

		F[0] = -10.2;
		F[1] = -11.0;
		F[2] = -5.0;
	} else {
		cout<<"Введiть матрицю А:\n";
		input(A, N, N);

		cout<<"\nВведiть стовпець F:\n";
		inputVector(F, N);
	}

	//Вивід a та f 
	cout<<"А:\n";
	display(A, N, N);
	cout<<"\nB:\n";
	displayVector(F, N);
	
	if(!EvklidTest(A)) return; 

	double norm, v, s;
	int i;
	for (i = 0; i < N; i++) X[i] = 0; 
	do {
		norm = 0;
		for (i = 0; i < N; i++) {
			s = 0;
			for (int j = 0; j < N; j++) 
				if (i != j) s += A[i][j] * X[j];
			v = X[i];
			X[i] = (F[i] - s) / A[i][i];
			norm = fabs(X[i] - v);
		}
	} while (norm > eps);

	//виведення результату
	cout<<"\n\nX:\n";
	displayVector(X, N);

	_getch();
}
