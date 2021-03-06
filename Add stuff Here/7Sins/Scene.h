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

#ifndef SCENE_H
#define SCENE_H

#include <vector>

#include "Utils.h"

#include "PhysicsWorld.h"
#include "GameObject.h"
#include "Game.h"

class Scene : public b2ContactListener, b2ContactFilter {
private:
	sf::Texture BackgroundTex;
	sf::RectangleShape _Background;
	std::vector<sf::Image> ObstacleSprites;

	sf::Image m_FallingObjectSprite;

	sf::Image EnemySprite;
	sf::Sprite backGround;
	b2World *_World;
	PhysicsBody Floor[1];
	std::vector<PhysicsBody> Obstacles;
	std::vector<PhysicsBody*> m_FallingObjects;
	std::vector<PhysicsBody*> m_DeadObjects;
	GameObject * m_currentGameObject;
	std::vector<PhysicsBody *> m_bodies;
	std::vector<GameObject *> Enemies;
	std::vector<GameObject *> GameObjectList;
	Animation AnimatedBack;
	int LevelIndex;
	
	sf::Text GameObjectsLeft;
	sf::Text ScoreTitle;
	sf::Text GameObjectsTitle;
	sf::Text Score;
	sf::Text GameOverText;
	sf::Text GameOverText2;
	sf::Text GameOverText3;
	sf::Font font;

	sf::Clock timer;
	bool KFC = false;
	

	int f_Score = 0;
	int f_GameObjectsLeft = 0;
	int numofobstacles = 3;

	Game * currentGame;
public:

	Scene();
	Scene(std::vector<GameObject *> GameObjects, sf::Image &image);
	Scene(b2World *aWorld, std::vector<GameObject *> Players, sf::Texture &image, int Level, Game *gameptr);
	~Scene();
	void input(sf::Event events);
	void SetFloor();
	void HorizontalBorder(PhysicsBody & body, float _xpos, float ypos, float origin_x, float origin_y, sf::Color fill);
	void HorizontalObstacle(PhysicsBody & body, float _xpos, float ypos, float origin_x, float origin_y, int SpriteIndex);
	void VerticleObstacle(PhysicsBody & body, float _xpos, float ypos, float origin_x, float origin_y, int SpriteIndex);

	void AddFallingObject();

	void SetObstacles();
	void SetEnemies();
	void draw();
	void update(float dt);
	void SetObstacleSprites();
	void AddSceneBodies();
	void GameOver();
	void SetWorld(b2World * aworld);
	bool isWon = false;
	bool isLost = false;
	
	//collision 
	void PreSolve(b2Contact* contact, const b2Manifold*);
	void PostSolve(b2Contact* contact, const b2ContactImpulse* impulse);
	bool ShouldCollide(b2Fixture* fixtureA, b2Fixture* fixtureB) {
		PhysicsBody* bodyDataA = static_cast<PhysicsBody*>(fixtureA->GetBody()->GetUserData());
		PhysicsBody* bodyDataB = static_cast<PhysicsBody*>(fixtureB->GetBody()->GetUserData());
		return (true);
	}
	void BeginContact(b2Contact * contact);
	void EndContact(b2Contact * contact);
	int getLevel();
};

#endif