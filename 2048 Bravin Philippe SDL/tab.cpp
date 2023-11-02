#include "tab.h"
#include <iostream>
#include <stdlib.h>
#include <string>

#include <typeinfo>
#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define CYN   "\x1B[36m"
#define MAG   "\x1B[35m"
#define RESET "\x1B[0m"

using namespace std;

// ---------- CONSTRUCTEUR ---------- //
Tab::Tab()
{
	// Création d'un tableau vide
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			t_valueTab[i][j] = 0;
			t_tab[i][j] = NULL;
		}
	}
}

// ---------- METHODE ---------- //

void Tab::Print_Tab(SDL_Renderer* renderer)
{
	for (int i = 0; i < 4 ; i++) {
		for (int j = 0; j < 4 ; j++) {
			if (t_tab[j][i] != NULL) {
				t_tab[j][i]->Draw(renderer);
			}
			
		}
	}
}
void Tab::Print_Tab2()
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (t_valueTab[i][j] == 0) { cout << "|    |"; }
			else if (t_valueTab[i][j] < 10) { cout << "|   " << CYN << t_valueTab[i][j] << RESET << "|"; }
			else if (t_valueTab[i][j] < 100) { cout << "|  " << GRN << t_valueTab[i][j] << RESET << "|"; }
			else if (t_valueTab[i][j] < 1000) { cout << "| " << RED << t_valueTab[i][j] << RESET << "|"; }
			else { cout << "|" << MAG << t_valueTab[i][j] << RESET << "|"; }
		}
		cout << endl;
	}
	cout << endl;
}

void Tab::Create_Object()
{
	// Création d'une tuile dans une case libre aléatoire
	int X = rand() % 4;
	int Y = rand() % 4;
	if (t_valueTab[X][Y] != NULL) {
		Create_Object();
	}
	else
	{
		t_tab[X][Y] = new GameObject(Y*160,X*160,160,160);
		t_valueTab[X][Y] = t_tab[X][Y]->Get_Value();
	}	
}

int Tab::Move_Tiles_Left()
{
	int nb_move = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++) {
			if (t_valueTab[i][j + 1]!=0) { // Si la case a droite n'est pas vide
				if (t_valueTab[i][j] == 0){ // Si la case est libre, Alors on déplace la case de droite, et on rapelle la fonction
					t_tab[i][j] = t_tab[i][j + 1];
					t_tab[i][j + 1] = NULL;
					t_valueTab[i][j] = t_valueTab[i][j + 1];
					t_valueTab[i][j + 1] = 0;
					nb_move += 1;
					t_tab[i][j]->ObjectMove(j * 160, i * 160);
					return Move_Tiles_Left() + nb_move;
				}
				else if (t_valueTab[i][j] == t_valueTab[i][j + 1] and t_tab[i][j]->Get_Merge() == false and t_tab[i][j + 1]->Get_Merge() == false){ // Si la case ij et la case a droite on la même valeur et qu'elles n'ont jamais fusionné
					nb_move += 1;
					t_tab[i][j]->Change_Bool(true); // On passe le booléen a true pour montrer qu'elle a fusionné 
					Merge_Tiles(4, t_valueTab[i][j], i, j);
				}
			}
		}
	}
	return nb_move;
}

int Tab::Move_Tiles_Right()
{
	int nb_move = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 3; j >= 1; j--) {
			if (t_valueTab[i][j - 1] != 0 ) {
				if (t_valueTab[i][j] == 0) {
					t_tab[i][j] = t_tab[i][j - 1];
					t_tab[i][j - 1] = NULL;
					t_valueTab[i][j] = t_valueTab[i][j - 1];
					t_valueTab[i][j - 1] = 0;

					nb_move += 1;
					t_tab[i][j]->ObjectMove(j * 160, i * 160);
					return Move_Tiles_Right() + nb_move;
				}
				if (t_valueTab[i][j] == t_valueTab[i][j - 1] and t_tab[i][j]->Get_Merge() == false and t_tab[i][j - 1]->Get_Merge() == false) {
					nb_move += 1;
					t_tab[i][j]->Change_Bool(true);
					Merge_Tiles(6, t_valueTab[i][j], i, j);
				}
			}
		}
	}
	return nb_move;
}

