#include "Theory.h"
#include "ChekOnRightOfNumber.h"

struct MathXP
{
	double p;
	int x;
};

void Probability() {
	int m, n;
	cout << "����������� ������ �� P(A) = m/n\n������� ����� ���������� ��������� �������:";
	do {
		n = ChekOnInt();
		if (n < 0) {
			cout << "���������� ��������� ������� �� ����� ���� ������ ����! ��������� �������: ";
		}
		else if (n == 0) {
			cout << "���������� ��������� ������� �� ����� ���� ����� ����! ��������� �������: ";
		}
	} while (n <= 0);
	cout << "������� ����� ���������� ������������� �������:";
	do {
		m = ChekOnInt();
		if (m > n) {
			cout << "���������� ������������� ������� �� ����� ���� ������ ���������� ��������� �������! ��������� �������: ";
		}
		else if (m == 0) {
			cout << "���������� ������������� ������� �� ����� ���� ����� ����! ��������� �������: ";
		}
		else if (m < 0) {
			cout << "���������� ������������� ������� �� ����� ���� �������������! ��������� �������: ";
		}
	} while (m <= 0 || m > n);
	
	cout << "����������� P(A) = m/n �����: " << double(m) / n;
}

double MathExpectation(MathXP* mathemExpDis, int &count) { //������ ��������������� ��������(����� ��� 2-�� �������)
	double MathExpectSum = 0;
	for (int i = 0; i < count; i++) {
		MathExpectSum += mathemExpDis[i].x * mathemExpDis[i].p;
	}
	return MathExpectSum;
}

void Dispersion() {
	MathXP mathemExpDis[100];
	int count;
	cout << "���������\n������� ���������� �������� ��������� �������� (�� ����� 100): ";
	do {
		count = ChekOnInt();
		if (count < 0) cout << "���������� �������� �� ����� ���� �������������! ��������� �������: ";
		if (count == 0) cout << "���������� �������� �� ����� ���� ������ ����! ��������� �������: ";
		if (count > 100) cout << "���������� �������� �� ����� ���� ������ ���! ��������� �������: ";
	} while (count <= 0);
	for (int i = 0; i < count; i++) {
		cout << "�������� �" << i + 1 << "\n�������� �������� X" << i + 1 << " = ";
		mathemExpDis[i].x = ChekOnInt();
		cout << "����������� �������� P" << i + 1 << " = ";
		do {
			mathemExpDis[i].p = ChekOnDouble();
			if (mathemExpDis[i].p < 0) cout << "����������� �� ����� ���� �������������! ��������� �������: ";
			if (mathemExpDis[i].p > 1) cout << "����������� �� ����� ���� ������ �������! ��������� �������: ";
		} while (mathemExpDis[i].p < 0 || mathemExpDis[i].p > 1);
	}
	double dispersion = 0, expectation = MathExpectation(mathemExpDis, count); //������ ���������� ��� "-(��� ��������)^2"
	for (int i = 0; i < count; i++) {
		dispersion += (mathemExpDis[i].x * mathemExpDis[i].x) * mathemExpDis[i].p;
	}
	dispersion -= expectation * expectation;
	cout << "��������� �����: " << dispersion;
}

void MathematicalExpectation() {
	MathXP mathemExpDis[100];
	int count;
	cout << "�������������� ��������\n������� ���������� �������� ��������� �������� (�� ����� 100): ";
	do {
		count = ChekOnInt();
		if (count < 0) cout << "���������� �������� �� ����� ���� �������������! ��������� �������: ";
		if (count == 0) cout << "���������� �������� �� ����� ���� ������ ����! ��������� �������: ";
		if (count > 100) cout << "���������� �������� �� ����� ���� ������ ���! ��������� �������: ";
	} while (count <= 0);
	for (int i = 0; i < count; i++) {
		cout << "�������� �" << i + 1 << "\n�������� �������� X" << i + 1 << " = ";
		mathemExpDis[i].x = ChekOnInt();
		cout << "����������� �������� P" << i + 1 << " = ";
		do {
			mathemExpDis[i].p = ChekOnDouble();
			if (mathemExpDis[i].p < 0) cout << "����������� �� ����� ���� �������������! ��������� �������: ";
			if (mathemExpDis[i].p > 1) cout << "����������� �� ����� ���� ������ �������! ��������� �������: ";
		} while (mathemExpDis[i].p < 0 || mathemExpDis[i].p > 1);
	}
	cout << "�������������� �������� �����: " << MathExpectation(mathemExpDis, count);
}

void Theory(int task) {
	switch (task) {
	case 0:Probability(); break; //�����������
	case 1:Dispersion(); break; //���������
	case 2:MathematicalExpectation(); break; //�����������
	default: break;
	}
}