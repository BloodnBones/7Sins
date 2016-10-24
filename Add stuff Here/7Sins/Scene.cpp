/*
Bachelor of Software Engineering
Media Design School
Auckland
NewZealand

(c) 2005 - 2016 Media Design School

File Name	:
Description	:
Authors		:	Tyrone Mills, Gabriel Mugadza, Mun Hou Yong, Dylan Ridgway
mail		:	tyrone.mill6438@mediadesign.school.nz
			,	dylan.rid6275@mediadesign.school.nz
			,
			,
*/

#include "Scene.h"

/*
* @brief	:Scene Constructor for creation of empty scene objects
* @return	:Scene
*/
Scene::Scene()
{
}

/*
* @brief	:Scene construnctor for test purposes(dont need to use anymore)
* @param	:Vector<GameObjects *> objects - Populates the characters ingame
* @param	:sf::Image image - Sets Background
* @return	:Scene
*/
Scene::Scene(std::vector<GameObject*> GameObjects, sf::Image & image)
{

	for (size_t i = 0; i < GameObjects.size(); i++)
	{
		
		GameObjectList.push_back(GameObjects[i]);
	}
	f_GameObjectsLeft = GameObjects.size();
	BackgroundTex.loadFromImage(image);
	_Background = sf::RectangleShape(sf::Vector2f((float)BackgroundTex.getSize().x, (float)BackgroundTex.getSize().y));
	_Background.setTexture(&BackgroundTex);

	backGround.setTexture(BackgroundTex);
	backGround.setScale(5, 5);
	AnimatedBack.setSprite(&backGround);
	AnimatedBack.SetAnim(0, 8);
	AnimatedBack.SetFrameRate(70);
	SetFloor();
	SetObstacleSprites();
	SetObstacles();
	AddSceneBodies();
	font.loadFromFile("images/contm.ttf");

	// GameObjects Text
	GameObjectsTitle.setFont(font);
	GameObjectsTitle.setCharacterSize(50);
	GameObjectsTitle.setFillColor(sf::Color::Red);
	GameObjectsTitle.setPosition(sf::Vector2f(45, 00));
	GameObjectsTitle.setString("GameObjects Left");

	GameObjectsLeft.setFont(font);
	GameObjectsLeft.setCharacterSize(50);
	GameObjectsLeft.setFillColor(sf::Color::Red);
	GameObjectsLeft.setPosition(sf::Vector2f(50, 50));

	//Score Text
	ScoreTitle.setFont(font);
	ScoreTitle.setCharacterSize(50);
	ScoreTitle.setFillColor(sf::Color::Red);
	ScoreTitle.setPosition(sf::Vector2f(795, 00));
	ScoreTitle.setString("Score ");

	Score.setFont(font);
	Score.setCharacterSize(50);
	Score.setFillColor(sf::Color::Red);
	Score.setPosition(sf::Vector2f(800, 50));

	m_FallingObjectSprite.loadFromFile("images/FallingObject.png");

	timer.restart();
}

/*
* @brief	:Scene construnctor (use this one)
* @param	:Vector<GameObjects *> objects - Populates the characters ingame
* @param	:sf::Image image - Sets Background
* @param	:int level - Sets the level index (we can set different values for multiple levels)
* @param	:Game * gameptr - Sets the current gamestate
* @return	:Scene
*/
Scene::Scene(b2World * aWorld, std::vector<GameObject *> Players, sf::Texture & image, int Level, Game *gameptr)
{
	currentGame = gameptr;
	LevelIndex = Level;
	_World = aWorld;
	_World->SetContactListener(this);
	_World->SetContactFilter(this);
	for (size_t i = 0; i < Players.size(); i++)
	{
		GameObjectList.push_back(Players[i]);
	}
	f_GameObjectsLeft = Players.size();
	BackgroundTex = image;
	_Background = sf::RectangleShape(sf::Vector2f((float)BackgroundTex.getSize().x, (float)BackgroundTex.getSize().y));
	_Background.setTexture(&BackgroundTex);

	backGround.setTexture(BackgroundTex);
	backGround.setScale(2, 2);
	AnimatedBack.setSprite(&backGround);
	AnimatedBack.SetAnim(0, 8);
	AnimatedBack.SetFrameRate(70);
	SetFloor();
	SetObstacleSprites();
	SetObstacles();
	AddSceneBodies();
	font.loadFromFile("images/contm.ttf");

	// GameObjects Text
	GameObjectsTitle.setFont(font);
	GameObjectsTitle.setCharacterSize(40);
	GameObjectsTitle.setFillColor(sf::Color::Red);
	GameObjectsTitle.setPosition(sf::Vector2f(45, 00));
	GameObjectsTitle.setString("Players Left");

	GameObjectsLeft.setFont(font);
	GameObjectsLeft.setCharacterSize(40);
	GameObjectsLeft.setFillColor(sf::Color::Red);
	GameObjectsLeft.setPosition(sf::Vector2f(50, 50));

	//Score Text
	ScoreTitle.setFont(font);
	ScoreTitle.setCharacterSize(40);
	ScoreTitle.setFillColor(sf::Color::Red);
	ScoreTitle.setPosition(sf::Vector2f(795, 00));
	ScoreTitle.setString(" ");

	Score.setFont(font);
	Score.setCharacterSize(50);
	Score.setFillColor(sf::Color::Red);
	Score.setPosition(sf::Vector2f(800, 50));

	GameOverText.setFont(font);
	GameOverText.setCharacterSize(75);
	GameOverText.setFillColor(sf::Color::Red);
	GameOverText.setPosition(sf::Vector2f(300, 50));

	GameOverText2.setFont(font);
	GameOverText2.setCharacterSize(50);
	GameOverText2.setFillColor(sf::Color::Red);
	GameOverText2.setPosition(sf::Vector2f(250, 150));

	GameOverText3.setFont(font);
	GameOverText3.setCharacterSize(50);
	GameOverText3.setFillColor(sf::Color::Red);
	GameOverText3.setPosition(sf::Vector2f(250, 250));

	m_FallingObjectSprite.loadFromFile("images/FallingObject.png");


	timer.restart();
	//std::cout << LevelIndex << endl;
}

