#include "Window.h"
#include <iostream>
#include <stdlib.h>
#include <SDL_image.h>

using namespace std;

Window::Window() {
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		cout << "SDL not Initialized" << SDL_GetError() << endl;
		exit(1);
	}
	w_window = SDL_CreateWindow("2048", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 900, 900, SDL_WINDOW_SHOWN);
	if (not w_window) {
		cout << "Window not created" << SDL_GetError() << endl;
		exit(1);
	}
	w_renderer = SDL_CreateRenderer(w_window, -1, SDL_RENDERER_ACCELERATED);
	if (not w_renderer) {
		cout << "Renderer not created" << SDL_GetError() << endl;
		exit(1);
	}
}

void Window::DrawBgFg(const char * file){
	SDL_Surface* Surface = IMG_Load(file);
	if (Surface == NULL) {
		cout << "Error SDL_LoadBMP :" << SDL_GetError() << endl;
		exit(1);
	}

	SDL_Texture* Texture;
	SDL_Rect Rect;
	Rect.w = 900;
	Rect.h = 900;
	Rect.x = 0;
	Rect.y = 0;

	Texture = SDL_CreateTextureFromSurface(w_renderer, Surface);
	if (Texture == NULL)
	{
		cout << "Error SDL_CreateTextureFromSurface :" << SDL_GetError() << endl;
		exit(1);
	}

	SDL_FreeSurface(Surface);

	SDL_QueryTexture(Texture, NULL, NULL, &Rect.w, &Rect.h);

	SDL_RenderCopy(w_renderer, Texture, NULL, &Rect);

	SDL_RenderPresent(w_renderer);
}

Window::~Window() {
	SDL_DestroyRenderer(w_renderer);
	SDL_DestroyWindow(w_window);
	SDL_Quit();
}

void Window::Update() {
	SDL_RenderPresent(w_renderer);
}

SDL_Renderer* Window::Get_Renderer() {
	return w_renderer;
}

void Window::Clear() {
	SDL_RenderClear(w_renderer);
}