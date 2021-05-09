#include "TextureManager.h"

TextureManager::TextureManager(std::string PersoPath, std::string OutilsPath, std::string AlimentPath)
{
	m_textAliments.loadFromFile(AlimentPath);
	m_textOutils.loadFromFile(OutilsPath);
	m_textPerso.loadFromFile(PersoPath);
}

void TextureManager::getTexture(TextureType m_type, sf::Vector2u positionInFile)
{
	if (m_type == TextureType::Aliments)
	{
		m_sprite.setTexture(m_textAliments);
		m_sprite.setTextureRect(sf::IntRect(positionInFile.x, positionInFile.y, positionInFile.x + 50, positionInFile.y + 50));

	}
	if (m_type == TextureType::Outils)
	{
		m_sprite.setTexture(m_textOutils);
		m_sprite.setTextureRect(sf::IntRect(positionInFile.x, positionInFile.y, positionInFile.x + 50, positionInFile.y + 50));

	}
	if (m_type == TextureType::Personnage)
	{
		m_sprite.setTexture(m_textPerso);
		m_sprite.setTextureRect(sf::IntRect(positionInFile.x, positionInFile.y, positionInFile.x + 50, positionInFile.y + 50));

	}
}

sf::Sprite TextureManager::getSprite()
{
	return m_sprite;
}