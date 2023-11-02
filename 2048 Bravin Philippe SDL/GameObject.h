#pragma once
#include <SDL.h>
#include <string>


using namespace std;

class GameObject
{
private:
	int o_width;
	int o_height;
	const char* o_Image;

	int o_value;
	bool o_merge;

	SDL_Texture* o_Texture;
	SDL_Rect o_Rect;
public:
	GameObject(int posX, int posY, int width, int height);

	void Draw(SDL_Renderer* renderer);

	void ObjectMove(int posX, int posY);
	void ChangeImage(const char* fileName);
	void DestroyTexture();

	int Get_Value();
	bool Get_Merge();
	void Change_Value(int New_value);
	void Change_Bool(bool new_merge);

	~GameObject();
};