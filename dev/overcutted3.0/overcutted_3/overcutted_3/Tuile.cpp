#include "Tuile.h"
Tuile::Tuile()
{
	m_sprite = m_textureManager->getTexture(TextureType::Outils, sf::Vector2u(0, 0));
}
