#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "Fructions_calculator.h"
#include "ChekOnRightOfNumber.h"


using namespace std;


struct Fraction
{
	int numerator, denominator;//числитель, знаменатель
};


HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE); //Получить дискриптор консоли

void MoveCord_X_Y(short x, short y) { //Функция перемещения символа по определённой координате
	SetConsoleCursorPosition(hStdOut, { x,y });
}

void CursorVisible(bool show, short sizecurs) { //Функция включения видимости курсора в консоли
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(hStdOut, &structCursorInfo);
	structCursorInfo.bVisible = show;//видимость
	structCursorInfo.dwSize = sizecurs; //размер курсора
	SetConsoleCursorInfo(hStdOut, &structCursorInfo);
}
void SetColor(int text, int background)//функция установления цвета текста и заднего фона
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

void AdditionOfFractions() { //Сложение дробей
	Fraction fraction[3];
	cout << "Сложение дробей..." << endl;
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
		for (int i = 1; i < 11; i++) {
			if (fraction[2].numerator % i == 0 && fraction[2].denominator % i == 0) {
	
			}
		}
	}
	cout << fraction[0].numerator << " / " << fraction[0].denominator << " + " << fraction[1].numerator << " / " << fraction[1].denominator << " = " << fraction[2].numerator << " / " << fraction[2].denominator << endl;
	cout << "Нажмите любую клавишу для продолжения...";
	_getch();
}

void SubtractionOfFractions() { //Вычитание дробей

}

void MultiplicationOfFractions() { //Умножение дробей

}

void DivisionOfFractions() { //Деление дробей

}

void ComparisonOfFractions() { //Сравнение дробей

}

void ReductionOfFractions() { //Сокращение дробей

}

void PerfomanceAtTen() { //Представление в десятичном виде

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