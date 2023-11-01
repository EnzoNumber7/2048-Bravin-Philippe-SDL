#pragma once

class Tile
{
private:
	int t_value;
	bool t_merge;

public:

	Tile();
	Tile(int value);

	int Get_Value();
	bool Get_Merge();
	void Change_Value(int New_value);
	void Change_Bool(bool new_merge);
	~Tile();
};