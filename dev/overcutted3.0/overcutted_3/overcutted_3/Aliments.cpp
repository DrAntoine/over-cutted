#include "Aliments.h"

Aliment::Aliment()
{
	m_etat = Etat::intacte;
	m_type = Type::none;
	m_coupable = false;
}

void Aliment::setCoupe()
{
	m_etat = Etat::couper;
}
