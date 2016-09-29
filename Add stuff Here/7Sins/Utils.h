#pragma once
//pre-defined headers
#include "include\Box2D\Box2D.h"
#include "SFML/Graphics.hpp"
#include "TextureManager.h"
#include <SFML/Audio.hpp>

static const int SCREEN_WIDTH = 1024;
static const int SCREEN_HEIGHT = 768;
static const int SCREEN_BPP = 32;
static const int gameTime = 10;
static const int RATIO = 30;
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