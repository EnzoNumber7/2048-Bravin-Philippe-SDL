#pragma once
#include <SDL.h>
#include <string>
using namespace std;

class GameObject
{
private:
	SDL_Texture* g_texture;
	SDL_Renderer* g_renderer;
public :
	GameObject();
	SDL_Texture* Get_Texture();
	SDL_Renderer* Get_Renderer();
	void SurfaceAndTexture(const char * way);
	~GameObject();
};

