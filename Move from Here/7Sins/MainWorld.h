#ifndef MAINWORLD_H
#define MAINWORLD_H

#include "Dependencies\Include\Box2D\Box2D.h"
#include "Dependencies\Include\SFML\Graphics.hpp"  

enum BodyType
{
	Player,
	ObstacleV,
	ObstacleH,
	ObstacleS,
	Ground,
	Enemy
};


//world object
struct PhysicsBody {
	b2BodyDef _BodyDef;
	b2PolygonShape _BodyShape;
	b2FixtureDef _FixtureDef;
	b2Body * _BodyPtr;
	sf::RectangleShape _RECT;
	sf::Texture Image;
	BodyType type;
	b2Vec2 velocity;
	bool isDead;
	float HP = 100;
};

struct LevelResources {
	sf::Image img_background;
	sf::Image img_player;
};

class MainWorld
{
public:
	MainWorld();
	~MainWorld();
	// setup box2d world
	void Init();
	// Get current world
	b2World * GetWorld();
	float GeTimeStep();
	int getVIterations();
	int getPIterations();
	LevelResources &getRes(int index); //return res[index]
	void SetTimeStep(float step);
private:
	LevelResources res[1]; 
	b2World *m_world;
	b2Vec2 m_gravity;
	float m_Timestep;
	int velocityIterations;
	int positionIterations;
};

#endif