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
			,	myemail@gmail.email
			,
			,
*/

#include "GameObject.h"


#define TEMPJUMP 700.0f
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
	m_fJumpCooldown = 10.0f;
	m_fChargeCooldown = 0.0f;
	m_JumpPower = TEMPJUMP;

	PlayerIndex = Index;
	currentGame = gameptr;
	m_world = aWorld;
	m_type = type;
	sprite.setTexture(image);
	offset = gameTime * 0.3f;
	if (m_type == BodyType::Player)
	{
		if (Index == 0)
		{
			xpos = 500;
			ypos = 00;
		}
		else
		{
			xpos = 668;
			ypos = 00;
		}
	}
	origin_x = 120;
	origin_y = 120;
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
	m_JumpPower = TEMPJUMP;
	m_fJumpCooldown = 10.0f;
	m_fChargeCooldown = 0.0f;
	PlayerIndex = Index;
	currentGame = gameptr;
	m_world = aWorld;
	m_type = type;
	LoadCharacterImage(character);
	offset = gameTime * 0.3f;
	
	switch (character)
	{
	case Lucia:
	{
		xpos = 100;
		ypos = 0;
		origin_x = 125 /2;
		origin_y = 198/2;
	}
	break;
	case Gabriel:
	{
		xpos = 280;
		ypos = 0;
		origin_x = 125/2;
		origin_y = 198/2;
	}
	break;
	case Joshua:
	{
		xpos = 390;
		ypos = 0;
		origin_x = 125/2;
		origin_y = 198/2;
	}
	break;
	case Betty:
	{
		xpos = 400;
		ypos = 0;
		origin_x = 20;
		origin_y = 40;
	}
	break;
	case Matthew:
	{
		xpos = 510;
		ypos = 0;
		origin_x = 125 / 2;
		origin_y = 198 / 2;
	}
	break;
	case Satella:
	{
		xpos = 620;
		ypos = 0;
		origin_x = 125;
		origin_y = 198;
	}
	break;
	case Honda:
	{
		xpos = 730;
		ypos = 0;
		origin_x = 125;
		origin_y = 198;
	}
	break;
	default:
	{
		xpos = 130;
		ypos = 0;
		origin_x = 125;
		origin_y = 198;
	}
	}
	fill = sf::Color(255, 0, 255, 255);
	SetPhysicsBox();
	if (m_type == BodyType::Player)
	{
		m_body._BodyPtr->SetActive(true);
	}

	//TO DO finalise values for character max speed and density
	//Dylan set unique charge amounts here
#pragma region CharacterStats
	switch (character)		
	{						
	case Lucia:
	{
		MAX_VELOCITY = 10.0f;
		m_body._FixtureDef.density = 16.0f;
	}
	break;
	case Gabriel:
	{
		MAX_VELOCITY = 7.0f;
		m_body._FixtureDef.density = 25.0f;
	}
	break;
	case Joshua:
	{
		MAX_VELOCITY = 7.5f;
		m_body._FixtureDef.density = 22.0f;
	}
	break;
	case Betty:
	{
		MAX_VELOCITY = 5.0f;
		m_body._FixtureDef.density = 20.0f;
	}
	break;
	case Matthew:
	{
		MAX_VELOCITY = 8.0f;
		m_body._FixtureDef.density = 20.0f;
	}
	break;
	case Satella:
	{
		MAX_VELOCITY = 7.0f;
		m_body._FixtureDef.density = 20.0f;
	}
	break;
	case Honda:
	{
		MAX_VELOCITY = 9.0f;
		m_body._FixtureDef.density = 18.0f;
	}
	break;
	default:
	{
		MAX_VELOCITY = 7.0f;
		m_body._FixtureDef.density = 20.0f;
	}
	}
