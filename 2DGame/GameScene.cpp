#include "GameScene.h"
#include "Utils.h"
#include "SpriteRenderer.h"
#include "GameObject.h"
#include "Menu.h"


// Game-related State data
SpriteRenderer  *Renderer;
GameObject      *Player;
TextLabel		*Test;

/*
* @brief
* @param
* @return
*/
GameScene::GameScene(GLuint width, GLuint height)
	: State(GAME_ACTIVE), Keys(), Width(width), Height(height)
{

}

/*
* @brief
* @param
* @return
*/
GameScene::~GameScene()
{
	delete Renderer;
	delete Player;
}

/*
* @brief
* @param
* @return
*/
void GameScene::Init()
{

	// Load shaders
	Utils::LoadShader("Shaders/SpriteVertex.vs", "Shaders/SpriteFragment.fs", nullptr, "sprite");
	// Configure shaders
	glm::mat4 projection = glm::ortho(0.0f, static_cast<GLfloat>(this->Width), static_cast<GLfloat>(this->Height), 0.0f, -1.0f, 1.0f);
	Utils::GetShader("sprite").Use().SetInteger("sprite", 0);
	Utils::GetShader("sprite").SetMatrix4("projection", projection);
	// Load textures
	Utils::LoadTexture("Assets/Art/Background.png", GL_FALSE, "background");
	Utils::LoadTexture("Assets/Art/Idle_000.png", GL_TRUE, "face");
	Utils::LoadTexture("Assets/Art/Tile1.png", GL_FALSE, "block");
	Utils::LoadTexture("Assets/Art/Lava_00.png", GL_FALSE, "block_solid");
	Utils::LoadTexture("Assets/Art/Idle__000.png", true, "paddle");
	// Set render-specific controls
	Renderer = new SpriteRenderer(Utils::GetShader("sprite"));
	// Load levels
	GameLevel one; one.Load("Assets/TileMaps/TileMap.lvl", this->Width, this->Height * 0.5);
	this->Levels.push_back(one);
	this->Level = 0;
	for (size_t i = 0; i < one.Bricks.size() -1; i++)
	{
		PhysicsObjects.push_back(&one.Bricks[i]);
	}

	// Configure game objects
	glm::vec2 playerPos = glm::vec2(this->Width / 2 - PLAYER_SIZE.x / 2, this->Height - PLAYER_SIZE.y);
	Player = new GameObject(playerPos, PLAYER_SIZE, Utils::GetTexture("paddle"));
	
	PhysicsObjects.push_back(Player);

	std::vector<std::string> Choices;
	Choices.push_back("Hello");

	Menu Start;
	Start.Init(Width, Height, "Assets/Fonts/arial.ttf", Choices, COL_MIDDLE, ROW_MIDDLE, glm::vec3(1.0f, 1.0f, 1.0f));
	Menus.insert(std::pair<std::string, Menu>("Start", Start));

	Test = new TextLabel("Testing", "Assets/Fonts/arial.ttf");
	Test->setColor(glm::vec3(1.0f, 1.0f, 1.0f));
	Test->setPosition(glm::vec2(30.0f, 320.0f));
}

/*
* @brief
* @param
* @return
*/
void GameScene::Update(GLfloat dt)
{
}

/*
* @brief	Checks for input and call the correct functions in response
* @param	GLfloat of delta time
* @return	None
*/
void GameScene::ProcessInput(GLfloat dt)
{
	//Respond to input based on game state
	switch (this->State)
	{
	case  GAME_ACTIVE:
	{

		GLfloat velocity = PLAYER_VELOCITY * dt;
		// Move playerboard
		if (this->Keys[GLFW_KEY_A])
		{
			if (Player->Position.x >= 0)
				Player->Position.x -= velocity;
		}
		if (this->Keys[GLFW_KEY_D])
		{
			if (Player->Position.x <= this->Width - Player->Size.x)
				Player->Position.x += velocity;
		}
		if (this->Keys[GLFW_KEY_W])
		{
			if (Player->Position.y >= 0)
				Player->Position.y -= velocity;
		}
		if (this->Keys[GLFW_KEY_S])
		{
			if (Player->Position.y <= this->Height - Player->Size.y)
				Player->Position.y += velocity;
		}
		if (this->Keys[GLFW_KEY_ESCAPE])
		{
			State = GAME_PAUSE;
		}
	}break;

	case GAME_MENU:
	{
		if (this->Keys[GLFW_KEY_S])
		{
			State = GAME_ACTIVE;
		}
	}break;

	case GAME_WIN:
	{

	}break;

	case GAME_PAUSE:
	{

	}break;
	}
}

/*
* @brief	Calls the render functions for each element in current game state
* @param	None
* @return	None
*/
void GameScene::Render()
{	//Switch based on game state to render correct scene
	switch (this->State)
	{
		//Render game active objects
	case  GAME_ACTIVE:
	{
		// Draw background
		Renderer->DrawSprite(Utils::GetTexture("background"), glm::vec2(0, 0), glm::vec2(this->Width, this->Height), 0.0f);
		// Draw level
		this->Levels[this->Level].Draw(*Renderer);
		// Draw player
		Player->Draw(*Renderer);		
	}break;

	//Render menu objects
	case GAME_MENU:
	{
		Menus["Start"].Draw();
	}break;

	case GAME_WIN:
	{

	}break;

	case GAME_PAUSE:
	{

	}break;
	}

}