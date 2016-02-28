#include <iostream>
#include <conio.h>
#include <clocale>
#include <math.h>
#include <cmath>

using namespace std;
	
int const N = 4;
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
		cout<<"\n\n\nЕвклiдову норма матрицi "<<Ek<<" > 1; Програму буде завершено !\n";
		_getch();
		return 0;
	} 
	return 1;
}

void main()	{
	setlocale(LC_ALL, "Ukrainian");
	if(testMode) {
		A[0][0] = -0.82;
		A[0][1] = -0.34;
		A[0][2] = -0.12;
		A[0][3] = 0.15;

		A[1][0] = 0.11;
		A[1][1] = -0.77;
		A[1][2] = -0.15;
		A[1][3] = 0.32;

		A[2][0] = 0.05;
		A[2][1] = -0.12;
		A[2][2] = -0.86;
		A[2][3] = -0.18;

		A[3][0] = 0.12;
		A[3][1] = 0.08;
		A[3][2] = 0.06;
		A[3][3] = -1.0;

		F[0] = -1.33;
		F[1] = 0.84;
		F[2] = -1.16;
		F[3] = 0.57;

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

	double TempX[N];
	//норма, розрахована ​​як найбільша різниця компонент стовпця іксів сусідніх ітерацій
	double norm; 

	//обчислення розвязків
	do {
		for (int i = 0; i < N; i++) {
			TempX[i] = F[i];
			for (int g = 0; g < N; g++) {
				if (i != g)
					TempX[i] -= A[i][g] * X[g];
			}
			TempX[i] /= A[i][i];
		}
                norm = fabs(X[0] - TempX[0]);
		for (int h = 0; h < N; h++) {
			if (fabs(X[h] - TempX[h]) > norm)
				norm = fabs(X[h] - TempX[h]);
			X[h] = TempX[h];
		}
	} while (norm > eps);


	//виведення результату
	cout<<"\n\nX:\n";
	displayVector(X, N);

	_getch();
}
