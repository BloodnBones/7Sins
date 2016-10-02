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
*/

#ifndef PHYSICSWORLD_H
#define PHYSICSWORLD_H

#include "include\Box2D\Box2D.h"
#include "include\SFML\Graphics.hpp"



class PhysicsWorld
{
public:
	PhysicsWorld();
	~PhysicsWorld();
	// setup box2d world
	void Init();
	// Get current world
	b2World * GetWorld();
	float GeTimeStep();
	int getVIterations();
	int getPIterations();
	void SetTimeStep(float step);
private:
	b2World *m_world;
	b2Vec2 m_gravity;
	float m_Timestep;
	int velocityIterations;
	int positionIterations;
};

#endif