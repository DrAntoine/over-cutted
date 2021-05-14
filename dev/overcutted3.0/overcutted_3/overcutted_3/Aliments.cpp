#include "Aliments.h"

Aliment::Aliment(TextureManager* pointeurTexture, int deplacableID) : Deplacable(pointeurTexture, deplacableID)
{
	std::cout << "Constructeur Aliments" << std::endl;
	m_etat = AlimentEtat::intacte;
	m_coupable = false;
	m_couper = false;
	std::cout << "Aliments OK" << std::endl;
}

Aliment::~Aliment()
{
}

void Aliment::setCoupe()
{
	if (!estCouper())
	{
		m_etat = AlimentEtat::couper;
		m_couper = true;
	}
}

bool Aliment::estCoupable()
{
	return m_coupable;
}

bool Aliment::estCouper()
{
	return m_couper;
}


