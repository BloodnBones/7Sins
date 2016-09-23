
#ifndef GAME_H
#define GAME_H
#include <vector>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "GameLevel.h"
#include "Menu.h"


// Represents the current state of the game
enum GameState {
	GAME_ACTIVE,
	GAME_MENU,
	GAME_WIN,
	GAME_PAUSE
};

// Initial size of the player paddle
const glm::vec2 PLAYER_SIZE(40, 50);
// Initial velocity of the player paddle
const GLfloat PLAYER_VELOCITY(500.0f);


// Game holds all game-related state and functionality.
// Combines all game-related data into a single class for
// easy access to each of the components and manageability.
class GameScene
{
public:
	// Game state
	GameState					State;
	GLboolean					Keys[1024];
	GLuint						Width, Height;
	std::vector<GameLevel>		Levels;
	GLuint						Level;
	std::vector<GameObject *>	PhysicsObjects;
	std::map<std::string, Menu> Menus;
	// Constructor/Destructor
	GameScene(GLuint width, GLuint height);
	~GameScene();
	// Initialize game state (load all shaders/textures/levels)
	void Init();
	// GameLoop
	void ProcessInput(GLfloat dt);
	void Update(GLfloat dt);
	void Render();
	
};

#endif