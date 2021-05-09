#include "Deplacable.h"

Deplacable::Deplacable()
{
	m_type = DeplacableType::none;
}
DeplacableType Deplacable::getType()
{
	return m_type;
}
