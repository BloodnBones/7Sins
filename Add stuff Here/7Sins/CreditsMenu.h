#pragma once
#include "GameState.h"
#include "button.h"
#include "Animation.h"

class CreditsMenu :	public GameState
{
public:
	CreditsMenu(Game* gameState);

	virtual void draw();
	virtual void update(const float dt);
	virtual void handleInput();

private:
	Animation AnimatedLogo;
	bool reverse = false;
	sf::View view;
	sf::Sprite backGround;
	sf::Clock deltaTime;
	sf::Sprite Logo;
	sf::Text _back;
	sf::Text _quit;
	sf::Font font;
	sf::Text _TeamMembers;
	sf::Text _Tyrone;
	sf::Text _Dylan;
	sf::Text _Gabriel;
	sf::Text _Mun;
	Button back;
	Button quit;
};

