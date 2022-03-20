#pragma once
#include "functions.h"

#define WIDTH 1280
#define HEIGTH 720

void FunctionVisualization(int TaskNumber) {
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		printf("SDL Error: %S", SDL_GetError());
	}

	SDL_Window* window = SDL_CreateWindow(u8"Привет! Русский заголовок!", 55, 55, WIDTH, HEIGTH, SDL_WINDOW_SHOWN);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

	SDL_RenderClear(renderer);





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