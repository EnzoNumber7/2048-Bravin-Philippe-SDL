#pragma once
#include "GameObject.h"
#include <SDL.h>
#include <string>
using namespace std;


GameObject::GameObject()
{
	
}

SDL_Texture* GameObject:: Get_Texture(){
	return(g_texture);
}
SDL_Renderer* GameObject::Get_Renderer(){
	return(g_renderer);
}
void GameObject::SurfaceAndTexture(const char * way)
{
	SDL_Surface* texture = SDL_LoadBMP(way);
	g_texture = SDL_CreateTextureFromSurface(g_renderer, texture);
	SDL_FreeSurface(texture);
}


