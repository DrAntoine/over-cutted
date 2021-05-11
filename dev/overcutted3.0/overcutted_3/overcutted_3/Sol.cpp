#include "Sol.h"
Sol::Sol(sf::Vector2u positionCarte)
{
	m_typeTuile = TuileType::Sol;
	m_marchable = true;
	m_positionMap = positionCarte;
	m_position = convert_posMap_to_pos(m_positionMap);
	m_sprite = m_texture.getTexture(TextureType::Outils, sf::Vector2u(1, 0), sf::Vector2u (m_position));
	
}
