#include <iostream>
#include "SFML\Graphics.hpp"


#pragma once
class Button
{
public:
	Button();
	~Button();

	Button(int x, int y, std::string);

	void Load(const sf::Texture& activeButton, const sf::Texture& button, const sf::Font& font);
	void Draw(sf::RenderWindow& window);

	void SetPosition(float x, float y);
	void SetScale();
	void SetNumber(std::string number);
	void SetActive(bool toggle, const sf::Texture& activeButton, const sf::Texture& button);

	bool CheckButton(int x, int y, const sf::Texture& activeButton, const sf::Texture& button);

private:
	sf::Sprite m_Sprite;

	sf::Text m_Text;
	sf::Vector2i m_Position;

	bool isLoaded;
};

