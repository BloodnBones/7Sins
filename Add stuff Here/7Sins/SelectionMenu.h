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
#include "GameObject.h"

class SelectionMenu : public GameState
{
public:
	SelectionMenu(Game* gameState);

	virtual void draw();
	virtual void update(const float dt);
	virtual void handleInput();

	void SetChoice(sf::Text* text, int choice);

private:
	sf::Sprite	backGround;
	sf::Font	font;

	bool		lucia = false,
				gabriel = false,
				joshua = false,
				betty = false,
				matthew = false,
				satella = false,
				honda = false;

	int			m_P1Choice = 0,
				m_P2Choice = 0,
				m_P3Choice = 0,
				m_P4Choice = 0;

	sf::Text	m_P1Current,
				m_P2Current,
				m_P3Current,
				m_P4Current;

	sf::Text	m_Player1,
				m_Player2,
				m_Player3,
				m_Player4;

	Button		done;
	Button		back;
	Button		quit;

	GameObject *GameObject1;
	GameObject *GameObject2;
	GameObject *GameObject3;
	GameObject *GameObject4;
	std::vector<GameObject *> GameObjectList;

};
