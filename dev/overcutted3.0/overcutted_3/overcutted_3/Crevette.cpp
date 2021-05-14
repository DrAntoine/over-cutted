#include "Crevette.h"

Crevette::Crevette(sf::Vector2f position, TextureManager* pointeurTexture) : Aliment(pointeurTexture)
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
sf::Sprite Crevette::spriteCrevette()
{

	if (m_etat == AlimentEtat::couper)
	{
		//m_sprite = m_textureManager->getTexture(TextureType::Aliments,);
	}
	/*if (m_etat == AlimentEtat::cuit)
	{
		//m_sprite = m_textureManager->getTexture(TextureType::Aliments,);
	}*/
	return m_sprite;
}