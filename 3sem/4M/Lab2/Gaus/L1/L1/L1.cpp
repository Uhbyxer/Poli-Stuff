#include <stdio.h>
#include <conio.h>
#include <clocale>
#include <math.h>

int const n = 3;
//якщо 0 - то ввід вхідних даних з клавуатури
int const testMode = 1;

void mainElem( int k, double mas[] [n + 1], int n, int xx[] ) {
  int i, j, i_max = k, j_max = k;
  double temp;
  
  //Шукаємо максимальний по модулю елемент
  for ( i = k; i < n; i++ )
    for ( j = k; j < n; j++ )
      if ( fabs( mas[i_max] [j_max] ) < fabs( mas[i] [j] ) )
      {
        i_max = i;
        j_max = j;
      }

  //Переставляємо рядки
  for ( j = k; j < n + 1; j++ ) {
    temp = mas[k] [j];
    mas[k] [j] = mas[i_max] [j];
    mas[i_max] [j] = temp;
  }

  //Переставляємо стовбці
  for ( i = 0; i < n; i++ ) {
    temp = mas[i] [k];
    mas[i] [k] = mas[i] [j_max];
    mas[i] [j_max] = temp;
  }

  //Враховуємо зміну порядку коренів
  i = xx[k];
  xx[k] = xx[j_max];
  xx[j_max] = i;
}
 
int main(void) {
  setlocale(LC_ALL, "Ukrainian");
  double mas[n] [n + 1];
  double x[n]; //Корені системы
  //відповідає за порядок коренів
  int xx[n]; 
  int i, j, k;

  if(testMode) {
	mas[0][0] = 0.92;
	mas[0][1] = -0.83;
	mas[0][2] = 0.62;

	mas[1][0] = 0.24;
	mas[1][1] = -0.54;
	mas[1][2] = 0.43;

	mas[2][0] = 0.73;
	mas[2][1] = -0.81;
	mas[2][2] = -0.67;	

	mas[0][n] = 2.15;
	mas[1][n] = 0.62;
	mas[2][n] = 0.88;

  } else {
 	printf( "Введiть систему:\n" );
		for ( i = 0; i < n; i++ )
			for ( j = 0; j < n + 1; j++ )
				scanf( "%lf", &mas[i][j]);
  }


  //виведення введеної системи
  printf( "Система:\n" );
  for ( i = 0; i < n; i++ ) {
    for ( j = 0; j < n + 1; j++ )
      printf( "%7.2f ", mas[i] [j] );
    printf( "\n" );
  }
  
  //спочатку всі корені по порядку
  for ( i = 0; i < n + 1; i++ ) xx[i] = i;
  
  //Прямий хід
  for ( k = 0; k < n; k++ )
  { //на якій позиції повинен стояти головний елемент
    mainElem( k, mas, n, xx ); //Встановлення головного елемента
    if ( fabs( mas[k] [k] ) < 0.0001 )
    {
      printf( "Система не має жодного рiшення !" );
      return ( 0 );
    }
    for ( j = n; j >= k; j-- )
      mas[k] [j] /= mas[k] [k];
    for ( i = k + 1; i < n; i++ )
      for ( j = n; j >= k; j-- )
        mas[i][j] -= mas[k] [j] * mas[i][k];
  }
  
  //Зворотній хід
  for ( i = 0; i < n; i++ )
    x[i] = mas[i] [n];
  for ( i = n - 2; i >= 0; i-- )
    for ( j = i + 1; j < n; j++ )
      x[i] -= x[j] * mas[i] [j];
  
  //Вивід результата
  printf( "Результат:\n" );
  for ( i = 0; i < n; i++ )
    for ( j = 0; j < n; j++ )
      if ( i == xx[j] )
      { //розтавлення коренів по порядку
        printf( "%f\n", x[j] );
        break;
      }
	  
  _getch();
  return 0;
}
