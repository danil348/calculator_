#include <iostream>
#include <locale>
#include <conio.h>
#include <Windows.h>
#include "polynomial.h"
using namespace std;


//сложение многочленов
void AdditionOfPolynomials() {
	int polyn_a[2], polyn_b[2], polyn_n[2], polyn_c[2];
	cout << "Многочлен вида: ax^2+bx+c\n" << "Введите коэфиценты и степень для первого многочлена\n";
	cout << "a = "; cin >> polyn_a[0]; cout << "b = "; cin >> polyn_b[0]; cout << "n = "; cin >> polyn_n[0], cout << "c = "; cin >> polyn_c[0];
	cout << "Введите коэфиценты и степень для второго многочлена\n";
	cout << "a = "; cin >> polyn_a[1]; cout << "b = "; cin >> polyn_b[1]; cout << "n = "; cin >> polyn_n[1], cout << "c = "; cin >> polyn_c[1];
	if (polyn_n[0] == polyn_n[1]) {
		if(polyn_a[0] + polyn_a[1] != 0)
			printf_s("%dx^(%d)", polyn_a[0] + polyn_a[1], polyn_n[0]);
		if (polyn_b[0] + polyn_b[1] != 0) {
			if (polyn_b[0] + polyn_b[1] > 0)
				printf_s("+%dx", polyn_b[0] + polyn_b[1]);
			else {
				printf_s("%dx", polyn_b[0] + polyn_b[1]);
			}
		}
		if (polyn_c[0] + polyn_c[1] != 0) {
			if (polyn_c[0] + polyn_c[1])
				printf_s("+%d", polyn_c[0] + polyn_c[1]);
			else
				printf_s("%d\n", polyn_c[0] + polyn_c[1]);
		}
	}
	else {
		if(polyn_a[0] != 0)
			printf_s("%dx^(%d)", polyn_a[0], polyn_n[0]);
		if (polyn_a[1] != 0) {
			if (polyn_a[1] > 0)
				printf_s(" + %dx^(%d)", polyn_a[1], polyn_n[1]);
			else
				printf_s(" - %dx^(%d)", polyn_a[1], polyn_n[1]);
		}
		if (polyn_b[0] + polyn_b[1] != 0) {
			if (polyn_b[0] + polyn_b[1] > 0)
				printf_s("+%dx", polyn_b[0] + polyn_b[1]);
			else {
				printf_s("%dx", polyn_b[0] + polyn_b[1]);
			}
		}
		if (polyn_c[0] + polyn_c[1] != 0) {
			if (polyn_c[0] + polyn_c[1] > 0)
				printf_s("+%d", polyn_c[0] + polyn_c[1]);
			else
				printf_s("%d\n", polyn_c[0] + polyn_c[1]);
		}
	}
}

//вычитание многочленов
void PolynomialSubtraction() {

}

//Умножение многочленов
void PolynomialMultiplication() {
	
}

//Умножение многочлена на число
void MultiplicationByNumber() {

}

//Производная от многочлена
void DerivativeOfaPolynomial() {

}

void Polynomial(int taskNumber) {
	switch (taskNumber) {
	case 0: AdditionOfPolynomials(); break;
	case 1: PolynomialSubtraction(); break;
	case 2: PolynomialMultiplication(); break;
	case 3: MultiplicationByNumber(); break;
	case 4: DerivativeOfaPolynomial(); break;
	default: break;
	}
}

//основная функция называть так как файл
//int Polynomial() {
//	setlocale(0, "");
//	int prov = 0, a = 0;
//	do {
//		switch (a)
//		{
//		case 0:
//			AdditionOfPolynomials();
//			a = -1;
//			break;
//		case 1:
//			PolynomialSubtraction();
//			break;
//		case 2:
//			PolynomialMultiplication();
//			break;
//		case 3:
//			MultiplicationByNumber();
//			break;
//		case 4:
//			DerivativeOfaPolynomial();
//			break;
//		}
//	} while (prov == 0);
//
//	return 0;
//}