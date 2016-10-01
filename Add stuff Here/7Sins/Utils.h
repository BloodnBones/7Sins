#pragma once
//pre-defined headers
#include "include\Box2D\Box2D.h"
#include "include\SFML\Graphics.hpp"
#include "TextureManager.h"
#include "include\SFML\Audio.hpp"

static const int SCREEN_WIDTH = 1024;
static const int SCREEN_HEIGHT = 768;
static const int SCREEN_BPP = 32;
static const int gameTime = 10;
static const int RATIO = 30;
static const b2Vec2 Gravity(0.f, 9.8f);
static const float StepRate = 1 / 60.0f;
static const int velIterations = 8;
static const int posIterations = 5;
#define UNRATIO (1.0F/RATIO)
//extern sf::RenderWindow window;

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