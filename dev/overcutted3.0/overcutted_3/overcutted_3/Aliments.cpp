#include "Aliments.h"

Aliment::Aliment(TextureManager* pointeurTexture, int deplacableID) : Deplacable(pointeurTexture, deplacableID)
{
	std::cout << "Constructeur Aliments" << std::endl;
	m_etat = AlimentEtat::intacte;
	m_coupable = false;
	std::cout << "Aliments OK" << std::endl;
}

Aliment::~Aliment()
{
}

void Aliment::setCoupe()
{
	m_etat = AlimentEtat::couper;
}


