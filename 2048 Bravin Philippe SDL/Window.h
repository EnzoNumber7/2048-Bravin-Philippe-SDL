#pragma once
#include <SDL.h>
#include "GameObject.h"
class Window : GameObject {
private:
	SDL_Window* w_window;
	SDL_Renderer* w_renderer;
	bool run;

public:
	Window();
	~Window();
	
	void Init(const char* title, int width, int height);
}; 