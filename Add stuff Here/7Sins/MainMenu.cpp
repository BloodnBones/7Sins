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
#include "SelectionMenu.h"
#include "CreditsMenu.h"


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

	backGround.setTexture(this->game->textureManager.getRef("gameBackGround"));
	backGround.setPosition(0, 0);
	backGround.setScale(0.8f, 0.9f);

	Logo.setTexture(this->game->textureManager.getRef("LogoAnim"));
	AnimatedLogo.setSprite(&Logo);
	AnimatedLogo.SetAnim(0, 8);
	AnimatedLogo.SetFrameRate(70);
	
	font.loadFromFile("images/Bad Coma.ttf");

	Logo.setPosition(350, 0);

	play.SetName("PLAY");
	play.SetPosition(500, 300);
	play.SetScale(2.0f, 2.0f);
	play.SetFont(font);

	_play.setString("PLAY");
	_play.setPosition(500, 300);
	_play.setScale(2.1f, 2.1f);
	_play.setFont(font);
	_play.setFillColor(sf::Color::Black);

	credits.SetName("CREDITS");
	credits.SetFont(font);
	credits.SetScale(2.0f, 2.0f);
	credits.SetPosition(435, 360);

	_credits.setString("CREDITS");
	_credits.setPosition(435, 360);
	_credits.setFont(font);
	_credits.setScale(2.1f, 2.1f);
	_credits.setFillColor(sf::Color::Black);

	quit.SetName("QUIT");
	quit.SetFont(font);
	quit.SetScale(2, 2);
	quit.SetPosition(500, 420);
	
	_quit.setString("QUIT");
	_quit.setPosition(500, 420);
	_quit.setScale(2.1f, 2.1f);
	_quit.setFont(font);
	_quit.setFillColor(sf::Color::Black);

	//playerSelect.SetName("PLAYER SELECT");
	//playerSelect.SetFont(font);
	//playerSelect.SetScale(1, 1);
	//playerSelect.SetPosition(480, 330);

}

/*
* @brief	:
* @param	:
* @return	:
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
* @brief	:
* @param	:
* @return	:
*/
void
MainMenu::update(const float dt)
{
	int i = 0;
	sf::Event events;

	game->window.pollEvent(events);

	int x = sf::Mouse::getPosition(game->window).x;
	int y = sf::Mouse::getPosition(game->window).y;

	float scale = (float)(123 + (sin(clock() / 1000) * 150));
	//animate logo

	AnimatedLogo.Animate();
	//Updates the buttons and calls the desired functions if they are clicked.
	if (play.CheckButton(game->window))
	{
		game->pushState(GAME_SELECT, new SelectionMenu(game));
		game->setState(GAME_SELECT);
	}
	if (quit.CheckButton(game->window))
	{
		game->window.close();
	}
	if (credits.CheckButton(game->window))
	{
		game->pushState(GAME_CREDITS, new CreditsMenu(game));
		game->setState(GAME_CREDITS);
	}
}

/*
* @brief	:
* @param	:
* @return	:
*/
void
MainMenu::draw()
{
	game->window.draw(backGround);
	AnimatedLogo.DrawSpriteAnim(game->window, AnimatedLogo.GetCurrentFrame(), 0, 500, 209);


	game->window.draw(_play);
	game->window.draw(_credits);
	game->window.draw(_quit);

	play.Draw(game);
	quit.Draw(game);
	credits.Draw(game);

	//playerSelect.Draw(game);
}

/*
* @brief	:
* @param	:
* @return	:
*/
void
MainMenu::startGame()
{
	game->pushState(GAME_PLAY, new MainGame(game));
	game->setState(GAME_PLAY);
}


