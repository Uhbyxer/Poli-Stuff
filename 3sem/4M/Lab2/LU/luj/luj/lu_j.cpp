#include <iostream>
#include <conio.h>
#include <clocale>

using namespace std;
	
int const N = 3;

//якщо 0 - то ввід вхідних даних з клавуатури
int const testMode = 1; 

double a[N][N], b[N][N], L[N][N], 
	   U[N][N], x[N][N], y[N][N];

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

//обчислення матриць L та U, де U*L*x=b
void calculateLU () {
	for(int i = 0; i < N; i++) U[0][i] = a[0][i];
	for(int i = 1; i < N; i++) L[i][0]= a [i][0] / U[0][0];
	
	U[1][1]=a[1][1]-L[1][0]*U[0][1];
	L[2][1]=(a[2][1]-L[2][0]*U[0][1])/U[1][1];
	U[1][2]=a[1][2]-L[1][0]*U[0][2];
	U[2][2]=a[2][2]-L[2][1]*U[1][2]-L[2][0]*U[0][2];

	for(int i = 0; i < N; i++) L[i][i] = 1;
}

//Обчислення Y=U*x
void calculateY() {
	y[0][0] = b[0][0];
	y[1][0] = b[1][0] - L[1][0] * y[0][0];
	y[2][0] = b[2][0] - L[2][0]*y[0][0] - L[2][1]*y[1][0];
}
	
//Обчислення Х
void calculateX() {
	x[2][0] = y[2][0] / U[2][2];
	x[1][0] = (y[1][0] - U[1][2] * x[2][0]) / U[1][1];
	x[0][0] = (y[0][0] - U[0][2] * x[2][0] - U[0][1] * x[1][0]) / U[0][0];
}

void main()	{
	setlocale(LC_ALL, "Ukrainian");
	if(testMode) {
		a[0][0] = 0.92;
		a[0][1] = -0.83;
		a[0][2] = 0.62;

		a[1][0] = 0.24;
		a[1][1] = -0.54;
		a[1][2] = 0.43;

		a[2][0] = 0.73;
		a[2][1] = -0.81;
		a[2][2] = -0.67;	

		b[0][0] = 2.15;
		b[1][0] = 0.62;
		b[2][0] = 0.88;

	} else {
		cout<<"Введiть матрицю А:\n";
		input(a, N, N);
		cout<<"\nВведiть стовпець B:\n";
		input(b, N, 1);
	}

	//Вивід a та b 
	cout<<"А:\n";
	display(a, N, N);
	cout<<"\nB:\n";
	display(b, N, 1);

	//обчислення L та U
	calculateLU();
	
	//Вивід L та U
	cout<<"\n\nL:\n";
	display(L, N, N);
	cout<<"\nU:\n";
	display(U, N, N);

	//обчислення Y та X
	calculateY();
	calculateX();

	//Вивід Y та X
	cout<<"\n\nY:\n";
	display(y, N, 1);
	cout<<"\n\nX:\n";
	display(x, N, 1);

	_getch();
}
