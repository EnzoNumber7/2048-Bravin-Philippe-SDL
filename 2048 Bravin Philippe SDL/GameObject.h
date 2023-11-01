#pragma once
#include "tab.h"
#include <SDL.h>
#include <string>


using namespace std;

class GameObject:Tab
{
private:
	int o_width;
	int o_height;
	int o_posX;
	int o_posY;
	const char* o_Image;

	SDL_Texture* o_Texture;
	SDL_Rect o_Rect;
public:
	GameObject(int posX, int posY, int width, int height, const char* fileName);

	void Draw(SDL_Renderer* renderer);

	void Move(int posX, int posY, SDL_Renderer* renderer);
	void Print_Tab();
	void ChangeImage(const char* fileName);


	/*SDL_Texture* Get_Texture();
	void SurfaceAndTexture(const char * way, SDL_Renderer* renderer);
	void queryTextureAndRenderCopy(SDL_Window* window, SDL_Renderer* renderer, int placementX, int placementY , const char* way, int windowWidth, int windowHeight, int screen);
	~GameObject();*/
};