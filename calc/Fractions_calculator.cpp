#include "Fructions_calculator.h"
#include "ChekOnRightOfNumber.h"

using namespace std;

struct Fraction
{
	int numerator, denominator;//числитель, знаменатель
};

void AdditionOfFractions() { //Сложение дробей
	Fraction fraction[3];
	cout << "Первая дробь\nЧислитель:";
	fraction[0].numerator = ChekOnInt();
	cout << "Знаменатель:";
	do {
		fraction[0].denominator = ChekOnInt();
		if (fraction[0].denominator == 0) {
			cout << "Делить на ноль нельзя! Повторите попытку: ";
		}
	} while (fraction[0].denominator == 0);

	cout << "Вторая дробь\nЧислитель:";
	fraction[1].numerator = ChekOnInt();
	cout << "Знаменатель:";
	do {
		fraction[1].denominator = ChekOnInt();
		if (fraction[1].denominator == 0) {
			cout << "Делить на ноль нельзя! Повторите попытку: ";
		}
	} while (fraction[1].denominator == 0);
	if (fraction[0].denominator != fraction[1].denominator) {
		fraction[2].denominator = fraction[0].denominator * fraction[1].denominator;
		fraction[2].numerator = fraction[0].numerator * fraction[1].denominator + fraction[1].numerator * fraction[0].denominator;
	}
	else {
		fraction[2].denominator = fraction[0].denominator;
		fraction[2].numerator = fraction[0].numerator + fraction[1].numerator;
	}

	if (fraction[2].numerator % fraction[2].denominator == 0) {
		fraction[2].numerator = fraction[2].numerator / fraction[2].denominator;
		fraction[2].denominator = 1;
	}
	else {
		for (int i = 2; i < 11; i++) {
			if (fraction[2].numerator % i == 0 && fraction[2].denominator % i == 0) {
				while (fraction[2].numerator % i == 0 && fraction[2].denominator % i == 0) {
					fraction[2].numerator /= i;
					fraction[2].denominator /= i;
				}
			}
		}
	}
	if (fraction[2].numerator < 0 && fraction[2].denominator < 0) {
		fraction[2].numerator *= -1;
		fraction[2].denominator *= -1;
	}
	if (fraction[0].numerator < 0) { //числитель первой дроби
		cout << "(" << fraction[0].numerator << ") / ";
	}
	else {
		cout << fraction[0].numerator << " / ";
	}

	if (fraction[0].denominator < 0) { //знаменатель первой дроби
		cout << "(" << fraction[0].denominator << ") + ";
	}
	else {
		cout << fraction[0].denominator << " + ";
	}

	if (fraction[1].numerator < 0) { //числитель второй дроби
		cout << "(" << fraction[1].numerator << ") / ";
	}
	else {
		cout << fraction[1].numerator << " / ";
	}

	if (fraction[1].denominator < 0) { //знаменатель второй дроби
		cout << "(" << fraction[1].denominator << ") = ";
	}
	else {
		cout << fraction[1].denominator << " = ";
	}

	if (fraction[2].numerator < 0) { //числитель трейтьей дроби
		cout << "(" << fraction[2].numerator << ") / ";
	}
	else {
		cout << fraction[2].numerator << " / ";
	}

	if (fraction[2].denominator < 0) { //знаменатель третьей дроби
		cout << "(" << fraction[2].denominator << ")";
	}
	else {
		cout << fraction[2].denominator;
	}
}

