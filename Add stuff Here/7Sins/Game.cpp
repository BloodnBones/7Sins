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
			,	gabriel.mugadza
			,	mun.houyong
			,	dylan.ridgeway
*/

#include "Game.h"
#include "GameState.h"

/*
* @brief
* @param
* @return
*/
Game::Game()
{
	loadTextures();
	window.create(sf::VideoMode(1200, 600), "Game", sf::Style::Close);
	window.setFramerateLimit(60);
	m_CurrentState = GAME_MENU;
}

/*
* @brief
* @param
* @return
*/
Game::~Game()
{
	if (!m_states.empty())
	{
		popState();
	}
	m_states.clear();
}

/*
* @brief	:Load the games textures into the texture manager.
* @param	:None
* @return	:None
*/
void
Game::loadTextures()
{
	textureManager.loadTexture("startPrompt", "images//startPrompt.png");
	textureManager.loadTexture("gameBackGround", "images//Background.png");
	textureManager.loadTexture("Lava", "images//Lava_00.png");
	textureManager.loadTexture("TileTop", "images//Tile1.png");
	textureManager.loadTexture("TileBelow", "images//Tile2.png");
	textureManager.loadTexture("IdleNinja", "images//Idle__000.png");
}

/*
* @brief
* @param
* @return
*/
void
Game::pushState(State statevalue, GameState* state)
{
	m_states.insert(std::pair<State, GameState*>( statevalue, state));
}

/*
* @brief	:Deletes the pointers within in the game map on game destruction
* @param	:None
* @return	:None
*/
void
Game::popState()
{
	for (std::map<State, GameState*>::iterator it = m_states.begin(); it != m_states.end(); ++it)
	{
		delete it->second;
	}
}

/*
* @brief	:returns the pointer to the current state to be used
* @param	:The key value to find the game state
* @return	:Pointer to the current game state
*/
GameState*
Game::currentState(State statevalue)
{
	if (m_states.empty())
	{
		return nullptr;
	}
	else
	{
		return m_states[statevalue];
	}
}

/*
* @brief	:Loops will Window is open Calls to correct state for input, draw and update.
* @param	:None
* @return	:None
*/
void
Game::gameLoop()
{
	sf::Clock clock;
	float frameRate = 0;
	while (window.isOpen())
	{
		sf::Time timeElapsed = clock.restart();
		float timeDelta = timeElapsed.asSeconds();

		GameState* Scene;

		//Switch what scene pointed to based on game state
		switch (m_CurrentState)
		{
		case GAME_PLAY:
		{
			Scene = currentState(GAME_PLAY);
		}break;
		case GAME_MENU:
		{
			Scene = currentState(GAME_MENU);
		}break;
		case GAME_PAUSE:
		{
			Scene = currentState(GAME_PAUSE);
		}break;
		case GAME_OVER:
		{
			Scene = currentState(GAME_OVER);
		}break;
		case GAME_SELECT:
		{
			Scene = currentState(GAME_SELECT);
		}break;
		default:
		{
			continue;	//Exit game if no states exist
		}
		}
		
		if (frameRate > StepRate)				//Regulate update rate to that of physics world
		{
			Scene->handleInput();
			Scene->update(timeDelta);

			window.clear();

			Scene->draw();

			window.display();
			frameRate = 0;						//Reset time since last sweep
		}
		frameRate += timeDelta;
	}
}

/*
* @brief	:Sets the enum vaule representing the state of the game
* @param	:New value of the enum
* @return	:None
*/
void
Game::setState(State newState)
{
	m_CurrentState = newState;
}