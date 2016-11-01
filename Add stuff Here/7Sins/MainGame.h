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
#ifndef MAINGAME_H
#define MAINGAME_H


#include "include\SFML\Graphics.hpp"

#include "GameState.h"
#include "PhysicsWorld.h"
#include "Scene.h"
#include "GameObject.h"

class MainGame : public GameState
{
public:
	MainGame(Game* game, int Player1, int Player2, int Player3, int Player4);
	MainGame(Game* game);

	virtual	void draw();
	virtual void update(const float dt);
	virtual void handleInput();

private:
	sf::View gameView;
	sf::View hudView;
	sf::Sprite _Background;
	PhysicsWorld * m_world;
	GameObject *GameObject1;
	GameObject *GameObject2;
	GameObject *GameObject3;
	GameObject *GameObject4;
	std::vector<GameObject *> GameObjectList;
	Scene* CurrentLevel; 
	int lvlindex = 1;

	float gameOverDelay = 0.1f;

	void PauseGame();

};

#endif