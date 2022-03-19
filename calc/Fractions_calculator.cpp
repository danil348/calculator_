#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "Fructions_calculator.h"
#include "ChekOnRightOfNumber.h"


using namespace std;


struct Fraction
{
	int numerator, denominator;//���������, �����������
};


HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE); //�������� ���������� �������

void MoveCord_X_Y(short x, short y) { //������� ����������� ������� �� ����������� ����������
	SetConsoleCursorPosition(hStdOut, { x,y });
}

void CursorVisible(bool show, short sizecurs) { //������� ��������� ��������� ������� � �������
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(hStdOut, &structCursorInfo);
	structCursorInfo.bVisible = show;//���������
	structCursorInfo.dwSize = sizecurs; //������ �������
	SetConsoleCursorInfo(hStdOut, &structCursorInfo);
}
void SetColor(int text, int background)//������� ������������ ����� ������ � ������� ����
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

void AdditionOfFractions() { //�������� ������
	Fraction fraction[3];
	cout << "�������� ������..." << endl;
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
		for (int i = 1; i < 11; i++) {
			if (fraction[2].numerator % i == 0 && fraction[2].denominator % i == 0) {
	
			}
		}
	}
	cout << fraction[0].numerator << " / " << fraction[0].denominator << " + " << fraction[1].numerator << " / " << fraction[1].denominator << " = " << fraction[2].numerator << " / " << fraction[2].denominator << endl;
	cout << "������� ����� ������� ��� �����������...";
	_getch();
}

void SubtractionOfFractions() { //��������� ������

}

void MultiplicationOfFractions() { //��������� ������

}

void DivisionOfFractions() { //������� ������

}

void ComparisonOfFractions() { //��������� ������

}

void ReductionOfFractions() { //���������� ������

}

void PerfomanceAtTen() { //������������� � ���������� ����

}


void FractionCalculator(int task){
	switch (task)
	{
	case 1: AdditionOfFractions(); break; //�������� ������
	case 2: SubtractionOfFractions();  break; //��������� ������
	case 3: MultiplicationOfFractions(); break; //��������� ������
	case 4: DivisionOfFractions(); system("cls"); break; //������� ������
	case 5: ComparisonOfFractions(); system("cls"); break; //��������� ������
	case 6: ReductionOfFractions(); system("cls"); break; //���������� ������
	case 7: PerfomanceAtTen(); system("cls"); break; //������������ � 10-���� ����
	case 8: cout << "������..."; break; //�����
	default:break;
	}
}