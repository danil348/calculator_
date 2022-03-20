#pragma once
#include "functions.h"
#include "ChekOnRightOfNumber.h"

#define WIDTH 1580
#define HEIGTH 1020

#define SEGMENT 80
#define OFFSET_X HEIGTH / 2
#define OFFSET_Y WIDTH / 2

struct Variables
{ 
	double A, B;
	double step;
	double arrA[100];
	int N;
	double a, b, x, c, d;
};

void EnteringTask(int TaskNumber, Variables &variables) {
	if (TaskNumber == 0) {
		// polinom
	}
	else if (TaskNumber == 1) {
		cout << "Степенная: a*x^b+c\n";
		cout << "Введите a ";
		variables.a = ChekOnDouble();
		cout << "Введите b ";
		variables.b = ChekOnDouble();
		cout << "Введите c ";
		variables.c = ChekOnDouble();
	}
	else if (TaskNumber == 2) {
		cout << "показательная: a*b^(c*x)+d\n";
		cout << "Введите a ";
		variables.a = ChekOnDouble();
		cout << "Введите b ";
		variables.b = ChekOnDouble();
		cout << "Введите c ";
		variables.c = ChekOnDouble();
		cout << "Введите d ";
		variables.d = ChekOnDouble();
	}
	else if (TaskNumber == 3) {
		cout << "показательная: a*ln(b*x)+c\n";
		cout << "Введите a ";
		variables.a = ChekOnDouble();
		cout << "Введите b ";
		variables.b = ChekOnDouble();
		cout << "Введите c ";
		variables.c = ChekOnDouble();
	}
	else if (TaskNumber == 4) {
		cout << "синусоида: a*sin(b*x+c)+d\n";
		cout << "Введите a ";
		variables.a = ChekOnDouble();
		cout << "Введите b ";
		variables.b = ChekOnDouble();
		cout << "Введите c ";
		variables.c = ChekOnDouble();
		cout << "Введите d ";
		variables.d = ChekOnDouble();
	}
	else if (TaskNumber == 5) {
		cout << "синусоида: a*cos(b*x+c)+d\n";
		cout << "Введите a ";
		variables.a = ChekOnDouble();
		cout << "Введите b ";
		variables.b = ChekOnDouble();
		cout << "Введите c ";
		variables.c = ChekOnDouble();
		cout << "Введите d ";
		variables.d = ChekOnDouble();
	}
}

void FunctionVisualization(int TaskNumber) {
	Variables variables;
	SDL_Point point = { 0,0 };

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		printf("SDL Error: %S", SDL_GetError());
	}

	EnteringTask(TaskNumber, variables);

	SDL_Window* window = SDL_CreateWindow(u8"Привет! Русский заголовок!", 55, 55, WIDTH, HEIGTH, SDL_WINDOW_SHOWN);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

	SDL_RenderClear(renderer);

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
	point.y = OFFSET_X;
	for (int i = 0; i < WIDTH; i++) {
		point.x = i;
		SDL_RenderDrawPoint(renderer, point.x, point.y);
	}
	for (int i = OFFSET_Y; i > 0; i--) {
		point.x = i;
		if ((OFFSET_Y - i) % SEGMENT == 0) {
			for (int j = -5; j < 5; j++) {
				point.y = OFFSET_X + j;
				SDL_RenderDrawPoint(renderer, point.x, point.y);
			}
		}
	}
	for (int i = OFFSET_Y; i < WIDTH; i++) {
		point.x = i;
		if ((i - OFFSET_Y) % SEGMENT == 0) {
			for (int j = -5; j < 5; j++) {
				point.y = OFFSET_X + j;
				SDL_RenderDrawPoint(renderer, point.x, point.y);
			}
		}
	}



	point.x = OFFSET_Y;
	for (int i = 0; i < HEIGTH; i++) {
		point.y = i;
		SDL_RenderDrawPoint(renderer, point.x, point.y);
	}
	for (int i = OFFSET_X; i < HEIGTH; i++) {
		point.y = i;
		if ((OFFSET_X - i) % SEGMENT == 0) {
			for (int j = -5; j < 5; j++) {
				point.x = OFFSET_Y + j;
				SDL_RenderDrawPoint(renderer, point.x, point.y);
			}
		}
	}
	for (int i = OFFSET_X; i > 0; i--) {
		point.y = i;
		if ((i - OFFSET_X) % SEGMENT == 0) {
			for (int j = -5; j < 5; j++) {
				point.x = OFFSET_Y + j;
				SDL_RenderDrawPoint(renderer, point.x, point.y);
			}
		}
	}
	
	int tmpX = 0;
	int tmpY = 0;
	for (int i = -WIDTH/2; i < WIDTH/2; i++) {
		point.x = i + WIDTH / 2;
		if (TaskNumber == 0) {

		}
		else if (TaskNumber == 1) {
			point.y = -(variables.a * pow(i, variables.b)) / SEGMENT - variables.c * SEGMENT + HEIGTH / 2;
			
			if (i != -WIDTH / 2) {
				SDL_RenderDrawLine(renderer, tmpX, tmpY, point.x, point.y);
			}
			tmpX = point.x;
			tmpY = point.y;
		}
		else if (TaskNumber == 2) {
			point.y = -variables.a * pow(variables.b, (variables.c * (double(i) / SEGMENT))) * SEGMENT - variables.d * SEGMENT + HEIGTH / 2;
			if (i != -WIDTH / 2) {
				SDL_RenderDrawLine(renderer, tmpX, tmpY, point.x, point.y);
			}
			tmpX = point.x;
			tmpY = point.y;
		}
		else if (TaskNumber == 3) {
			point.y = -variables.a * log(variables.b * double(i)/SEGMENT) * SEGMENT - variables.c * SEGMENT + HEIGTH / 2;
			if (i != -WIDTH / 2) {
				SDL_RenderDrawLine(renderer, tmpX, tmpY, point.x, point.y);
			}
			tmpX = point.x;
			tmpY = point.y;
		}
		else if (TaskNumber == 4) {
			point.y = -variables.a * sin(variables.b * double(i) / SEGMENT + variables.c) * SEGMENT - variables.d * SEGMENT + HEIGTH / 2;
			if (i != -WIDTH / 2) {
				SDL_RenderDrawLine(renderer, tmpX, tmpY, point.x, point.y);
			}
			tmpX = point.x;
			tmpY = point.y;
		}
		else if (TaskNumber == 5) {
			point.y = -variables.a * cos(variables.b * double(i) / SEGMENT + variables.c) * SEGMENT - variables.d * SEGMENT + HEIGTH / 2;
			if (i != -WIDTH / 2) {
				SDL_RenderDrawLine(renderer, tmpX, tmpY, point.x, point.y);
			}
			tmpX = point.x;
			tmpY = point.y;
		}
	}


	SDL_RenderPresent(renderer);
	SDL_Delay(5000);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void FunctionInput(int TaskNumber, Variables& varb) {

	if (TaskNumber == 0) {
		cout << "Полином степени N: a0 + a1*x + a2*x^2 + ... +aN*x^N\n";
		cout << "Введите N:";
	}
	else if (TaskNumber == 1) {
		cout << "Степенная: a*x^b+c\n";
		cout << "Введите a ";
		varb.a = ChekOnDouble();
		cout << "Введите b ";
		varb.b = ChekOnDouble();
		cout << "Введите c ";
		varb.c = ChekOnDouble();
	}
	else if (TaskNumber == 2) {
		cout << "Показательная: a*b^(c*x)+d\n";
		cout << "Введите a ";
		varb.a = ChekOnDouble();
		cout << "Введите b ";
		varb.b = ChekOnDouble();
		cout << "Введите c ";
		varb.c = ChekOnDouble();
		cout << "Введите d ";
		varb.d = ChekOnDouble();
	}
	else if (TaskNumber == 3) {
	}
}

