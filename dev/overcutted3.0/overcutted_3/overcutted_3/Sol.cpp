#include "Sol.h"
Sol::Sol(sf::Vector2u position)
{
	m_positionMap = position;
	m_typeTuile = TuileType::Sol;
	m_marchable = true;
	m_sprite = m_textureManager->getTexture(TextureType::Outils, sf::Vector2u(1, 0));
}
