#pragma once
#include "GameObject.h"
#include <SDL.h>
#include <string>
#include <iostream>

using namespace std;


GameObject::GameObject(int posX, int posY, int width, int height, const char* fileName)
{
	o_posX = posX;
	o_posY = posY;
	o_width = width;
	o_height = height;
	o_Texture = NULL;
	o_Rect.x = o_posX;
	o_Rect.y = o_posY;
	o_Rect.w = o_width;
	o_Rect.h = o_height;
	o_Image = fileName;
}

void GameObject::Draw(SDL_Renderer* renderer) {

	SDL_Surface* Surface = SDL_LoadBMP(o_Image);
	if (Surface == NULL) {
		cout << "Error SDL_LoadBMP :" << SDL_GetError() << endl;
		exit(1);
	}

	o_Texture = SDL_CreateTextureFromSurface(renderer, Surface);
	if (o_Texture == NULL)
	{
		cout << "Error SDL_CreateTextureFromSurface :" << SDL_GetError() << endl;
		exit(1);
	}

	SDL_FreeSurface(Surface);

	SDL_QueryTexture(o_Texture, NULL, NULL, &o_Rect.w, &o_Rect.h);

	SDL_RenderCopy(renderer, o_Texture, NULL, &o_Rect);

	SDL_RenderPresent(renderer);
}

void GameObject::Move(int posX, int posY, SDL_Renderer* renderer) {
	SDL_DestroyTexture(o_Texture);
	o_Rect.x = posX;
	o_Rect.y = posY;
}

void GameObject::ChangeImage(const char* fileName) {
	o_Image = fileName;
}

/*void GameObject::Print_Tab()
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (t_valueTab[i][j] == 2) { }
			else if (t_valueTab[i][j] == 4) { }
			else if (t_valueTab[i][j] == 8) {; }
			else if (t_valueTab[i][j] == 16) { }
			else if (t_valueTab[i][j] == 32) { }
			else if (t_valueTab[i][j] == 64) { }
			else if (t_valueTab[i][j] == 128) { }
			else if (t_valueTab[i][j] == 256) { }
			else if (t_valueTab[i][j] == 512) { }
			else if (t_valueTab[i][j] == 1024) { }
			else if (t_valueTab[i][j] == 2048) { }
		}
		cout << endl;
	}
	cout << endl;
}*/

/*SDL_Texture* GameObject::Get_Texture() {
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
}*/


