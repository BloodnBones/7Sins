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
	sf::Image EnemySprite;
	b2World *_World;
	PhysicsBody Floor[1];
	std::vector<PhysicsBody> Obstacles;
	GameObject * m_currentGameObject;
	std::vector<PhysicsBody *> m_bodies;
	std::vector<GameObject *> Enemies;
	GameObject * GameObjectList[3];

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
	void SetObstacles();
	void SetEnemies();
	void draw();
	void update();
	void SetObstacleSprites();
	void AddSceneBodies();
	void GameOver();
	void SetWorld(b2World * aworld);
	bool isWon = false;
	bool isLost = false;
	void PreSolve(b2Contact* contact, const b2Manifold*);
	void PostSolve(b2Contact* contact, const b2ContactImpulse* impulse);
	bool ShouldCollide(b2Fixture* fixtureA, b2Fixture* fixtureB) {
		PhysicsBody* bodyDataA = static_cast<PhysicsBody*>(fixtureA->GetBody()->GetUserData());
		PhysicsBody* bodyDataB = static_cast<PhysicsBody*>(fixtureB->GetBody()->GetUserData());
		return (true);
		
	}
	int getLevel();
};

#endif