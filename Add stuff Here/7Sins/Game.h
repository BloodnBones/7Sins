/*
Bachelor of Software Engineering
Media Design School
Auckland
NewZealand

(c) 2005 - 2016 Media Design School

File Name	:
Description	:
Authors		:	Tyrone Mills, Gabriel Mugadza, Mun Hou Yong, Dylan Ridgeway
mail		:	tyrone.mill6438@mediadesign.school.nz
			,
			,
			,
*/

#ifndef GAME_HPP
#define GAME_HPP

#pragma once

#include <vector>
#include "include\SFML\Graphics.hpp"
#include "Utils.h"


enum State {
	GAME_PLAY = 0,
	GAME_MENU = 1,
	GAME_OVER = 2,
	GAME_PAUSE = 3
};

class GameState;

class Game
{
public:
	
	void pushState(State statevalue, GameState* state);
	void popState();

	GameState* currentState(State statevalue);

	void gameLoop();

	void setState(State newState);

	sf::RenderWindow window;
	TextureManager textureManager;

	//constructor, destructor
	Game();
	~Game();

private:

	void loadTextures();
	std::map<State, GameState*> m_states;
	State m_CurrentState;
};

#endif /*GAME_HPP*/