int Tab::Move_Tiles_Up()
{
	int nb_move = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			if (t_valueTab[i + 1][j] != 0) {
				if (t_valueTab[i][j] == 0) {
					t_tab[i][j] = t_tab[i + 1][j];
					t_tab[i + 1][j] = NULL;
					t_valueTab[i][j] = t_valueTab[i + 1][j];
					t_valueTab[i + 1][j] = 0;

					nb_move += 1;
					t_tab[i][j]->ObjectMove(j * 160, i * 160);
					return Move_Tiles_Up() + nb_move;
				}
				else if (t_valueTab[i + 1][j] == t_valueTab[i][j] and t_tab[i][j]->Get_Merge() == false and t_tab[i + 1][j]->Get_Merge() == false) {
					nb_move += 1;
					t_tab[i][j]->Change_Bool(true);
					Merge_Tiles(8, t_valueTab[i][j], i, j);
				}
			}
		}
	}
	return nb_move;
}

int Tab::Move_Tiles_Down()
{
	int nb_move = 0;
	for (int i = 3; i >= 1; i--) {
		for (int j = 0; j < 4; j++) {
			if (t_valueTab[i - 1][j] != 0 ) {
				if (t_valueTab[i][j] == 0) {
					t_tab[i][j] = t_tab[i - 1][j];
					t_tab[i - 1][j] = NULL;
					t_valueTab[i][j] = t_valueTab[i - 1][j];
					t_valueTab[i - 1][j] = 0;
					t_tab[i][j]->ObjectMove(j * 160, i * 160);

					nb_move += 1;
					t_tab[i][j]->ObjectMove(j * 160, i * 160);
					return Move_Tiles_Down() + nb_move;
				}
				else if (t_valueTab[i - 1][j] == t_valueTab[i][j] and t_tab[i][j]->Get_Merge() == false and t_tab[i - 1][j]->Get_Merge() == false) {
					nb_move += 1;
					t_tab[i][j]->Change_Bool(true);
					Merge_Tiles(2, t_valueTab[i][j], i, j);
				}
			}
		}
	}
	return nb_move;
} 

void Tab::Merge_Tiles(int direction, int value, int pos_X, int pos_Y)
{
	// Direction: 4 = Gauche ; 2 = Bas ; 6 = Droite et 8 = Haut
	if (direction == 4) {
		Delete_Tile(pos_X, pos_Y + 1);
		t_tab[pos_X][pos_Y]->Change_Value(value*2);
		t_valueTab[pos_X][pos_Y] = value * 2;
	}
	else if (direction == 8) {
		Delete_Tile(pos_X + 1, pos_Y);
		t_tab[pos_X][pos_Y]->Change_Value(value * 2);
		t_valueTab[pos_X][pos_Y] = value * 2;
	}
	else if (direction == 6) {
		Delete_Tile(pos_X, pos_Y - 1);
		t_tab[pos_X][pos_Y]->Change_Value(value * 2);
		t_valueTab[pos_X][pos_Y] = value * 2;
	}
	else if (direction == 2) {
		Delete_Tile(pos_X - 1, pos_Y);
		t_tab[pos_X][pos_Y]->Change_Value(value * 2);
		t_valueTab[pos_X][pos_Y] = value * 2;
	}
	if (value * 2 == 4){
		t_tab[pos_X][pos_Y]->ChangeImage("img/4.bmp");
	}
	else if (value * 2 == 8) {
		t_tab[pos_X][pos_Y]->ChangeImage("img/8.bmp");
	}
	else if (value * 2 == 16) {
		t_tab[pos_X][pos_Y]->ChangeImage("img/16.bmp");
	}
	else if (value * 2 == 32) {
		t_tab[pos_X][pos_Y]->ChangeImage("img/32.bmp");
	}
	else if (value * 2 == 64) {
		t_tab[pos_X][pos_Y]->ChangeImage("img/64.bmp");
	}
	else if (value * 2 == 128) {
		t_tab[pos_X][pos_Y]->ChangeImage("img/128.bmp");
	}
	else if (value * 2 == 256) {
		t_tab[pos_X][pos_Y]->ChangeImage("img/256.bmp");
	}
	else if (value * 2 == 512) {
		t_tab[pos_X][pos_Y]->ChangeImage("img/512.bmp");
	}
	else if (value * 2 == 1024) {
		t_tab[pos_X][pos_Y]->ChangeImage("img/1024.bmp");
	}
	else if (value * 2 == 2048) {
		t_tab[pos_X][pos_Y]->ChangeImage("img/2048.bmp");
	}
}

