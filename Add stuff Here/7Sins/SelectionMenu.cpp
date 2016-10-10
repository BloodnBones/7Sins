#include "SelectionMenu.h"
#include "MainGame.h"

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
	m_P1Current.setString("LUCIA");
	m_P1Current.setPosition(200, 400);
	m_P1Current.setScale(1, 1);
	m_P1Current.setFont(font);
	m_P1Current.setFillColor(sf::Color::Black);
	m_P1Current.setCharacterSize(30);

	m_P2Current.setString("LUCIA");
	m_P2Current.setPosition(400, 400);
	m_P2Current.setScale(1, 1);
	m_P2Current.setFont(font);
	m_P2Current.setFillColor(sf::Color::Black);
	m_P2Current.setCharacterSize(30);

	m_P3Current.setString("LUCIA");
	m_P3Current.setPosition(600, 400);
	m_P3Current.setScale(1, 1);
	m_P3Current.setFont(font);
	m_P3Current.setFillColor(sf::Color::Black);
	m_P3Current.setCharacterSize(30);;

	m_P4Current.setString("LUCIA");
	m_P4Current.setPosition(800, 400);
	m_P4Current.setScale(1, 1);
	m_P4Current.setFont(font);
	m_P4Current.setFillColor(sf::Color::Black);
	m_P4Current.setCharacterSize(30);

	m_Player1.setString("PLAYER 1");
	m_Player1.setPosition(200, 100);
	m_Player1.setScale(1, 1);
	m_Player1.setFont(font);
	m_Player1.setFillColor(sf::Color::Black);
	m_Player1.setCharacterSize(30);

	m_Player2.setString("PLAYER 2");
	m_Player2.setPosition(400, 100);
	m_Player2.setScale(1, 1);
	m_Player2.setFont(font);
	m_Player2.setFillColor(sf::Color::Black);
	m_Player2.setCharacterSize(30);

	m_Player3.setString("PLAYER 3");
	m_Player3.setPosition(600, 100);
	m_Player3.setScale(1, 1);
	m_Player3.setFont(font);
	m_Player3.setFillColor(sf::Color::Black);
	m_Player3.setCharacterSize(30);

	m_Player4.setString("PLAYER 4");
	m_Player4.setPosition(800, 100);
	m_Player4.setFont(font);
	m_Player4.setScale(1, 1);
	m_Player4.setFillColor(sf::Color::Black);
	m_Player4.setCharacterSize(30);

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
		case sf::Event::KeyReleased:
			switch (event.key.code)
			{
			case sf::Keyboard::A:
				if (m_P1Choice > 0 && !m_Player1Chosen)
				{
					m_P1Choice--;
				}
				break;
			case sf::Keyboard::D:
				if (m_P1Choice < 7 && !m_Player1Chosen)
				{
					m_P1Choice++;
				}
				break;
			case sf::Keyboard::Space:
			{
				m_Player1Chosen = true;
				m_Player1.setFillColor(sf::Color::Green);
				Taken(m_P1Choice);
			}break;
			case sf::Keyboard::Right:
			{
				if (m_P2Choice < 7 && !m_Player2Chosen)
				{
					m_P2Choice++;
				}
			}	break;
			case sf::Keyboard::Left:
			{	if (m_P2Choice > 0 && !m_Player2Chosen)
			{
				m_P2Choice--;
			}
			}	break;
			case sf::Keyboard::Return:
			{
				m_Player2Chosen = true;
				m_Player2.setFillColor(sf::Color::Green);
				Taken(m_P2Choice);
			}break;
			}
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

	SetChoice(&m_P1Current, m_P1Choice);
	SetChoice(&m_P2Current, m_P2Choice);
	SetChoice(&m_P3Current, m_P3Choice);
	SetChoice(&m_P4Current, m_P4Choice);

	//Updates the buttons and calls the desired functions if they are clicked.
	//if (lucia.CheckButton(game->window))
	{
		//	std::cout << "Sorry I don't do anything" << std::endl;
			//Check which controller clicked
			//Assign character to that controler
			//Add this to the vector
			//if (joystic1) then
			//GameObject1 = new ....lucia;
	}

	if (done.CheckButton(game->window))
	{
		//GameObject1 = new GameObject()
		//game->pushState(GAME_PLAY, new MainGame(game, m_P1Choice, m_P2Choice, m_P3Choice, m_P4Choice));
		game->pushState(GAME_PLAY, new MainGame(game));
		game->setState(GAME_PLAY);
		//game->setState(GAME_MENU);
		Reset();
	}
	if (back.CheckButton(game->window))
	{
		Reset();
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

	game->window.draw(m_Player1);
	game->window.draw(m_Player2);
	game->window.draw(m_Player3);
	game->window.draw(m_Player4);

	game->window.draw(m_P1Current);
	game->window.draw(m_P2Current);
	game->window.draw(m_P3Current);
	game->window.draw(m_P4Current);

	done.Draw(game);
	back.Draw(game);
	quit.Draw(game);
}

/*
* @brief	:Updates the name of the character the player has currently selected
* @param	:Text* - The text deisplayinjg the current characters name
* @param	:int - th numeric value of the currently selected player
* @return	:None
*/
void SelectionMenu::SetChoice(sf::Text* text, int choice)
{
	switch (choice)
	{
	case Lucia:
	{	text->setString("LUCIA"); }
	break;
	case Gabriel:
	{	text->setString("GABRIEL"); }
	break;
	case Joshua:
	{text->setString("JOSHUA"); }
	break;
	case Betty:
	{	text->setString("BETTY"); }
	break;
	case Matthew:
	{text->setString("MATTHEW"); }
	break;
	case Satella:
	{text->setString("SATELLA"); }
	break;
	case Honda:
	{text->setString("HONDA"); }
	break;
	case NONE:
	{text->setString(""); }
	break;
	default:
	{text->setString("Error"); }
	}
}

/*
* @brief	:
* @param	:
* @return	:
*/
void SelectionMenu::Taken(int choice)
{
	switch (choice)
	{
	case Lucia:
	{lucia = true; }
	break;
	case Gabriel:
	{gabriel = true; }
	break;
	case Joshua:
	{joshua = true; }
	break;
	case Betty:
	{betty = true; }
	break;
	case Matthew:
	{matthew = true; }
	break;
	case Satella:
	{satella = true; }
	break;
	case Honda:
	{honda = true; }
	break;
	case NONE:
	{ }break;
	default:
	{}
	}
}

void SelectionMenu::Reset()
{
	lucia = false;
	gabriel = false;
	joshua = false;
	betty = false;
	matthew = false;
	satella = false;
	honda = false;

	m_P1Choice = NONE;
	m_P2Choice = NONE;
	m_P3Choice = NONE;
	m_P4Choice = NONE;

	m_Player1Chosen = false;
	m_Player2Chosen = false;
	m_Player3Chosen = false;
	m_Player4Chosen = false;

	m_Player1.setFillColor(sf::Color::Black);
	m_Player2.setFillColor(sf::Color::Black);
	m_Player3.setFillColor(sf::Color::Black);
	m_Player4.setFillColor(sf::Color::Black);
}