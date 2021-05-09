#include "Stock.h"

Stock::Stock(sf::Vector2u position, DeplacableType typeAlimentAFournir)
{
	if (typeAlimentAFournir == DeplacableType::assiette)
	{
		m_sprite = m_textureManager->getTexture(TextureType::Outils, sf::Vector2u(1, 2));
	}
	if (typeAlimentAFournir == DeplacableType::poisson)
	{
		m_sprite = m_textureManager->getTexture(TextureType::Outils, sf::Vector2u(1, 1));
	}
	if (typeAlimentAFournir == DeplacableType::crevette)
	{
		m_sprite = m_textureManager->getTexture(TextureType::Outils, sf::Vector2u(0, 3));
	}
}
