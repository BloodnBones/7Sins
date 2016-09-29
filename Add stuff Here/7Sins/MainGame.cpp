#include "MainGame.h"


/*
* @brief
* @param
* @return
*/
MainGame::MainGame(Game* game)
{
	this->game = game;
	sf::Vector2f pos = sf::Vector2f(this->game->window.getSize());
	this->hudView.setSize(pos);
	this->gameView.setSize(pos);
	pos *= 0.5f;
	this->hudView.setCenter(pos);
	this->gameView.setCenter(pos);

	_Background.setTexture(this->game->textureManager.getRef("gameBackGround"));
	_Background.setPosition(0, 0);
	_Background.setScale(sf::Vector2f(0.75f, 0.8f));

	m_World = new b2World(Gravity);									//Start the physics world

}

/*
* @brief
* @param
* @return
*/
void
MainGame::draw(const float dt)
{

	game->window.draw(_Background);

}

/*
* @brief
* @param
* @return
*/
void
MainGame::update(const float dt)
{
	m_World->Step(StepRate, velIterations, posIterations);
}

/*
* @brief
* @param
* @return
*/
void
MainGame::handleInput()
{
	sf::Event event;

	while (this->game->window.pollEvent(event))
	{
		switch (event.type)
		{
			case sf::Event::Closed:
				game->window.close();
				break;
					
			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Escape)
				{
					PauseGame();
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
MainGame::PauseGame()
{

}