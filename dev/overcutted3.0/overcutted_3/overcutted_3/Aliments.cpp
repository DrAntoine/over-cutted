#include "Aliments.h"

Aliment::Aliment()
{
	m_etat = AlimentEtat::intacte;
	m_coupable = false;
}

void Aliment::setCoupe()
{
	m_etat = AlimentEtat::couper;
}


