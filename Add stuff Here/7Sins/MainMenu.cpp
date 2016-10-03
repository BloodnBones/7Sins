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
* @brief	:
* @param	:Pointer to the gamestate calling MainMenu
* @return
*/
MainMenu::MainMenu(Game* gameState)
{
	this->game = gameState;

	sf::Vector2f pos = sf::Vector2f(this->game->window.getSize());
	this->view.setSize(pos);
	pos *= 0.5f;
	this->view.setCenter(pos);

	startPrompt.setTexture(this->game->textureManager.getRef("gameBackGround"));
	startPrompt.setPosition(0, 0);

	font.loadFromFile("images/contm.ttf");

	play.SetName("PLAY");
	play.SetPosition(550, 200);
	play.SetScale(1, 1);
	play.SetFont(font);

	quit.SetName("QUIT");
	quit.SetFont(font);
	quit.SetScale(1,1);
	quit.SetPosition(550, 400);

	credits.SetName("CREDITS");
	credits.SetFont(font);
	credits.SetScale(1, 1);
	credits.SetPosition(530, 260);

	playerSelect.SetName("PLAYER SELECT");
	playerSelect.SetFont(font);
	playerSelect.SetScale(1, 1);
	playerSelect.SetPosition(480, 330);

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
	int i = 0;
	sf::Event events;

	game->window.pollEvent(events);

	int x = sf::Mouse::getPosition(game->window).x;
	int y = sf::Mouse::getPosition(game->window).y;

	float scale = 123 +( sin(clock()/1000) * 150);

	//Updates the buttons and calls the desired functions if they are clicked.
	if (play.CheckButton(game->window))
	{
		game->pushState(GAME_PLAY, new MainGame(game));
		game->setState(GAME_PLAY);
	}
	if (quit.CheckButton(game->window))
	{
		game->window.close();
	}
	if (credits.CheckButton(game->window))
	{
		std::cout << "Sorry I don't do anything" << std::endl;
	}
	if (playerSelect.CheckButton(game->window))
	{
		std::cout << "Sorry I don't do anything" << std::endl;
	}
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
	quit.Draw(game);
	play.Draw(game);
	credits.Draw(game);
	playerSelect.Draw(game);
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


