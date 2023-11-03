#include <iostream>
#include <SDL.h>
#include "Window.h"
#include "GameObject.h"
#include "tab.h"




using namespace std;

int main(int argc, char** argv) {
	srand(time(NULL));
	Window* screen = new Window();
	Tab* Game = new Tab;
	bool run = true;
	bool winLose = false;
	unsigned int ticksA = SDL_GetTicks();
	unsigned int ticksB = SDL_GetTicks();
	int delta = 0;

	screen->DrawBgFg("2048 Bravin Philippe SDL/img/Background.bmp");
	screen->DrawBgFg("2048 Bravin Philippe SDL/img/Foreground.bmp");
	Game->Create_Object();
	Game->Create_Object();
	Game->Print_Game(screen->Get_Renderer());

	while (run) {

		if (Game->Win()) {
			screen->Clear();
			winLose = true;
			Game->Delete_Tab();
			screen->DrawBgFg("2048 Bravin Philippe SDL/img/Background.bmp");
			screen->DrawBgFg("2048 Bravin Philippe SDL/img/WinScreen.png");
			Game->Print_Game(screen->Get_Renderer());
		}
		if (Game->Loose()) {
			screen->Clear();
			winLose = true;
			Game->Delete_Tab();
			screen->DrawBgFg("2048 Bravin Philippe SDL/img/Background.bmp");
			screen->DrawBgFg("2048 Bravin Philippe SDL/img/LoseScreen.png");
			Game->Print_Game(screen->Get_Renderer());
		}

		
		int move = 0;
		ticksA = SDL_GetTicks();
		SDL_Event event;
		while (SDL_PollEvent(&event) != 0) {
			switch (event.type) {
			case SDL_QUIT:
				run = false;
				break;
			case SDL_KEYDOWN:
				if (event.key.keysym.sym == SDLK_LEFT and winLose == false) {
					move = Game->Move_Tiles_Left();
					Game->Reset_Bool();
					if (move > 0) {
						screen->Clear();
						Game->Create_Object();
						screen->DrawBgFg("2048 Bravin Philippe SDL/img/Background.bmp");
						screen->DrawBgFg("2048 Bravin Philippe SDL/img/Foreground.bmp");
						Game->Print_Game(screen->Get_Renderer());
					}
					screen->Update();
				}
				else if (event.key.keysym.sym == SDLK_RIGHT and winLose == false) {
					move = Game->Move_Tiles_Right();
					Game->Reset_Bool();
					if (move > 0) {
						screen->Clear();
						Game->Create_Object();
						screen->DrawBgFg("2048 Bravin Philippe SDL/img/Background.bmp");
						screen->DrawBgFg("2048 Bravin Philippe SDL/img/Foreground.bmp");
						Game->Print_Game(screen->Get_Renderer());
					}
					screen->Update();
				}
				else if (event.key.keysym.sym == SDLK_UP and winLose == false) {
					move = Game->Move_Tiles_Up();
					Game->Reset_Bool();
					if (move > 0) {
						screen->Clear();
						Game->Create_Object();
						screen->DrawBgFg("2048 Bravin Philippe SDL/img/Background.bmp");
						screen->DrawBgFg("2048 Bravin Philippe SDL/img/Foreground.bmp");
						Game->Print_Game(screen->Get_Renderer());
					}
					screen->Update();
				}
				else if (event.key.keysym.sym == SDLK_DOWN and winLose == false) {
					move = Game->Move_Tiles_Down();
					Game->Reset_Bool();
					if (move > 0) {
						screen->Clear();
						Game->Create_Object();
						screen->DrawBgFg("2048 Bravin Philippe SDL/img/Background.bmp");
						screen->DrawBgFg("2048 Bravin Philippe SDL/img/Foreground.bmp");
						Game->Print_Game(screen->Get_Renderer());
					}
					screen->Update();
				}
				else if (event.key.keysym.sym == SDLK_SPACE and winLose == true) {
					screen->Clear();
					screen->DrawBgFg("2048 Bravin Philippe SDL/img/Background.bmp");
					screen->DrawBgFg("2048 Bravin Philippe SDL/img/Foreground.bmp");
					Game->Create_Object();
					Game->Create_Object();
					Game->Print_Game(screen->Get_Renderer());
					winLose = false;
				}
				break;
			}
		}
		delta = ticksA - ticksB;
		if (delta > 1000 / 120)
		{
			std::cout << "fps: " << 1000 / delta << std::endl;

			ticksB = ticksA;

		}

	}
	delete screen;
	delete Game;
	return 0;
}