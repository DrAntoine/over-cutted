#include "OuvertureSalle.h"
OuvertureSalle::OuvertureSalle(sf::Vector2u positioncarte)
{
	m_positionMap = positioncarte;
	m_sprite = m_textureManager->getTexture(TextureType::Outils, sf::Vector2u(7, 0));
}
