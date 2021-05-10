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
