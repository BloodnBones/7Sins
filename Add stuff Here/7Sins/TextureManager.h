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
*/

#pragma once

#include "include\SFML\Graphics.hpp"
#include <string>
#include <map>

class TextureManager
{
public:
	TextureManager();
	~TextureManager();

	void loadTexture(const std::string &name, const std::string &filename);

	sf::Texture &getRef(const std::string& textureName);


private:

	std::map<std::string, sf::Texture> m_textures;
};

