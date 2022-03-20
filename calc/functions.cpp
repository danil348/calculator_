#pragma once
#include "functions.h"
#include "ChekOnRightOfNumber.h"
#include <math.h>

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
		cout << "Полином степени N: a0 + a1*x + a2*x^2 + ... +aN*x^N\n";
		cout << "Введите N не больше 100 (от N будет зависить количество переменных a):";
		do {
			variables.N = ChekOnInt();
			if (variables.N < 0) cout << "Степень полинома не может быть меньше нуля! Повторите попытку: ";
			if (variables.N == 0) cout << "Степень полинома не может быть равна нулю! Повторите попытку: ";
			if (variables.N > 100) cout << "Ограничение степени в 100! Повторите попытку: ";
		} while (variables.N <= 0 || variables.N > 100);
		cout << "Введите переменные a:\n";
		for (int i = 0; i < variables.N; i++) {
			cout << "a" << i + 1 << ": ";
			variables.arrA[i] = ChekOnDouble();
		}
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

void ExtremesSearch(int TaskNumber) {
	Variables variables;
	double min = 0;
	double eps = 0;
	cout << "введите левую границу";
	variables.A = ChekOnDouble();
	cout << "введите правую границу";
	variables.B = ChekOnDouble();

	EnteringTask(TaskNumber, variables);
	if (TaskNumber == 0) {

	}
	else if (TaskNumber == 1) {
		//min = variables.a* variables.b*pow(variables.A, variables.b)
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
	int sum = 0;
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
	SDL_Delay(20000);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void FunctionInput(int TaskNumber, Variables& varb) {

	if (TaskNumber == 0) {
		cout << "Полином степени N: a0 + a1*x + a2*x^2 + ... +aN*x^N\n";
		cout << "Введите N не больше 100 (от N будет зависить количество переменных a):";
		do {
			varb.N = ChekOnInt();
			if (varb.N < 0) cout << "Степень полинома не может быть меньше нуля! Повторите попытку: ";
			if (varb.N == 0) cout << "Степень полинома не может быть равна нулю! Повторите попытку: ";
			if (varb.N > 100) cout << "Ограничение степени в 100! Повторите попытку: ";
		} while (varb.N <= 0 || varb.N > 100);
		cout << "Введите переменные a:\n";
		for (int i = 0; i < varb.N; i++) {
			cout << "a" << i << ": ";
			varb.arrA[i] = ChekOnDouble();
		}
	}
	else if (TaskNumber == 1) {
		cout << "Степенная: a*x^b+c\n";
		cout << "Введите a: ";
		varb.a = ChekOnDouble();
		cout << "Введите b: ";
		varb.b = ChekOnDouble();
		cout << "Введите c: ";
		varb.c = ChekOnDouble();
	}
	else if (TaskNumber == 2) {
		cout << "Показательная: a*b^(c*x)+d\n";
		cout << "Введите a: ";
		varb.a = ChekOnDouble();
		cout << "Введите b: ";
		varb.b = ChekOnDouble();
		cout << "Введите c: ";
		varb.c = ChekOnDouble();
		cout << "Введите d: ";
		varb.d = ChekOnDouble();
	}
	else if (TaskNumber == 3) {
		cout << "Логарифмическая: a*ln(b*x)+c\n";
		cout << "Введите a: ";
		varb.a = ChekOnDouble();
		cout << "Введите b: ";
		varb.b = ChekOnDouble();
		cout << "Введите c: ";
		varb.c = ChekOnDouble();
	}
	else if (TaskNumber == 4) {
		cout << "Синусоида: a*sin(b*x+c)+d\n";
		cout << "Введите a: ";
		varb.a = ChekOnDouble();
		cout << "Введите b: ";
		varb.b = ChekOnDouble();
		cout << "Введите c: ";
		varb.c = ChekOnDouble();
		cout << "Введите d: ";
		varb.d = ChekOnDouble();
	}
	else if (TaskNumber == 5) {
		cout << "Косинусоида: a*cos(b*x+c)+d\n";
		cout << "Введите a: ";
		varb.a = ChekOnDouble();
		cout << "Введите b: ";
		varb.b = ChekOnDouble();
		cout << "Введите c: ";
		varb.c = ChekOnDouble();
		cout << "Введите d: ";
		varb.d = ChekOnDouble();
	}
	cout << "Введите начало отрезка: ";
	varb.A = ChekOnDouble();
	cout << "Введите конец отрезка: ";
	do {
		varb.B = ChekOnDouble();
		if (varb.B < varb.A) cout << "Конец отрезка не может быть меньше начала! Повторите попытку";
	} while (varb.B < varb.A);
	cout << "Введите шаг интегрирования (чем меньше значение, тем больше точность): ";
	do {
		varb.step = ChekOnDouble();
		if (varb.step == 0) cout << "Шаг не может быть равен нулю! Повторите попытку: ";
	} while (varb.step == 0);
}
double FunctionIntegral(double &sum,Variables varb, double x ,int &TaskNumber) {
	sum = 0;
	if (TaskNumber == 0) {
		for (int i = 0; i < varb.N; i++) {
			sum += varb.arrA[i] * pow(x, i);
		}
	}
	if (TaskNumber == 1) {
		sum = varb.a * pow(x, varb.b) + varb.c;
	}
	if (TaskNumber == 2) {
		sum = varb.a * pow(varb.b, (varb.c * x)) + varb.d;
	}
	if (TaskNumber == 3) {
		sum = varb.a * log(varb.b * x) + varb.c;
	}
	if (TaskNumber == 4) {
		sum = varb.a * sin(varb.b * x + varb.c) + varb.d;
	}
	if (TaskNumber == 5) {
		sum = varb.a * cos(varb.b * x + varb.c) + varb.d;
	}
	return sum;
}

void Integral(int TaskNumber) {
	Variables varb;
	double sum, sum_integral = 0;
	cout << "Нахождение определённого интеграла на отрезке:" << endl;
	FunctionInput(TaskNumber, varb);
	varb.x = varb.step + varb.A;
	while (varb.x < varb.B) {
		sum_integral += 2 * FunctionIntegral(sum, varb, varb.x, TaskNumber);
		varb.x += varb.step;
	}
	sum_integral = (varb.step / 2) * (sum_integral + FunctionIntegral(sum, varb, varb.A, TaskNumber));
	cout << "Интегрирование равно: " << sum_integral;
}
//------------------------------------------------------------

// Полином степени N
double fpol(int N, double* a, double x) {

	double y = 0;
	for (int i = 0; i < N; i++) {
		y += a[i] * pow(x, i);
	}

	return y;
}
void RootPol() {

	double a[100];
	double x;
	int N = 1;
	double left = -1, right = 1, eps = 0.1;
	bool check = true;

	do {
		if (N < 1) cout << "N не может быть меньше 1" << endl;
		cout << "Введите N: "; N = ChekOnInt();
	} while (N < 1);

	for (int i = 0; i < N; i++) {
		cout << "a[" << i << "] = ";
		a[i] = ChekOnDouble();
	}

	cout << "Границы поиска корней (знаки на границах должны быть разные): " << endl;
	do {
		if (left >= 0) cout << "Левая граница введена неверно" << endl;
		if (right <= 0) cout << "Правая граница введена неверно" << endl;
		cout << "Левая граница = "; left = ChekOnDouble();
		cout << "Правая граница = "; right = ChekOnDouble();
	} while (left >= 0 or right <= 0);

	do {
		if (eps > 1 or eps <= 0) cout << "Точность введена неверно" << endl;
		cout << "Точность = "; eps = ChekOnDouble();
	} while (eps > 1 or eps <= 0);

	do {
		x = (left + right) / 2;
		if (int(fpol(N, a, x)) != 0 and ((right - left) / 2) < eps) {
			cout << "На данном отрезке функция не имеет корней" << endl;
			check = false;
			break;
		}
		if (fpol(N, a, x) * fpol(N, a, left) <= 0) right = x;
		else left = x;
	} while (fabs(left - right) >= eps);

	if (check) cout << "X = " << x << endl;

}

// Степенная
double fdeg(double A, double B, double C, double x) {

	return A * pow(x, B) + C;
}
void RootDeg()	 {

	double A, B, C;
	double left = -1, right = 1, x, eps = 0.1;
	bool check = true;

	cout << "Коэффициенты уравнения функции: " << endl;
	cout << "A = "; A = ChekOnDouble();
	cout << "B = "; B = ChekOnDouble();
	cout << "C = "; C = ChekOnDouble();

	cout << "Границы поиска корней (знаки на границах должны быть разные): " << endl;
	do {
		if (left >= 0) cout << "Левая граница введена неверно" << endl;
		if (right <= 0) cout << "Правая граница введена неверно" << endl;
		cout << "Левая граница = "; left = ChekOnDouble();
		cout << "Правая граница = "; right = ChekOnDouble();
	} while (left >= 0 or right <= 0);

	do {
		if (eps > 1 or eps <= 0) cout << "Точность введена неверно" << endl;
		cout << "Точность = "; eps = ChekOnDouble();
	} while (eps > 1 or eps <= 0);

	do {
		x = (left + right) / 2;
		if (int(fdeg(A, B, C, x)) != 0 and ((right - left) / 2) < eps) {
			cout << "На данном отрезке функция не имеет корней" << endl;
			check = false;
			break;
		}
		if (fdeg(A, B, C, x) * fdeg(A, B, C, left) <= 0) right = x;
		else left = x;
	} while (fabs(left - right) >= eps);

	if (check) cout << "X = " << x << endl;
}

// Показательная
double find(double A, double B, double C, double D, double x) {
	
	return A * pow(B, C * x) + D;
}
void RootInd() {

	double A, B, C, D;
	double left = -1, right = 1, x, eps = 0.1;
	bool check = true;

	cout << "Коэффициенты уравнения функции: " << endl;
	cout << "A = "; A = ChekOnDouble();
	cout << "B = "; B = ChekOnDouble();
	cout << "C = "; C = ChekOnDouble();
	cout << "D = "; D = ChekOnDouble();

	cout << "Границы поиска корней (знаки на границах должны быть разные): " << endl;
	do {
		if (left >= 0) cout << "Левая граница введена неверно" << endl;
		if (right <= 0) cout << "Правая граница введена неверно" << endl;
		cout << "Левая граница = "; left = ChekOnDouble();
		cout << "Правая граница = "; right = ChekOnDouble();
	} while (left >= 0 or right <= 0);

	do {
		if (eps > 1 or eps <= 0) cout << "Точность введена неверно" << endl;
		cout << "Точность = "; eps = ChekOnDouble();
	} while (eps > 1 or eps <= 0);

	do {
		x = (left + right) / 2;
		if (int(find(A, B, C, D, x)) != 0 and ((right - left) / 2) < eps) {
			cout << "На данном отрезке функция не имеет корней" << endl;
			check = false;
			break;
		}
		if (find(A, B, C, D, x) * find(A, B, C, D, left) <= 0) right = x;
		else left = x;
	} while (fabs(left - right) >= eps);

	if (check) cout << "X = " << x << endl;
}

// Логарифмическая
double flog(double A, double B, double C, double x) {
	return A * log(B * x) + C;
}
void RootLog() {

	double A, B, C;
	double left = -1, right = 1, x, eps = 0.1;
	bool check = true;

	cout << "Коэффициенты уравнения функции: " << endl;
	cout << "A = "; A = ChekOnDouble();
	cout << "B = "; B = ChekOnDouble();
	cout << "C = "; C = ChekOnDouble();

	cout << "Границы поиска корней (знаки на границах должны быть разные): " << endl;
	do {
		if (left >= 0) cout << "Левая граница введена неверно" << endl;
		if (right <= 0) cout << "Правая граница введена неверно" << endl;
		cout << "Левая граница = "; left = ChekOnDouble();
		cout << "Правая граница = "; right = ChekOnDouble();
	} while (left >= 0 or right <= 0);

	do {
		if (eps > 1 or eps <= 0) cout << "Точность введена неверно" << endl;
		cout << "Точность = "; eps = ChekOnDouble();
	} while (eps > 1 or eps <= 0);

	do {
		x = (left + right) / 2;
		if (int(flog(A, B, C, x)) != 0 and ((right - left) / 2) < eps) {
			cout << "На данном отрезке функция не имеет корней" << endl;
			check = false;
			break;
		}
		if (flog(A, B, C, x) * flog(A, B, C, left) <= 0) right = x;
		else left = x;
	} while (fabs(left - right) >= eps);

	if (check) cout << "X = " << x << endl;
}

// Синусоида
double fsin(double A, double B, double C, double D, double x) {

	return   A * sin(B * x + C) + D;
}
void RootSin() {

	double A, B, C, D;
	double left = -1, right = 1, x, eps = 0.1;
	bool check = true;

	cout << "Коэффициенты уравнения синусоиды: " << endl;
	cout << "A = "; A = ChekOnDouble();
	cout << "B = "; B = ChekOnDouble();
	cout << "C = "; C = ChekOnDouble();
	cout << "D = "; D = ChekOnDouble();

	cout << "Границы поиска корней (знаки на границах должны быть разные): " << endl;
	do {
		if (left >= 0) cout << "Левая граница введена неверно" << endl;
		if (right <= 0) cout << "Правая граница введена неверно" << endl;
		cout << "Левая граница = "; left = ChekOnDouble();
		cout << "Правая граница = "; right = ChekOnDouble();
	} while (left >= 0 or right <= 0);

	do {
		if (eps > 1 or eps <= 0) cout << "Точность введена неверно" << endl;
		cout << "Точность = "; eps = ChekOnDouble();
	} while (eps > 1 or eps <= 0);

	do {
		x = (left + right) / 2;
		if (int(fsin(A, B, C, D, x)) != 0 and ((right - left) / 2) < eps) {
			cout << "На данном отрезке функция не имеет корней" << endl;
			check = false;
			break;
		}
		if (fsin(A, B, C, D, x) * fsin(A, B, C, D, left) <= 0) right = x;
		else left = x;
	} while (fabs(left - right) >= eps);

	if (check) cout << "X = " << x << endl;
}

// Косинусоида
double fcos(double A, double B, double C, double D, double x) {

	return   A * cos(B * x + C) + D;
}
void RootCos() {

	double A, B, C, D;
	double left = -1, right = 1, x, eps = 0.1;
	bool check = true;

	cout << "Коэффициенты уравнения косинусоиды: " << endl;
	cout << "A = "; A = ChekOnDouble();
	cout << "B = "; B = ChekOnDouble();
	cout << "C = "; C = ChekOnDouble();
	cout << "D = "; D = ChekOnDouble();

	cout << "Границы поиска корней (знаки на границах должны быть разные): " << endl;
	do {
		if (left >= 0) cout << "Левая граница введена неверно" << endl;
		if (right <= 0) cout << "Правая граница введена неверно" << endl;
		cout << "Левая граница = "; left = ChekOnDouble();
		cout << "Правая граница = "; right = ChekOnDouble();
	} while (left >= 0 or right <= 0);

	do {
		if (eps > 1 or eps <= 0) cout << "Точность введена неверно" << endl;
		cout << "Точность = "; eps = ChekOnDouble();
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

	if (check) cout << "X = " << x << endl;
}

void RootSearch(int taskNumber) {
	switch (taskNumber) {
	case 0: RootPol(); break;
	case 1: RootDeg(); break;
	case 2: RootInd(); break;
	case 3: RootLog(); break;
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
	case 3: ExtremesSearch(secondTaskNumber); break;
	default: break;
	}
}