void Integral(int TaskNumber) {
	Variables varb;
	cout << "Нахождение определённого интеграла на отрезке:" << endl;
	FunctionInput(TaskNumber, varb);



}
//------------------------------------------------------------
double fsin(double A, double B, double C, double D, double x) {

	return   A * sin(B * x + C) + D;
}

double fcos(double A, double B, double C, double D, double x) {

	return   A * cos(B * x + C) + D;
}

void RootSin() {

	double A, B, C, D;
	double left, right, x, eps;

	cout << "Коэффициенты уравнения синусоиды: " << endl;
	cout << "A = "; cin >> A;
	cout << "B = "; cin >> B;
	cout << "C = "; cin >> C;
	cout << "D = "; cin >> D;

	cout << "Границы поиска корней: " << endl;
	cout << "Левая граница = "; cin >> left;
	cout << "Правая граница = "; cin >> right;
	cout << "Точность = "; cin >> eps;

	do {
		x = (left + right) / 2;
		if (fsin(A, B, C, D, x) * fsin(A, B, C, D, left) <= 0) right = x;
		else left = x;
	} while (fabs(left - right) >= eps);
	cout << "X = " << x << "\n";
}

void RootCos() {

	double A, B, C, D;
	double left = -1, right = 1, x, eps = 0.1;
	bool check = true;

	cout << "Коэффициенты уравнения косинусоиды: " << endl;
	cout << "A = "; cin >> A;
	cout << "B = "; cin >> B;
	cout << "C = "; cin >> C;
	cout << "D = "; cin >> D;

	cout << "Границы поиска корней (знаки на границах должны быть разные): " << endl;
	do {
		if (left >= 0) cout << "Левая граница введена неверно" << endl;
		if (right <= 0) cout << "Правая граница введена неверно" << endl;
		cout << "Левая граница = "; cin >> left;
		cout << "Правая граница = "; cin >> right;
	} while (left >= 0 or right <= 0);

	do {
		if (eps > 1 or eps <= 0) cout << "Точность введена неверно" << endl;
		cout << "Точность = "; cin >> eps;
	} while (eps > 1 or eps <= 0);

	do {
		x = (left + right) / 2;
		if (int(fcos(A, B, C, D, x)) != 0 and ((right - left) / 2) < eps) {
			cout << "На данном отрезке функция не имеет корней" << endl;
			check = false;
			break;
		}
		if (fcos(A, B, C, D, x) * fcos(A, B, C, D, left) <= 0) right = x;
		else left = x;
	} while (fabs(left - right) >= eps);

	if (check) cout << "X = " << x << "\n";
}

void RootSearch(int taskNumber) {
	switch (taskNumber) {
	case 0: break;
	case 1: break;
	case 2: break;
	case 3: break;
	case 4: RootSin(); break;
	case 5: RootCos(); break;
	default: break;
	}
}

void functions(int  firstTaskNumber, int secondTaskNumber) {
	switch (firstTaskNumber) {
	case 0: Integral(secondTaskNumber); break;
	case 1: FunctionVisualization(secondTaskNumber); break;
	case 2: RootSearch(secondTaskNumber); break;
	//case 3: RootSearch(secondTaskNumber); break;
	default: break;
	}
}