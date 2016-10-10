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

	//_Background.setTexture(this->game->textureManager.getRef("gameBackGround"));
	//_Background.setPosition(0, 0);
	//_Background.setScale(sf::Vector2f(0.75f, 0.8f));

	//level settings
	m_world = new PhysicsWorld();
	GameObject1 = new GameObject(m_world->GetWorld(), this->game->textureManager.getRef("WrathIdle"), BodyType::Player, this->game, 0);
	GameObject2 = new GameObject(m_world->GetWorld(), this->game->textureManager.getRef("IdleNinja"), BodyType::Player, this->game, 1);

	GameObjectList.push_back(GameObject1);
	GameObjectList.push_back(GameObject2);							//Start the physics world

	CurrentLevel =  new Scene(m_world->GetWorld(), GameObjectList, this->game->textureManager.getRef("gameBackGround"), lvlindex, this->game);

}

/*
* @brief
* @param
* @return
*/
void
MainGame::draw()
{

	//game->window.draw(_Background);
	CurrentLevel->draw();
}

/*
* @brief
* @param
* @return
*/
void
MainGame::update(const float dt)
{
	m_world->GetWorld()->Step(StepRate, velIterations, posIterations);
	CurrentLevel->update();
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
	CurrentLevel->input(event);

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