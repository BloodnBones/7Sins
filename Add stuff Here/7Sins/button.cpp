/*
Bachelor of Software Engineering
Media Design School
Auckland
NewZealand

(c) 2005 - 2016 Media Design School

File Name	:	button.cpp
Description	:	Contains the functions associated with the button objects for setting and getting interactions
Authors		:	Tyrone Mills, Gabriel Mugadza, Mun Hou Yong, Dylan Ridgeway
mail		:	tyrone.mill6438@mediadesign.school.nz
*/

#include "button.h"
#include <iostream>
#include "Utils.h"



Button::Button()
{
}


Button::~Button()
{
}

Button::Button(int x, int y, std::string name)
{
	SetPosition(x, y);
	SetName(name);
}

void Button::Load(const sf::Texture& activeButton, const sf::Texture& button, const sf::Font& font)
{
	//m_Text.setFont(font);
	//m_Text.setFillColor(sf::Color::White);

}

void Button::Draw(Game* gameState)
{
	gameState->window.draw(m_Text);
}

void Button::SetPosition(float x, float y)
{
	m_Position.x = x;
	m_Position.y = y;
	m_Text.setPosition(x, y);
}

void Button::SetScale(float x, float y)
{
	m_Scale.x = x;
	m_Scale.y = y;
}

void Button::SetName(std::string name)
{
	m_Text.setString(name);
	m_Color = sf::Color::Black;
}

void Button::SetActive(bool toggle, const sf::Texture& activeButton, const sf::Texture& button)
{
	if (toggle)
	{
		//m_Sprite.setTexture(activeButton);
	}
	else
	{
		//m_Sprite.setTexture(button);
	}
}

void Button::SetFont(sf::Font& font)
{
	m_Text.setFont(font);
	m_Text.setCharacterSize(30);
}

/*
* @brief	:Set the color of the buttons text deafaults to black
* @param	:Color to set the text to
* @return	:None
*/
void Button::SetFillColor(sf::Color color)
{
	m_Color = color;
}

/*
* @brief	:Updates the button based on the mouse position
* @param	:Reference to the window to get mouse input from
* @return	:Bool value of wether the button was pressed
*/
bool Button::CheckButton(sf::RenderWindow& window)
{
	int x = sf::Mouse::getPosition(window).x;
	int y = sf::Mouse::getPosition(window).y;

	if (m_Text.getGlobalBounds().contains(x, y))				//Mouse movement check for color change
	{
		m_Text.setFillColor(sf::Color(255, 0, 0, 255));
		m_Text.setOutlineColor(sf::Color(0, 255, 0, 255));
		m_Text.setScale(1.1f * m_Scale);
		m_Text.setPosition(m_Position.x-3, m_Position.y - 3);
	}
	else
	{
		m_Text.setFillColor(m_Color);
		m_Text.setScale(m_Scale);
		m_Text.setPosition(m_Position);
	}

	if (m_Text.getGlobalBounds().contains(x, y) && sf::Mouse::isButtonPressed(sf::Mouse::Left))		//Check if button clicked
	{
		return true;
	}
	else
	{
		return false;
	}
}