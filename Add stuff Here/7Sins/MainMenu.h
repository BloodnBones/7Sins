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

#pragma once

#include "include\SFML\Graphics.hpp"

#include "GameState.h"

class MainMenu : public GameState
{
public:
	MainMenu(Game* gameState);

	virtual void draw(const float dt);
	virtual void update(const float dt);
	virtual void handleInput();


private:
	sf::View view;
	sf::Sprite startPrompt;
	//Transitions to main game
	void startGame();
};

