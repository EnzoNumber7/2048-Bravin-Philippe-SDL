#include "Window.h"
#include <iostream>
#include <stdlib.h>

using namespace std;
void Window::queryTextureAndRenderCopy(SDL_Rect rect, SDL_Window* window, int placementX, int placementY, int screen) {
	if (SDL_QueryTexture(g_texture->Get_Texture(), NULL, NULL, &rect.w, &rect.h) != 0) {
		Error("Impossible de charger la texture");
		Destroy(window, g_renderer);
	}
	rect.x = placementX;
	rect.y = placementY;

	if (screen) {
		rect.w = windowWidth;
		rect.h = windowHeight;
	}

	if (!screen) {
		rect.w = (windowWidth / 4);
		rect.h = (windowHeight / 4);
	}

	if (SDL_RenderCopy(g_renderer, g_texture, NULL, &rect) != 0) {
		Error("Impossible d'afficher l'image");
		Destroy(window, g_renderer);
	}
}