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

#include "MainMenu.h"
#include "MainGame.h"
#include "GameState.h"

#include <iostream>
#include <cmath>

/*
* @brief
* @param
* @return
*/
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

/*
* @brief
* @param
* @return
*/
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

/*
* @brief
* @param
* @return
*/
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

/*
* @brief
* @param
* @return
*/
void
MainMenu::draw(const float dt)
{
	game->window.draw(startPrompt);
}

/*
* @brief
* @param
* @return
*/
void
MainMenu::startGame()
{
	game->pushState(GAME_PLAY, new MainGame(game));
	game->setState(GAME_PLAY);
}


