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
	string mainMenu[mainMenuSize] = { "������ �����������", "����������� ������", "��������� �����������", "�������������",
		"������ � ���������", "����������","�����" };

	int activeTheoryMenu = 0;
	static const int TheoryMenuSize = 3;
	string TheoryMenu[TheoryMenuSize] = { "����������� ", "���������", "��� ��������" };

	int activeFractionsMenu = 0;
	static const int FractionsMenuSize = 7;
	string FractionsMenu[FractionsMenuSize] = { "�������� ������", "��������� ������", "���������", "�������", "���������",
		"����������", "������������� � ���� ���. �����"};

	int activeMatrixMenu = 0;
	static const int MatrixMenuSize = 9;
	string MatrixMenu[MatrixMenuSize] = { "�������� ������", "��������� ������", "��������� ������", "��������� ������� �� �����",
		"�������� ������� � ������", "��������� ����� �� �������", "���������������� �������", "�������� �������", "������������"};

	int active�ombinatoricMenu = 0;
	static const int �ombinatoricMenuSize = 5;
	string �ombinatoricMenu[�ombinatoricMenuSize] = { "���������� � ������������", "���������� ��� ����������", "��������� � ������������",
		"��������� ��� ����������", "������������"};
	
	int activePolynomialMenu = 0;
	static const int PolynomialMenuSize = 6;
	string PolynomialMenu[PolynomialMenuSize] = { "������� ����������� � �������", "�������� �����������", "��������� �����������",
		"��������� �����������", "��������� ���������� �� �����", "���������� ����������� �� ����������" };

	int activeFunctionsMenu = 0;
	static const int FunctionsMenuSize = 4;
	string FunctionsMenu[FunctionsMenuSize] = { "���������� ������������ ��������� �� �������", "���������� ������� �������", "����� ����� Y=0 �� �������",
		"����� ����������� �� �������" };

	int activeFunctionsDopMenu = 0;
	static const int FunctionsDopMenuSize = 6;
	string FunctionsDopMenu[FunctionsDopMenuSize] = { "������� ������� N: a0+a1*x+a2*x^2+...aN*x^N", "���������: a*x^b+c", "�������������: a*b^(c*x)+d",
		"�������������: a*ln(b*x)+c","���������: a*sin(b*x+c)+d","�����������: a*cos(b*x+c)+d" };
};

