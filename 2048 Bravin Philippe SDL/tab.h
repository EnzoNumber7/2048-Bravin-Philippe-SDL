#pragma once
#include "tuile.h"
#include <string>
using namespace std;

class Tab : Tile
{
private:
	Tile* t_tab[4][4];
	int t_valueTab[4][4];

public:

	Tab();
	Tab(string line1, string line2, string line3, string line4);

	void Print_Tab();
	void Create_Tiles();
	int Move_Tiles_Left();
	int Move_Tiles_Right();
	int Move_Tiles_Up();
	int Move_Tiles_Down();
	void Merge_Tiles(int direction,int value, int pos_X, int pos_Y);
	void Reset_Bool();
	void Delete_Tiles();
	void Delete_Tile(int pos_X,int pos_Y);
	bool Win();
	bool Loose();

	bool CompareTab( Tab* resultTab);

	~Tab();
};