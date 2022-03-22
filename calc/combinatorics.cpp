#include "combinatorics.h"

void PlacementRepeat() {

	int total = 1;
	do {
		if (total < 1) cout << "Ошибка! Общее количество элементов должно быть больше 0." << endl;
		cout << "Общее количество элементов: ";
		total = ChekOnInt();
	} while (total < 1);

	int picked = 1;
	do {
		if (picked < 1) cout << "Ошибка! Количество выбираемых элементов должно быть больше 0." << endl;
		cout << "Количество выбираемых элементов: ";
		picked = ChekOnInt();
	} while (picked < 1);

	double result = 1;

	// Формула: result = total^picked

	result = pow(total, picked);

	cout << "Ответ: " << result;
}

void PlacementNoRepeat() {

	int total = 1, picked = 1;

	do {
		if (picked > total) cout << "Ошибка! Количество выбираемых элементов не может быть больше общего количества элементов. Повторите ввод." << endl;

		total = 1;
		do {
			if (total < 1) cout << "Ошибка! Общее количество элементов должно быть больше 0." << endl;
			cout << "Общее количество элементов: ";
			total = ChekOnInt();
		} while (total < 1);

		picked = 1;
		do {
			if (picked < 1) cout << "Ошибка! Количество выбираемых элементов должно быть больше 0." << endl;
			cout << "Количество выбираемых элементов: ";
			picked = ChekOnInt();
		} while (picked < 1);
	} while (picked > total);

	double result = 1;

	// Формула: result = total! / (total-picked)!

	for (int i = 1; i <= total; i++) {
		result *= i;
		if (i <= total - picked) result /= i;	
	}

	cout << "Ответ: " << result;
}

void CombinationRepeat() {

	int total = 1;
	do {
		if (total < 1) cout << "Ошибка! Общее количество элементов должно быть больше 0." << endl;
		cout << "Общее количество элементов: ";
		total = ChekOnInt();
	} while (total < 1);

	int picked = 1;
	do {
		if (picked < 1) cout << "Ошибка! Количество выбираемых элементов должно быть больше 0." << endl;
		cout << "Количество выбираемых элементов: ";
		picked = ChekOnInt();
	} while (picked < 1);

	double result = 1;

	// Формула: result = (total+picked-1)! / (picked! * (total-1)!)

	for (int i = 1; i <= total + picked - 1; i++) {
		result *= i;
		if (i <= picked) result /= i;
		if (i <= total - 1) result /= i;
	}

	cout << "Ответ: " << result;
}

void CombinationNoRepeat() {

	int total = 1, picked = 1;

	do {
		if (picked > total) cout << "Ошибка! Количество выбираемых элементов не может быть больше общего количества элементов. Повторите ввод." << endl;

		total = 1;
		do {
			if (total < 1) cout << "Ошибка! Общее количество элементов должно быть больше 0." << endl;
			cout << "Общее количество элементов: ";
			total = ChekOnInt();
		} while (total < 1);

		picked = 1;
		do {
			if (picked < 1) cout << "Ошибка! Количество выбираемых элементов должно быть больше 0." << endl;
			cout << "Количество выбираемых элементов: ";
			picked = ChekOnInt();
		} while (picked < 1);
	} while (picked > total);

	double result = 1;

	// Формула: result = total! / (picked! * (total-picked)!)

	for (int i = 1; i <= total; i++) {
		result *= i;
		if (i <= picked) result /= i;
		if (i <= total - picked) result /= i;
	}

	cout << "Ответ: " << result;
}

void Transposition() {

	int total = 1;
	do {
		if (total < 1) cout << "Ошибка! Общее количество элементов должно быть больше 0." << endl;
		cout << "Общее количество элементов: ";
		total = ChekOnInt();
	} while (total < 1);

	double result = 1;

	// Формула: result = total!

	for (int i = 1; i <= total; i++) {
		result *= i;
	}

	cout << "Ответ: " << result;
}

void combinatorics(int taskNumber) {
	switch (taskNumber) {
	case 0: PlacementRepeat(); break;
	case 1: PlacementNoRepeat(); break;
	case 2: CombinationRepeat(); break;
	case 3: CombinationNoRepeat(); break;
	case 4: Transposition(); break;
	default: break;
	}
}