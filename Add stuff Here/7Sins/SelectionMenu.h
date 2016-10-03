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
#include "button.h"
#include "GameState.h"

class SelectionMenu : public GameState
{
public:
	SelectionMenu(Game* gameState);

	virtual void draw();
	virtual void update(const float dt);
	virtual void handleInput();

private:
	sf::Sprite backGround;
	sf::Font font;

	Button lucia;
	Button gabriel;
	Button joshua;
	Button betty;
	Button matthew;
	Button satella;
	Button honda;

	Button done;
	Button back;
	Button quit;


	GameObject *GameObject1;
	std::vector<GameObject *> GameObjectList;

};
