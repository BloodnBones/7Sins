#pragma once

#include <SFML\Graphics.hpp>

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

