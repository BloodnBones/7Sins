#include "GameObject.h"


/*
* @brief
* @param
* @return
*/
GameObject::GameObject(b2World *aWorld, sf::Image &image, BodyType type)
{
	m_world = aWorld;
	m_type = type;
	sprite.loadFromImage(image);
	offset = gameTime * 0.3f;
	if (m_type == BodyType::Player)
	{
		xpos = 200;
		ypos = 450;
	}
	origin_x = 20;
	origin_y = 40;
	fill = sf::Color(255, 0, 255, 255);
	SetPhysicsBox();
	if (m_type == BodyType::Player)
	{
		m_body._BodyPtr->SetActive(true);
	}
}

/*
* @brief
* @param
* @return
*/
GameObject::GameObject(b2World * aWorld, sf::Image & image, BodyType type, float _xpos, float _ypos)
{
	m_world = aWorld;
	m_type = type;
	sprite.loadFromImage(image);
	offset = gameTime * 0.3f;

	xpos = _xpos;
	ypos = _ypos;

	origin_x = 20;
	origin_y = 40;
	fill = sf::Color(255, 0, 255, 255);
	SetPhysicsBox();
	if (m_type == BodyType::Player)
	{
		m_body._BodyPtr->SetActive(false);
	}

}

/*
* @brief
* @param
* @return
*/
GameObject::~GameObject()
{
	m_body._BodyPtr->DestroyFixture(m_body._BodyPtr->GetFixtureList());
	m_world->DestroyBody(m_body._BodyPtr);
}

/*
* @brief
* @param
* @return
*/
void GameObject::Init(b2World & world)
{
}

/*
* @brief
* @param
* @return
*/
void GameObject::SetPhysicsBox()
{
	b2CircleShape Shape;
	Shape.m_radius = 0.5;
	m_body._RECT = sf::RectangleShape(sf::Vector2f(origin_x * 2, origin_y));
	m_body._RECT.setOrigin(origin_x, origin_y / 2);
	m_body._RECT.setTexture(&sprite);
	m_body._BodyDef.position.Set(xpos / RATIO, ypos / RATIO);
	m_body._BodyDef.type = b2_dynamicBody;
	m_body._BodyShape.SetAsBox(origin_x / RATIO, (origin_y / 2) / RATIO);
	m_body._FixtureDef.shape = &Shape;
	m_body._FixtureDef.density = 1.0f;
	m_body._FixtureDef.restitution = 0.2f;
	m_body._FixtureDef.friction = 0.05f;
	m_body._BodyPtr = m_world->CreateBody(&m_body._BodyDef);
	m_body._BodyPtr->CreateFixture(&Shape, 1.0f);
	m_body._BodyPtr->SetUserData(&m_body);
	bodyDef.position.Set(0, 0);
	groundBody = m_world->CreateBody(&bodyDef);
	m_body.type = m_type;
	if (m_type == BodyType::Enemy)
	{
		m_body.HP = 3;
	}
}

/*
* @brief
* @param
* @return
*/
void GameObject::input(sf::Event events)
{

	if (m_body.type == BodyType::Player)
	{
		switch (events.type) {
		case sf::Event::KeyPressed:
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			{
				m_body._BodyPtr->ApplyLinearImpulse(b2Vec2(-1, 0), m_body._BodyPtr->GetWorldCenter(), true);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{
				m_body._BodyPtr->ApplyLinearImpulse(b2Vec2(1, 0), m_body._BodyPtr->GetWorldCenter(), true);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{
				if (jumpTimer > 0.5)
				{
					m_body._BodyPtr->ApplyLinearImpulse(b2Vec2(0, -5), m_body._BodyPtr->GetWorldCenter(), true);
					timer.restart();
				}
			}

			break;
		}
	}
}

/*
* @brief
* @param
* @return
*/
void GameObject::draw()
{
	App.draw(m_body._RECT);
}

/*
* @brief
* @param
* @return
*/
void GameObject::SetPosition(float x, float y)
{
	xpos = x;
	ypos = y;
	//update position settings for Box2D
	m_body._BodyPtr->DestroyFixture(m_body._BodyPtr->GetFixtureList());
	m_world->DestroyBody(m_body._BodyPtr);
	m_body._BodyDef.position.Set(xpos / RATIO, ypos / RATIO - 1 * 5 / RATIO);
	m_body._BodyPtr = m_world->CreateBody(&m_body._BodyDef);
	m_body._BodyPtr->CreateFixture(&m_body._FixtureDef);
	m_body._RECT.setPosition(m_body._BodyPtr->GetPosition().x*RATIO,
		m_body._BodyPtr->GetPosition().y*RATIO);
	if (m_type == BodyType::Player)
	{
		m_body._BodyPtr->SetActive(false);
	}
}

/*
* @brief
* @param
* @return
*/
void GameObject::update()
{
	xpos = m_body._BodyPtr->GetPosition().x;
	ypos = m_body._BodyPtr->GetPosition().y;
	//cout << xpos << ", " << ypos << endl;
	m_body._RECT.setPosition(xpos*RATIO, ypos*RATIO);
	jumpTimer = timer.getElapsedTime().asSeconds();
}

/*
* @brief
* @param
* @return
*/
void GameObject::setImpulse(float x, float y)
{
	m_body._BodyPtr->ApplyLinearImpulse(b2Vec2(x, -y), m_body._BodyPtr->GetWorldCenter(), true);
}

/*
* @brief
* @param
* @return
*/
void GameObject::Shoot(float x, float y)
{
	//m_body._BodyPtr->SetActive(true);
	this->setImpulse(x, y);
}

/*
* @brief
* @param
* @return
*/
PhysicsBody * GameObject::getBody()
{
	return &m_body;
}

