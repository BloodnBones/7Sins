#include "SelectionMenu.h"


/*
* @brief	:Constructor for the player selecetion menu
* @param	:Pointer to the game state
*
*/
SelectionMenu::SelectionMenu(Game* gameState)
{
	this->game = gameState;

	backGround.setTexture(this->game->textureManager.getRef("gameBackGround"));
	backGround.setPosition(0, 0);
	backGround.setScale(0.8f, 0.9f);

	font.loadFromFile("images/contm.ttf");

	//Character Buttons
	lucia.SetName("LUCIA");
	lucia.SetPosition(100, 350);
	lucia.SetScale(1, 1);
	lucia.SetFont(font);

	gabriel.SetName("GABRIEL");
	gabriel.SetPosition(230, 350);
	gabriel.SetScale(1, 1);
	gabriel.SetFont(font);

	joshua.SetName("JOSHUA");
	joshua.SetPosition(380, 350);
	joshua.SetScale(1, 1);
	joshua.SetFont(font);

	betty.SetName("BETTY");
	betty.SetPosition(520, 350);
	betty.SetScale(1, 1);
	betty.SetFont(font);

	matthew.SetName("MATTHEW");
	matthew.SetPosition(630, 350);
	matthew.SetScale(1, 1);
	matthew.SetFont(font);

	satella.SetName("SATELLA");
	satella.SetPosition(800, 350);
	satella.SetScale(1, 1);
	satella.SetFont(font);

	honda.SetName("HONDA");
	honda.SetPosition(970, 350);
	honda.SetScale(1, 1);
	honda.SetFont(font);

	//Menu Buttons
	done.SetName("DONE");
	done.SetPosition(200, 500);
	done.SetScale(1, 1);
	done.SetFont(font);
	done.SetFillColor(sf::Color::White);			//If not used color will be black

	back.SetName("BACK");
	back.SetPosition(500, 500);
	back.SetScale(1, 1);
	back.SetFont(font);
	back.SetFillColor(sf::Color::White);

	quit.SetName("QUIT");
	quit.SetPosition(800, 500);
	quit.SetScale(1, 1);
	quit.SetFont(font);
	quit.SetFillColor(sf::Color::White);
}

/*
* @brief	:Handles close button event
* @param	:None
* @return	:None
*/
void
SelectionMenu::handleInput()
{
	sf::Event event;

	while (game->window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			game->window.close();
			break;
		}
	}
}

/*
* @brief	:Updates the menubased on player input and selection
* @param	:delta time
* @return	:None
*/
void
SelectionMenu::update(const float dt)
{
	int i = 0;
	sf::Event events;

	game->window.pollEvent(events);

	int x = sf::Mouse::getPosition(game->window).x;
	int y = sf::Mouse::getPosition(game->window).y;

	float scale = 123 + (sin(clock() / 1000) * 150);

	//Updates the buttons and calls the desired functions if they are clicked.
	if (lucia.CheckButton(game->window))
	{
		std::cout << "Sorry I don't do anything" << std::endl;
	}
	if (gabriel.CheckButton(game->window))
	{
		std::cout << "Sorry I don't do anything" << std::endl;
	}
	if (joshua.CheckButton(game->window))
	{
		std::cout << "Sorry I don't do anything" << std::endl;
	}
	if (betty.CheckButton(game->window))
	{
		std::cout << "Sorry I don't do anything" << std::endl;
	}
	if (matthew.CheckButton(game->window))
	{
		std::cout << "Sorry I don't do anything" << std::endl;
	}
	if (satella.CheckButton(game->window))
	{
		std::cout << "Sorry I don't do anything" << std::endl;
	}
	if (honda.CheckButton(game->window))
	{
		std::cout << "Sorry I don't do anything" << std::endl;
	}

	if (done.CheckButton(game->window))
	{
		std::cout << "Sorry I don't do anything" << std::endl;
		game->setState(GAME_MENU);
	}
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
* @brief	:Calls to each button to draw to the gaem window
* @param	:None
* @return	:None
*/
void
SelectionMenu::draw()
{
	game->window.draw(backGround);

	lucia.Draw(game);
	gabriel.Draw(game);
	joshua.Draw(game);
	betty.Draw(game);
	matthew.Draw(game);
	satella.Draw(game);
	honda.Draw(game);

	done.Draw(game);
	back.Draw(game);
	quit.Draw(game);
}