#include "Aliments.h"

Aliment::Aliment()
{
	m_etat = Etat::intacte;
}

void Aliment::setCoupe()
{
	m_etat = Etat::couper;
}
