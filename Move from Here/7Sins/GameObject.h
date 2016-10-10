#ifndef GameObject_H
#define GameObject_H

#include "Globals.h"
#include "Dependencies\Include\Box2D\Box2D.h"
#include "Dependencies\Include\SFML\System.hpp"
#include "Dependencies\Include\SFML\Window.hpp"
#include <cstdio>
#include <iostream>
#include "MainWorld.h"
#include "QueryCallback.h"
using namespace std;

class GameObject
{
private:
	
	PhysicsBody m_body;
	PhysicsBody m_Mouse;
	BodyType m_type;

	b2World *m_world;
	b2BodyDef bodyDef;
	b2Body* groundBody;

	float xpos;
	float ypos;
	float origin_x;
	float origin_y;
	float offset;
	float p1x;
	float p1y;

	sf::Color fill;
	sf::Texture sprite;

	sf::Clock timer;
	bool canJump;
	float jumpTimer = 3;
	
public:
	GameObject(b2World *aWorld, sf::Image &image, BodyType type);
	GameObject(b2World *aWorld, sf::Image &image, BodyType type, float xpos, float ypos);
	~GameObject();
	void Init(b2World & world);
	void SetPhysicsBox();
	void input(sf::Event events);
	void draw();
	void SetPosition(float x, float y);
	void update();
	void setImpulse(float x, float y);
	void Shoot(float x, float y);
	PhysicsBody * getBody();

	bool	canKill;
	float	KillTime = 2;
};

#endif