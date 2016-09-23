#ifndef MENU_H
#define MENU_H

//Local Includes
#include "Utils.h"
#include "TextLabel.h"

//Library Includes
#include <vector>
enum Column{
	LEFT = 0,
	COL_MIDDLE = 1,
	RIGHT = 2
};

enum Row {
	TOP = 0,
	ROW_MIDDLE = 1,
	BOTTOM = 2
};

class Menu
{
public:
	Menu();
	~Menu();

	void Init(GLuint Width, GLuint Height, std::string font, std::vector<std::string> Options, Column col, Row row, glm::vec3 Color);
	int Update();
	void Draw();


private:
	std::vector<TextLabel>	Buttons;
	GLuint					Width, Height;

};


#endif // !MENU_H
