#include "Tuile.h"
Tuile::Tuile(TextureManager* pointeurText) : Entite(pointeurText)
{
	std::cout << "Constructeur Tuile" << std::endl;
	m_sprite = m_textureManager->getTexture(TextureType::Outils, sf::Vector2u(0, 0));
	m_position = sf::Vector2f(50, 50);
	m_libre = true;
	m_marchable = true;
	m_typeTuile = TuileType::None;
	std::cout << "Tuile OK" << std::endl;
}

TuileType Tuile::getTypeTuile()
{
	return m_typeTuile;
}

bool Tuile::getMarchable()
{
	return m_marchable;
}

sf::Vector2u Tuile::getMapPos()
{
	return m_positionMap;
}


