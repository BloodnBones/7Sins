#include "Menu.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

/*
* @brief
* @param
* @return
*/
Menu::Menu()
{
}

/*
* @brief
* @param
* @return
*/
Menu::~Menu()
{
}

/*
* @brief	Intitialises a Menu object with required data
* @param	Width of the Screen
* @param	Height of the screen
* @param	Pathway to the desired font as a string
* @param	Vector of strings with the option names
* @param	Column alignment of buttons
* @param	Row alignment of buttons
* @param	Color of the Text to be displayed
* @return	None
*
*/
void Menu::Init(GLuint Width, GLuint Height, std::string font, std::vector<std::string> Options, Column col, Row row, glm::vec3 Color)
{
	for(auto const& itter: Options)
	{ 
		glm::vec2  Pos;

		if (col == 0)
		{
			Pos.x = 20.0f;
		}
		else if (col == 1)
		{
			Pos.x = Width / 2;
			Pos.x -= (itter.size() / 2) * 30;
		}
		else { Pos.x = Width - (itter.size() * 10); }

		Pos.y = Width / 2;
		Pos.y += (itter.size() / 2) * 20;

		TextLabel Label(itter, font);
		Label.setColor(Color);
		Label.setPosition(Pos);
		Buttons.push_back(Label);
	}
}

/*
* @brief
* @param
* @return
*/
void Menu::Draw()
{
	for (unsigned int i =0; i < Buttons.size(); ++i)
	{
		Buttons[i].Render();
	}
}

/*
* @brief
* @param
* @return
*/
int Menu::Update()
{


	return 0;
}