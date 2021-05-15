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

bool Aliment::CompareEtatAliment(Aliment& const b)
{
	if (m_couper == b.m_couper && m_etat == b.m_etat) return true;
	return false;
}

//AlimentEtat Aliment::getEtat()
//{
//	return m_etat;
//}

bool operator==(Aliment& const a, Aliment& const b)
{
	return a.CompareEtatAliment(b);
}
