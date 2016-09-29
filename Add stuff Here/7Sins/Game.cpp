#include "Game.h"
#include "GameState.h"

#include <SFML\Graphics.hpp>

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
* @brief
* @param
* @return
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
* @brief	Deletes the pointer within in the game map on game destruction
* @param	None
* @return	None
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
* @brief	returns the pointer to the current state to be used
* @param	The keyb value to find the game state
* @return	Pointer to the current game state
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
* @brief	Loops will Window is open Calls to correct state for input, draw and update.
* @param	None
* @return	None
*/
void
Game::gameLoop()
{
	sf::Clock clock;

	while (window.isOpen())
	{
		sf::Time timeElapsed = clock.restart();
		float timeDelta = timeElapsed.asSeconds();

		GameState* Scene;

		/*if (currentState() == nullptr)
		{
			continue;
		}*/
		//Switch what scene point to based on game state
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
		default:
		{
			continue;
		}
		}

		Scene->handleInput();
		Scene->update(timeDelta);

		window.clear();

		Scene->draw(timeDelta);

		window.display();
	}
}

/*
* @brief	Sets the enum vaule representing the state of the game
* @param	New value of the enum
* @return	None
*/
void
Game::setState(State newState)
{
	m_CurrentState = newState;
}