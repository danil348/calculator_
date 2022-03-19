#include "ChekOnRightOfNumber.h"

int ChekOnInt() {
	int coi;
	while (true) {
		if (scanf_s("%d", &coi) == false || getchar() != '\n') {
			while (getchar() != '\n');
			cout << "Неверный ввод, повторите попытку: ";
		}
		else {
			return coi;
		}
	}
}

double ChekOnDouble() {
	double cod;
	while (true) {
		if (scanf_s("%lf", &cod) == false || getchar() != '\n') {
			while (getchar() != '\n');
			cout << "Неврный ввод, повторите попытку: ";
		}
		else {
			return cod;
		}
	}
}