#include "Fructions_calculator.h"
#include "ChekOnRightOfNumber.h"

using namespace std;

struct Fraction
{
	int numerator, denominator;//���������, �����������
};

void AdditionOfFractions() { //�������� ������
	Fraction fraction[3];
	cout << "������ �����\n���������:";
	fraction[0].numerator = ChekOnInt();
	cout << "�����������:";
	do {
		fraction[0].denominator = ChekOnInt();
		if (fraction[0].denominator == 0) {
			cout << "������ �� ���� ������! ��������� �������: ";
		}
	} while (fraction[0].denominator == 0);

	cout << "������ �����\n���������:";
	fraction[1].numerator = ChekOnInt();
	cout << "�����������:";
	do {
		fraction[1].denominator = ChekOnInt();
		if (fraction[1].denominator == 0) {
			cout << "������ �� ���� ������! ��������� �������: ";
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
	if (fraction[0].numerator < 0) { //��������� ������ �����
		cout << "(" << fraction[0].numerator << ") / ";
	}
	else {
		cout << fraction[0].numerator << " / ";
	}

	if (fraction[0].denominator < 0) { //����������� ������ �����
		cout << "(" << fraction[0].denominator << ") + ";
	}
	else {
		cout << fraction[0].denominator << " + ";
	}

	if (fraction[1].numerator < 0) { //��������� ������ �����
		cout << "(" << fraction[1].numerator << ") / ";
	}
	else {
		cout << fraction[1].numerator << " / ";
	}

	if (fraction[1].denominator < 0) { //����������� ������ �����
		cout << "(" << fraction[1].denominator << ") = ";
	}
	else {
		cout << fraction[1].denominator << " = ";
	}

	if (fraction[2].numerator < 0) { //��������� �������� �����
		cout << "(" << fraction[2].numerator << ") / ";
	}
	else {
		cout << fraction[2].numerator << " / ";
	}

	if (fraction[2].denominator < 0) { //����������� ������� �����
		cout << "(" << fraction[2].denominator << ")";
	}
	else {
		cout << fraction[2].denominator;
	}
}

void SubtractionOfFractions() { //��������� ������
	Fraction fraction[3];
	cout << "������ �����\n���������:";
	fraction[0].numerator = ChekOnInt();
	cout << "�����������:";
	do {
		fraction[0].denominator = ChekOnInt();
		if (fraction[0].denominator == 0) {
			cout << "������ �� ���� ������! ��������� �������: ";
		}
	} while (fraction[0].denominator == 0);

	cout << "������ �����\n���������:";
	fraction[1].numerator = ChekOnInt();
	cout << "�����������:";
	do {
		fraction[1].denominator = ChekOnInt();
		if (fraction[1].denominator == 0) {
			cout << "������ �� ���� ������! ��������� �������: ";
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
	if (fraction[0].numerator < 0) { //��������� ������ �����
		cout << "(" << fraction[0].numerator << ") / ";
	}
	else {
		cout << fraction[0].numerator << " / ";
	}

	if (fraction[0].denominator < 0) { //����������� ������ �����
		cout << "(" << fraction[0].denominator << ") - ";
	}
	else {
		cout << fraction[0].denominator << " - ";
	}

	if (fraction[1].numerator < 0) { //��������� ������ �����
		cout << "(" << fraction[1].numerator << ") / ";
	}
	else {
		cout << fraction[1].numerator << " / ";
	}

	if (fraction[1].denominator < 0) { //����������� ������ �����
		cout << "(" << fraction[1].denominator << ") = ";
	}
	else {
		cout << fraction[1].denominator << " = ";
	}

	if (fraction[2].numerator < 0) { //��������� �������� �����
		cout << "(" << fraction[2].numerator << ") / ";
	}
	else {
		cout << fraction[2].numerator << " / ";
	}

	if (fraction[2].denominator < 0) { //����������� ������� �����
		cout << "(" << fraction[2].denominator << ")";
	}
	else {
		cout << fraction[2].denominator;
	}
}

void MultiplicationOfFractions() { //��������� ������
	Fraction fraction[3];
	cout << "������ �����\n���������:";
	fraction[0].numerator = ChekOnInt();
	cout << "�����������:";
	do {
		fraction[0].denominator = ChekOnInt();
		if (fraction[0].denominator == 0) {
			cout << "������ �� ���� ������! ��������� �������: ";
		}
	} while (fraction[0].denominator == 0);

	cout << "������ �����\n���������:";
	fraction[1].numerator = ChekOnInt();
	cout << "�����������:";
	do {
		fraction[1].denominator = ChekOnInt();
		if (fraction[1].denominator == 0) {
			cout << "������ �� ���� ������! ��������� �������: ";
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
	if (fraction[0].numerator < 0) { //��������� ������ �����
		cout << "(" << fraction[0].numerator << ") / ";
	}
	else {
		cout << fraction[0].numerator << " / ";
	}

	if (fraction[0].denominator < 0) { //����������� ������ �����
		cout << "(" << fraction[0].denominator << ") * ";
	}
	else {
		cout << fraction[0].denominator << " * ";
	}

	if (fraction[1].numerator < 0) { //��������� ������ �����
		cout << "(" << fraction[1].numerator << ") / ";
	}
	else {
		cout << fraction[1].numerator << " / ";
	}

	if (fraction[1].denominator < 0) { //����������� ������ �����
		cout << "(" << fraction[1].denominator << ") = ";
	}
	else {
		cout << fraction[1].denominator << " = ";
	}

	if (fraction[2].numerator < 0) { //��������� �������� �����
		cout << "(" << fraction[2].numerator << ") / ";
	}
	else {
		cout << fraction[2].numerator << " / ";
	}

	if (fraction[2].denominator < 0) { //����������� ������� �����
		cout << "(" << fraction[2].denominator << ")";
	}
	else {
		cout << fraction[2].denominator;
	}
}

void DivisionOfFractions() { //������� ������
	Fraction fraction[3];
	do {
		cout << "������ �����\n���������:";
		fraction[0].numerator = ChekOnInt();
		cout << "�����������:";
		do {
			fraction[0].denominator = ChekOnInt();
			if (fraction[0].denominator == 0) {
				cout << "������ �� ���� ������! ��������� �������: ";
			}
		} while (fraction[0].denominator == 0);

		cout << "������ �����\n���������:";
		fraction[1].numerator = ChekOnInt();
		cout << "�����������:";
		do {
			fraction[1].denominator = ChekOnInt();
			if (fraction[1].denominator == 0) {
				cout << "������ �� ���� ������! ��������� �������: ";
			}
		} while (fraction[1].denominator == 0);

		fraction[2].numerator = fraction[0].numerator * fraction[1].denominator;
		fraction[2].denominator = fraction[0].denominator * fraction[1].numerator;
		if (fraction[2].denominator == 0) {
			cout << "������ �� ���� ������! ��������� �������";
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
	if (fraction[0].numerator < 0) { //��������� ������ �����
		cout << "(" << fraction[0].numerator << ") / ";
	}
	else {
		cout << fraction[0].numerator << " / ";
	}

	if (fraction[0].denominator < 0) { //����������� ������ �����
		cout << "(" << fraction[0].denominator << ") : ";
	}
	else {
		cout << fraction[0].denominator << " : ";
	}

	if (fraction[1].numerator < 0) { //��������� ������ �����
		cout << "(" << fraction[1].numerator << ") / ";
	}
	else {
		cout << fraction[1].numerator << " / ";
	}

	if (fraction[1].denominator < 0) { //����������� ������ �����
		cout << "(" << fraction[1].denominator << ") = ";
	}
	else {
		cout << fraction[1].denominator << " = ";
	}

	if (fraction[2].numerator < 0) { //��������� �������� �����
		cout << "(" << fraction[2].numerator << ") / ";
	}
	else {
		cout << fraction[2].numerator << " / ";
	}

	if (fraction[2].denominator < 0) { //����������� ������� �����
		cout << "(" << fraction[2].denominator << ")";
	}
	else {
		cout << fraction[2].denominator;
	}
}

void ComparisonOfFractions() { //��������� ������
	Fraction fraction[3];
	cout << "������ �����\n���������:";
	fraction[0].numerator = ChekOnInt();
	cout << "�����������:";
	do {
		fraction[0].denominator = ChekOnInt();
		if (fraction[0].denominator == 0) {
			cout << "������ �� ���� ������! ��������� �������: ";
		}
	} while (fraction[0].denominator == 0);

	cout << "������ �����\n���������:";
	fraction[1].numerator = ChekOnInt();
	cout << "�����������:";
	do {
		fraction[1].denominator = ChekOnInt();
		if (fraction[1].denominator == 0) {
			cout << "������ �� ���� ������! ��������� �������: ";
		}
	} while (fraction[1].denominator == 0);
	
	if (fraction[0].numerator < 0 && fraction[0].denominator < 0) { //���� ���� � ���� ������������, �� ����� ������������
		fraction[0].numerator *= -1;
		fraction[0].denominator *= -1;
	}
	if (fraction[1].numerator < 0 && fraction[1].denominator < 0) { //���� ���� � ���� ������������, �� ����� ������������
		fraction[1].numerator *= -1;
		fraction[1].denominator *= -1;
	}

	if (fraction[0].numerator < 0) { //��������� ������ �����
		cout << "(" << fraction[0].numerator << ") / ";
	}
	else {
		cout << fraction[0].numerator << " / ";
	}

	if (fraction[0].denominator < 0) { //����������� ������ �����
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


	if (fraction[1].numerator < 0) { //��������� ������ �����
		cout << "(" << fraction[1].numerator << ") / ";
	}
	else {
		cout << fraction[1].numerator << " / ";
	}

	if (fraction[1].denominator < 0) { //����������� ������ �����
		cout << "(" << fraction[1].denominator << ")";
	}
	else {
		cout << fraction[1].denominator;
	}
}

void ReductionOfFractions() { //���������� ������
	Fraction fraction[3];
	cout << "�����\n���������:";
	fraction[2].numerator = ChekOnInt();
	cout << "�����������:";
	do {
		fraction[2].denominator = ChekOnInt();
		if (fraction[2].denominator == 0) {
			cout << "������ �� ���� ������! ��������� �������: ";
		}
	} while (fraction[2].denominator == 0);

	if (fraction[2].numerator < 0) { //���������
		cout << "(" << fraction[2].numerator << ") / ";
	}
	else {
		cout << fraction[2].numerator << " / ";
	}

	if (fraction[2].denominator < 0) { //�����������
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


	if (fraction[2].numerator < 0) { //���������
		cout << "(" << fraction[2].numerator << ") / ";
	}
	else {
		cout << fraction[2].numerator << " / ";
	}

	if (fraction[2].denominator < 0) { //�����������
		cout << "(" << fraction[2].denominator << ")";
	}
	else {
		cout << fraction[2].denominator;
	}
}

void PerfomanceAtTen() { //������������� � ���������� ����
	Fraction fraction[3];
	cout << "�����\n���������:";
	fraction[2].numerator = ChekOnInt();
	cout << "�����������:";
	do {
		fraction[2].denominator = ChekOnInt();
		if (fraction[2].denominator == 0) {
			cout << "������ �� ���� ������! ��������� �������: ";
		}
	} while (fraction[2].denominator == 0);

	if (fraction[2].numerator < 0) { //���������
		cout << "(" << fraction[2].numerator << ") / ";
	}
	else {
		cout << fraction[2].numerator << " / ";
	}

	if (fraction[2].denominator < 0) { //�����������
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
	case 0: AdditionOfFractions(); break; //�������� ������
	case 1: SubtractionOfFractions();  break; //��������� ������
	case 2: MultiplicationOfFractions(); break; //��������� ������
	case 3: DivisionOfFractions(); break; //������� ������
	case 4: ComparisonOfFractions(); break; //��������� ������
	case 5: ReductionOfFractions(); break; //���������� ������
	case 6: PerfomanceAtTen(); break; //������������ � 10-���� ����
	default: break;
	}
}