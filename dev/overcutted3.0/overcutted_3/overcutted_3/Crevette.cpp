#include "Crevette.h"

Crevette::Crevette()
{
	//m_sprite = m_textureManager->getTexture(TextureType::Aliments,);
	m_type = DeplacableType::crevette;
	m_coupable = true;
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