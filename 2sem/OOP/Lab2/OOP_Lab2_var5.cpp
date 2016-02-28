#include <iostream>
#include <conio.h>
#include <math.h>

using namespace std;

class Matrix {
public:
	int* data;
	int size;

	//конструктор з ≥н≥ц≥ал≥зац≥Їю початкових данних
	//першим числом повиинно бути розм≥р матриц≥ з≥ знаком м≥нус
	//в протилежному випадку заповненн€ масиву початковими значенн€ми
	//не в≥дбудетьс€
    Matrix(int matSize, ...) {
        size = matSize;
		if(size<0) size = -size;
        data = new int[size*size];

		if(matSize < 0) {
			int *p = &matSize;
			for(int i = 0; i < size*size; i++) {
				p++;
				*(data+i) = *(p);
			}
		}
    }

	//конструктор без параметр≥в 
	//створюЇтьс€ масив 2*2
    Matrix() {
        size = 2;
        data = new int[4];
	}

	//конструктор коп≥й
	Matrix(const Matrix &p) {
		size = p.size;
        data = new int[size*size];
		
		int* k =	p.data;	 
		for(int i = 0; i < size*size; i++)
			*(data+i) = *(k+i);
	}

	//деструктор
    ~Matrix() {
        delete[] data;
    }
    
	//перезавантаженн€ оператора [] 
	int* operator[](int row) {
        return data+row*size;
    }

	//перезавантаженн€ оператора = 
	Matrix& operator=(const Matrix& right) {
        //перев≥рка на самоприсвоЇнн€
        if (this == &right) {
            return *this;
        }
        size = right.size;
        int* k =	right.data;
		for(int i = 0; i < size*size; i++)
			*(data+i) = *(k+i);

		return *this;
    }

	//ƒружн≥ функц≥њ

	//унарний "-"
	friend const Matrix operator-(const Matrix& right);
	
	//б≥нарний "-" (матриц€3 = матриц€1 - матриц€2)
	friend const Matrix operator-(const Matrix& left, const Matrix& right);

	//б≥нарний "-" (матриц€3 = матриц€1 - число)
	friend const Matrix operator-(const Matrix& left, int right);

	//матриц€1 += матриц€2;
	friend Matrix& operator+=(Matrix& left, const Matrix& right);

	//матриц€1 += число;
	friend Matrix& operator+=(Matrix& left, int right);

	//"*" (матриц€3 = матриц€1 * матриц€2)
	friend const Matrix operator*(const Matrix& left, const Matrix& right);

	//"*" (матриц€2 = матриц€1 * число)
	friend const Matrix operator*(const Matrix& left, int right);

	//перезавантаженн€ виводу масиву на екран
	friend ostream& operator<<(ostream&, const Matrix&);

	//перезавантаженн€ вводу масиву з клав≥атури
	friend istream& operator>>(istream&, const Matrix&);
};


//унарний "-"
const Matrix operator-(const Matrix& right) {
    
	Matrix left(right.size);
	int* k =	right.data;
	for(int i = 0; i < right.size*right.size; i++)
		*(left.data+i) = -*(k+i);

	return left;
}

//б≥нарний "-" (матриц€3 = матриц€1 - матриц€2)
const Matrix operator-(const Matrix& left, const Matrix& right) {
    Matrix result(left.size);
	int* k =	left.data;
	int* m =	right.data;
	for(int i = 0; i < left.size*left.size; i++)
		*(result.data+i) = *(k+i) - *(m+i);

	return result;
}

//б≥нарний "-" (матриц€3 = матриц€1 - число)
const Matrix operator-(const Matrix& left, int right) {
    Matrix result(left.size);
	int* k =	left.data;
	for(int i = 0; i < left.size*left.size; i++)
		*(result.data+i) = *(k+i) - right;

	return result;
}

//"*" (матриц€3 = матриц€1 * матриц€2)
const Matrix operator*(const Matrix& left, const Matrix& right) {
    Matrix result(left.size);
	int* k =	left.data;
	int* m =	right.data;
	for(int i = 0; i < left.size*left.size; i++)
		*(result.data+i) = (*(k+i)) * (*(m+i));

	return result;
}

//"*" (матриц€2 = матриц€1 * число)
const Matrix operator*(const Matrix& left, int right) {
    Matrix result(left.size);
	int* k =	left.data;
	for(int i = 0; i < left.size*left.size; i++)
		*(result.data+i) = (*(k+i)) * right;

	return result;
}


//матриц€1 += матриц€2;
Matrix& operator+=(Matrix& left, const Matrix& right) {
    int* m =	right.data;
	for(int i = 0; i < left.size*left.size; i++)
		*(left.data+i) +=  *(m+i);
	
	return left;
}

//матриц€1 += число;
Matrix& operator+=(Matrix& left, int right) {
	for(int i = 0; i < left.size*left.size; i++)
		*(left.data+i) +=  right;
	
	return left;
}

//перезавантаженн€ виводу масиву на екран
ostream& operator<<(ostream& output, const Matrix& matr) {
	int* m =	matr.data;

	for(int i = 0, k = 0; i < matr.size; i++) {
		for(int j = 0; j < matr.size; j++, k++) {
			output<<(*(m+k))<<"\t";
		}
		output<<"\n";
	}
	return output;
}

//перезавантаженн€ вводу масиву з клав≥атури
istream& operator>>(istream& input, const Matrix& matr) {
	int* m =	matr.data;

	for(int i = 0, k = 0; i < matr.size; i++) 
		for(int j = 0; j < matr.size; j++, k++) { 
			cout<<"["<<i+1<<"]["<<j+1<<"]: ";
			input>>(*(m+k));
		}
	return input;
}

void main() {
	const int N = 2;

	//з початковою ≥н≥ц≥ал≥зац≥Їю
	Matrix a(-2,1,2,3,4);
	cout<<"a = {1,2,3,4}:\n"<<a;

	//без параметр≥в - по замовчуванню 2*2
	Matrix b;
	cout<<"\nInput b:\n";
	cin>>b;
	cout<<"\nb:\n"<<b;
	
	//з вказаним розм≥ром, без ≥н≥ц≥ал≥зац≥њ
	Matrix c(N);
	c = -b;
	cout<<"\nc = -b\n"<<c;
	
	//коп≥юванн€м
	Matrix d(c);
	cout<<"\nMatrix d(c)\n"<<d;

	d = b - 5;
	cout<<"\nd = b - 5\n"<<d;

	b = d - a;
	cout<<"\nb = d - a\n"<<b;

	c = a * 2;
	cout<<"\nc = a * 2\n"<<c;

	a = b * c;
	cout<<"\na = b * c\n"<<a;

	a += 3;
	cout<<"\na += 3\n"<<a;

	a += c;
	cout<<"\na += c\n"<<a;

	_getch();
}