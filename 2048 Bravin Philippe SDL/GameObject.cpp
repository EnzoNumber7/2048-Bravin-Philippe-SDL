#pragma once
#include "GameObject.h"
#include <SDL.h>
#include <string>
using namespace std;


GameObject::GameObject()
{
	
}

SDL_Texture* GameObject::Get_Texture() {
	return(g_texture);
}
void GameObject::SurfaceAndTexture(const char * way, SDL_Renderer* renderer)
{
	SDL_Surface* texture = SDL_LoadBMP(way);
	g_texture = SDL_CreateTextureFromSurface(renderer, texture);
	SDL_FreeSurface(texture);
}
void GameObject::queryTextureAndRenderCopy(SDL_Window* window, SDL_Renderer* renderer, int placementX, int placementY, const char* way ,int windowWidth,int windowHeight, int screen) {
	SurfaceAndTexture(way,renderer);
	if (SDL_QueryTexture(g_texture, NULL, NULL, &rect.w, &rect.h) != 0) {
		Error("Impossible de charger la texture");
		Destroy(window, renderer);
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
	if ((SDL_RenderCopy,renderer, g_texture, NULL, &rect) != 0) {
		Error("Impossible d'afficher l'image");
		Destroy(window,renderer);
	}
}