void SubtractionOfFractions() { //Вычитание дробей
	Fraction fraction[3];
	cout << "Первая дробь\nЧислитель:";
	fraction[0].numerator = ChekOnInt();
	cout << "Знаменатель:";
	do {
		fraction[0].denominator = ChekOnInt();
		if (fraction[0].denominator == 0) {
			cout << "Делить на ноль нельзя! Повторите попытку: ";
		}
	} while (fraction[0].denominator == 0);

	cout << "Вторая дробь\nЧислитель:";
	fraction[1].numerator = ChekOnInt();
	cout << "Знаменатель:";
	do {
		fraction[1].denominator = ChekOnInt();
		if (fraction[1].denominator == 0) {
			cout << "Делить на ноль нельзя! Повторите попытку: ";
		}
	} while (fraction[1].denominator == 0);
	if (fraction[0].denominator != fraction[1].denominator) {
		fraction[2].denominator = fraction[0].denominator * fraction[1].denominator;
		fraction[2].numerator = fraction[0].numerator * fraction[1].denominator - fraction[1].numerator * fraction[0].denominator;
	}
	else {
		fraction[2].denominator = fraction[0].denominator;
		fraction[2].numerator = fraction[0].numerator - fraction[1].numerator;
	}

	if (fraction[2].numerator % fraction[2].denominator == 0) {
		fraction[2].numerator = fraction[2].numerator / fraction[2].denominator;
		fraction[2].denominator = 1;
	}
	else {
		for (int i = 2; i < 11; i++) {
			if (fraction[2].numerator % i == 0 && fraction[2].denominator % i == 0) {
				while (fraction[2].numerator % i == 0 && fraction[2].denominator % i == 0) {
					fraction[2].numerator /= i;
					fraction[2].denominator /= i;
				}
			}
		}
	}
	if (fraction[2].numerator < 0 && fraction[2].denominator < 0) {
		fraction[2].numerator *= -1;
		fraction[2].denominator *= -1;
	}
	if (fraction[0].numerator < 0) { //числитель первой дроби
		cout << "(" << fraction[0].numerator << ") / ";
	}
	else {
		cout << fraction[0].numerator << " / ";
	}

	if (fraction[0].denominator < 0) { //знаменатель первой дроби
		cout << "(" << fraction[0].denominator << ") - ";
	}
	else {
		cout << fraction[0].denominator << " - ";
	}

	if (fraction[1].numerator < 0) { //числитель второй дроби
		cout << "(" << fraction[1].numerator << ") / ";
	}
	else {
		cout << fraction[1].numerator << " / ";
	}

	if (fraction[1].denominator < 0) { //знаменатель второй дроби
		cout << "(" << fraction[1].denominator << ") = ";
	}
	else {
		cout << fraction[1].denominator << " = ";
	}

	if (fraction[2].numerator < 0) { //числитель трейтьей дроби
		cout << "(" << fraction[2].numerator << ") / ";
	}
	else {
		cout << fraction[2].numerator << " / ";
	}

	if (fraction[2].denominator < 0) { //знаменатель третьей дроби
		cout << "(" << fraction[2].denominator << ")";
	}
	else {
		cout << fraction[2].denominator;
	}
}

void MultiplicationOfFractions() { //Умножение дробей
	Fraction fraction[3];
	cout << "Первая дробь\nЧислитель:";
	fraction[0].numerator = ChekOnInt();
	cout << "Знаменатель:";
	do {
		fraction[0].denominator = ChekOnInt();
		if (fraction[0].denominator == 0) {
			cout << "Делить на ноль нельзя! Повторите попытку: ";
		}
	} while (fraction[0].denominator == 0);

	cout << "Вторая дробь\nЧислитель:";
	fraction[1].numerator = ChekOnInt();
	cout << "Знаменатель:";
	do {
		fraction[1].denominator = ChekOnInt();
		if (fraction[1].denominator == 0) {
			cout << "Делить на ноль нельзя! Повторите попытку: ";
		}
	} while (fraction[1].denominator == 0);
	
	fraction[2].numerator = fraction[0].numerator * fraction[1].numerator;
	fraction[2].denominator = fraction[0].denominator * fraction[1].denominator;

	if (fraction[2].numerator % fraction[2].denominator == 0) {
		fraction[2].numerator = fraction[2].numerator / fraction[2].denominator;
		fraction[2].denominator = 1;
	}
	else {
		for (int i = 2; i < 11; i++) {
			if (fraction[2].numerator % i == 0 && fraction[2].denominator % i == 0) {
				while (fraction[2].numerator % i == 0 && fraction[2].denominator % i == 0) {
					fraction[2].numerator /= i;
					fraction[2].denominator /= i;
				}
			}
		}
	}
	if (fraction[2].numerator < 0 && fraction[2].denominator < 0) {
		fraction[2].numerator *= -1;
		fraction[2].denominator *= -1;
	}
	if (fraction[0].numerator < 0) { //числитель первой дроби
		cout << "(" << fraction[0].numerator << ") / ";
	}
	else {
		cout << fraction[0].numerator << " / ";
	}

	if (fraction[0].denominator < 0) { //знаменатель первой дроби
		cout << "(" << fraction[0].denominator << ") * ";
	}
	else {
		cout << fraction[0].denominator << " * ";
	}

	if (fraction[1].numerator < 0) { //числитель второй дроби
		cout << "(" << fraction[1].numerator << ") / ";
	}
	else {
		cout << fraction[1].numerator << " / ";
	}

	if (fraction[1].denominator < 0) { //знаменатель второй дроби
		cout << "(" << fraction[1].denominator << ") = ";
	}
	else {
		cout << fraction[1].denominator << " = ";
	}

	if (fraction[2].numerator < 0) { //числитель трейтьей дроби
		cout << "(" << fraction[2].numerator << ") / ";
	}
	else {
		cout << fraction[2].numerator << " / ";
	}

	if (fraction[2].denominator < 0) { //знаменатель третьей дроби
		cout << "(" << fraction[2].denominator << ")";
	}
	else {
		cout << fraction[2].denominator;
	}
}

