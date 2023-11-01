#include <iostream>
#include <SDL.h>
#include "Window.h"
#include "GameObject.h"
#include "tab.h"
#include "tuile.h"

#undef main

using namespace std;

int main() {

	Window screen;

	GameObject object1(0,0,200,200, "2048 Bravin Philippe SDL/img/128.bmp");

	object1.Draw(screen.Get_Renderer());
	object1.Move(200, 200, screen.Get_Renderer());
	object1.ChangeImage("2048 Bravin Philippe SDL/img/2048.bmp");


	while (true) {
		screen.Update();
		screen.Clear();
		object1.Draw(screen.Get_Renderer());
	}

	return 0;
}