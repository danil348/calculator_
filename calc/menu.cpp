#include "menu.h"

void menu::ConsoleCursorVisible(bool show)
{
	GetConsoleCursorInfo(hStdOut, &structCursorInfo);
	structCursorInfo.bVisible = show;
	SetConsoleCursorInfo(hStdOut, &structCursorInfo);
}

void menu::init()
{
	ConsoleCursorVisible(false);
	isRunning = true;
	while (runnig() == true) {
		drow(mainMenu, mainMenuSize, activeMainMenu);
		update(0);
	}
}

void menu::drow(string *typeMenu, const int menuSize, int activeMenu)
{
	system("cls");

	for (int i = 0; i < menuSize; i++)
	{
		cout << typeMenu[i];
		for (int j = typeMenu[i].size(); j < 20; j++) {
			cout << " ";
		}
		if (activeMenu == i) {
			cout << "\t\t<--";
		}
		cout << endl;
	}
}

void menu::update(int menuIndex)
{
	if (menuIndex == 0) {
		cmd = _getch();

		if (cmd == -32) cmd = _getch();
		switch (cmd)
		{
		case ESCAPE:
			isRunning = false;
			break;
		case ENTER:
			if (activeMainMenu >= 0 && activeMainMenu < mainMenuSize - 1) {
				update(activeMainMenu + 1);
			}
			else if (activeMainMenu == 6) {
				isRunning = false;
				exit(0);
			}
			break;
		case UP:
			if (activeMainMenu > 0) {
				activeMainMenu--;
			}
			else {
				activeMainMenu = mainMenuSize - 1;
			}
			break;
		case DOWN:
			if (activeMainMenu < mainMenuSize - 1) {
				activeMainMenu++;
			}
			else {
				activeMainMenu = 0;
			}
			break;
		default: break;
		}
	}
	else if(menuIndex == 1){
		drow(TheoryMenu, TheoryMenuSize, activeTheoryMenu, menuIndex);
	}
	else if (menuIndex == 2) {
		drow(FractionsMenu, FractionsMenuSize, activeFractionsMenu, menuIndex);
	}
	else if (menuIndex == 3) {
		drow(MatrixMenu, MatrixMenuSize, activeMatrixMenu, menuIndex);
	}
	else if (menuIndex == 4) {
		drow(ÑombinatoricMenu, ÑombinatoricMenuSize, activeÑombinatoricMenu, menuIndex);
	}
	else if (menuIndex == 5) {
		//drow(TheoryMenu, TheoryMenuSize, activeTheoryMenu, menuIndex);
	}
	else if (menuIndex == 6) {
		drow(PolynomialMenu, PolynomialMenuSize, activePolynomialMenu, menuIndex);
	}
}

bool menu::runnig()
{
	return isRunning;
}

void menu::drow(string *typeMenu, const int menuSize, int &activeMenu, int menuIndex)
{
	do {
		drow(typeMenu, menuSize, activeMenu);
		cmd = _getch();
		if (cmd == -32) cmd = _getch();
		switch (cmd) {
		case ESCAPE: system("cls"); activeMenu = 0;  break;
		case ENTER:
			system("cls");
			functionSelection(menuIndex);
			cout << "\n\níàæìèòå Enter ÷òîáû âåðíóòüñÿ ê âûáîðó äåéñòâèé\n";
			do {
				cmd = _getch();
				if (cmd == -32) cmd = _getch();
				switch (cmd) {
				case ESCAPE: system("cls"); break;
				case ENTER: system("cls"); break;
				}
			} while (cmd != ESCAPE && cmd != ENTER);
			activeMenu = 0;
			break;
		case UP:
			if (activeMenu > 0) {
				activeMenu--;
			}
			else {
				activeMenu = menuSize - 1;
			}
			break;
		case DOWN:
			if (activeMenu < menuSize - 1) {
				activeMenu++;
			}
			else {
				activeMenu = 0;
			}
			break;
		default: break;
		}
	} while (cmd != ESCAPE && cmd != ENTER);
}

void menu::functionSelection(int menuIndex)
{
	switch (menuIndex) {
	/*case 1: Polynomial(activeTheoryMenu); break;
	case 2: Polynomial(activeTheoryMenu); break;
	case 3: Polynomial(activeTheoryMenu); break;
	case 4: Polynomial(activeTheoryMenu); break;
	case 5: Polynomial(activeTheoryMenu); break;*/
	case 6: Polynomial(activePolynomialMenu); break;
	default:
		break;
	}
}