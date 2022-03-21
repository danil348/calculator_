#include <iostream>
#include "matrix.h"
#include <stdarg.h>
using namespace std;

//���� ������
int EnterRows() {
	int rows;
	cout << "������� ���������� ����� ������� ";
	do {
		rows = ChekOnInt();
		if (rows <= 0) cout << "��������� ����" << endl;
	} while (rows <= 0);
	return rows;
}

//���� ��������
int EnterColumns() {
	int columns;
	cout << "������� ���������� ��������� � ������ ";
	do {
		columns = ChekOnInt();
		if (columns <= 0) cout << "��������� ����" << endl;
	} while (columns <= 0);
	return columns;
}

//���� �������
double* EnterMatrix(int rows, int columns) {
	double* Matrix;
	Matrix = (double*)malloc(rows * columns * sizeof(double));

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {

			cout << "Matrix[" << i << "][" << j << "] = ";
			*(Matrix + i * columns + j) = ChekOnDouble();
		}
	}

	return Matrix;

}

//�������� ������
void AdditionOfMatrix(int k) {

	int rows, columns;
	double* Matrix1, * Matrix2;

	rows = EnterRows();
	columns = EnterColumns();

	Matrix1 = (double*)malloc(rows * columns * sizeof(double));
	cout << "�������  ������ �������:" << endl;
	Matrix1 = EnterMatrix(rows, columns);

	Matrix2 = (double*)malloc(rows * columns * sizeof(double));
	cout << "�������  ������ �������:" << endl;
	Matrix2 = EnterMatrix(rows, columns);


	cout << "��������� �������:" << endl << "������:" << endl;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			cout << *(Matrix1 + i * columns + j) << "\t ";
		}
		cout << endl;
	}

	cout << endl << "������:" << endl;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			cout << *(Matrix2 + i * columns + j) << "\t ";
		}
		cout << endl;
	}


	if (k == 0) {
		cout << "��� �������� ������ ��������: " << endl;
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				*(Matrix1 + i * columns + j) = *(Matrix1 + i * columns + j) + *(Matrix2 + i * columns + j);
				cout << *(Matrix1 + i * columns + j) << "\t ";
			}
			cout << endl;
		}
	}
	else {
		cout << "��� ��������� ������ ��������: " << endl;
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				*(Matrix1 + i * columns + j) = *(Matrix1 + i * columns + j) - *(Matrix2 + i * columns + j);
				cout << *(Matrix1 + i * columns + j) << "\t ";
			}
			cout << endl;
		}
	}
}

//��������� ������
void MultiplicationMatrix() {
	int rows1, rows2, columns1, columns2, flag = 0;
	double* Matrix1, * Matrix2, * Matrix3;
	do { 
		flag = 0;
		cout << "������ �������: " << endl;
		rows1 = EnterRows();
		columns1 = EnterColumns();
		cout << "������ �������: " << endl;
		rows2 = EnterRows();
		columns2 = EnterColumns();
		if (columns1 != rows2)
		{
			system("cls");
			cout << "��������� ����������! ��������� ���� " << endl;
			flag = 1;
		}
	} while (flag == 1);

	Matrix1 = (double*)malloc(rows1 * columns1 * sizeof(double));
	cout << "�������  ������ �������:" << endl;
	Matrix1 = EnterMatrix(rows1, columns1);

	Matrix2 = (double*)malloc(rows2 * columns2 * sizeof(double));
	cout << "�������  ������ �������:" << endl;
	Matrix2 = EnterMatrix(rows2, columns2);


	cout << "��������� �������: " << endl << "������: " << endl;
	for (int i = 0; i < rows1; i++) {
		for (int j = 0; j < columns1; j++) {
			cout << *(Matrix1 + i * columns1 + j) << "\t ";
		}
		cout << endl;
	}
	cout << endl << "������: " << endl;
	for (int i = 0; i < rows2; i++) {
		for (int j = 0; j < columns2; j++) {
			cout << *(Matrix2 + i * columns2 + j) << "\t ";
		}
		cout << endl;
	}

	Matrix3 = (double*)malloc(rows1 * columns2 * sizeof(double));
	for (int i = 0; i < rows1; i++) {
		for (int j = 0; j < columns2; j++) {
			*(Matrix3 + i * columns2 + j) = 0;
			for (int k = 0; k < columns1; k++) {
				*(Matrix3 + i * columns2 + j) += *(Matrix1 + i * columns1 + k) * *(Matrix2 + k * columns2 + j);
			}
		}
	}

	cout << "������� ������������" << endl;
	for (int i = 0; i < rows1; i++) {
		for (int j = 0; j < columns2; j++)
			cout << *(Matrix3 + i * columns2 + j) << "\t ";
		cout << endl;
	}
}

