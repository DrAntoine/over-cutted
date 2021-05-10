#include "Tuile.h"
Tuile::Tuile() : Entite()
{
	m_sprite = m_textureManager->getTexture(TextureType::Outils, sf::Vector2u(0, 0));
	m_position = sf::Vector2f(50, 50);
	m_libre = true;
	m_marchable = true;
	m_typeTuile = TuileType::None;
}

TuileType Tuile::getTypeTuile()
{
	return m_typeTuile;
}

sf::Vector2f Tuile::convert_posMap_to_pos(sf::Vector2u m_positionMap)
{
	sf::Vector2f position = sf::Vector2f(m_positionMap.x * m_taille.x, m_positionMap.y * m_taille.y);
	return position;
}
