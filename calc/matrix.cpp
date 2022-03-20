#include <iostream>
#include "matrix.h"
using namespace std;


int EnterRows() {
	int rows;
	cout << "Введите количество строк матрицы ";
	do {
		rows = ChekOnInt();
		if (rows <= 0) cout << "Повторите ввод" << endl;
	} while (rows <= 0);
	return rows;
}


int EnterColumns() {
	int columns;
	cout << "Введите количество элементов в строке ";
	do {
		columns = ChekOnInt();
		if (columns <= 0) cout << "Повторите ввод" << endl;
	} while (columns <= 0);
	return columns;
}


double* EnterMatrix(int rows, int columns) {
	double* Matrix;
	Matrix = (double*)malloc(rows * columns * sizeof(double));

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {

			cout << "Matrix[" << i << "][" << j << "] = ";
			scanf_s("%lf", (Matrix + i * columns + j));
		}
	}

	return Matrix;

}


void AdditionOfMatrix(int k) {

	int rows, columns;
	double* Matrix1, * Matrix2;

	rows = EnterRows();
	columns = EnterColumns();

	Matrix1 = (double*)malloc(rows * columns * sizeof(double));
	cout << "Введите  первую матрицу:" << endl;
	Matrix1 = EnterMatrix(rows, columns);

	Matrix2 = (double*)malloc(rows * columns * sizeof(double));
	cout << "Введите  вторую матрицу:" << endl;
	Matrix2 = EnterMatrix(rows, columns);


	cout << "Введенные матрицы:" << endl;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			cout << *(Matrix1 + i * columns + j) << "\t ";
		}
		cout << endl;
	}
	cout << endl;

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			cout << *(Matrix2 + i * columns + j) << "\t ";
		}
		cout << endl;
	}


	if (k == 0) {
		cout << "При сложении матриц получаем: " << endl;
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				*(Matrix1 + i * columns + j) = *(Matrix1 + i * columns + j) + *(Matrix2 + i * columns + j);
				cout << *(Matrix1 + i * columns + j) << "\t ";
			}
			cout << endl;
		}
	}
	else {
		cout << "При вычитании матриц получаем: " << endl;
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				*(Matrix1 + i * columns + j) = *(Matrix1 + i * columns + j) - *(Matrix2 + i * columns + j);
				cout << *(Matrix1 + i * columns + j) << "\t ";
			}
			cout << endl;
		}
	}
}


void MultiplicationMatrix() {
	int rows1, rows2, columns1, columns2, flag = 0;
	double* Matrix1, * Matrix2, * Matrix3;
	do {
		cout << "Первая матрица: " << endl;
		rows1 = EnterRows();
		columns1 = EnterColumns();
		cout << "Вторая матрица: " << endl;
		rows2 = EnterRows();
		columns2 = EnterColumns();
		if (columns1 != rows2)
		{
			cout << "Умножение невозможно! Повторите ввод " << endl;
			flag = 1;
		}
	} while (flag == 1);

	Matrix1 = (double*)malloc(rows1 * columns1 * sizeof(double));
	cout << "Введите  первую матрицу:" << endl;
	Matrix1 = EnterMatrix(rows1, columns1);

	Matrix2 = (double*)malloc(rows2 * columns2 * sizeof(double));
	cout << "Введите  вторую матрицу:" << endl;
	Matrix2 = EnterMatrix(rows2, columns2);


	cout << "Введенные матрицы: " << endl << "Первая: " << endl;
	for (int i = 0; i < rows1; i++) {
		for (int j = 0; j < columns1; j++) {
			cout << *(Matrix1 + i * columns1 + j) << "\t ";
		}
		cout << endl;
	}
	cout << endl << "Вторая: " << endl;
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

	cout << "Матрица произведения" << endl;
	for (int i = 0; i < rows1; i++) {
		for (int j = 0; j < columns2; j++)
			cout << *(Matrix3 + i * columns2 + j) << "\t ";
		cout << endl;
	}
}


void MultiplicationMatrixByANumber() {
	int rows, columns, number;
	double* Matrix1;

	rows = EnterRows();
	columns = EnterColumns();

	Matrix1 = (double*)malloc(rows * columns * sizeof(double));
	cout << "Введите матрицу:" << endl;
	Matrix1 = EnterMatrix(rows, columns);

	cout << "Введенная матрица:" << endl;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			cout << *(Matrix1 + i * columns + j) << "\t ";
		}
		cout << endl;
	}
	cout << endl;
	cout << "Введите число, на которое хотите умножить матрицу" << endl;
	number = ChekOnInt();
	cout << "При умножении матрицы на число получаем: " << endl;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			*(Matrix1 + i * columns + j) = *(Matrix1 + i * columns + j) * number;
			cout << *(Matrix1 + i * columns + j) << "\t ";
		}
		cout << endl;
	}
}


