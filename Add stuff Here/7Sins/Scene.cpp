//#include "Scene.h"
//
///*
//* @brief
//* @param
//* @return
//*/
//Scene::Scene()
//{
//}
//
///*
//* @brief
//* @param
//* @return
//*/
//Scene::Scene(std::vector<GameObject*> GameObjects, sf::Image & image)
//{
//
//	for (size_t i = 0; i < GameObjects.size(); i++)
//	{
//		GameObjectList[i] = GameObjects[i];
//	}
//	m_currentGameObject = GameObjectList[0];
//	f_GameObjectsLeft = GameObjects.size();
//	BackgroundTex.loadFromImage(image);
//	EnemySprite.loadFromFile("Assets/Sprites/Pig.png");
//	_Background = sf::RectangleShape(sf::Vector2f((float)BackgroundTex.getSize().x, (float)BackgroundTex.getSize().y));
//	_Background.setTexture(&BackgroundTex);
//	SetFloor();
//	SetObstacleSprites();
//	SetObstacles();
//	AddSceneBodies();
//	font.loadFromFile("Assets/Fonts/angryGameObjects-regular.ttf");
//
//	// GameObjects Text
//	GameObjectsTitle.setFont(font);
//	GameObjectsTitle.setCharacterSize(50);
//	GameObjectsTitle.setFillColor(sf::Color::Red);
//	GameObjectsTitle.setPosition(sf::Vector2f(45, 00));
//	GameObjectsTitle.setString("GameObjects Left");
//
//	GameObjectsLeft.setFont(font);
//	GameObjectsLeft.setCharacterSize(50);
//	GameObjectsLeft.setFillColor(sf::Color::Red);
//	GameObjectsLeft.setPosition(sf::Vector2f(50, 50));
//
//	//Score Text
//	ScoreTitle.setFont(font);
//	ScoreTitle.setCharacterSize(50);
//	ScoreTitle.setFillColor(sf::Color::Red);
//	ScoreTitle.setPosition(sf::Vector2f(795, 00));
//	ScoreTitle.setString("Score ");
//
//	Score.setFont(font);
//	Score.setCharacterSize(50);
//	Score.setFillColor(sf::Color::Red);
//	Score.setPosition(sf::Vector2f(800, 50));
//
//	timer.restart();
//}
//
///*
//* @brief
//* @param
//* @return
//*/
//Scene::Scene(b2World * aWorld, std::vector<GameObject *> Players, sf::Image & image, int Level)
//{
//	LevelIndex = Level;
//	_World = aWorld;
//	_World->SetContactListener(this);
//	_World->SetContactFilter(this);
//	for (size_t i = 0; i < Players.size(); i++)
//	{
//		GameObjectList[i] = Players[i];
//	}
//	m_currentGameObject = GameObjectList[0];
//	f_GameObjectsLeft = Players.size();
//	BackgroundTex.loadFromImage(image);
//	EnemySprite.loadFromFile("Assets/Sprites/Pig.png");
//	_Background = sf::RectangleShape(sf::Vector2f((float)BackgroundTex.getSize().x, (float)BackgroundTex.getSize().y));
//	_Background.setTexture(&BackgroundTex);
//	SetFloor();
//	SetObstacleSprites();
//	SetObstacles();
//	AddSceneBodies();
//	font.loadFromFile("Assets/Fonts/angryGameObjects-regular.ttf");
//
//	// GameObjects Text
//	GameObjectsTitle.setFont(font);
//	GameObjectsTitle.setCharacterSize(50);
//	GameObjectsTitle.setFillColor(sf::Color::Red);
//	GameObjectsTitle.setPosition(sf::Vector2f(45, 00));
//	GameObjectsTitle.setString("GameObjects Left");
//
//	GameObjectsLeft.setFont(font);
//	GameObjectsLeft.setCharacterSize(50);
//	GameObjectsLeft.setFillColor(sf::Color::Red);
//	GameObjectsLeft.setPosition(sf::Vector2f(50, 50));
//
//	//Score Text
//	ScoreTitle.setFont(font);
//	ScoreTitle.setCharacterSize(50);
//	ScoreTitle.setFillColor(sf::Color::Red);
//	ScoreTitle.setPosition(sf::Vector2f(795, 00));
//	ScoreTitle.setString("Score ");
//
//	Score.setFont(font);
//	Score.setCharacterSize(50);
//	Score.setFillColor(sf::Color::Red);
//	Score.setPosition(sf::Vector2f(800, 50));
//
//	GameOverText.setFont(font);
//	GameOverText.setCharacterSize(75);
//	GameOverText.setFillColor(sf::Color::Red);
//	GameOverText.setPosition(sf::Vector2f(300, 50));
//
//	GameOverText2.setFont(font);
//	GameOverText2.setCharacterSize(50);
//	GameOverText2.setFillColor(sf::Color::Red);
//	GameOverText2.setPosition(sf::Vector2f(250, 150));
//
//	GameOverText3.setFont(font);
//	GameOverText3.setCharacterSize(50);
//	GameOverText3.setFillColor(sf::Color::Red);
//	GameOverText3.setPosition(sf::Vector2f(250, 250));
//
//	timer.restart();
//	std::cout << LevelIndex << endl;
//}
//
///*
//* @brief
//* @param
//* @return
//*/
//Scene::~Scene()
//{
//}
//
///*
//* @brief
//* @param
//* @return
//*/
//void Scene::input(sf::Event events)
//{
//	m_currentGameObject->input(events);
//	switch (events.type) {
//	case sf::Event::KeyPressed:
//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
//			if (isLost)
//			{
//				isWon = true;
//				printf("Reset");
//			}
//		}
//		break;
//	}
//}
//
///*
//* @brief
//* @param
//* @return
//*/
//void Scene::SetFloor()
//{
//	//floor
//	HorizontalBorder(Floor[0], (float)450, (float)730, (float)50000, (float)50,
//		sf::Color::Black);
//}
//
///*
//* @brief
//* @param
//* @return
//*/
//void Scene::HorizontalBorder(PhysicsBody & body, float _xpos, float ypos, float origin_x, float origin_y, sf::Color fill)
//{
//	body._BodyDef.position.Set(_xpos / RATIO, ypos / RATIO);
//	body._BodyDef.type = b2_staticBody;
//	body._RECT = sf::RectangleShape(sf::Vector2f(origin_x * 6, origin_y));
//	body._RECT.setOrigin(origin_x, origin_y / 6);
//	body._RECT.setFillColor(fill);
//	body._BodyShape.SetAsBox(origin_x / RATIO, (origin_y / 6) / RATIO);
//	body._FixtureDef.shape = &body._BodyShape;
//	body._FixtureDef.density = 5.0f;
//	body._FixtureDef.friction = 0.5f;
//	body._BodyPtr = _World->CreateBody(&body._BodyDef);
//	body._BodyPtr->CreateFixture(&body._BodyShape, 5.0f);
//	body._BodyPtr->SetUserData(&body);
//	//set position
//	body._RECT.setPosition(body._BodyPtr->GetPosition().x*RATIO, body._BodyPtr->GetPosition().y*RATIO);
//	body.type = Ground;
//}
//
///*
//* @brief
//* @param
//* @return
//*/
//void Scene::HorizontalObstacle(PhysicsBody & body, float _xpos, float ypos, float origin_x, float origin_y, int SpriteIndex)
//{
//
//	body.Image.loadFromImage(ObstacleSprites[SpriteIndex]);
//	body._BodyDef.position.Set(_xpos / RATIO, ypos / RATIO);
//	body._BodyDef.type = b2_kinematicBody;
//	body._RECT = sf::RectangleShape(sf::Vector2f(origin_x * 2, origin_y));
//	body._RECT.setOrigin(origin_x, origin_y / 2);
//	body._RECT.setTexture(&body.Image);
//	body._BodyShape.SetAsBox(origin_x / RATIO, (origin_y / 2) / RATIO);
//	body._FixtureDef.shape = &body._BodyShape;
//	body._FixtureDef.density = 5.0f;
//	body._FixtureDef.friction = 1.5f;
//	body._BodyPtr = _World->CreateBody(&body._BodyDef);
//	body._BodyPtr->CreateFixture(&body._BodyShape, 1.0f);
//	body._BodyPtr->SetUserData(&body);
//	//set position
//	body._RECT.setPosition(body._BodyPtr->GetPosition().x*RATIO, body._BodyPtr->GetPosition().y*RATIO);
//	body.type = ObstacleH;
//}
//
///*
//* @brief
//* @param
//* @return
//*/
//void Scene::VerticleObstacle(PhysicsBody & body, float _xpos, float ypos, float origin_x, float origin_y, int SpriteIndex)
//{
//	body.Image.loadFromImage(ObstacleSprites[SpriteIndex]);
//	body._BodyDef.position.Set(_xpos / RATIO, ypos / RATIO);
//	body._BodyDef.type = b2_dynamicBody;
//	body._RECT = sf::RectangleShape(sf::Vector2f(origin_x, origin_y * 2));
//	body._RECT.setOrigin(origin_x / 2, origin_y);
//	body._RECT.setTexture(&body.Image);
//	body._BodyShape.SetAsBox((origin_x / 2) / RATIO, origin_y / RATIO);
//	body._FixtureDef.shape = &body._BodyShape;
//	body._FixtureDef.density = 5.0f;
//	body._FixtureDef.friction = 0.5f;
//	body._BodyPtr = _World->CreateBody(&body._BodyDef);
//	body._BodyPtr->CreateFixture(&body._BodyShape, 1.0f);
//	body._BodyPtr->SetUserData(&body);
//	//set position
//	body._RECT.setPosition(body._BodyPtr->GetPosition().x*RATIO, body._BodyPtr->GetPosition().y*RATIO);
//	body.type = ObstacleV;
//}
//
///*
//* @brief
//* @param
//* @return
//*/
//void Scene::SetObstacles()
//{
//	float Xpos, Ypos;
//	Xpos = 0;
//	Ypos = 700;
//	int z = 0;
//	for (size_t i = 0; i < 400; i++)
//	{
//		PhysicsBody _body;
//		Obstacles.push_back(_body);
//	}
//
//	if (!Obstacles.empty())
//	{
//		for (size_t y = 0; y < 4; y++)
//		{
//			for (size_t x = 0; x < 100; x++)
//			{
//				if (y != 3)
//				{
//					HorizontalObstacle(Obstacles[z], (float)Xpos, (float)Ypos, (float)20, (float)40,
//						1);
//				}
//				else
//				{
//					HorizontalObstacle(Obstacles[z], (float)Xpos, (float)Ypos, (float)20, (float)40,
//						0);
//				}
//				Xpos += 20;
//				z++;
//			}
//			Ypos -= 40;
//			Xpos = 0;
//		}
//
//	}
////	SetEnemies();
//}
//
///*
//* @brief
//* @param
//* @return
//*/
//void Scene::SetEnemies()
//{
//	GameObject *Enemy = new GameObject(_World, EnemySprite, BodyType::Enemy, (float)680, (float)425);
//	Enemies.push_back(Enemy);
//}
//
///*
//* @brief
//* @param
//* @return
//*/
//void Scene::draw()
//{
//	App.draw(_Background);
//	App.draw(ScoreTitle);
//	App.draw(GameObjectsTitle);
//	App.draw(GameObjectsLeft);
//	App.draw(Score);
//	App.draw(GameOverText);
//	App.draw(GameOverText2);
//	App.draw(GameOverText3);
//	//draw floor and walls
//	if (!Obstacles.empty())
//	{
//		for (size_t i = 0; i < Obstacles.size(); i++)
//			App.draw(Obstacles[i]._RECT);
//	}
//	if (!Enemies.empty())
//	{
//		for (size_t i = 0; i < Enemies.size(); i++)
//			Enemies[i]->draw();
//	}
//
//	for (int i = 0; i < 1; i++)
//		App.draw(Floor[i]._RECT);
//	m_currentGameObject->draw();
//}
//
///*
//* @brief
//* @param
//* @return
//*/
//void Scene::update()
//{
//	float xpos;
//	float ypos;
//	float rotationAngle;
//	//update Obstacles
//
//	if (!Obstacles.empty())
//	{
//		for (auto i = Obstacles.begin(); i != Obstacles.end();)
//		{
//
//			PhysicsBody* data = static_cast<PhysicsBody*>((*i)._BodyPtr->GetUserData());
//			if (((data && (data->isDead && data->HP <= 0))))
//			{
//				//delete data;
//				i = Obstacles.erase(i);
//				continue;
//			}
//			else
//			{
//				if ((*i).HP < 100 && (*i).type == BodyType::ObstacleH)
//				{
//					sf::Texture Image;
//					Image.loadFromImage(ObstacleSprites[0]);
//					(*i)._RECT.setTexture(&Image);
//				}
//				if ((*i).HP < 100 && (*i).type == BodyType::ObstacleV)
//				{
//					sf::Texture Image;
//					Image.loadFromImage(ObstacleSprites[1]);
//					(*i)._RECT.setTexture(&Image);
//				}
//				xpos = (*i)._BodyPtr->GetPosition().x;
//				ypos = (*i)._BodyPtr->GetPosition().y;
//				rotationAngle = (*i)._BodyPtr->GetAngle();
//				(*i)._RECT.setPosition(xpos*RATIO, ypos*RATIO);
//				(*i)._RECT.setRotation(rotationAngle * (float)-57.295);
//			}
//			++i;
//		}
//	}
//
//	//update Enemies
//	if (!Enemies.empty())
//	{
//		for (auto i = Enemies.begin(); i != Enemies.end();)
//		{
//
//			PhysicsBody* data = static_cast<PhysicsBody*>((*i)->getBody()->_BodyPtr->GetUserData());
//			if (((data && (data->isDead && data->HP <= 0))))
//			{
//				//delete data;
//				i = Enemies.erase(i);
//				continue;
//			}
//			else
//			{
//				(*i)->update();
//			}
//			++i;
//		}
//	}
//
//	m_currentGameObject->update();
//
//	if (m_currentGameObject->canKill && KFC == false)
//	{
//		KFC = true;
//		timer.restart();
//		std::cout << "Start Timer " << endl;
//	}
//	if (m_currentGameObject->canKill && timer.getElapsedTime().asSeconds() > m_currentGameObject->KillTime)
//	{
//
//		std::cout << "Killing time" << endl;
//		for (size_t i = 0; i < 3; i++)
//		{
//			if (m_currentGameObject == GameObjectList[i])
//			{
//				if (f_GameObjectsLeft - 1 == 0)
//				{
//
//					if (Enemies.empty())
//					{
//						
//						isWon = true;
//					}
//					else
//					{
//						//isLost = true;
//						GameOver();
//					}
//				}
//				else
//				{
//					if (i + 1 < 3)
//					{
//						m_currentGameObject = GameObjectList[i + 1];
//						f_GameObjectsLeft--;
//					}
//					break;
//				}
//
//			}
//		}
//
//		KFC = false;
//	}
//
//
//	GameObjectsLeft.setString(std::to_string(f_GameObjectsLeft - 1));
//	Score.setString(std::to_string(f_Score));
//}
//
///*
//* @brief
//* @param
//* @return
//*/
//void Scene::SetObstacleSprites()
//{
//	sf::Image spr;
//	spr.loadFromFile("Assets/Sprites/Tile1.png");
//	ObstacleSprites.push_back(spr);
//
//	sf::Image spr1;
//	spr1.loadFromFile("Assets/Sprites/Tile2.png");
//	ObstacleSprites.push_back(spr1);
//}
//
///*
//* @brief
//* @param
//* @return
//*/
//void Scene::AddSceneBodies()
//{
//	for (size_t i = 0; i < 1; i++)
//	{
//		m_bodies.push_back(&Floor[i]);
//	}
//	if (!Obstacles.empty())
//	{
//		for (size_t i = 0; i < Obstacles.size(); i++)
//		{
//			m_bodies.push_back(&Obstacles[i]);
//		}
//	}
//}
//
///*
//* @brief
//* @param
//* @return
//*/
//void Scene::GameOver()
//{
//	isLost = true;
//	_World->SetAllowSleeping(true);
//	GameOverText.setString(" GAME OVER ");
//	GameOverText2.setString("Press R to restart ");
//	GameOverText3.setString("Press ESC to exit");
//}
//
///*
//* @brief
//* @param
//* @return
//*/
//void Scene::SetWorld(b2World * aworld)
//{
//	_World = aworld;
//	_World->SetContactListener(this);
//	_World->SetContactFilter(this);
//}
//
///*
//* @brief
//* @param
//* @return
//*/
//void Scene::PreSolve(b2Contact * contact, const b2Manifold *)
//{
//	PhysicsBody* bodyDataA = static_cast<PhysicsBody*>(contact->GetFixtureA()->GetBody()->GetUserData());
//	PhysicsBody* bodyDataB = static_cast<PhysicsBody*>(contact->GetFixtureB()->GetBody()->GetUserData());
//	if (bodyDataA)
//		bodyDataA->velocity = contact->GetFixtureA()->GetBody()->GetLinearVelocity();
//	if (bodyDataB)
//		bodyDataB->velocity = contact->GetFixtureB()->GetBody()->GetLinearVelocity();
//}
//
///*
//* @brief
//* @param
//* @return
//*/
//void Scene::PostSolve(b2Contact * contact, const b2ContactImpulse * impulse)
//{
//	if (impulse->normalImpulses[0] > 1)
//	{
//		float maxImpulse = 0.0f;
//		for (int i = 0; i < contact->GetManifold()->pointCount; ++i)
//		{
//			maxImpulse = b2Max(maxImpulse, impulse->normalImpulses[i]);
//		}
//
//		//If FixtureA has energy, calculate lost energy according to impulse strength and add that to totalscore
//		PhysicsBody* bodyDataA = static_cast<PhysicsBody*>(contact->GetFixtureA()->GetBody()->GetUserData());
//		PhysicsBody* bodyDataB = static_cast<PhysicsBody*>(contact->GetFixtureB()->GetBody()->GetUserData());
//		float deltaEnergy = 0;
//
//		if (bodyDataA && !bodyDataA->isDead)
//		{
//			deltaEnergy = maxImpulse * (float)0.1;
//			bodyDataA->HP -= deltaEnergy * 10;
//			if (bodyDataB && !bodyDataA->HP)
//			{
//				contact->GetFixtureB()->GetBody()->SetLinearVelocity(bodyDataB->_BodyPtr->GetLinearVelocity());
//			}
//		}
//		else if (bodyDataA || bodyDataA->type == Enemy)
//		{
//			bodyDataA->isDead = true;
//		}
//
//		f_Score += (int)deltaEnergy;
//
//		deltaEnergy = 0;
//		if(bodyDataB && !bodyDataB->isDead)
//		{
//			deltaEnergy = maxImpulse * (float)0.1;
//			bodyDataB->HP -= deltaEnergy * 10;
//			if (bodyDataA && !bodyDataB->HP)
//			{
//				contact->GetFixtureB()->GetBody()->SetLinearVelocity(bodyDataB->_BodyPtr->GetLinearVelocity());
//			}
//		}
//		else if (bodyDataB || bodyDataB->type == Enemy)
//		{
//			bodyDataB->isDead = true;
//		}
//
//		f_Score += (int)deltaEnergy;
//		//	ScoreCount.setString(std::to_string(f_Score));
//		cout << "Score: " << f_Score << endl;
//	}
//}
//
///*
//* @brief
//* @param
//* @return
//*/
//int Scene::getLevel()
//{
//	return LevelIndex;
//}
//
