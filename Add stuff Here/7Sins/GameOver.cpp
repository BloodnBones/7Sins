#include "GameOver.h"



GameOver::GameOver(Game* gameState)
{
	this->game = gameState;

	sf::Vector2f pos = sf::Vector2f(this->game->window.getSize());
	this->m_View.setSize(pos);
	pos *= 0.5f;
	this->m_View.setCenter(pos);

	m_BackGround.setTexture(this->game->textureManager.getRef("gameBackGround"));
	m_BackGround.setPosition(0, 0);
	m_BackGround.setScale(0.8f, 0.9f);

	m_Logo.setTexture(this->game->textureManager.getRef("LogoAnim"));
	AnimatedLogo.setSprite(&m_Logo);
	AnimatedLogo.SetAnim(0, 4);

	font.loadFromFile("images/contm.ttf");

	m_Logo.setPosition(350, 0);

	m_Back.SetName("MAIN MENU");
	m_Back.SetPosition(350, 500);
	m_Back.SetScale(1, 1);
	m_Back.SetFont(font);

	m_Quit.SetName("QUIT");
	m_Quit.SetFont(font);
	m_Quit.SetScale(1, 1);
	m_Quit.SetPosition(750, 500);

	m_GameOver.setString("GAME OVER");
	m_GameOver.setPosition(420, 300);
	m_GameOver.setScale(2, 2);
	m_GameOver.setFillColor(sf::Color::Red);
	m_GameOver.setFont(font);
	m_GameOver.setCharacterSize(30);
}


GameOver::~GameOver()
{
}

/*
* @brief
* @param
* @return
*/
void
GameOver::handleInput()
{
	sf::Event event;

	while (game->window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
		{game->window.close(); }
			break;
		}
	}
}

/*
* @brief
* @param
* @return
*/
void
GameOver::update(const float dt)
{
	int i = 0;
	sf::Event events;

	game->window.pollEvent(events);

	int x = sf::Mouse::getPosition(game->window).x;
	int y = sf::Mouse::getPosition(game->window).y;

	float scale = (float)(123 + (sin(clock() / 1000) * 150));
	//animate logo

	AnimatedLogo.Animate();
	//Updates the buttons and calls the desired functions if they are clicked.
	if (m_Back.CheckButton(game->window))
	{
		game->setState(GAME_MENU);

	}
	if (m_Quit.CheckButton(game->window))
	{
		game->window.close();
	}
}

/*
* @brief
* @param
* @return
*/
void
GameOver::draw()
{
	game->window.draw(m_BackGround);
	AnimatedLogo.DrawSpriteAnim(game->window, AnimatedLogo.GetCurrentFrame(), 0, 500, 209);
	m_Quit.Draw(game);
	m_Back.Draw(game);
	game->window.draw(m_GameOver);

}