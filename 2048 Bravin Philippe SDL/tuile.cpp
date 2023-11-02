#include "tuile.h"
#include <iostream>
#include <stdlib.h>  

using namespace std;

Tile::Tile() 
{

	// Génération Aléatoire de la valeur entre 2 et 4
	int tab[10] = { 2,2,2,2,2,2,2,2,2,4 };
	int i = rand() % 10;
	t_value = tab[i];

	t_merge = false;
}

int Tile::Get_Value()
{
	return (t_value);
}

bool Tile::Get_Merge()
{
	return(t_merge);
}

void Tile::Change_Value(int New_value)
{
	t_value = New_value;
}

void Tile::Change_Bool(bool new_merge)
{
	t_merge = new_merge;
}

Tile::~Tile() 
{
}