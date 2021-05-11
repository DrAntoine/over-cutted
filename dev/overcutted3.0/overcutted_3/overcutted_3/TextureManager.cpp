#include "TextureManager.h"

TextureManager::TextureManager(/*std::string PersoPath, std::string OutilsPath, std::string AlimentPath*/)
{
	m_textAliments.loadFromFile("Textures/Aliments.png");
	m_textOutils.loadFromFile("Textures/decors.png");
	m_textPerso.loadFromFile("Textures/Perso.png");
	m_imageSize = sf::Vector2u(50, 50);
}

sf::Sprite TextureManager::getTexture(TextureType m_type, sf::Vector2u positionInFile)
{
	if (m_type == TextureType::Aliments)
	{
		m_sprite.setTexture(m_textAliments);
		m_sprite.setTextureRect(sf::IntRect(positionInFile.x, positionInFile.y ,m_imageSize.x, m_imageSize.y));

	}
	if (m_type == TextureType::Outils)
	{
		m_sprite.setTexture(m_textOutils);
		m_sprite.setTextureRect(sf::IntRect(positionInFile.x, positionInFile.y,  m_imageSize.x, m_imageSize.y));

	}
	if (m_type == TextureType::Personnage)
	{
		m_sprite.setTexture(m_textPerso);
		m_sprite.setTextureRect(sf::IntRect(positionInFile.x, positionInFile.y, positionInFile.x + m_imageSize.x, positionInFile.y + m_imageSize.y));
	}
	return m_sprite;
}