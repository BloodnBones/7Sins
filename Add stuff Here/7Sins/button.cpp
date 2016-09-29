#include "button.h"
#include <iostream>



Button::Button()
{
}


Button::~Button()
{
}

Button::Button(int x, int y, std::string number)
{
	SetPosition(x, y);
	SetNumber(number);
}

void Button::Load(const sf::Texture& activeButton, const sf::Texture& button, const sf::Font& font)
{
	m_Text.setFont(font);
	m_Text.setFillColor(sf::Color::Black);
	m_Sprite.setTexture(button);

}

void Button::Draw(sf::RenderWindow& renderWindow)
{

	renderWindow.draw(m_Sprite);
	renderWindow.draw(m_Text);
}

void Button::SetPosition(float x, float y)
{
	m_Position.x = x;
	m_Position.y = y;
	m_Sprite.setPosition(x, y);
	m_Text.setPosition(x+22, y+12);
}

void Button::SetScale()
{
	m_Sprite.scale(sf::Vector2f(2.2f, 1.0f));
}

void Button::SetNumber(std::string number)
{
	m_Text.setString(number);
}

void Button::SetActive(bool toggle, const sf::Texture& activeButton, const sf::Texture& button)
{
	if (toggle)
	{
		m_Sprite.setTexture(activeButton);
	}
	else
	{
		m_Sprite.setTexture(button);
	}
}

bool Button::CheckButton(int x, int y, const sf::Texture& activeButton, const sf::Texture& button)
{
	if (x >= m_Position.x && x <= m_Position.x + 60 && y >= m_Position.y && y <= m_Position.y + 60)
	{
		SetActive(true, activeButton, button);
		return true;
	}
	else
	{
		SetActive(false, activeButton, button);
		return false;
	}
}