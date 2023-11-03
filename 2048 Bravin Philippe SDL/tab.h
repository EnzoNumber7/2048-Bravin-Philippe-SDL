#pragma once
#include "GameObject.h"
#include <string>
using namespace std;

class Tab
{
private:
	GameObject* t_tab[4][4];
	int t_valueTab[4][4];

public:

	Tab();

	void Print_Tab(SDL_Renderer* renderer);
	void Print_Tab2();
	void Create_Object();
	int Move_Tiles_Left();
	int Move_Tiles_Right();
	int Move_Tiles_Up();
	int Move_Tiles_Down();
	void Merge_Tiles(int direction,int value, int pos_X, int pos_Y);
	void Reset_Bool();
	void Delete_Tiles();
	void Delete_Tile(int pos_X,int pos_Y);
	void Delete_Tab();
	bool Win();
	bool Loose();

	bool CompareTab( Tab* resultTab);

	~Tab();
};