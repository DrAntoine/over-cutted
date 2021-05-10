#include "Sol.h"
Sol::Sol(sf::Vector2u position)
{
	m_typeTuile = TuileType::Sol;
	m_marchable = true;
	m_positionMap = positionCarte;
	m_position = convert_posMap_to_pos(m_positionMap);
	m_sprite = m_textureManager->getTexture(TextureType::Outils, sf::Vector2u(1, 0));
}
