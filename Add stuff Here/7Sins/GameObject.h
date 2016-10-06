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

#ifndef GameObject_H
#define GameObject_H

#include "Utils.h"
#include "include\Box2D\Box2D.h"
#include "include\SFML\System.hpp"
#include "include\SFML\Window.hpp"
#include <cstdio>
#include <cmath>
#include <math.h>
#include <iostream>


#include "PhysicsWorld.h"
#include "QueryCallback.h"
#include "Game.h"
using namespace std;

class GameObject
{
private:
	
	PhysicsBody m_body;			//Struct of objects physics body settings
	PhysicsBody m_Mouse;
	BodyType m_type;
	Character m_Character;

	b2World *m_world;
	b2BodyDef bodyDef;
	b2Body* groundBody;			//Pointer to objects physics world body

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
	Game * currentGame;
	bool isGrounded = false;

	float MAX_VELOCITY = 7.0f;
	float stillTime = 0;
	sf::Clock deltaClock;
	sf::Time deltaTime = deltaClock.restart();

	//multiplayer things
	int PlayerIndex;  //player 1,2 etc...


public:
	GameObject(b2World *aWorld, sf::Texture& image, BodyType type, Game *gameptr, int Index);
	GameObject::GameObject(b2World *aWorld, Character character, BodyType type, Game *gameptr, int Index);
	GameObject(b2World *aWorld, sf::Texture &image, BodyType type, float xpos, float ypos);
	~GameObject();
	void Init(b2World & world);
	void SetPhysicsBox();
	void input(sf::Event events);
	void draw();
	void SetPosition(float x, float y);
	void update();
	void setImpulse(float x, float y);
	void Shoot(float x, float y);
	void Player1Input();
	void Player2Input();
	void SetPlayerIndex(int Index);
	void LoadCharacterImage(Character character);
	PhysicsBody * getBody();

	bool	canKill;
	float	KillTime = 2;
};

#endif