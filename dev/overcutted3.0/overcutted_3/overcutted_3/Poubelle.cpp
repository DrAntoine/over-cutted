#include "Poubelle.h"

Poubelle::Poubelle(sf::Vector2f position)
{
	m_position = position;
	m_type = TuileType::Poubelle;
	m_marchable = false;
	m_sprite = m_textureManager->getTexture(TextureType::Outils, sf::Vector2u(0, 0)); //TODO definir la position dans le fichier.
}