#include "Menu.h"


Menu::Menu()
{
}

Menu::~Menu()
{
}



/*
* @brief	Intitialises a Menu object with required data
* @param
* @param
* @param
* @param
* @param
* @param
* @param
* @return	None
*
*/
void Menu::Init(GLuint Width, GLuint Height, std::string font, std::vector<std::string> Options, Column col, Row row, glm::vec3 Color)
{
	int x = (Width/2) * col;
	int y = (Height / 2) * row;
	
	for(auto const& itter: Options)
	{ 
		TextLabel Label(itter, font);
		Label.setColor(Color);
	}
}


void Menu::Draw()
{

}


int Menu::Update()
{
	return 0;
}