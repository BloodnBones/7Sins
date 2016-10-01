#include "include\SFML\Graphics.hpp"
#include "button.h"
#include "Game.h"
#include "MainMenu.h"
#include <iostream>
#include <map>


int main()
{

	Game game;
	game.pushState(GAME_MENU, new MainMenu(&game));
	//game.pushState(GAME_PAUSE, new )
	
	game.gameLoop();

	return 0;
}