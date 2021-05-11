#include "Aliments.h"

Aliment::Aliment(TextureManager* pointeurTexture) : Deplacable(pointeurTexture)
{
	std::cout << "Constructeur Aliments" << std::endl;
	m_etat = AlimentEtat::intacte;
	m_coupable = false;
	std::cout << "Aliments OK" << std::endl;
}

void Aliment::setCoupe()
{
	m_etat = AlimentEtat::couper;
}


