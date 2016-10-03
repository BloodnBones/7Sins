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
*/

#ifndef GAME_STATE_HPP
#define GAME_STATE_HPP

#pragma once
#include "Game.h"
#include "Utils.h"


//Abstract GameState class
class GameState
{
public:

	Game* game;

	virtual void draw() = 0;
	virtual void update(const float dt) = 0;
	virtual void handleInput() = 0;
};

#endif /*GAME_STATE_HPP*/

