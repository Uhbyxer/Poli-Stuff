#include <iostream>
#include <conio.h>
#include <math.h>

using namespace std;

class Matrix {
public:
	int* data;
	int size;

	//����������� � ������������ ���������� ������
	//������ ������ �������� ���� ����� ������� � ������ ����
	//� ������������ ������� ���������� ������ ����������� ����������
	//�� ����������
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

	//����������� ��� ��������� 
	//����������� ����� 2*2
    Matrix() {
        size = 2;
        data = new int[4];
	}

	//����������� ����
	Matrix(const Matrix &p) {
		size = p.size;
        data = new int[size*size];
		
		int* k =	p.data;	 
		for(int i = 0; i < size*size; i++)
			*(data+i) = *(k+i);
	}

	//����������
    ~Matrix() {
        delete[] data;
    }
    
	//���������������� ��������� [] 
	int* operator[](int row) {
        return data+row*size;
    }

	//���������������� ��������� = 
	Matrix& operator=(const Matrix& right) {
        //�������� �� �������������
        if (this == &right) {
            return *this;
        }
        size = right.size;
        int* k =	right.data;
		for(int i = 0; i < size*size; i++)
			*(data+i) = *(k+i);

		return *this;
    }

	//����� �������

	//������� "-"
	friend const Matrix operator-(const Matrix& right);
	
	//������� "-" (�������3 = �������1 - �������2)
	friend const Matrix operator-(const Matrix& left, const Matrix& right);

	//������� "-" (�������3 = �������1 - �����)
	friend const Matrix operator-(const Matrix& left, int right);

	//�������1 += �������2;
	friend Matrix& operator+=(Matrix& left, const Matrix& right);

	//�������1 += �����;
	friend Matrix& operator+=(Matrix& left, int right);

	//"*" (�������3 = �������1 * �������2)
	friend const Matrix operator*(const Matrix& left, const Matrix& right);

	//"*" (�������2 = �������1 * �����)
	friend const Matrix operator*(const Matrix& left, int right);

	//���������������� ������ ������ �� �����
	friend ostream& operator<<(ostream&, const Matrix&);

	//���������������� ����� ������ � ���������
	friend istream& operator>>(istream&, const Matrix&);
};


//������� "-"
const Matrix operator-(const Matrix& right) {
    
	Matrix left(right.size);
	int* k =	right.data;
	for(int i = 0; i < right.size*right.size; i++)
		*(left.data+i) = -*(k+i);

	return left;
}

//������� "-" (�������3 = �������1 - �������2)
const Matrix operator-(const Matrix& left, const Matrix& right) {
    Matrix result(left.size);
	int* k =	left.data;
	int* m =	right.data;
	for(int i = 0; i < left.size*left.size; i++)
		*(result.data+i) = *(k+i) - *(m+i);

	return result;
}

//������� "-" (�������3 = �������1 - �����)
const Matrix operator-(const Matrix& left, int right) {
    Matrix result(left.size);
	int* k =	left.data;
	for(int i = 0; i < left.size*left.size; i++)
		*(result.data+i) = *(k+i) - right;

	return result;
}

//"*" (�������3 = �������1 * �������2)
const Matrix operator*(const Matrix& left, const Matrix& right) {
    Matrix result(left.size);
	int* k =	left.data;
	int* m =	right.data;
	for(int i = 0; i < left.size*left.size; i++)
		*(result.data+i) = (*(k+i)) * (*(m+i));

	return result;
}

//"*" (�������2 = �������1 * �����)
const Matrix operator*(const Matrix& left, int right) {
    Matrix result(left.size);
	int* k =	left.data;
	for(int i = 0; i < left.size*left.size; i++)
		*(result.data+i) = (*(k+i)) * right;

	return result;
}


//�������1 += �������2;
Matrix& operator+=(Matrix& left, const Matrix& right) {
    int* m =	right.data;
	for(int i = 0; i < left.size*left.size; i++)
		*(left.data+i) +=  *(m+i);
	
	return left;
}

//�������1 += �����;
Matrix& operator+=(Matrix& left, int right) {
	for(int i = 0; i < left.size*left.size; i++)
		*(left.data+i) +=  right;
	
	return left;
}

//���������������� ������ ������ �� �����
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

//���������������� ����� ������ � ���������
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

	//� ���������� ������������
	Matrix a(-2,1,2,3,4);
	cout<<"a = {1,2,3,4}:\n"<<a;

	//��� ��������� - �� ������������ 2*2
	Matrix b;
	cout<<"\nInput b:\n";
	cin>>b;
	cout<<"\nb:\n"<<b;
	
	//� �������� �������, ��� �����������
	Matrix c(N);
	c = -b;
	cout<<"\nc = -b\n"<<c;
	
	//����������
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