#pragma endregion
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
	m_JumpPower = TEMPJUMP;
	m_fJumpCooldown = 10.0f;
	m_fChargeCooldown = 0.0f;
	m_world = aWorld;
	m_type = type;
	sprite.setTexture(image);
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
	currentGame = nullptr;
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
	m_body._Sprite = sprite;
	m_body._RECT = sf::RectangleShape(sf::Vector2f(origin_x , origin_y));
	m_body._RECT.setOrigin(origin_x / 2, origin_y / 2);
	m_body._RECT.setTexture(sprite.getTexture());
	m_body._BodyDef.position.Set(xpos / RATIO, ypos / RATIO);
	m_body._BodyDef.type = b2_dynamicBody;
	m_body._BodyShape.SetAsBox((origin_x/2) / RATIO, (origin_y / 2) / RATIO);
	m_body._FixtureDef.shape = &m_body._BodyShape;
	m_body._FixtureDef.density = 20.0f;
	m_body._FixtureDef.restitution = 0.02f;
	m_body._FixtureDef.friction = 0.9f;
	m_body._BodyPtr = m_world->CreateBody(&m_body._BodyDef);
	m_body._BodyPtr->CreateFixture(&m_body._FixtureDef);
	m_body._BodyPtr->SetUserData(&m_body);
	m_body._BodyPtr->SetFixedRotation(true);
	m_body._BodyPtr->SetAngularDamping(100.0f);
	bodyDef.position.Set(0, 0);
	groundBody = m_world->CreateBody(&bodyDef);
	m_body.type = m_type;
	if (m_type == BodyType::Enemy)
	{
		m_body.HP = 3;
	}
	Animate.setSprite(&m_body._Sprite);
	Animate.SetAnim(0, 8);

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
		//Player 3
		else if (PlayerIndex == 2)
		{
			Player3Input();
		}
		//Player 4
		else if (PlayerIndex == 3)
		{
			Player4Input();
		}
	}
}

/*
* @brief	:draws to window
* @return	:void
*/
void GameObject::draw()
{
	/*if (PlayerIndex == 0)
	{
		Animate.DrawSpriteAnim(currentGame->window, Animate.GetCurrentFrame(), 0, 165, 198);
	}
	else
	{
		Animate.DrawSprite(currentGame->window);
	}*/
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

}

/*
* @brief	:updates the object
* @return	:void
*/
void GameObject::update()
{
	m_fChargeCooldown += deltaTime.asSeconds();
	m_fJumpCooldown += deltaTime.asSeconds();
	float rotationAngle;
	Animate.Animate();
	xpos = (float)((m_body._BodyPtr->GetPosition().x * RATIO));
	ypos = (m_body._BodyPtr->GetPosition().y * RATIO);
	rotationAngle = m_body._BodyPtr->GetAngle();
	m_body._RECT.setRotation(rotationAngle * (float)-57.295);
	m_body._RECT.setPosition(xpos, ypos);


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
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) )
	{
		float a = (m_fChargeCooldown * 10000);
		if (a > 1.0f) {
			//m_body._BodyPtr->SetLinearVelocity(b2Vec2(m_body._BodyPtr->GetLinearVelocity().x * 5.0f, 1.0f));
			int b = 1; if (current_Velocity.x < 0) { b = -1; }
			m_body._BodyPtr->ApplyLinearImpulseToCenter(b2Vec2(b * (std::abs(current_Velocity.x) + 1200 * 50), current_Velocity.y), true);
			m_fChargeCooldown = 0.0f;
		}
		
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && current_Velocity.x > -MAX_VELOCITY)
	{
		m_body._BodyPtr->ApplyLinearImpulse(b2Vec2(-100, 0), m_body._BodyPtr->GetWorldCenter(), true);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && current_Velocity.x < MAX_VELOCITY)
	{
		m_body._BodyPtr->ApplyLinearImpulse(b2Vec2(100, 0), m_body._BodyPtr->GetWorldCenter(), true);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		//if (isGrounded)
		//{
		float a = (m_fJumpCooldown * 10000);
		if (m_body.Touching == true) {
			m_body._BodyPtr->ApplyLinearImpulse(b2Vec2(current_Velocity.x, -m_JumpPower), m_body._BodyPtr->GetWorldCenter(), true);
			m_fJumpCooldown = 0.0f;
		}
		//}
	}
	if (sf::Joystick::isConnected(0))			//Checks if a joystick(controller) is plugged in 
	{
		float x = sf::Joystick::getAxisPosition(0, sf::Joystick::X);
		m_body._BodyPtr->ApplyLinearImpulse(b2Vec2(x, 0), m_body._BodyPtr->GetWorldCenter(), true);
	}
	//Checks for button on controller being pressed
	if (sf::Joystick::isButtonPressed(0, 1) && isGrounded)
	{
		m_body._BodyPtr->ApplyLinearImpulse(b2Vec2(0, -5), m_body._BodyPtr->GetWorldCenter(), true);

	}
}

