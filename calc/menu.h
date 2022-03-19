#pragma once

#include <conio.h>
#include <iostream>
#include <windows.h>

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
	void drow(string *typeMenu, const int menuSize, int activeMenu);
	void update(int menuIndex);
	bool runnig();

private:
	char cmd = ' ';
	bool isRunning = false;

	int activeMainMenu = 0;
	static const int mainMenuSize = 7;
	string mainMenu[mainMenuSize] = { "теория вероятности", "калькулятор дробей", "матричный калькулятор", "комбинаторика",
	"работа с функциями", "многочлены","выход" };


	int activeTheoryMenu = 0;
	static const int TheoryMenuSize = 3;
	string TheoryMenu[TheoryMenuSize] = { "вероятность ", "дисперсия", "мат ожидание" };

};