//��������� ������� �� �����
void MultiplicationMatrixByANumber() {
	int rows, columns;
	double* Matrix1, number;

	rows = EnterRows();
	columns = EnterColumns();

	Matrix1 = (double*)malloc(rows * columns * sizeof(double));
	cout << "������� �������:" << endl;
	Matrix1 = EnterMatrix(rows, columns);

	cout << "��������� �������:" << endl;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			cout << *(Matrix1 + i * columns + j) << "\t ";
		}
		cout << endl;
	}
	cout << endl;
	cout << "������� �����, �� ������� ������ �������� �������" << endl;
	number = ChekOnDouble();
	cout << "��� ��������� ������� �� ����� ��������: " << endl;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			*(Matrix1 + i * columns + j) = *(Matrix1 + i * columns + j) * number;
			cout << *(Matrix1 + i * columns + j) << "\t ";
		}
		cout << endl;
	}
}

//�������� ������� �����(���������� ��� �������� � ������������, ���������� �� �����)
void AdditionMatrixAndNumber(int k) {

	int rows, columns;
	double* Matrix1, number;

	rows = EnterRows();
	columns = rows;
	cout << "��� ������� ������ �������n�� ����� ����� ���������� �������� (" << rows << ")" << endl;

	Matrix1 = (double*)malloc(rows * columns * sizeof(double));
	cout << "������� �������:" << endl;
	Matrix1 = EnterMatrix(rows, columns);

	cout << "��������� �������:" << endl;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			cout << *(Matrix1 + i * columns + j) << "\t ";
		}
		cout << endl;
	}
	cout << endl;
	if (k == 0) {
		cout << "������� �����, ������� ������ ��������� � ������� " << endl;
		number = ChekOnDouble();
		for (int i = 0; i < rows; i++) {
			*(Matrix1 + i * columns + i) = *(Matrix1 + i * columns + i) + number;
		}
		cout << "��� ����������� ����� � ������� ��������: " << endl;
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				cout << *(Matrix1 + i * columns + j) << "\t ";
			}
			cout << endl;
		}
	}
	else {

		cout << "������� �����, ������� ������ ������� �� ������� " << endl;
		number = ChekOnDouble();
		for (int i = 0; i < rows; i++) {
			*(Matrix1 + i * columns + i) = *(Matrix1 + i * columns + i) - number;
		}
		cout << "��� ��������� ����� �� ������� ��������: " << endl;
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				cout << *(Matrix1 + i * columns + j) << "\t ";
			}
			cout << endl;
		}




	}



}

//���������������� �������
void TransposeMatrix() {

	int rows, columns;
	double Matrix1[10][10];

	do {
		rows = EnterRows();
		if (rows > 10) {
			cout << "� ������ ������� ���������� ������ ������� ����������� ����� 10. ��������� ����" << endl;
		}
	} while (rows > 10);

	do {
		columns= EnterRows();
		if (columns > 10) {
			cout << "� ������ ������� ���������� ������ ������� ����������� ����� 10. ��������� ����" << endl;
		}
	} while (columns > 10);

	cout << "������� �������:" << endl;
	for (int i = 0; i < rows; i++) {

		for (int j = 0; j < columns; j++) {
			cout << "Matrix[" << i << "][" << j << "] = ";
			Matrix1[i][j] = ChekOnDouble();
		}
	}

	cout << "��������� �������:" << endl;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			cout << Matrix1[i][j] << "\t ";
		}
		cout << endl;
	}
	cout << endl;

	double TransposeMatrix[10][10]{};
	for (int i = 0; i < rows; i++){
		for (int j = 0; j < columns; j++){
			TransposeMatrix[j][i] = Matrix1[i][j];
		}
	}

	cout << "����������������� �������:" << endl;
	for (int i = 0; i < columns; i++) {
		for (int j = 0; j < rows; j++) {
			cout << TransposeMatrix[i][j] << "\t ";
		}
		cout << endl;
	}
	cout << endl;
}

