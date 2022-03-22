#include "Theory.h"
#include "ChekOnRightOfNumber.h"

struct MathXP
{
	double p;
	int x;
};

void Probability() {
	int m, n;
	cout << "Вероятность исхода по P(A) = m/n\nВведите общее количество вероятных исходов:";
	do {
		n = ChekOnInt();
		if (n < 0) {
			cout << "Количество вероятных исходов не может быть меньше нуля! повторите попытку: ";
		}
		else if (n == 0) {
			cout << "Количество вероятных исходов не может быть равно ноль! Повторите попытку: ";
		}
	} while (n <= 0);
	cout << "Введите общее количество благоприятных исходов:";
	do {
		m = ChekOnInt();
		if (m > n) {
			cout << "Количество благоприятных исходов не может быть больше количества вероятных исходов! Повторите попытку: ";
		}
		else if (m == 0) {
			cout << "Количество благоприятных исходов не может быть равно ноль! Повторите попытку: ";
		}
		else if (m < 0) {
			cout << "Количество благоприятных исходов не может быть отрицательным! Повторите попытку: ";
		}
	} while (m <= 0 || m > n);
	
	cout << "Вероятность P(A) = m/n равна: " << double(m) / n;
}

double MathExpectation(MathXP* mathemExpDis, int &count) { //Расчёт математического ожидания(нужно для 2-ух функций)
	double MathExpectSum = 0;
	for (int i = 0; i < count; i++) {
		MathExpectSum += mathemExpDis[i].x * mathemExpDis[i].p;
	}
	return MathExpectSum;
}

void Dispersion() {
	MathXP mathemExpDis[100];
	int count;
	cout << "Дисперсия\nУкажите количество значений случайной величины (не более 100): ";
	do {
		count = ChekOnInt();
		if (count < 0) cout << "Количество значений не может быть отрицательным! Повторите попытку: ";
		if (count == 0) cout << "Количество значений не может быть равным нулю! Повторите попытку: ";
		if (count > 100) cout << "Количество значений не может быть больше ста! Повторите попытку: ";
	} while (count <= 0);
	for (int i = 0; i < count; i++) {
		cout << "Значение №" << i + 1 << "\nЗанчение величины X" << i + 1 << " = ";
		mathemExpDis[i].x = ChekOnInt();
		cout << "Вероятность величины P" << i + 1 << " = ";
		do {
			mathemExpDis[i].p = ChekOnDouble();
			if (mathemExpDis[i].p < 0) cout << "Вероятность не может быть отрицательной! Повторите попытку: ";
			if (mathemExpDis[i].p > 1) cout << "Вероятность не может быть больше единицы! Повторите попытку: ";
		} while (mathemExpDis[i].p < 0 || mathemExpDis[i].p > 1);
	}
	double dispersion = 0, expectation = MathExpectation(mathemExpDis, count); //расчёт дисперсиии без "-(мат ожидания)^2"
	for (int i = 0; i < count; i++) {
		dispersion += (mathemExpDis[i].x * mathemExpDis[i].x) * mathemExpDis[i].p;
	}
	dispersion -= expectation * expectation;
	cout << "Дисперсия равна: " << dispersion;
}

void MathematicalExpectation() {
	MathXP mathemExpDis[100];
	int count;
	cout << "Матиматическое ожидание\nУкажите количество значений случайной величины (не более 100): ";
	do {
		count = ChekOnInt();
		if (count < 0) cout << "Количество значений не может быть отрицательным! Повторите попытку: ";
		if (count == 0) cout << "Количество значений не может быть равным нулю! Повторите попытку: ";
		if (count > 100) cout << "Количество значений не может быть больше ста! Повторите попытку: ";
	} while (count <= 0);
	for (int i = 0; i < count; i++) {
		cout << "Значение №" << i + 1 << "\nЗанчение величины X" << i + 1 << " = ";
		mathemExpDis[i].x = ChekOnInt();
		cout << "Вероятность величины P" << i + 1 << " = ";
		do {
			mathemExpDis[i].p = ChekOnDouble();
			if (mathemExpDis[i].p < 0) cout << "Вероятность не может быть отрицательной! Повторите попытку: ";
			if (mathemExpDis[i].p > 1) cout << "Вероятность не может быть больше единицы! Повторите попытку: ";
		} while (mathemExpDis[i].p < 0 || mathemExpDis[i].p > 1);
	}
	cout << "Математическое ожидание равно: " << MathExpectation(mathemExpDis, count);
}

void Theory(int task) {
	switch (task) {
	case 0:Probability(); break; //Вероятность
	case 1:Dispersion(); break; //Дисперсия
	case 2:MathematicalExpectation(); break; //Матожидание
	default: break;
	}
}