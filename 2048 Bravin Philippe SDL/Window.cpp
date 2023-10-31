#include "Window.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

Window::Window() {}

Window::~Window() {}

void Window::Init(const char* title, int width, int height) {
	if (SDL_Init(SDL_INIT_VIDEO) == 0) {

		cout << "SDL Initialized" << endl;
		w_window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width,height,0);
		if (w_window) {
			cout << "Window created" << endl;
		}
		w_renderer = SDL_CreateRenderer(w_window, -1, 0);
		if (w_renderer) {
			cout << "Renderer created" << endl;
		}
		run = true;
	}
	run = false;
	
}



