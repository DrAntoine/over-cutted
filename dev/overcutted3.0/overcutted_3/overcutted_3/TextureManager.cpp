#include "TextureManager.h"

TextureManager::TextureManager(std::string PersoPath, std::string OutilsPath, std::string AlimentPath, sf::Vector2u imageSize)
{
	m_textAliments.loadFromFile(AlimentPath);
	m_textOutils.loadFromFile(OutilsPath);
	m_textPerso.loadFromFile(PersoPath);
	m_imageSize = imageSize;
}

sf::Sprite TextureManager::getTexture(TextureType type, sf::Vector2u positionInFile)
{
	//il se passe des trucs
	//return le_sprite
}