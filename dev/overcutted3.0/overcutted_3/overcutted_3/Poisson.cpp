#include "Poisson.h"

Poisson::Poisson()
{
	//m_sprite = m_textureManager->getTexture(TextureType::Aliments,);
	m_type = DeplacableType::poisson;
	m_coupable = true;
}

sf::Sprite Poisson::spritePoisson()
{

	if (m_etat == AlimentEtat::couper)
	{
		//m_sprite = m_textureManager->getTexture(TextureType::Aliments,);
	}
	/*if (m_etat == AlimentEtat::cuit)
	{
		//m_sprite = m_textureManager->getTexture(TextureType::Aliments,);
	}*/
}