void DivisionOfFractions() { //Деление дробей
	Fraction fraction[3];
	do {
		cout << "Первая дробь\nЧислитель:";
		fraction[0].numerator = ChekOnInt();
		cout << "Знаменатель:";
		do {
			fraction[0].denominator = ChekOnInt();
			if (fraction[0].denominator == 0) {
				cout << "Делить на ноль нельзя! Повторите попытку: ";
			}
		} while (fraction[0].denominator == 0);

		cout << "Вторая дробь\nЧислитель:";
		fraction[1].numerator = ChekOnInt();
		cout << "Знаменатель:";
		do {
			fraction[1].denominator = ChekOnInt();
			if (fraction[1].denominator == 0) {
				cout << "Делить на ноль нельзя! Повторите попытку: ";
			}
		} while (fraction[1].denominator == 0);

		fraction[2].numerator = fraction[0].numerator * fraction[1].denominator;
		fraction[2].denominator = fraction[0].denominator * fraction[1].numerator;
		if (fraction[2].denominator == 0) {
			cout << "Делить на ноль нельзя! Повторите попытку";
		}

	} while (fraction[2].denominator == 0);
	
	if (fraction[2].numerator % fraction[2].denominator == 0) {
		fraction[2].numerator = fraction[2].numerator / fraction[2].denominator;
		fraction[2].denominator = 1;
	}
	else {
		for (int i = 2; i < 11; i++) {
			if (fraction[2].numerator % i == 0 && fraction[2].denominator % i == 0) {
				while (fraction[2].numerator % i == 0 && fraction[2].denominator % i == 0) {
					fraction[2].numerator /= i;
					fraction[2].denominator /= i;
				}
			}
		}
	}
	if (fraction[2].numerator < 0 && fraction[2].denominator < 0) {
		fraction[2].numerator *= -1;
		fraction[2].denominator *= -1;
	}
	if (fraction[0].numerator < 0) { //числитель первой дроби
		cout << "(" << fraction[0].numerator << ") / ";
	}
	else {
		cout << fraction[0].numerator << " / ";
	}

	if (fraction[0].denominator < 0) { //знаменатель первой дроби
		cout << "(" << fraction[0].denominator << ") : ";
	}
	else {
		cout << fraction[0].denominator << " : ";
	}

	if (fraction[1].numerator < 0) { //числитель второй дроби
		cout << "(" << fraction[1].numerator << ") / ";
	}
	else {
		cout << fraction[1].numerator << " / ";
	}

	if (fraction[1].denominator < 0) { //знаменатель второй дроби
		cout << "(" << fraction[1].denominator << ") = ";
	}
	else {
		cout << fraction[1].denominator << " = ";
	}

	if (fraction[2].numerator < 0) { //числитель трейтьей дроби
		cout << "(" << fraction[2].numerator << ") / ";
	}
	else {
		cout << fraction[2].numerator << " / ";
	}

	if (fraction[2].denominator < 0) { //знаменатель третьей дроби
		cout << "(" << fraction[2].denominator << ")";
	}
	else {
		cout << fraction[2].denominator;
	}
}

