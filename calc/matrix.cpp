#include <iostream>
#include "matrix.h"
using namespace std;


int* EnterMatrix(int rows, int columns) {
	int* Array;
	Array = (int*)malloc(rows * columns * sizeof(int));

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {

			cout << "Array[" << i << "][" << j << "] = ";
			scanf_s("%d", (Array + i * columns + j));
		}
	}

	return Array;

}

void AdditionOfMatrix() {



	int rows = 0, columns = 0, * Array1, *Array2;
	cout << "������� ���������� ����� ������� ";
	do {
		rows = ChekOnInt();
		if (rows <= 0) cout << "��������� ����" << endl;
	} while (rows <= 0);

	cout << "������� ���������� ��������� � ������ ";
	do {
		columns = ChekOnInt();
		if (columns <= 0) cout << "��������� ����" << endl;
	} while (columns <= 0);

	Array1 = (int*)malloc(rows * columns * sizeof(int));
	cout << "�������  ������ ������:" << endl;
	Array1 = EnterMatrix(rows, columns);

	Array2 = (int*)malloc(rows * columns * sizeof(int));
	cout << "�������  ������ ������:" << endl;
	Array2 = EnterMatrix(rows, columns);


	cout << "��������� �������:" << endl;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			cout << *(Array1 + i * columns + j) << "\t ";
		}
		cout << endl;
	}
	cout << endl;

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			cout << *(Array2 + i * columns + j) << "\t ";
		}
		cout << endl;
	}
	cout << "��� �������� �������� ��������: " << endl;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			*(Array1 + i * columns + j) = *(Array1 + i * columns + j) + *(Array2 + i *columns + j);
			cout << *(Array1 + i * columns + j) << "\t ";
		}
		cout << endl;
	}

}


void Matrix(int taskNumber) {
	switch (taskNumber) {
	/*case 0: DivisionOfPolynomials(); break;
	case 1: AdditionOfPolynomials(); break;
	case 2: PolynomialSubtraction(); break;
	case 3: PolynomialMultiplication(); break;
	case 4: MultiplicationByNumber(); break;
	case 5: DerivativeOfaPolynomial(); break;*/
	default: break;
	}
}