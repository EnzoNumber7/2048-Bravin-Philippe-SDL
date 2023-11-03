#pragma once
#include "GameObject.h"
#include <SDL.h>
#include <string>
#include <iostream>
#include <SDL_image.h>

using namespace std;



GameObject::GameObject(int posX, int posY, int width, int height)
{
	o_width = width;
	o_height = height;
	o_Texture = NULL;
	o_Rect.x = posX;
	o_Rect.y = posY;
	o_Rect.w = o_width;
	o_Rect.h = o_height;
	o_Image = "2048 Bravin Philippe SDL/img/2.png";

	// Génération Aléatoire de la valeur entre 2 et 4
	int tab[10] = { 2,2,2,2,2,2,2,2,2,4 };
	int i = rand() % 10;
	o_value = tab[i];
	if (tab[i]==2){
		o_Image = "2048 Bravin Philippe SDL/img/2.png";
	}
	else if (tab[i]==4){
		o_Image = "2048 Bravin Philippe SDL/img/4.png";
	}
	o_merge = false;
}

void GameObject::Draw(SDL_Renderer* renderer, const char* filename) {
	SDL_Surface* Surface = IMG_Load(filename);
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

void GameObject::ObjectMove(int posX, int posY) {
	o_Rect.x = posX;
	o_Rect.y = posY;
}

void GameObject::DestroyTexture() {
	SDL_DestroyTexture(o_Texture);
}

void GameObject::ChangeImage(const char* fileName) {
	o_Image = "2048 Bravin Philippe SDL/img/2.png";
}
int GameObject::Get_Value()
{
	return (o_value);
}

bool GameObject::Get_Merge()
{
	return(o_merge);
}

void GameObject::Change_Value(int New_value)
{
	o_value = New_value;
}

void GameObject::Change_Bool(bool new_merge)
{
	o_merge = new_merge;
}

GameObject::~GameObject(){}