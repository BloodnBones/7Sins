#pragma once

#include <SFML/Graphics.hpp>
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

