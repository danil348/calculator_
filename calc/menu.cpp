#include "menu.h"

void menu::init()
{
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
			if (activeMainMenu == 0) {
				update(1);
			}
			else if (activeMainMenu == 1) {
				update(2);
			}
			else if (activeMainMenu == 2) {
				update(3);
			}
			else if (activeMainMenu == 3) {
				update(4);
			}
			else if (activeMainMenu == 4) {
				update(5);
			}
			else if (activeMainMenu == 5) {
				update(6);
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
	else if (menuIndex == 1) {
		do {
			drow(TheoryMenu, TheoryMenuSize, activeTheoryMenu);
			cmd = _getch();
			if (cmd == -32) cmd = _getch();
			switch (cmd) {
			case ESCAPE: system("cls"); activeTheoryMenu = 0;  break;
			case ENTER: 
				system("cls"); 
				//polynominal(activeTheoryMenu);
				if (activeTheoryMenu == 0) {
					cout << "task 1\n";
					cout << "нажмите ентер для продолжения";
				}
				else if (activeTheoryMenu == 1) {
					cout << "task 2\n";
					cout << "нажмите ентер для продолжения";
				}
				else if (activeTheoryMenu == 2) {
					cout << "task 3\n";
					cout << "нажмите ентер для продолжения";
				}
				do {
					cmd = _getch();
					if (cmd == -32) cmd = _getch();
					switch (cmd) {
					case ESCAPE: system("cls"); break;
					case ENTER: system("cls"); break;
					}
				} while (cmd != ESCAPE && cmd != ENTER);
				activeTheoryMenu = 0; 
				break;
			case UP:
				if (activeTheoryMenu > 0) {
					activeTheoryMenu--;
				}
				else {
					activeTheoryMenu = TheoryMenuSize - 1;
				}
				break;
			case DOWN:
				if (activeTheoryMenu < TheoryMenuSize - 1) {
					activeTheoryMenu++;
				}
				else {
					activeTheoryMenu = 0;
				}
				break;
			default: break;
			}
		} while (cmd != ESCAPE && cmd != ENTER);
	}
}

bool menu::runnig()
{
	return isRunning;
}
