#pragma once
#include "functions.h"
#include "ChekOnRightOfNumber.h"
#include <math.h>

#define WIDTH 1580
#define HEIGTH 1020

#define SEGMENT 80
#define OFFSET_X HEIGTH/2
#define OFFSET_Y WIDTH/2

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
		cout << "���������: a*x^b+c\n";
		cout << "������� a ";
		variables.a = ChekOnDouble();
		cout << "������� b ";
		variables.b = ChekOnDouble();
		cout << "������� c ";
		variables.c = ChekOnDouble();
	}
	else if (TaskNumber == 2) {
		cout << "�������������: a*b^(c*x)+d\n";
		cout << "������� a ";
		variables.a = ChekOnDouble();
		cout << "������� b ";
		variables.b = ChekOnDouble();
		cout << "������� c ";
		variables.c = ChekOnDouble();
		cout << "������� d ";
		variables.d = ChekOnDouble();
	}
	else if (TaskNumber == 3) {
		cout << "�������������: a*ln(b*x)+c\n";
		cout << "������� a ";
		variables.a = ChekOnDouble();
		cout << "������� b ";
		variables.b = ChekOnDouble();
		cout << "������� c ";
		variables.c = ChekOnDouble();
	}
}

void FunctionVisualization(int TaskNumber) {
	Variables variables;
	SDL_Point point = { 0,0 };

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		printf("SDL Error: %S", SDL_GetError());
	}

	EnteringTask(TaskNumber, variables);

	SDL_Window* window = SDL_CreateWindow(u8"������! ������� ���������!", 55, 55, WIDTH, HEIGTH, SDL_WINDOW_SHOWN);
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
	}


	SDL_RenderPresent(renderer);
	SDL_Delay(5000);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void FunctionInput(int TaskNumber, Variables& varb) {

	if (TaskNumber == 0) {
		cout << "������� ������� N: a0 + a1*x + a2*x^2 + ... +aN*x^N\n";
		cout << "������� N �� ������ 100 (�� N ����� �������� ���������� ���������� a):";
		do {
			varb.N = ChekOnInt();
			if (varb.N < 0) cout << "������� �������� �� ����� ���� ������ ����! ��������� �������: ";
			if (varb.N == 0) cout << "������� �������� �� ����� ���� ����� ����! ��������� �������: ";
			if (varb.N > 100) cout << "����������� ������� � 100! ��������� �������: ";
		} while (varb.N <= 0 || varb.N > 100);
		cout << "������� ���������� a:\n";
		for (int i = 0; i < varb.N; i++) {
			cout << "a" << i + 1 << ": ";
			varb.arrA[i] = ChekOnDouble();
		}
	}
	else if (TaskNumber == 1) {
		cout << "���������: a*x^b+c\n";
		cout << "������� a: ";
		varb.a = ChekOnDouble();
		cout << "������� b: ";
		varb.b = ChekOnDouble();
		cout << "������� c: ";
		varb.c = ChekOnDouble();
	}
	else if (TaskNumber == 2) {
		cout << "�������������: a*b^(c*x)+d\n";
		cout << "������� a: ";
		varb.a = ChekOnDouble();
		cout << "������� b: ";
		varb.b = ChekOnDouble();
		cout << "������� c: ";
		varb.c = ChekOnDouble();
		cout << "������� d: ";
		varb.d = ChekOnDouble();
	}
	else if (TaskNumber == 3) {
		cout << "���������������: a*ln(b*x)+c\n";
		cout << "������� a: ";
		varb.a = ChekOnDouble();
		cout << "������� b: ";
		varb.b = ChekOnDouble();
		cout << "������� c: ";
		varb.c = ChekOnDouble();
	}
	cout << "������� ������ �������: ";
	varb.A = ChekOnDouble();
	cout << "������� ����� �������: ";
	do {
		varb.B = ChekOnDouble();
		if (varb.B < varb.A) cout << "����� ������� �� ����� ���� ������ ������! ��������� �������";
	} while (varb.B < varb.A);
	cout << "������� ��� �������������� (��� ������ ��������, ��� ������ ��������): ";
	do {
		varb.step = ChekOnDouble();
		if (varb.step == 0) cout << "��� �� ����� ���� ����� ����! ��������� �������: ";
	} while (varb.step == 0);
}

double FunctionIntegral(double &sum,Variables varb, int &TaskNumber) {
	sum = 0;
	if (TaskNumber == 0) {
		for (int i = 0; i < varb.N; i++) {
			sum += varb.arrA[i] * pow(varb.x, i);
		}
		return sum;
	}

}

void Integral(int TaskNumber) {
	Variables varb;
	double sum, sum_integral = 0;
	cout << "���������� ������������ ��������� �� �������:" << endl;
	FunctionInput(TaskNumber, varb);
	varb.x = varb.step + varb.A;
	while (varb.x < varb.B) {
		sum_integral += 2 * FunctionIntegral(sum, varb, TaskNumber);
		varb.x += varb.step;
		if (varb.x >= varb.B) break;
	}
	sum_integral *= varb.step / 3;
	cout << "�������������� �����: " << sum_integral;
}

void functions(int  firstTaskNumber, int secondTaskNumber) {
	cout << firstTaskNumber << " " << secondTaskNumber << endl;
	switch (firstTaskNumber) {
	case 0: Integral(secondTaskNumber); break;
	case 1: FunctionVisualization(secondTaskNumber); break;
	/*case 0: PlacementRepeat(); break;
	case 1: PlacementNoRepeat(); break;
	case 2: CombinationRepeat(); break;
	case 3: CombinationNoRepeat(); break;
	case 4: Transposition(); break;*/
	default: break;
	}
}