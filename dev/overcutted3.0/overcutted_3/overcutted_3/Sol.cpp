#include "Sol.h"
Sol::Sol(sf::Vector2f position)
{
	m_sprite = m_textureManager->getTexture(TextureType::Outils, sf::Vector2u(1, 0));
}
