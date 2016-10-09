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

#include "GameObject.h"


/*
* @brief	:GameObject constructor
* @param	:b2World * aworld - a pointer to the box2d world
* @param	:sf::Texture &image - the sprite
* @param	:BodyType type - sets the PhysicsBody body type
* @param	:Game * gameptr - sets the current gamestate
* @return	:GameObject
*/
GameObject::GameObject(b2World *aWorld, sf::Texture& image, BodyType type, Game *gameptr, int Index)
{
	PlayerIndex = Index;
	currentGame = gameptr;
	m_world = aWorld;
	m_type = type;
	sprite = image;
	offset = gameTime * 0.3f;
	if (m_type == BodyType::Player)
	{
		if (Index == 0)
		{
			xpos = 200;
			ypos = 250;
		}
		else
		{
			xpos = 600;
			ypos = 250;
		}
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
* @brief	:GameObject constructor
* @param	:b2World * aworld - a pointer to the box2d world
* @param	:Character character - players choice of characrter to be
* @param	:BodyType type - sets the PhysicsBody body type
* @param	:Game * gameptr - sets the current gamestate
* @return	:GameObject
*/
GameObject::GameObject(b2World *aWorld, int character, BodyType type, Game *gameptr, int Index)
{
	PlayerIndex = Index;
	currentGame = gameptr;
	m_world = aWorld;
	m_type = type;
	LoadCharacterImage(character);
	offset = gameTime * 0.3f;
	if (m_type == BodyType::Player)
	{
		if (Index == 0)
		{
			xpos = 200;
			ypos = 250;
		}
		else
		{
			xpos = 600;
			ypos = 250;
		}
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
* @brief	:GameObject constructor
* @param	:b2World * aworld - a pointer to the box2d world
* @param	:sf::Texture &image - the sprite
* @param	:BodyType type - sets the PhysicsBody body type
* @param	:float _xpos - x position;
* @param	:float _ypos - y position;
* @return	:GameObject
*/
GameObject::GameObject(b2World * aWorld, sf::Texture& image, BodyType type, float _xpos, float _ypos)
{
	m_world = aWorld;
	m_type = type;
	sprite = image;
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
* @brief	:GameObject Destructor, destroys the gameobject
*/
GameObject::~GameObject()
{
	m_body._BodyPtr->DestroyFixture(m_body._BodyPtr->GetFixtureList());
	m_world->DestroyBody(m_body._BodyPtr);
}

/*
* @brief	:not used( obsolete)
* @param
* @return
*/
void GameObject::Init(b2World & world)
{
}

/*
* @brief	:sets the Physicsbody things
* @return	:void
*/
void GameObject::SetPhysicsBox()
{
	m_body._RECT = sf::RectangleShape(sf::Vector2f(origin_x * 2, origin_y));
	m_body._RECT.setOrigin(origin_x, origin_y / 2);
	m_body._RECT.setTexture(&sprite);
	m_body._BodyDef.position.Set(xpos / RATIO, ypos / RATIO);
	m_body._BodyDef.type = b2_dynamicBody;
	m_body._BodyShape.SetAsBox(origin_x / RATIO, (origin_y / 2) / RATIO);
	m_body._FixtureDef.shape = &m_body._BodyShape;
	m_body._FixtureDef.density = 2.0f;
	m_body._FixtureDef.restitution = 0.1f;
	m_body._FixtureDef.friction = 0.9f;
	m_body._BodyPtr = m_world->CreateBody(&m_body._BodyDef);
	m_body._BodyPtr->CreateFixture(&m_body._FixtureDef);
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
* @brief	:Input handler
* @param	:sf::Event events - sfml event handler
* @return	:void
*/
void GameObject::input(sf::Event events)
{
	//TO DO - Add controls for multiple player
	b2Vec2 current_Velocity = m_body._BodyPtr->GetLinearVelocity();

	if (m_body.type == BodyType::Player)
	{
		//Cap Max Velocity
		if (abs(current_Velocity.x) > MAX_VELOCITY)
		{
			current_Velocity.x = sgn(current_Velocity.x) * MAX_VELOCITY;
			m_body._BodyPtr->SetLinearVelocity(current_Velocity);
		}

		//Player 1
		if (PlayerIndex == 0)
		{
			Player1Input();
		}

		//Player 2
		else if (PlayerIndex == 1)
		{
			Player2Input();
		}
	}
}

/*
* @brief	:draws to window
* @return	:void
*/
void GameObject::draw()
{
	currentGame->window.draw(m_body._RECT);
}

/*
* @brief	:sets the position of the object both onscreen and in box2d(can be used for testing, not really ingame)
* @param	:float x - new  x position
* @param	:float y - new  y position
* @return	:void
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
* @brief	:updates the object
* @return	:void
*/
void GameObject::update()
{
	xpos = m_body._BodyPtr->GetPosition().x;
	ypos = m_body._BodyPtr->GetPosition().y;

	m_body._RECT.setPosition(xpos*RATIO, ypos*RATIO);
	jumpTimer = timer.getElapsedTime().asSeconds();

	if (m_body.Touching)
	{
		isGrounded = true;
	}
	else
	{
		isGrounded = false;
	}



}

/*
* @brief	:sets an impulse
* @param	:float x - power to x axis
* @param	:float y - power to y axis
* @return	:void
*/
void GameObject::setImpulse(float x, float y)
{
	m_body._BodyPtr->ApplyLinearImpulse(b2Vec2(x, -y), m_body._BodyPtr->GetWorldCenter(), true);
}

/*
* @brief	:obsolete
* @param
* @return
*/
void GameObject::Shoot(float x, float y)
{
	//m_body._BodyPtr->SetActive(true);
	this->setImpulse(x, y);
}

/*
* @brief	:Process the iputs for each player
* @param
* @return
*/
void GameObject::Player1Input()
{
	b2Vec2 current_Velocity = m_body._BodyPtr->GetLinearVelocity();
	//Damp the velocity when not moving
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		stillTime += deltaTime.asSeconds();
		m_body._BodyPtr->SetLinearVelocity(b2Vec2(current_Velocity.x * 0.9f, current_Velocity.y));
	}
	else
	{
		stillTime = 0;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && current_Velocity.x > -MAX_VELOCITY)
	{
		m_body._BodyPtr->ApplyLinearImpulse(b2Vec2(-2, 0), m_body._BodyPtr->GetWorldCenter(), true);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && current_Velocity.x < MAX_VELOCITY)
	{
		m_body._BodyPtr->ApplyLinearImpulse(b2Vec2(2, 0), m_body._BodyPtr->GetWorldCenter(), true);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		if (isGrounded)
		{
			m_body._BodyPtr->ApplyLinearImpulse(b2Vec2(0, -15), m_body._BodyPtr->GetWorldCenter(), true);

		}
	}
	if (sf::Joystick::isConnected(0))			//Checks if a joystick(controller) is plugged in 
	{
		float x = sf::Joystick::getAxisPosition(0, sf::Joystick::X);
		m_body._BodyPtr->ApplyLinearImpulse(b2Vec2(x, 0), m_body._BodyPtr->GetWorldCenter(), true);

		//Checks for button on controller being pressed
		if (sf::Joystick::isButtonPressed(0, 1) && isGrounded)
		{
			m_body._BodyPtr->ApplyLinearImpulse(b2Vec2(0, -5), m_body._BodyPtr->GetWorldCenter(), true);

		}
	}
}

void GameObject::Player2Input()
{
	b2Vec2 current_Velocity = m_body._BodyPtr->GetLinearVelocity();
	//Damp the velocity when not moving
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		stillTime += deltaTime.asSeconds();
		m_body._BodyPtr->SetLinearVelocity(b2Vec2(current_Velocity.x * 0.9f, current_Velocity.y));
	}
	else
	{
		stillTime = 0;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && current_Velocity.x > -MAX_VELOCITY)
	{
		m_body._BodyPtr->ApplyLinearImpulse(b2Vec2(-2, 0), m_body._BodyPtr->GetWorldCenter(), true);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && current_Velocity.x < MAX_VELOCITY)
	{
		m_body._BodyPtr->ApplyLinearImpulse(b2Vec2(2, 0), m_body._BodyPtr->GetWorldCenter(), true);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad0))
	{
		if (isGrounded)
		{
			m_body._BodyPtr->ApplyLinearImpulse(b2Vec2(0, -15), m_body._BodyPtr->GetWorldCenter(), true);

		}
	}
	if (sf::Joystick::isConnected(1))			//Checks if a joystick(controller) is plugged in 
	{
		float x = sf::Joystick::getAxisPosition(0, sf::Joystick::X);
		m_body._BodyPtr->ApplyLinearImpulse(b2Vec2(x, 0), m_body._BodyPtr->GetWorldCenter(), true);

		//Checks for button on controller being pressed
		if (sf::Joystick::isButtonPressed(0, 1) && isGrounded)
		{
			m_body._BodyPtr->ApplyLinearImpulse(b2Vec2(0, -5), m_body._BodyPtr->GetWorldCenter(), true);

		}

	}
}

void GameObject::SetPlayerIndex(int Index)
{
	PlayerIndex = Index;
}

/*
* @brief	:Loades image based on playeres choice of character
* @param	:Enum value of the chosen character
*/
void GameObject::LoadCharacterImage(int character)
{
	switch (character)
	{
	case Lucia:
		sprite = this->currentGame->textureManager.getRef("Lucia");
		break;
	case Gabriel:
		sprite = this->currentGame->textureManager.getRef("Gabriel");
		break;
	case Joshua:
		sprite = this->currentGame->textureManager.getRef("Joshua");
		break;
	case Betty:
		sprite = this->currentGame->textureManager.getRef("Betty");
		break;
	case Matthew:
		sprite = this->currentGame->textureManager.getRef("Matthew");
		break;
	case Satella:
		sprite = this->currentGame->textureManager.getRef("Satella");
		break;
	case Honda:
		sprite = this->currentGame->textureManager.getRef("Honda");
		break;
	case NONE:
		sprite;
		break;
	default:
		sprite = this->currentGame->textureManager.getRef("IdleNinja");
	}
}

/*
* @brief	:returns a pointer to the Physics body so that it can be changed from elsewhere
* @return	:PhysicsBody * - GameObject::m_body
*/
PhysicsBody * GameObject::getBody()
{
	return &m_body;
}