void ComparisonOfFractions() { //Сравнение дробей
	Fraction fraction[3];
	cout << "Первая дробь\nЧислитель:";
	fraction[0].numerator = ChekOnInt();
	cout << "Знаменатель:";
	do {
		fraction[0].denominator = ChekOnInt();
		if (fraction[0].denominator == 0) {
			cout << "Делить на ноль нельзя! Повторите попытку: ";
		}
	} while (fraction[0].denominator == 0);

	cout << "Вторая дробь\nЧислитель:";
	fraction[1].numerator = ChekOnInt();
	cout << "Знаменатель:";
	do {
		fraction[1].denominator = ChekOnInt();
		if (fraction[1].denominator == 0) {
			cout << "Делить на ноль нельзя! Повторите попытку: ";
		}
	} while (fraction[1].denominator == 0);
	
	if (fraction[0].numerator < 0 && fraction[0].denominator < 0) { //если числ и знам отрицательны, то дробь положительна
		fraction[0].numerator *= -1;
		fraction[0].denominator *= -1;
	}
	if (fraction[1].numerator < 0 && fraction[1].denominator < 0) { //если числ и знам отрицательны, то дробь положительна
		fraction[1].numerator *= -1;
		fraction[1].denominator *= -1;
	}

	if (fraction[0].numerator < 0) { //числитель первой дроби
		cout << "(" << fraction[0].numerator << ") / ";
	}
	else {
		cout << fraction[0].numerator << " / ";
	}

	if (fraction[0].denominator < 0) { //знаменатель первой дроби
		cout << "(" << fraction[0].denominator << ")";
	}
	else {
		cout << fraction[0].denominator;
	}

	double fract1, fract2;
	fract1 = double(fraction[0].numerator) / fraction[0].denominator;
	fract2 = double(fraction[1].numerator) / fraction[1].denominator;

	if (fract1 < fract2) {
		cout << " < ";
	}
	else if (fract1 > fract2) {
		cout << " > ";
	}
	else {
		cout << " = ";
	}


	if (fraction[1].numerator < 0) { //числитель второй дроби
		cout << "(" << fraction[1].numerator << ") / ";
	}
	else {
		cout << fraction[1].numerator << " / ";
	}

	if (fraction[1].denominator < 0) { //знаменатель второй дроби
		cout << "(" << fraction[1].denominator << ")";
	}
	else {
		cout << fraction[1].denominator;
	}
}

void ReductionOfFractions() { //Сокращение дробей
	Fraction fraction[3];
	cout << "Дробь\nЧислитель:";
	fraction[2].numerator = ChekOnInt();
	cout << "Знаменатель:";
	do {
		fraction[2].denominator = ChekOnInt();
		if (fraction[2].denominator == 0) {
			cout << "Делить на ноль нельзя! Повторите попытку: ";
		}
	} while (fraction[2].denominator == 0);

	if (fraction[2].numerator < 0) { //числитель
		cout << "(" << fraction[2].numerator << ") / ";
	}
	else {
		cout << fraction[2].numerator << " / ";
	}

	if (fraction[2].denominator < 0) { //знаменатель
		cout << "(" << fraction[2].denominator << ") = ";
	}
	else {
		cout << fraction[2].denominator << " = ";
	}

	for (int i = 2; i < 11; i++) {
		if (fraction[2].numerator % i == 0 && fraction[2].denominator % i == 0) {
			while (fraction[2].numerator % i == 0 && fraction[2].denominator % i == 0) {
				fraction[2].numerator /= i;
				fraction[2].denominator /= i;
			}
		}
	}
	if (fraction[2].numerator < 0 && fraction[2].denominator < 0) {
		fraction[2].numerator *= -1;
		fraction[2].denominator *= -1;
	}


	if (fraction[2].numerator < 0) { //числитель
		cout << "(" << fraction[2].numerator << ") / ";
	}
	else {
		cout << fraction[2].numerator << " / ";
	}

	if (fraction[2].denominator < 0) { //знаменатель
		cout << "(" << fraction[2].denominator << ")";
	}
	else {
		cout << fraction[2].denominator;
	}
}

void PerfomanceAtTen() { //Представление в десятичном виде
	Fraction fraction[3];
	cout << "Дробь\nЧислитель:";
	fraction[2].numerator = ChekOnInt();
	cout << "Знаменатель:";
	do {
		fraction[2].denominator = ChekOnInt();
		if (fraction[2].denominator == 0) {
			cout << "Делить на ноль нельзя! Повторите попытку: ";
		}
	} while (fraction[2].denominator == 0);

	if (fraction[2].numerator < 0) { //числитель
		cout << "(" << fraction[2].numerator << ") / ";
	}
	else {
		cout << fraction[2].numerator << " / ";
	}

	if (fraction[2].denominator < 0) { //знаменатель
		cout << "(" << fraction[2].denominator << ") = ";
	}
	else {
		cout << fraction[2].denominator << " = ";
	}
	double result_fract = double(fraction[2].numerator) / fraction[2].denominator;
	if (result_fract < 0) {
		cout << "(" << result_fract << ")";
	}
	else {
		cout << result_fract;
	}
}


void FractionCalculator(int task){
	switch (task) {
	case 0: AdditionOfFractions(); break; //Сложение дробей
	case 1: SubtractionOfFractions();  break; //Вычитание дробей
	case 2: MultiplicationOfFractions(); break; //Умножение дробей
	case 3: DivisionOfFractions(); break; //Деление дробей
	case 4: ComparisonOfFractions(); break; //Сравнение дробей
	case 5: ReductionOfFractions(); break; //Сокращение дробей
	case 6: PerfomanceAtTen(); break; //Представлние в 10-чном виде
	default: break;
	}
}