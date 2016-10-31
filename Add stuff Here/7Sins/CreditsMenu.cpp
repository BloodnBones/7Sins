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


#include "CreditsMenu.h"


/*
*	@brief	:
*	@param	:
*	@retrun	:
*/
CreditsMenu::CreditsMenu(Game * gameState)
{
	this->game = gameState;

	sf::Vector2f pos = sf::Vector2f(this->game->window.getSize());
	this->view.setSize(pos);
	pos *= 0.5f;
	this->view.setCenter(pos);

	backGround.setTexture(this->game->textureManager.getRef("gameBackGround"));
	backGround.setPosition(0, 0);
	backGround.setScale(0.8f, 0.9f);

	Logo.setTexture(this->game->textureManager.getRef("LogoAnim"));
	AnimatedLogo.setSprite(&Logo);
	AnimatedLogo.SetAnim(0, 8);
	AnimatedLogo.SetFrameRate(70);

	font.loadFromFile("images/Bad Coma.ttf");

	Logo.setPosition(350, 0);

	back.SetName("BACK");
	back.SetPosition(300, 420);
	back.SetScale(2.0f, 2.0f);
	back.SetFont(font);

	//_back.setString("BACK");
	//_back.setPosition(300, 420);
	//_back.setScale(2.1f, 2.1f);
	//_back.setFont(font);
	//_back.setFillColor(sf::Color::Black);

	quit.SetName("QUIT");
	quit.SetFont(font);
	quit.SetScale(2, 2);
	quit.SetPosition(600, 420);

	//_quit.setString("QUIT");
	//_quit.setPosition(600, 420);
	//_quit.setScale(2.1f, 2.1f);
	//_quit.setFont(font);
	//_quit.setFillColor(sf::Color::Black);


	_Tyrone.setString("TYRONE MILLS");
	_Tyrone.setPosition(400, 250);
	_Tyrone.setScale(1.0f, 1.0f);
	_Tyrone.setFont(font);
	_Tyrone.setFillColor(sf::Color::Black);

	_Dylan.setString("DYLAN RIDGWAY");
	_Dylan.setPosition(400, 280);
	_Dylan.setScale(1.0f, 1.0f);
	_Dylan.setFont(font);
	_Dylan.setFillColor(sf::Color::Black);

	_Gabriel.setString("GABRIEL MUGADZA");
	_Gabriel.setPosition(400, 310);
	_Gabriel.setScale(1.0f, 1.0f);
	_Gabriel.setFont(font);
	_Gabriel.setFillColor(sf::Color::Black);

	_Mun.setString("MUN HOU YONG");
	_Mun.setPosition(400, 340);
	_Mun.setScale(1.0f, 1.0f);
	_Mun.setFont(font);
	_Mun.setFillColor(sf::Color::Black);

}

/*
*	@brief	:
*	@param	:
*	@retrun	:
*/
void CreditsMenu::draw()
{
	game->window.draw(backGround);
	AnimatedLogo.DrawSpriteAnim(game->window, AnimatedLogo.GetCurrentFrame(), 0, 500, 209);

	//game->window.draw(_back);
	//game->window.draw(_quit);

	game->window.draw(_Tyrone);
	game->window.draw(_Dylan);
	game->window.draw(_Gabriel);
	game->window.draw(_Mun);

	back.Draw(game);
	quit.Draw(game);


}

/*
*	@brief	:
*	@param	:
*	@retrun	:
*/
void CreditsMenu::update(const float dt)
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
	if (back.CheckButton(game->window))
	{
		game->setState(GAME_MENU);
	}
	if (quit.CheckButton(game->window))
	{
		game->window.close();
	}
}

/*
*	@brief	:
*	@param	:
*	@retrun	:
*/
void CreditsMenu::handleInput()
{
}

