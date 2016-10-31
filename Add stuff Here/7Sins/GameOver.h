#pragma once
#include "GameState.h"
#include "Utils.h"
#include "button.h"
#include "Animation.h"


class GameOver : public GameState
{
public:
	GameOver(Game* gameState);
	~GameOver();

	virtual void draw();
	virtual void update(const float dt);
	virtual void handleInput();

private:
	Animation AnimatedLogo;
	sf::View m_View;
	Button m_Back;
	Button m_Quit;
	sf::Text m_GameOver;
	sf::Sprite m_BackGround;
	sf::Sprite m_Logo;
	sf::Font font;
};

