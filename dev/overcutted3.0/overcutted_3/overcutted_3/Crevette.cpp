#include "Crevette.h"

Crevette::Crevette()
{
	std::cout << "Constructeur Crevette" << std::endl;
	//m_sprite = m_textureManager->getTexture(TextureType::Aliments,);
	m_type = DeplacableType::crevette;
	m_coupable = true;
	std::cout << "Crevette OK" << std::endl;
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