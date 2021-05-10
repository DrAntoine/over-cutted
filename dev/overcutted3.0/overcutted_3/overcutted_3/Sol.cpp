#include "Sol.h"
Sol::Sol(sf::Vector2u positionCarte)
{
	m_positionMap = positionCarte;
	m_sprite = m_textureManager->getTexture(TextureType::Outils, sf::Vector2u(1, 0));
}
