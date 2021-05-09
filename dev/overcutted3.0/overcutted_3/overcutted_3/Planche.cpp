#include "Planche.h"

Planche::Planche(sf::Vector2f position)
{
	m_position = position;
	m_type = TuileType::Planche_decoupe;
	m_marchable = false;
	m_sprite = m_textureManager->getTexture(TextureType::Outils, sf::Vector2u(4, 0));
}
