/*
Bachelor of Software Engineering
Media Design School
Auckland
NewZealand

(c) 2005 - 2016 Media Design School

File Name	:	Utils.h
Description	:	Contains useful structs and global variables
Authors		:	Tyrone Mills, Gabriel Mugadza, Mun Hou Yong, Dylan Ridgeway
mail		:	tyrone.mill6438@mediadesign.school.nz
			,
			,
			,
*/

#pragma once
//pre-defined headers
#include <Box2D\Box2D.h>
//#include "include\Box2D\Box2D.h"
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
	Enemy,
	FallingObject
};

//world object
struct PhysicsBody {

	PhysicsBody() {

	};


	b2BodyDef _BodyDef;
	b2PolygonShape _BodyShape;
	b2FixtureDef _FixtureDef;
	b2Body * _BodyPtr;
	sf::RectangleShape _RECT;
	sf::Texture Image;
	BodyType type;
	b2Vec2 velocity;
	bool Touching;
	float HP = 100;
};

enum Character
{
	Lucia	= 1,
	Gabriel = 2,
	Joshua	= 3,
	Betty	= 4,
	Matthew	= 5,
	Satella = 6,
	Honda	= 7,
	NONE	= 0
};

//returns 0 if greater and 1 if less
template <typename T> int sgn(T val) {
	return (T(0) < val) - (val < T(0));
}