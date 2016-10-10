#include "MainWorld.h"


/*
* @brief
* @param
* @return
*/
MainWorld::MainWorld()
{
	m_gravity = b2Vec2(0.f, 9.8f);
	m_world = new b2World(m_gravity);

	m_Timestep = 1.0f / 180.0f;
	velocityIterations = 8;
	positionIterations = 3;

	res[0].img_background.loadFromFile("Assets/Sprites/Background.png");
}

/*
* @brief
* @param
* @return
*/
MainWorld::~MainWorld()
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
void MainWorld::Init()
{
}


// Get current world
/*
* @brief
* @param
* @return
*/
b2World * MainWorld::GetWorld()
{
	return m_world;
}

/*
* @brief
* @param
* @return
*/
float MainWorld::GeTimeStep()
{
	return m_Timestep;
}

/*
* @brief
* @param
* @return
*/
void MainWorld::SetTimeStep(float step)
{
	m_Timestep = step;
}

/*
* @brief
* @param
* @return
*/
int MainWorld::getVIterations() {
	return velocityIterations;
}

/*
* @brief
* @param
* @return
*/
int MainWorld::getPIterations() {
	return positionIterations;
}

/*
* @brief
* @param
* @return
*/
LevelResources &MainWorld::getRes(int index) {
	return res[index];
}