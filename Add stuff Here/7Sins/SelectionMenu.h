/*
c) 2005 - 2016 Media Design School

File Name	:	SelectionMenu.h
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
	~SelectionMenu();

	virtual void draw();
	virtual void update(const float dt);
	virtual void handleInput();

	void SetChoice(sf::Sprite* sprite, sf::Text* text, int choice);
	bool Taken(int choice);
	void Reset();

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

	int			m_P1Choice = NONE,
				m_P2Choice = NONE,
				m_P3Choice = NONE,
				m_P4Choice = NONE;

	bool		m_Player1Chosen = false,
				m_Player2Chosen = false,
				m_Player3Chosen = false,
				m_Player4Chosen = false;

	int			m_PlayersChosen = 0;

	float		buttonDelayP1 = 0.0f;
	float		buttonDelayP2 = 0.0f;
	float		buttonDelayP3 = 0.0f;
	float		buttonDelayP4 = 0.0f;


	sf::Text	m_P1Current,
				m_P2Current,
				m_P3Current,
				m_P4Current;

	sf::Text	m_Player1,
				m_Player2,
				m_Player3,
				m_Player4;

	sf::Sprite	m_Player1Spr,
				m_Player2Spr,
				m_Player3Spr,
				m_Player4Spr;

	Button		done;
	Button		back;
	Button		quit;

	GameObject *GameObject1;
	GameObject *GameObject2;
	GameObject *GameObject3;
	GameObject *GameObject4;
	std::vector<GameObject *> GameObjectList;

};