/*
* @brief	:Process the iputs for each player
* @param
* @return
*/
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

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::RShift))
	{
		float a = (m_fChargeCooldown * 10000);
		if (a > 1.0f) {
			//m_body._BodyPtr->SetLinearVelocity(b2Vec2(m_body._BodyPtr->GetLinearVelocity().x * 5.0f, 1.0f));
			int b = 1; if (current_Velocity.x < 0) { b = -1; }
			m_body._BodyPtr->ApplyLinearImpulseToCenter(b2Vec2(b * (std::abs(current_Velocity.x) + 1200 * 50), current_Velocity.y), true);
			m_fChargeCooldown = 0.0f;
		}

	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && current_Velocity.x > -MAX_VELOCITY)
	{
		m_body._BodyPtr->ApplyLinearImpulse(b2Vec2(-170, 0), m_body._BodyPtr->GetWorldCenter(), true);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && current_Velocity.x < MAX_VELOCITY)
	{
		m_body._BodyPtr->ApplyLinearImpulse(b2Vec2(170, 0), m_body._BodyPtr->GetWorldCenter(), true);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad0))
	{
		//if (isGrounded)
		//{
		float a = (m_fJumpCooldown * 10000);
		if (m_body.Touching == true) {
			m_body._BodyPtr->ApplyLinearImpulse(b2Vec2(current_Velocity.x, -m_JumpPower), m_body._BodyPtr->GetWorldCenter(), true);
			m_fJumpCooldown = 0.0f;
		}
		//}
	}
	if (sf::Joystick::isConnected(1))			//Checks if a joystick(controller) is plugged in 
	{
		float x = sf::Joystick::getAxisPosition(1, sf::Joystick::X);
		m_body._BodyPtr->ApplyLinearImpulse(b2Vec2(x, 0), m_body._BodyPtr->GetWorldCenter(), true);
	}
	//Checks for button on controller being pressed
	if (sf::Joystick::isButtonPressed(1, 1) && isGrounded)
	{
		m_body._BodyPtr->ApplyLinearImpulse(b2Vec2(0, -5), m_body._BodyPtr->GetWorldCenter(), true);

	}
}

/*
* @brief	:Process the iputs for each player
* @param
* @return
*/
void GameObject::Player3Input()
{
	b2Vec2 current_Velocity = m_body._BodyPtr->GetLinearVelocity();
	//Damp the velocity when not moving
	if (sf::Joystick::isConnected(2))			//Checks if a joystick(controller) is plugged in 
	{
		float x = sf::Joystick::getAxisPosition(2, sf::Joystick::X);
		m_body._BodyPtr->ApplyLinearImpulse(b2Vec2(x, 0), m_body._BodyPtr->GetWorldCenter(), true);

		//Checks for button on controller being pressed
		if (sf::Joystick::isButtonPressed(2, 1) && isGrounded)
		{
			m_body._BodyPtr->ApplyLinearImpulse(b2Vec2(0, -5), m_body._BodyPtr->GetWorldCenter(), true);

		}

	}
}

/*
* @brief	:Process the iputs for each player
* @param
* @return
*/
void GameObject::Player4Input()
{
	b2Vec2 current_Velocity = m_body._BodyPtr->GetLinearVelocity();
	//Damp the velocity when not moving
	if (sf::Joystick::isConnected(3))			//Checks if a joystick(controller) is plugged in 
	{
		float x = sf::Joystick::getAxisPosition(3, sf::Joystick::X);
		m_body._BodyPtr->ApplyLinearImpulse(b2Vec2(x, 0), m_body._BodyPtr->GetWorldCenter(), true);

		//Checks for button on controller being pressed
		if (sf::Joystick::isButtonPressed(3, 1) && isGrounded)
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
		sprite.setTexture(this->currentGame->textureManager.getRef("Lust"));
		break;
	case Gabriel:
		sprite.setTexture(this->currentGame->textureManager.getRef("Gluttony"));
		break;
	case Joshua:
		sprite.setTexture(this->currentGame->textureManager.getRef("Greed"));
		break;
	case Betty:
		sprite.setTexture(this->currentGame->textureManager.getRef("Sloth"));
		break;
	case Matthew:
		sprite.setTexture(this->currentGame->textureManager.getRef("Wrath"));
		break;
	case Satella:
		sprite.setTexture(this->currentGame->textureManager.getRef("Envy"));
		break;
	case Honda:
		sprite.setTexture(this->currentGame->textureManager.getRef("Pride"));
		break;
	case NONE:
		sprite;
		break;
	default:
		sprite.setTexture(this->currentGame->textureManager.getRef("Wrath"));
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

