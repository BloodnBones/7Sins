#include "TextureManager.h"

#include <iostream>

/*
* @brief
* @param
* @return
*/
TextureManager::TextureManager()
{
}

/*
* @brief
* @param
* @return
*/
TextureManager::~TextureManager()
{
}

/*
* @brief	Loads named textures into map containing all needed textures
* @param	The key name to use for the loaded texture
* @param	File pathway to load texture from
* @return	None
*/
void 
TextureManager::loadTexture(const std::string& name, const std::string& filename)
{
	sf::Texture texture;

	if (!texture.loadFromFile(filename))
	{

	}
	
	this->m_textures[name] = texture;
}

/*
* @brief
* @param
* @return
*/
sf::Texture&
TextureManager::getRef(const std::string& textureName)
{
	return this->m_textures.at(textureName);
}
