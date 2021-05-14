#include "Poisson.h"

Poisson::Poisson(sf::Vector2f position, TextureManager* pointeurTexture) : Aliment(pointeurTexture)
{
	std::cout << "Constructeur Poisson (position)" << std::endl;
	m_position = position;
	m_sprite = m_textureManager->getTexture(TextureType::Aliments, sf::Vector2u(0, 1));
	m_type = DeplacableType::poisson;
	m_coupable = true;
	std::cout << "Poisson OK" << std::endl;
}

sf::Sprite Poisson::spritePoisson()
{

	if (m_etat == AlimentEtat::couper)
	{
		m_sprite = m_textureManager->getTexture(TextureType::Aliments, sf::Vector2u(0, 0));
	}
	if (m_etat == AlimentEtat::cuit)
	{
		//m_sprite = m_textureManager->getTexture(TextureType::Aliments, sf::Vector2u(0, 0));
	}
	return m_sprite;
}
