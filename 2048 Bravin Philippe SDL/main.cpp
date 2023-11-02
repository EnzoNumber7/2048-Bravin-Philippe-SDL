#include <iostream>
#include <SDL.h>
#include "Window.h"
#include "GameObject.h"
#include "tab.h"
#include "tuile.h"



using namespace std;

int main(int argc, char** argv) {
	srand(time(NULL));
	Window screen;
	Tab Game;
	Game.Create_Object();
	Game.Create_Object();
	bool run = true;

	while (run) {
		screen.Clear();
		screen.Update();
		Game.Print_Tab(screen.Get_Renderer());
		int move = 0;

		SDL_Event event;

		while (SDL_PollEvent(&event) != 0) {
			switch (event.type) {
			case SDL_QUIT:
				run = false;
				break;
			case SDL_KEYDOWN:
				if (event.key.keysym.sym == SDLK_LEFT) {
					move = Game.Move_Tiles_Left();
					Game.Reset_Bool();
					if (move > 0) {
						Game.Create_Object();
						Game.Print_Tab(screen.Get_Renderer());
						Game.Print_Tab2();
					}
				}
				else if (event.key.keysym.sym == SDLK_RIGHT) {
					move = Game.Move_Tiles_Right();
					Game.Reset_Bool();
					if (move > 0) {
						Game.Create_Object();
						Game.Print_Tab(screen.Get_Renderer());
						Game.Print_Tab2();
					}
				}
				else if (event.key.keysym.sym == SDLK_UP) {
					move = Game.Move_Tiles_Up();
					Game.Reset_Bool();
					if (move > 0) {
						Game.Create_Object();
						Game.Print_Tab(screen.Get_Renderer());
						Game.Print_Tab2();
					}
				}
				else if (event.key.keysym.sym == SDLK_DOWN) {
					move = Game.Move_Tiles_Down();
					Game.Reset_Bool();
					if (move > 0) {
						Game.Create_Object();
						Game.Print_Tab(screen.Get_Renderer());
						Game.Print_Tab2();
					}
				}
				break;
			}
		}

	}
	/*Tab* tab = new Tab();
	tab->Create_Tiles();
	tab->Create_Tiles();
	tab->Print_Tab();
	bool run = true;
	while (run)
	{
		if (tab->Win()) {
			cout << "Bravo, vous avez gagner";
			run = false;
			break;
		}
		if (tab->Loose()) {
			cout << "Vous avez perdu";
			run = false;
			break;
		}
		int c = 0;
		int move;
		switch ((c = _getch()))
		{
		case KEY_UP:
			move = tab->Move_Tiles_Up();
			tab->Reset_Bool();
			if (move > 0) {
				tab->Create_Tiles();
				tab->Print_Tab();
			}
			break;
		case KEY_DOWN:
			move = tab->Move_Tiles_Down();
			tab->Reset_Bool();
			if (move > 0) {
				tab->Create_Tiles();
				tab->Print_Tab();
			}
			break;
		case KEY_RIGHT:
			move = tab->Move_Tiles_Right();
			tab->Reset_Bool();
			if (move > 0) {
				tab->Create_Tiles();
				tab->Print_Tab();
			}
			break;
		case KEY_LEFT:
			move = tab->Move_Tiles_Left();
			tab->Reset_Bool();
			if (move > 0) {
				tab->Create_Tiles();
				tab->Print_Tab();
			}
			break;
		default:
			run = true;
			break;
		}
	}*/

	screen.Clear();
	return 0;
}