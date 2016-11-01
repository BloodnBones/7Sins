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
#include "GameOver.h"


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
	GameObject1 = new GameObject(m_world->GetWorld(), this->game->textureManager.getRef("Wrath"), BodyType::Player, this->game, 0);
	GameObject2 = new GameObject(m_world->GetWorld(), this->game->textureManager.getRef("IdleNinja"), BodyType::Player, this->game, 1);

	GameObjectList.push_back(GameObject1);
	GameObjectList.push_back(GameObject2);							//Start the physics world

	CurrentLevel =  new Scene(m_world->GetWorld(), GameObjectList, this->game->textureManager.getRef("AnimBackGround"), lvlindex, this->game);

}

/*
* @brief	:Contructor that takes int the players choices for charcter
* @param	:Game Pointer
* @param	:Enum value of player 1's character choice
* @param	:Enum value of player 2's character choice
* @param	:Enum value of player 3's character choice
* @param	:Enum value of player 4's character choice
* @return	:
*/
MainGame::MainGame(Game* game, int Player1, int Player2, int Player3, int Player4)
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
	if (Player1 != NONE)
	{
		GameObject1 = new GameObject(m_world->GetWorld(), Player1, BodyType::Player, this->game, 0);
		GameObjectList.push_back(GameObject1);
	}
	if (Player2 != NONE)
	{
		GameObject2 = new GameObject(m_world->GetWorld(), Player2, BodyType::Player, this->game, 1);
		GameObjectList.push_back(GameObject2);
	}
	if (Player3 != NONE)
	{
		GameObject3 = new GameObject(m_world->GetWorld(), Player3, BodyType::Player, this->game, 2);
		GameObjectList.push_back(GameObject3);
	}
	if (Player4 != NONE)
	{
		GameObject4 = new GameObject(m_world->GetWorld(), Player4, BodyType::Player, this->game, 3);
		GameObjectList.push_back(GameObject4);
	}


						//Start the physics world
	if (CurrentLevel != nullptr)
	{
		delete CurrentLevel;
	}
	CurrentLevel = new Scene(m_world->GetWorld(), GameObjectList, this->game->textureManager.getRef("AnimBackGround"), lvlindex, this->game);

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

	if (CurrentLevel->isWon)
	{
		if (gameOverDelay < 0)
		{
			game->pushState(GAME_OVER, new GameOver(game));
			game->setState(GAME_OVER);
		}
		
		std::cout << gameOverDelay << endl;
		gameOverDelay -= dt * 1000;
	}


	CurrentLevel->update(dt);
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
			{
				if (event.key.code == sf::Keyboard::Escape)
				{
					PauseGame();
				}
				if (event.key.code == sf::Keyboard::F)
				{
					game->pushState(GAME_OVER, new GameOver(game));
					game->setState(GAME_OVER);
				}
			}break;
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