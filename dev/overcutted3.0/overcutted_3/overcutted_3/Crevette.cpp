#include "Crevette.h"

Crevette::Crevette(sf::Vector2f position, TextureManager* pointeurTexture, int deplacableID) : Aliment(pointeurTexture, deplacableID)
{
	std::cout << "Constructeur Crevette" << std::endl;
	m_position = position;
	m_sprite = m_textureManager->getTexture(TextureType::Aliments, sf::Vector2u(0,0));
	m_type = DeplacableType::crevette;
	m_coupable = true;
	std::cout << "Crevette OK" << std::endl;
}
Crevette::~Crevette()
{
}
void Crevette::draw(sf::RenderWindow* maFenetre)
{
	spriteCrevette();
	m_sprite.setPosition(m_position);
	maFenetre->draw(m_sprite);
}

void Crevette::spriteCrevette()
{
	if (m_etat == AlimentEtat::intacte)
	{
		m_sprite = m_textureManager->getTexture(TextureType::Aliments, sf::Vector2u(0, 0));
	}
	if (m_etat == AlimentEtat::couper)
	{
		m_sprite = m_textureManager->getTexture(TextureType::Aliments,sf::Vector2u(1,0));
	}
	/*if (m_etat == AlimentEtat::cuit)
	{
		//m_sprite = m_textureManager->getTexture(TextureType::Aliments,);
	}*/
}