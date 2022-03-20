#pragma once

#include <conio.h>
#include <iostream>
#include <windows.h>
#include "polynomial.h"
#include "Fructions_calculator.h"
#include "matrix.h"
#include "combinatorics.h"
#include "Theory.h"
#include "functions.h"

#define ESCAPE 27
#define ENTER 13
#define RIGHT 77
#define LEFT 75
#define DOWN 80
#define UP 72

using namespace std;

class menu
{
public:
	void init();
	void ConsoleCursorVisible(bool show);
	void drow(string *typeMenu, const int menuSize, int activeMenu);
	void update(int menuIndex);
	bool runnig();

private:
	void drow(string* typeMenu, const int menuSize, int& activeMenu, int menuIndex);
	void functionSelection(int menuIndex);
	char cmd = ' ';
	bool isRunning = false;
	CONSOLE_CURSOR_INFO structCursorInfo;
	HWND hWnd = GetForegroundWindow();
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

	int activeMainMenu = 0;
	static const int mainMenuSize = 7;
	string mainMenu[mainMenuSize] = { "теория вероятности", "калькулятор дробей", "матричный калькулятор", "комбинаторика",
		"работа с функциями", "многочлены","выход" };

	int activeTheoryMenu = 0;
	static const int TheoryMenuSize = 3;
	string TheoryMenu[TheoryMenuSize] = { "вероятность ", "дисперсия", "мат ожидание" };

	int activeFractionsMenu = 0;
	static const int FractionsMenuSize = 7;
	string FractionsMenu[FractionsMenuSize] = { "сложение дробей", "вычитание дробей", "умножение", "деление", "сравнение",
		"сокращение", "Представление в виде дес. дроби"};

	int activeMatrixMenu = 0;
	static const int MatrixMenuSize = 9;
	string MatrixMenu[MatrixMenuSize] = { "сложение матриц", "вычитание матриц", "умножение матриц", "умножение матрицы на число",
		"сложение матрицы с числом", "вычитание числа из матрицы", "транспонирование матрицы", "обратная матрица", "определитель"};

	int activeСombinatoricMenu = 0;
	static const int СombinatoricMenuSize = 5;
	string СombinatoricMenu[СombinatoricMenuSize] = { "размещение с повторениями", "размещение без повторений", "сочетания с повторениями",
		"сочетания без повторений", "перестановки"};
	
	int activePolynomialMenu = 0;
	static const int PolynomialMenuSize = 6;
	string PolynomialMenu[PolynomialMenuSize] = { "деление многочленов в столбик", "сложение многочленов", "вычитание многочленов",
		"умножение многочленов", "умножение многочлена на число", "вычисление производной от многочлена" };

	int activeFunctionsMenu = 0;
	static const int FunctionsMenuSize = 4;
	string FunctionsMenu[FunctionsMenuSize] = { "вычисление определённого интеграла на отрезке", "построение графика функции", "поиск корня Y=0 на отрезке",
		"поиск экстремумов на отрезке" };

	int activeFunctionsDopMenu = 0;
	static const int FunctionsDopMenuSize = 6;
	string FunctionsDopMenu[FunctionsDopMenuSize] = { "полином степени N: a0+a1*x+a2*x^2+...aN*x^N", "степенная: a*x^b+c", "показательная: a*b^(c*x)+d",
		"показательная: a*ln(b*x)+c","синусоида: a*sin(b*x+c)+d","косинусоида: a*cos(b*x+c)+d" };
};

