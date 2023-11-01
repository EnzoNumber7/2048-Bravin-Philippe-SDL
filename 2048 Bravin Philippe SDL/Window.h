#pragma once
#include <SDL.h>

class Window {
private:
	SDL_Window* w_window;
	SDL_Renderer* w_renderer;

public:
	Window();
	~Window();

	void Update();

	SDL_Renderer* Get_Renderer();
	
	void Clear();
};