#include "Poisson.h"

Poisson::Poisson(sf::Vector2f position, TextureManager* pointeurTexture, int deplacableID) : Aliment(pointeurTexture, deplacableID)
{
	std::cout << "Constructeur Poisson (position)" << std::endl;
	m_position = position;
	m_sprite = m_textureManager->getTexture(TextureType::Aliments, sf::Vector2u(0, 1));
	m_type = DeplacableType::poisson;
	m_coupable = true;
	std::cout << "Poisson OK" << std::endl;
}

Poisson::~Poisson()
{
}
void Poisson::draw(sf::RenderWindow* maFenetre)
{
	spritePoisson();
	m_sprite.setPosition(m_position);
	maFenetre->draw(m_sprite);
}

void Poisson::spritePoisson()
{

	if (m_etat == AlimentEtat::intacte)
	{
		m_sprite = m_textureManager->getTexture(TextureType::Aliments, sf::Vector2u(0, 1));
	}
	if (m_etat == AlimentEtat::couper)
	{
		m_sprite = m_textureManager->getTexture(TextureType::Aliments, sf::Vector2u(1, 1));
	}

}
