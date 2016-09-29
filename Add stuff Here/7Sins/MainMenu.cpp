#include "MainMenu.h"
#include "MainGame.h"
#include "GameState.h"

#include <iostream>
#include <cmath>

MainMenu::MainMenu(Game* gameState)
{
	this->game = gameState;

	sf::Vector2f pos = sf::Vector2f(this->game->window.getSize());
	this->view.setSize(pos);
	pos *= 0.5f;
	this->view.setCenter(pos);

	startPrompt.setTexture(this->game->textureManager.getRef("startPrompt"));
	startPrompt.setPosition(380, 500);
}


void
MainMenu::handleInput()
{
	sf::Event event;

	while (game->window.pollEvent(event))
	{
		switch (event.type)
		{
			case sf::Event::Closed:
				game->window.close();
				break;

			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Return || event.key.code == sf::Keyboard::Space)
				{
					startGame();
				}
				break;
		}
	}
}

void
MainMenu::update(const float dt)
{
	float test = dt;

	int i = 0;
	/*if (true)
	{
		startPrompt.setColor(sf::Color::Black);
	}
	else
	{
		startPrompt.setColor(sf::Color::White);
	}*/
}

void
MainMenu::draw(const float dt)
{
	game->window.draw(startPrompt);
}

void
MainMenu::startGame()
{
	game->pushState(GAME_PLAY, new MainGame(game));
	game->setState(GAME_PLAY);
}

