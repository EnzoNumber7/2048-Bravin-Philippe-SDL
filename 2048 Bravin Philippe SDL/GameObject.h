#pragma once
#include <SDL.h>
#include <string>
using namespace std;

class GameObject
{
private:
	SDL_Texture* g_texture;
	SDL_Rect rect;
public :
	GameObject();
	SDL_Texture* Get_Texture();
	void SurfaceAndTexture(const char * way, SDL_Renderer* renderer);
	void queryTextureAndRenderCopy(SDL_Window* window, SDL_Renderer* renderer, int placementX, int placementY , const char* way, int windowWidth, int windowHeight, int screen);
	~GameObject();
};

