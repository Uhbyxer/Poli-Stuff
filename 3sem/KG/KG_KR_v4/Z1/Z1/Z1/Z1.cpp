#include <iostream>
#include <conio.h>
#include <clocale>
#include <math.h>
#include <cmath>

using namespace std;

void main() {
	double pi = 3.14;
	double kx = 3.0;
	double ky = 5.0;
	double alphaGrad = 60.0;

	double x, y, x1, y1, x2, y2;
	double alpha = alphaGrad * pi / 180.0;

	cout<<"x, y:\n";
	cin>>x>>y;

	x1 = kx * x;
	y1 = ky * y;
	cout<<"\n(x1, y1): "<<x1<<", "<<y1;

	x2 = x1 * cos(alpha) + y1 * sin(alpha);
	y2 = -x1 * sin(alpha) + y1 * cos(alpha);


	cout<<"\n(x2, y2): "<<x2<<", "<<y2;

	_getch();
}