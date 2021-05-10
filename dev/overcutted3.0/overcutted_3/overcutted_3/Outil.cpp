#include "Outil.h"

Outil::Outil()
{
	m_currentAliment = nullptr;
	m_libre = true;
}

bool Outil::Est_libre()
{
	return m_libre;
}