void AdditionMatrixAndNumber(int k) {

	int rows, columns, number;
	double* Matrix1;

	rows = EnterRows();
	columns = rows;
	cout << "Для данного случая количесnво строк равно количеству столбцов (" << rows << ")" << endl;

	Matrix1 = (double*)malloc(rows * columns * sizeof(double));
	cout << "Введите матрицу:" << endl;
	Matrix1 = EnterMatrix(rows, columns);

	cout << "Введенная матрица:" << endl;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			cout << *(Matrix1 + i * columns + j) << "\t ";
		}
		cout << endl;
	}
	cout << endl;
	if (k == 0) {
		cout << "Введите число, которое хотите прибавить к матрице " << endl;
		number = ChekOnInt();
		for (int i = 0; i < rows; i++) {
			*(Matrix1 + i * columns + i) = *(Matrix1 + i * columns + i) + number;
		}
		cout << "При прибавлении числа к матрице получаем: " << endl;
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				cout << *(Matrix1 + i * columns + j) << "\t ";
			}
			cout << endl;
		}
	}
	else {

		cout << "Введите число, которое хотите вычести из матрицы " << endl;
		number = ChekOnInt();
		for (int i = 0; i < rows; i++) {
			*(Matrix1 + i * columns + i) = *(Matrix1 + i * columns + i) - number;
		}
		cout << "При вычитании числа из матрицы получаем: " << endl;
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				cout << *(Matrix1 + i * columns + j) << "\t ";
			}
			cout << endl;
		}




	}



}


void TransposeMatrix() {

	int rows, columns;
	double* Matrix1, tmp;

	rows = EnterRows();
	columns = EnterColumns();

	Matrix1 = (double*)malloc(rows * columns * sizeof(double));
	cout << "Введите матрицу:" << endl;
	Matrix1 = EnterMatrix(rows, columns);

	cout << "Введенная матрица:" << endl;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			cout << *(Matrix1 + i * columns + j) << "\t ";
		}
		cout << endl;
	}
	cout << endl;


	for (int i = 0; i < 5; ++i)
	{
		for (int j = i; j < 5; ++j)
		{
			tmp = *(Matrix1 + i * columns + j);
			*(Matrix1 + i * columns + j) = *(Matrix1 + j * columns + i);
			*(Matrix1 + i * columns + j) = tmp;
		}
	}



	cout << "Транспонированная матрица:" << endl;
	for (int i = 0; i < columns; i++) {
		for (int j = 0; j < rows; j++) {
			cout << *(Matrix1 + i * rows + j) << "\t ";
		}
		cout << endl;
	}
	cout << endl;



}



void InverseMatrix() {


}



// НЕ ГОТОВО
double matrixDet(double* matrix, int size) {
	double det = 0;
	int degree = 1;

	if (size == 0) {
		size = EnterRows();
		cout << "Для данного случая количество строк равно количеству столбцов (" << size << ")" << endl;

		matrix = (double*)malloc(size * size * sizeof(double));
		cout << "Введите матрицу:" << endl;
		matrix = EnterMatrix(size, size);

		cout << "Введенная матрица:" << endl;
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				cout << *(matrix + i * size + j) << "\t ";
			}
			cout << endl;
		}
		cout << endl;

	}

	if (size == 1) {
		det = det + *(matrix + 0 * size + 0);
	}
	else if (size == 2) {
		det = det + *(matrix + 0 * size + 0) * *(matrix + 1 * size + 1) - *(matrix + 0 * size + 1) * *(matrix + 1 * size + 0);
	}
	else {
		int newSize = size - 1;
		double* newMatrix = (double*)malloc((newSize) * (newSize) * sizeof(double));
		for (int j = 0; j < size; j++) {


			int offsetCol = 0;
			for (int i = 0; i < size - 1; i++) {
				offsetCol = 0;
				for (int jj = 0; jj < size - 1; jj++) {
					if (jj == j) {
						offsetCol = 1;
					}
					*(newMatrix + i * size + jj) = *(matrix + (i + 1) * size + (jj + offsetCol));
				}
			}

			det = det + (degree * *(matrix + j)) /*matrixDet(newMatrix, newSize)*/;
			//cout << *(matrix + 0 * size + 0) * *(matrix + 1 * size + 1) - *(matrix + 0 * size + 1) * *(matrix + 1 * size + 0)
			cout << *(newMatrix + 0 * size + 0) * *(newMatrix + 1 * size + 1) - *(newMatrix + 0 * size + 1) * *(newMatrix + 1 * size + 0);
			degree *= -1;



		}
		cout << det << endl;
	}

	return det;
}


void Matrix(int taskNumber) {
	switch (taskNumber) {
	case 0: AdditionOfMatrix(0); break;				//Сложение матриц+
	case 1: AdditionOfMatrix(1); break;				//Вычитание матриц+
	case 2:	MultiplicationMatrix(); break;			//Умножение матриц+
	case 3: MultiplicationMatrixByANumber(); break;	//Умножение матрицы на число+
	case 4: AdditionMatrixAndNumber(0); break;		//Сложение матрицы и числа+
	case 5: AdditionMatrixAndNumber(1); break;		//Вычитание из матрицы числа+
	case 6:	TransposeMatrix(); break;				//Транспонирование матрицы + 
	case 7:				break;							//Обратная матрица
	case 8: matrixDet(0, 0); break;						//Определитель
	default: break;
	}
}