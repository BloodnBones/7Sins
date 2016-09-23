
#include "Dependencies\soil\SOIL.h"
#include "Dependencies\include\glm\glm.hpp"
#include "Dependencies\include\glm\gtc\matrix_transform.hpp"
#include "Dependencies\include\glm\gtc\type_ptr.hpp"
#include "Shader.h"
#include "Utils.h"

#include "Dependencies\ft2build.h"
#include FT_FREETYPE_H

#include <map>
#include <string>
#include <iostream>

struct Character{
	GLuint TextureID;
	glm::ivec2 Size;		//Size of glyph
	glm::ivec2 Bearing;
	GLuint Advance;
};

class TextLabel
{
public:
	TextLabel(std::string text, std::string font);
	~TextLabel() {};

	void Render();

	void setPosition(glm::vec2 pos);
	void setColor(glm::vec3 color);
	void setScale(GLfloat scale);
	void setText(std::string text);

private:
	std::string text;
	GLfloat scale;
	glm::vec3 color;
	glm::vec2 position;

	GLuint VAO, VBO, program;
	std::map<GLchar, Character> Characters;
};

