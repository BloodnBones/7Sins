#include "TextureManager.h"

#include <iostream>


TextureManager::TextureManager()
{
}


TextureManager::~TextureManager()
{
}


void 
TextureManager::loadTexture(const std::string& name, const std::string& filename)
{
	sf::Texture texture;

	if (!texture.loadFromFile(filename))
	{

	}
	
	this->m_textures[name] = texture;
}

sf::Texture&
TextureManager::getRef(const std::string& textureName)
{
	return this->m_textures.at(textureName);
}
