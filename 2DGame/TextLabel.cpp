#include "TextLabel.h"



TextLabel::TextLabel(std::string text, std::string font)
{
	this->text = text;
	this->color = glm::vec3(1.0, 0.0, 1.0);
	this->scale = 1.0;
	this->setPosition(position);

	Shader shaderLoader = Utils::LoadShader("Assets/Shaders/VAO_Text.vs", "Assets/Shaders/VAO_Text.fs", nullptr, "text");

	program = shaderLoader.ID;

	glm::mat4 projection = glm::ortho(0.0f,	static_cast<GLfloat>(1500), 0.0f,
		static_cast<GLfloat>(800));

	glUseProgram(program);
	glUniformMatrix4fv(glGetUniformLocation(program, "projection"),	1, GL_FALSE, glm::value_ptr(projection));

	FT_Library ft;

	if (FT_Init_FreeType(&ft))
	{
		std::cout << "ERROR::FREETYPE: Could not init FreeType Library" << std::endl;
	}
	FT_Face face; // Load font as face

	if (FT_New_Face(ft, font.c_str(), 0, &face))
	{
		std::cout << "ERROR::FREETYPE: Failed to load font" << std::endl;
	}

	// Set size to load glyphs as
	FT_Set_Pixel_Sizes(face, 0, 48);

	// Disable byte-alignment restriction
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	// Load first 128 characters of ASCII set
	for (GLubyte c = 0; c < 128; c++)
	{

		// Load character glyph
		if (FT_Load_Char(face, c, FT_LOAD_RENDER))
		{
			std::cout << "ERROR::FREETYTPE: Failed to load Glyph" << std::endl;
			continue;
		}

		// Generate texture
		GLuint texture;

		glGenTextures(1, &texture);

		glBindTexture(GL_TEXTURE_2D, texture);

		glTexImage2D(
			GL_TEXTURE_2D,
			0,
			GL_RED,
			face->glyph->bitmap.width,
			face->glyph->bitmap.rows,
			0,
			GL_RED,
			GL_UNSIGNED_BYTE,
			face->glyph->bitmap.buffer);

		// Set texture options
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		// Now store character for later use
		Character character = {
			texture,
			glm::ivec2(face->glyph->bitmap.width, face->glyph->bitmap.rows),
			glm::ivec2(face->glyph->bitmap_left, face->glyph->bitmap_top), face->glyph->advance.x

		};

		Characters.insert(std::pair<GLchar, Character>(c, character));

	}// for loop end

	glBindTexture(GL_TEXTURE_2D, 0);

	// Destroy FreeType once we're finished
	FT_Done_Face(face);
	FT_Done_FreeType(ft);

	// Configure VAO/VBO for texture quads
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * 6 * 4, NULL, GL_DYNAMIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), 0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}


void TextLabel::Render()
{
	glm::vec2 textPos = this->position;
	//enable blending

	glEnable(GL_CULL_FACE);

	glEnable(GL_BLEND);

	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	// Activate corresponding render state

	glUseProgram(program);
	glUniform3f(glGetUniformLocation(program, "textColor"), this->color.x, this->color.y, this->color.z);
	glActiveTexture(GL_TEXTURE0);
	glBindVertexArray(VAO);

	std::string::const_iterator c;

	for (c = text.begin(); c != text.end(); c++)
	{
		Character ch = Characters[*c];
		GLfloat xpos = textPos.x + ch.Bearing.x * this->scale;
		GLfloat ypos = textPos.y - (ch.Size.y - ch.Bearing.y) * this->scale;
		GLfloat w = ch.Size.x * this->scale;
		GLfloat h = ch.Size.y * this->scale;

		// Update VBO for each character

		GLfloat vertices[6][4] = {
				{ xpos, ypos + h, 0.0, 0.0 }, { xpos, ypos, 0.0, 1.0 }, { xpos + w, ypos, 1.0, 1.0},
				{ xpos, ypos + h, 0.0, 0.0 }, { xpos + w, ypos, 1.0, 1.0 }, { xpos + w, ypos + h, 1.0, 0.0 }
		};

		// Render glyph texture over quad

		glBindTexture(GL_TEXTURE_2D, ch.TextureID);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glDrawArrays(GL_TRIANGLES, 0, 6);
		// Now advance cursors for next glyph
		textPos.x += (ch.Advance >> 6) * this->scale;

	} // end of for loop

	glBindVertexArray(0);

	glBindTexture(GL_TEXTURE_2D, 0);
	glDisable(GL_CULL_FACE);
	glDisable(GL_BLEND);

}


void TextLabel::setPosition(glm::vec2 pos)
{
	this->position = pos;
}

void TextLabel::setColor(glm::vec3 color)
{
	this->color = color;
}

void TextLabel::setScale(GLfloat scale)
{
	this->scale = scale;
}

void TextLabel::setText(std::string text)
{
	this->text = text;
}