/*
* @brief	:Scene destructor(needs to kill all pointers and clear all vectors)
* @param	:
* @return	:
*/
Scene::~Scene()
{
	Obstacles.clear();
}

/*
* @brief	:Scene input handler
* @param	:sf::Event events - sfml event handler
* @return	:void
*/
void Scene::input(sf::Event events)
{
	for (size_t i = 0; i < GameObjectList.size(); i++)
	{
		GameObjectList[i]->input(events);
	}

	switch (events.type) {
	case sf::Event::KeyPressed:
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
			if (isLost)
			{
				isWon = true;
				printf("Reset");
			}
		}
		break;
	}
}

/*
* @brief	:Sets the ground object(aka Lava)
* @return	:void
*/
void Scene::SetFloor()
{
	//floor
	HorizontalBorder(Floor[0], (float)450, (float)730, (float)50000, (float)50,
		sf::Color::Black);
}

/*
* @brief	:Sets a Horizontal static body
* @param	:PhysicsBody &body - the body thats going to be used
* @param	:float _xpos - the x position box2d
* @param	:float  ypos - the y position box2d
* @param	:float origin_x - the center position of the shape box2d & sfml
* @param	:float origin_y - the center position of the shape box2d & sfml
* @param	:sf::Color fill - the colour of the object (to be later changed to be lava)
* @return	:void
*/
void Scene::HorizontalBorder(PhysicsBody & body, float _xpos, float ypos, float origin_x, float origin_y, sf::Color fill)
{
	body._BodyDef.position.Set(_xpos / RATIO, ypos / RATIO);
	body._BodyDef.type = b2_staticBody;
	body._RECT = sf::RectangleShape(sf::Vector2f(origin_x * 6, origin_y));
	body._RECT.setOrigin(origin_x, origin_y / 6);
	body._RECT.setFillColor(fill);
	body._BodyShape.SetAsBox(origin_x / RATIO, (origin_y / 6) / RATIO);
	body._FixtureDef.shape = &body._BodyShape;
	body._FixtureDef.density = 10.0f;
	body._FixtureDef.friction = 1.0f;
	body._BodyPtr = _World->CreateBody(&body._BodyDef);
	body._BodyPtr->CreateFixture(&body._FixtureDef);
	body._BodyPtr->SetUserData(&body);
	//set position
	body._RECT.setPosition(body._BodyPtr->GetPosition().x*RATIO, body._BodyPtr->GetPosition().y*RATIO);
	body.type = Ground;
}