void Tab::Reset_Bool()
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (t_valueTab[i][j] != 0) {
				t_tab[i][j]->Change_Bool(false);
			}
		}
	}
}

bool Tab::Win()
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (t_valueTab[i][j] == 2048) {
				return (true);
			}
		}
	}
	return(false);
}

bool Tab::Loose()
{
	// La fonction vérifie si la case ij est pleine et s'il n'y a pas de possibilité de fusion, cela est fait pour toute les cases
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (i>0 and i<3 and j>0 and j<3){
				if (t_valueTab[i][j] == 0 or t_valueTab[i][j] == t_valueTab[i - 1][j] or t_valueTab[i][j] == t_valueTab[i + 1][j] or t_valueTab[i][j] == t_valueTab[i][j - 1] or t_valueTab[i][j] == t_valueTab[i][j + 1]) {
					return (false);
				}
			}
			else if (i > 0 and i < 3 and j>0) {
				if (t_valueTab[i][j] == 0 or t_valueTab[i][j] == t_valueTab[i - 1][j] or t_valueTab[i][j] == t_valueTab[i + 1][j] or t_valueTab[i][j] == t_valueTab[i][j - 1]) {
					return (false);
				}
			}
			else if (i > 0 and i < 3 and j<3) {
				if (t_valueTab[i][j] == 0 or t_valueTab[i][j] == t_valueTab[i - 1][j] or t_valueTab[i][j] == t_valueTab[i + 1][j] or t_valueTab[i][j] == t_valueTab[i][j + 1]) {
					return (false);
				}
			}
			else if (i > 0 and j > 0 and j < 3) {
				if (t_valueTab[i][j] == 0 or t_valueTab[i][j] == t_valueTab[i - 1][j] or t_valueTab[i][j] == t_valueTab[i][j - 1] or t_valueTab[i][j] == t_valueTab[i][j + 1]) {
					return (false);
				}
			}
			else if (i < 3 and j >0 and j < 3) {
				if (t_valueTab[i][j] == 0 or t_valueTab[i][j] == t_valueTab[i + 1][j] or t_valueTab[i][j] == t_valueTab[i][j - 1] or t_valueTab[i][j] == t_valueTab[i][j + 1]) {
					return (false);
				}
			}
			else if (i > 0 and j>0) {
				if (t_valueTab[i][j] == 0 or t_valueTab[i][j] == t_valueTab[i - 1][j] or t_valueTab[i][j] == t_valueTab[i][j - 1]) {
					return (false);
				}
			}
			else if (i < 3 and j>0) {
				if (t_valueTab[i][j] == 0 or t_valueTab[i][j] == t_valueTab[i + 1][j] or t_valueTab[i][j] == t_valueTab[i][j - 1]) {
					return (false);
				}
			}
			else if (i > 0 and j < 3) {
				if (t_valueTab[i][j] == 0 or t_valueTab[i][j] == t_valueTab[i - 1][j] or t_valueTab[i][j] == t_valueTab[i][j + 1]) {
					return (false);
				}
			}
			else if (i < 3 and j < 3) {
				if (t_valueTab[i][j] == 0 or t_valueTab[i][j] == t_valueTab[i + 1][j] or t_valueTab[i][j] == t_valueTab[i][j + 1]) {
					return (false);
				}
			}
		}
	}
	return (true);
}

void Tab::Delete_Tile(int pos_X, int pos_Y)
{
	t_tab[pos_X][pos_Y]->DestroyTexture();
	delete(t_tab[pos_X][pos_Y]);
	t_valueTab[pos_X][pos_Y] = 0;
	
}

// ---------- TEST ---------- //

bool Tab::CompareTab(Tab* resultTab)
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (resultTab->t_valueTab[i][j] != t_valueTab[i][j]) {
				return false;
			}
		}
	}
	return true;
}

// ---------- DESTRUCTEUR ---------- //

void Tab::Delete_Tiles()
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (t_valueTab[i][j] != 0) {
				delete(t_tab[i][j]);
			}
		}
	}
}

Tab::~Tab()
{
	Delete_Tiles();
}
