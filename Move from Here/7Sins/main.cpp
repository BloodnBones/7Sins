#include "Globals.h"
#include "MainWorld.h"
#include "GameObject.h"
#include "Scene.h"
using namespace sf;

sf::RenderWindow App;
bool g_fullscreen;
bool worldset = false;
int main()
{
	int lvlindex = 1;
	g_fullscreen = false;
	//create the window
	App.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP),
		"GameObjects", !sf::Style::Resize | sf::Style::Close);

	////Sound Stuff
	//sf::SoundBuffer buff;
	//buff.loadFromFile("Assets/Sounds/JoJos Bizarre Adventure - Escape from DIO.wav");

	//sf::Sound bk_music;
	//bk_music.setBuffer(buff);
	//bk_music.setLoop(true);

	////bk_music.play();

	//Game stuff
	MainWorld *Level1 = new MainWorld();
	GameObject *GameObject1 =new GameObject(Level1->GetWorld(), Level1->getRes(0).img_player, BodyType::Player);
	GameObject *GameObject2 =new GameObject(Level1->GetWorld(), Level1->getRes(0).img_player, BodyType::Player);
	std::vector<GameObject *> GameObjectList;

	GameObjectList.push_back(GameObject1);
	GameObjectList.push_back(GameObject2);
	Scene* Current = new Scene(Level1->GetWorld(), GameObjectList, Level1->getRes(0).img_background, lvlindex);

	//this is the start of the main game loop
	while (App.isOpen()) {
		if (!Current->isWon)
		{

			Level1->GetWorld()->Step(Level1->GeTimeStep(), Level1->getVIterations(), Level1->getPIterations());

			//process any events
			sf::Event events;
			while (App.pollEvent(events)) {
				Current->input(events);
				switch (events.type) {
				case sf::Event::Closed:
					App.close(); //close application
					break;
				case sf::Event::KeyPressed:
					//exit with escape
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
						App.close();
					//fullscreen wih F11
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::F11)) {
						if (g_fullscreen == false) {
							App.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP), "GameObjects", sf::Style::Fullscreen);
							g_fullscreen = true;
						}
						else {
							App.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP), "GameObjects", !sf::Style::Resize | sf::Style::Close);
							g_fullscreen = false;
						}
					}
				}
			}
			App.clear(sf::Color(000, 000, 100));  //no color = black

			if (!Current->isWon)
			{
				Current->update(); //kill things
				Current->draw(); //draw everything
			}
			App.display();//display window contents
		}
		else
		{
			if (lvlindex == 1)
			{
				//remake world
				Level1 = nullptr;
				Level1 = new MainWorld();

				//remake GameObjects
				for (std::vector< GameObject *>::iterator it = GameObjectList.begin(); it != GameObjectList.end(); ++it)
				{
					delete (*it);
				}
				GameObjectList.clear();

				GameObject1 = new GameObject(Level1->GetWorld(), Level1->getRes(0).img_player, BodyType::Player);
				GameObject2 = new GameObject(Level1->GetWorld(), Level1->getRes(0).img_player, BodyType::Player);

				GameObjectList.push_back(GameObject1);
				GameObjectList.push_back(GameObject2);

				//remake level
				lvlindex++;
				Current = nullptr;
				Current = new Scene(Level1->GetWorld(), GameObjectList, Level1->getRes(0).img_background, lvlindex);
			}
			else
			{
				Level1 = nullptr;
				Level1 = new MainWorld();


				for (std::vector< GameObject *>::iterator it = GameObjectList.begin(); it != GameObjectList.end(); ++it)
				{
					delete (*it);
				}
				GameObjectList.clear();

				GameObject1 = new GameObject(Level1->GetWorld(), Level1->getRes(0).img_player, BodyType::Player);
				GameObject2 = new GameObject(Level1->GetWorld(), Level1->getRes(0).img_player, BodyType::Player);

				GameObjectList.push_back(GameObject1);
				GameObjectList.push_back(GameObject2);

				lvlindex--;
				Current = nullptr;
				Current = new Scene(Level1->GetWorld(), GameObjectList, Level1->getRes(0).img_background, lvlindex);
			}
		}
		
	}

	delete Level1;
	return 0;
}