/*
* @brief	:Sets a Horizontal Tile body
* @param	:PhysicsBody &body - the body thats going to be used
* @param	:float _xpos - the x position box2d
* @param	:float  ypos - the y position box2d
* @param	:float origin_x - the center position of the shape box2d & sfml
* @param	:float origin_y - the center position of the shape box2d & sfml
* @param	:int SpriteIndex - Sets the sprite based on the index (to be later changed to be texture manager)
* @return	:void
*/
void Scene::HorizontalObstacle(PhysicsBody & body, float _xpos, float ypos, float origin_x, float origin_y, int SpriteIndex)
{

	body.Image.loadFromImage(ObstacleSprites[SpriteIndex]);
	body._BodyDef.position.Set(_xpos / RATIO, ypos / RATIO);
	body._BodyDef.type = b2_staticBody;
	body._RECT = sf::RectangleShape(sf::Vector2f(origin_x * 2, origin_y));
	body._RECT.setOrigin(origin_x, origin_y / 2);
	body._RECT.setTexture(&body.Image);
	body._BodyShape.SetAsBox(origin_x / RATIO, (origin_y / 2) / RATIO);
	body._FixtureDef.shape = &body._BodyShape;
	body._FixtureDef.density = 5.0f;
	body._FixtureDef.friction = 1.5f;
	body._BodyPtr = _World->CreateBody(&body._BodyDef);
	body._BodyPtr->CreateFixture(&body._BodyShape, 1.0f);
	body._BodyPtr->SetUserData(&body);
	//set position
	body._RECT.setPosition(body._BodyPtr->GetPosition().x*RATIO, body._BodyPtr->GetPosition().y*RATIO);
	body.type = ObstacleH;
}

/*
* @brief	:to delete(obsolete)
* @return	:void
*/
void Scene::VerticleObstacle(PhysicsBody & body, float _xpos, float ypos, float origin_x, float origin_y, int SpriteIndex)
{
	body.Image.loadFromImage(ObstacleSprites[SpriteIndex]);
	body._BodyDef.position.Set(_xpos / RATIO, ypos / RATIO);
	body._BodyDef.type = b2_dynamicBody;
	body._RECT = sf::RectangleShape(sf::Vector2f(origin_x, origin_y * 2));
	body._RECT.setOrigin(origin_x / 2, origin_y);
	body._RECT.setTexture(&body.Image);
	body._BodyShape.SetAsBox((origin_x / 2) / RATIO, origin_y / RATIO);
	body._FixtureDef.shape = &body._BodyShape;
	body._FixtureDef.density = 5.0f;
	body._FixtureDef.friction = 0.5f;
	body._BodyPtr = _World->CreateBody(&body._BodyDef);
	body._BodyPtr->CreateFixture(&body._BodyShape, 1.0f);
	body._BodyPtr->SetUserData(&body);
	//set position
	body._RECT.setPosition(body._BodyPtr->GetPosition().x*RATIO, body._BodyPtr->GetPosition().y*RATIO);
	body.type = ObstacleV;
}

void Scene::AddFallingObject()
{
	PhysicsBody* body = new PhysicsBody();
	int randx = (rand() % SCREEN_WIDTH) + 10;
	int y = -10;

	float origin_x = 20.0f;
	float origin_y = 20.0f;


	body->_BodyDef.position.Set(randx / RATIO, y / RATIO);
	body->_BodyDef.type = b2_dynamicBody;
	body->_RECT = sf::RectangleShape(sf::Vector2f(origin_x, origin_y));
	body->_RECT.setOrigin(origin_x / 2, origin_y / 2);
	body->_RECT.setTexture(&currentGame->textureManager.getRef("FallingObject"));
	body->_BodyShape.SetAsBox((origin_x / 2) / RATIO, (origin_y / 2) / RATIO);
	body->_FixtureDef.shape = &body->_BodyShape;
	body->_FixtureDef.density = 5.0f;
	body->_FixtureDef.friction = 1.5f;
	body->type = BodyType::FallingObject;
	body->_BodyPtr = _World->CreateBody(&body->_BodyDef);
	body->_BodyPtr->CreateFixture(&body->_BodyShape, 1.0f);
	body->_BodyPtr->SetUserData(body);
	body->dead = false;
	//set position
	body->_RECT.setPosition(body->_BodyPtr->GetPosition().x*RATIO, body->_BodyPtr->GetPosition().y*RATIO);
	
	body->_BodyPtr->ApplyForceToCenter(b2Vec2(0, 180), true);

	m_FallingObjects.push_back(body);
}

/*
* @brief	:Sets the Tiles (ground objects)
* @notes	:currently sets 400 tiles into 4 rows of 100
* @return	:void
*/
void Scene::SetObstacles()
{
	float Xpos, Ypos;
	Xpos = 0;
	Ypos = 600;
	int z = 0;
	for (size_t i = 0; i < 400; i++)
	{
		PhysicsBody _body;
		Obstacles.push_back(_body);
	}

	if (!Obstacles.empty())
	{
		for (size_t y = 0; y < 4; y++)
		{
			for (size_t x = 0; x < 100; x++)
			{
				if (y != 3)
				{
					HorizontalObstacle(Obstacles[z], (float)Xpos, (float)Ypos, (float)20, (float)40,
						1);
				}
				else
				{
					HorizontalObstacle(Obstacles[z], (float)Xpos, (float)Ypos, (float)20, (float)40,
						0);
				}
				Xpos += 20;
				z++;
			}
			Ypos -= 40;
			Xpos = 0;
		}

	}
	//	SetEnemies();
}

