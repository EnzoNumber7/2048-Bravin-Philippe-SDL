#pragma once
#include <SDL.h>
#include "GameObject.h"
class Window : GameObject {
private:
	int windowWidth;
	int windowHeight;
public:
	Window();
	void queryTextureAndRenderCopy(SDL_Rect rect, SDL_Window* window, int placementX, int placementY, int screen);
	~Window();
}; 