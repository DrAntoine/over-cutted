#include "Tuile.h"
Tuile::Tuile() : Entite()
{
	m_sprite = m_textureManager->getTexture(TextureType::Outils, sf::Vector2u(0, 0));
	m_position = sf::Vector2f(50, 50);
}

TuileType Tuile::getTypeTuile()
{
	return m_typeTuile;
}