/*
* @brief	:Obsolete as no enemies present ingame
* @notes	:could change to holy beam launcher
* @return	:void
*/
void Scene::SetEnemies()
{
}

/*
* @brief	:Draws to window
* @return	:void
*/
void Scene::draw()
{
	AnimatedBack.DrawSpriteAnim(currentGame->window, AnimatedBack.GetCurrentFrame(), 0, 828, 358);
	//currentGame->window.draw(_Background);
	currentGame->window.draw(ScoreTitle);
	currentGame->window.draw(GameObjectsTitle);
	currentGame->window.draw(GameObjectsLeft);
	currentGame->window.draw(Score);
	currentGame->window.draw(GameOverText);
	currentGame->window.draw(GameOverText2);
	currentGame->window.draw(GameOverText3);

	if (!Obstacles.empty())
	{
		for (size_t i = 0; i < Obstacles.size(); i++) {
			currentGame->window.draw(Obstacles[i]._RECT);
		}
	}
	if (!m_FallingObjects.empty())
	{
		for (size_t i = 0; i < m_FallingObjects.size(); i++) {
			currentGame->window.draw(m_FallingObjects[i]->_RECT);
		}
	}
	for (int i = 0; i < 1; i++)
	{
		currentGame->window.draw(Floor[i]._RECT);
	}
	for (size_t i = 0; i < GameObjectList.size(); i++)
	{
		GameObjectList[i]->draw();
	}
}

/*
* @brief	:updates the scene (after the world step process)
* @return	:void
*/
void Scene::update(float dt)
{
	AnimatedBack.Animate();
	static float temp = 0;
	temp += (dt * 10000);


	if (temp > 3.2f) {
		temp = 0.0f;
		AddFallingObject();
	}

	float xpos;
	float ypos;
	float rotationAngle;
	//update Obstacles
	if (!Obstacles.empty())
	{
		for (size_t i = 0; i < Obstacles.size(); i++)
		{
			if (Obstacles[i].dead == true) {
				Obstacles[i]._BodyPtr->DestroyFixture(Obstacles[i]._BodyPtr->GetFixtureList());
				Obstacles[i]._BodyPtr->GetWorld()->DestroyBody(Obstacles[i]._BodyPtr);
				Obstacles[i].Zero();
			}
			if (Obstacles[i]._BodyPtr != NULL) {
				xpos = Obstacles[i]._BodyPtr->GetPosition().x;
				ypos = Obstacles[i]._BodyPtr->GetPosition().y;
				rotationAngle = Obstacles[i]._BodyPtr->GetAngle();
				Obstacles[i]._RECT.setPosition(xpos*RATIO, ypos*RATIO);
				Obstacles[i]._RECT.setRotation(rotationAngle * (float)-57.295);
			}
			else {
				Obstacles.erase(Obstacles.begin() + i);
				i -= 1;
			}
		}
	}

	if (!m_FallingObjects.empty())
	{
		for (auto i = m_FallingObjects.begin(); i != m_FallingObjects.end();)
		{
			xpos = (*i)->_BodyPtr->GetPosition().x;
			ypos = (*i)->_BodyPtr->GetPosition().y;
			rotationAngle = (*i)->_BodyPtr->GetAngle();
			(*i)->_RECT.setPosition(xpos*RATIO, ypos*RATIO);
			(*i)->_RECT.setRotation(rotationAngle * (float)-57.295);

			++i;
		}
	}

	for (size_t i = 0; i < GameObjectList.size(); i++)
	{
		GameObjectList[i]->update();
	}

	if (m_DeadObjects.size() > 0) {
		
		
		for (unsigned int i = 0; i < m_FallingObjects.size(); ++i) {
			if (m_FallingObjects[i]->dead == true) {
				m_FallingObjects.erase(m_FallingObjects.begin() + i);
				i = -1;
			}
		}
		for (unsigned int i = 0; i < m_DeadObjects.size(); ++i) {
			m_DeadObjects[i]->_BodyPtr->DestroyFixture(m_DeadObjects[i]->_BodyPtr->GetFixtureList());
			m_DeadObjects[i]->_BodyPtr->GetWorld()->DestroyBody(m_DeadObjects[i]->_BodyPtr);
			m_DeadObjects[i]->Zero();
			//delete (m_FallingObjects[i]);
		}
		m_DeadObjects.clear();
	}
	//m_FallingObjects[i]->_BodyPtr->GetWorld()->DestroyBody(m_FallingObjects[i]->_BodyPtr);
	GameObjectsLeft.setString(std::to_string(GameObjectList.size()));
}