//������� ����������������� ���������� ������������ �������
double Determinant(double(*matrix)[10], int size) {
	double determinant = 0;
	int degree = 1;

	if (size == 1) {
		determinant = determinant + matrix[0][0];
	}
	else if (size == 2) {
		determinant = determinant + matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
	}
	else {
		int const newSize = size - 1;
		double newMatrix[10][10];
		for (int j = 0; j < size; j++) {


			int offsetCol = 0;
			for (int i = 0; i < size - 1; i++) {
				offsetCol = 0;
				for (int jj = 0; jj < size - 1; jj++) {
					if (jj == j) {
						offsetCol = 1;
					}
					newMatrix[i][jj] = matrix[i + 1][jj + offsetCol];
				}
			}
			determinant += degree * matrix[0][j] * Determinant(newMatrix, newSize);

			degree *= -1;
		}
	}
	return determinant;
}

//���������� �������� �������
int InverseMatrix() {
	int size;
	double matrix[10][10], determinant;
	do {
		size = EnterRows();
		if (size > 10) {
			cout << "� ������ ������� ���������� ������ ������� ����������� ����� 10. ��������� ����" << endl;
		}
	} while (size > 10);
	cout << "��� ������� ������ ���������� ����� ����� ���������� �������� (" << size << ")" << endl;

	cout << "������� �������:" << endl;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << "Matrix[" << i << "][" << j << "] = ";
			matrix[i][j] = ChekOnDouble();
		}
	}

	cout << "��������� �������:" << endl;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << matrix[i][j] << "\t ";
		}
		cout << endl;
	}
	cout << endl;

	determinant = Determinant(matrix, size);
	if (!determinant) {
		cout << "������������ ����� ����. ���������� ����������" << endl;
		return 0;
	}

	double newMatrix[10][10];
	double minor[10][10];					//���������� ������
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			int ki = 0;
			for (int ii = 0; ii < size; ii++) {
				if (i != ii) {
					for (int jj = 0, kj = 0; jj < size; jj++) {
						if (j != jj) {
							minor[ki][kj] = matrix[ii][jj];
							kj++;
						}
					}
					ki++;
				}
			}
			newMatrix[i][j] = pow(-1, i + j + 2) * Determinant(minor, size - 1);// ����� ������� �� ���������
		}
	}

	double TransposeMatrix[10][10]{};

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			TransposeMatrix[j][i] = newMatrix[i][j];
		}
	}


	cout << "�������� �������: " << endl;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			TransposeMatrix[i][j] /= determinant;
			printf_s("%10.3lf",TransposeMatrix[i][j]);
		}
		cout << endl;
	}
	cout << endl;

	return 1;
}

//������������ �������
double DeterminantMatrix() {
	int size;
	double matrix[10][10], determinant;
	do {
		size = EnterRows();
		if (size > 10) {
			cout << "� ������ ������� ���������� ������ ������� ����������� ����� 10. ��������� ����" << endl;
		}
	} while (size > 10);

	cout << "��� ������� ������ ���������� ����� ����� ���������� �������� (" << size << ")" << endl;


	cout << "������� �������:" << endl;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << "Matrix[" << i << "][" << j << "] = ";
			matrix[i][j] = ChekOnDouble();
		}
	}

	cout << "��������� �������:" << endl;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << matrix[i][j] << "\t ";
		}
		cout << endl;
	}
	cout << endl;

	determinant = Determinant(matrix, size);
	cout << "������������ �������: " << determinant;
	return 1;
}



void Matrix(int taskNumber) {
	switch (taskNumber) {
	case 0: AdditionOfMatrix(0); break;				//�������� ������
	case 1: AdditionOfMatrix(1); break;				//��������� ������
	case 2:	MultiplicationMatrix(); break;			//��������� ������
	case 3: MultiplicationMatrixByANumber(); break;	//��������� ������� �� �����
	case 4: AdditionMatrixAndNumber(0); break;		//�������� ������� � �����
	case 5: AdditionMatrixAndNumber(1); break;		//��������� �� ������� �����
	case 6:	TransposeMatrix(); break;				//���������������� ������� 
	case 7:	InverseMatrix(); break;					//�������� �������
	case 8: DeterminantMatrix(); break;				//������������
	default: break;
	}
}