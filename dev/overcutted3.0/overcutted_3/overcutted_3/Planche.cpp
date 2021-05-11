#include "Planche.h"

Planche::Planche(sf::Vector2u position)
{
	m_positionMap = position;
	m_position = convert_posMap_to_pos(m_positionMap);
	m_typeTuile = TuileType::Planche_decoupe;
	m_marchable = false;
	//m_sprite.setPosition(m_position);
	m_sprite = m_textureManager->getTexture(TextureType::Outils, sf::Vector2u(0, 4), sf::Vector2u(m_position));
}