/*
* @brief	:Sets the tiles
* @notes	:to be changed to texture manager so this will later become obsolete
* @return
*/
void Scene::SetObstacleSprites()
{
	sf::Image spr;
	spr.loadFromFile("images/Tile1.png");
	ObstacleSprites.push_back(spr);

	sf::Image spr1;
	spr1.loadFromFile("images/Tile2.png");
	ObstacleSprites.push_back(spr1);
}

/*
* @brief	:obsolete doesnt get used
* @param	:None
* @return	:None
*/
void Scene::AddSceneBodies()
{
	for (size_t i = 0; i < 1; i++)
	{
		m_bodies.push_back(&Floor[i]);
	}
	if (!Obstacles.empty())
	{
		for (size_t i = 0; i < Obstacles.size(); i++)
		{
			m_bodies.push_back(&Obstacles[i]);
		}
	}
}

/*
* @brief	:Ends the game
* @return	:void
*/
void Scene::GameOver()
{
	isLost = true;
	_World->SetAllowSleeping(true);
	GameOverText.setString(" GAME OVER ");
	GameOverText2.setString("Press R to restart ");
	GameOverText3.setString("Press ESC to exit");
}

/*
* @brief	:sets the box2dWorld
* @param	:b2World * world - a pointer to the world we are going to use
* @return	:void
*/
void Scene::SetWorld(b2World * aworld)
{
	_World = aworld;
	_World->SetContactListener(this);
	_World->SetContactFilter(this);
}

/*
* @brief	:Box2d collision detection presolve function override
* @param	:b2Contact * contact - a pointer to the contact point on a body(can be used for damage based on body parts)
* @param	:b2Manifold *- convex shapes collisions
* @return	:void
*/
void Scene::PreSolve(b2Contact * contact, const b2Manifold *)
{

}

/*
* @brief	:Calculates score based on collision(not really needed)
* @param	:b2Contact * contact - a pointer to the contact point on a body
* @param	:b2ContactImpulse impulse - the amount of energy used on impact
* @return	:void
*/
void Scene::PostSolve(b2Contact * contact, const b2ContactImpulse * impulse)
{


}

void Scene::BeginContact(b2Contact * contact)
{

	PhysicsBody* bodyDataA = static_cast<PhysicsBody*>(contact->GetFixtureA()->GetBody()->GetUserData());
	PhysicsBody* bodyDataB = static_cast<PhysicsBody*>(contact->GetFixtureB()->GetBody()->GetUserData());

	if (bodyDataA->type == FallingObject && bodyDataA->dead == false && bodyDataB->type == ObstacleH) {
		
		bodyDataA->dead = true;
		m_DeadObjects.push_back(bodyDataA);

		bodyDataB->dead = true;
		//m_DeadObjects.push_back(bodyDataB);
	}
	if (bodyDataB->type == FallingObject && bodyDataB->dead == false && bodyDataA->type == ObstacleH) {
		
		bodyDataB->dead = true;
		m_DeadObjects.push_back(bodyDataB);

		bodyDataA->dead = true;
		//m_DeadObjects.push_back(bodyDataA);
	}

	if (bodyDataA->type == Player && bodyDataB->type == ObstacleH)
	{
		
		bodyDataA->Touching = true;
		bodyDataB->Touching = true;
		
	}
	else if (bodyDataB->type == Player && bodyDataA->type == ObstacleH)
	{
		
		bodyDataA->Touching = true;
		bodyDataB->Touching = true;
	}
	else
	{
		bodyDataA->Touching = false;
		bodyDataB->Touching = false;
	}

}

void Scene::EndContact(b2Contact * contact)
{

	PhysicsBody* bodyDataA = static_cast<PhysicsBody*>(contact->GetFixtureA()->GetBody()->GetUserData());
	PhysicsBody* bodyDataB = static_cast<PhysicsBody*>(contact->GetFixtureB()->GetBody()->GetUserData());

	bodyDataA->Touching = false;
	bodyDataB->Touching = false;
}

/*
* @brief	:returns the level index
* @return	:int - Scene::LevelIndex
*/
int Scene::getLevel()
{
	return LevelIndex;
}

