#include "Aliments.h"

Aliment::Aliment()
{
	m_etat = AlimentEtat::intacte;
	m_type = AlimentType::none;
	m_coupable = false;
}

void Aliment::setCoupe()
{
	m_etat = AlimentEtat::couper;
}

AlimentType Aliment::getType()
{
	return m_type;
}
