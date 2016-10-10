#include "PhysicsWorld.h"


/*
* @brief
* @param
* @return
*/
PhysicsWorld::PhysicsWorld()
{
	m_gravity = b2Vec2(0.f, 9.8f);
	m_world = new b2World(m_gravity);

	m_Timestep = 1.0f / 180.0f;
	velocityIterations = 8;
	positionIterations = 3;
}

/*
* @brief
* @param
* @return
*/
PhysicsWorld::~PhysicsWorld()
{
	m_world = NULL;
	delete m_world;
}


// setup box2d world
/*
* @brief
* @param
* @return
*/
void PhysicsWorld::Init()
{
}


// Get current world
/*
* @brief
* @param
* @return
*/
b2World * PhysicsWorld::GetWorld()
{
	return m_world;
}

/*
* @brief
* @param
* @return
*/
float PhysicsWorld::GeTimeStep()
{
	return m_Timestep;
}

/*
* @brief
* @param
* @return
*/
void PhysicsWorld::SetTimeStep(float step)
{
	m_Timestep = step;
}

/*
* @brief
* @param
* @return
*/
int PhysicsWorld::getVIterations() {
	return velocityIterations;
}

/*
* @brief
* @param
* @return
*/
int PhysicsWorld::getPIterations() {
	return positionIterations;
}
