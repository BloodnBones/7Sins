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

#include <iostream>
#include "include\SFML\Graphics.hpp"
#include "Game.h"

#pragma once
class Button
{
public:
	Button();
	~Button();

	Button(int x, int y, std::string);

	void Load(const sf::Texture& activeButton, const sf::Texture& button, const sf::Font& font);
	void Draw(Game* gameState);

	void SetPosition(float x, float y);
	void SetScale(float x, float y);
	void SetName(std::string number);
	void SetActive(bool toggle, const sf::Texture& activeButton, const sf::Texture& button);
	void SetFont(sf::Font& font);
	void SetFillColor(sf::Color color);

	bool CheckButton(sf::RenderWindow& window);

private:
	sf::Text m_Text;
	sf::Vector2f m_Scale;
	sf::Vector2f m_Position;
	sf::Color m_Color;

	bool isLoaded;
};

