#pragma once
#include "functions.h"
#include "ChekOnRightOfNumber.h"

#define WIDTH 1580
#define HEIGTH 1020

#define SEGMENT 100
#define OFFSET_X (WIDTH - WIDTH % SEGMENT) / 2 + SEGMENT/ 2
#define OFFSET_Y (HEIGTH - HEIGTH % SEGMENT) / 2 + SEGMENT/ 2

struct Variables
{
	double a, b, x, c, N, d;
};

void EnteringTask(int TaskNumber, Variables &variables) {
	
	if (TaskNumber == 0) {
		// polinom
	}
	else if (TaskNumber == 1) {
		cout << "Степенная: a*x^b+c\n";
		cout << "Введите a";
		variables.a = ChekOnDouble();
		cout << "Введите b";
		variables.b = ChekOnDouble();
		cout << "Введите c";
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

	SDL_Window* window = SDL_CreateWindow(u8"Привет! Русский заголовок!", 55, 55, WIDTH, HEIGTH, SDL_WINDOW_SHOWN);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

	SDL_RenderClear(renderer);

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
	point.y = OFFSET_X;
	for (int i = 0; i < WIDTH; i++) {
		point.x = i;
		if ((i % SEGMENT) == 0) {
			for (int j = -10; j < 10; j++) {
				point.y = HEIGTH / 2 + j;
				SDL_RenderDrawPoint(renderer, point.x, point.y);
			}
		}
		SDL_RenderDrawPoint(renderer, point.x, point.y);
	}
	point.x = OFFSET_X;
	for (int i = 0; i < HEIGTH; i++) {
		point.y = i;
		if ((i % SEGMENT - HEIGTH%100) == 0) {
			for (int j = -10; j < 10; j++) {
				point.x = WIDTH / 2 + j;
				SDL_RenderDrawPoint(renderer, point.x, point.y);
			}
		}
		SDL_RenderDrawPoint(renderer, point.x, point.y);
	}

	for (int i = -WIDTH/2; i < WIDTH/2; i++) {
		for (int j = 0; j < 200; j++) {
			if (TaskNumber == 0) {

			}
			else if (TaskNumber == 1) {
				point.x = i + (WIDTH - WIDTH % SEGMENT) / 2 + SEGMENT / 2;
				point.y = -(variables.a * pow(i, variables.b))/100 + (HEIGTH + HEIGTH % 100)/2 - variables.c * SEGMENT;
				if (point.y == 1 && point.x == 1) {
					SDL_SetRenderDrawColor(renderer, 255, 2, 3, 0);
				}
				else {
					SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
				}
				SDL_RenderDrawPoint(renderer, point.x, point.y);
			}
		}
	}


	SDL_RenderPresent(renderer);
	SDL_Delay(5000);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void functions(int  firstTaskNumber, int secondTaskNumber) {
	cout << firstTaskNumber << " " << secondTaskNumber << endl;
	switch (firstTaskNumber) {
	case 1: FunctionVisualization(secondTaskNumber); break;
	/*case 0: PlacementRepeat(); break;
	case 1: PlacementNoRepeat(); break;
	case 2: CombinationRepeat(); break;
	case 3: CombinationNoRepeat(); break;
	case 4: Transposition(); break;*/
	default: break;
	}
}