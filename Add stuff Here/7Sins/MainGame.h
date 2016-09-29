#pragma once

#include <SFML\Graphics.hpp>

#include "GameState.h"

class MainGame : public GameState
{
public:
	MainGame(Game* game);

	virtual	void draw(const float dt);
	virtual void update(const float dt);
	virtual void handleInput();

private:
	sf::View gameView;
	sf::View hudView;
	sf::Sprite _Background;

	void PauseGame();

};

