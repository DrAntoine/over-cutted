#include "Outil.h"

Outil::Outil()
{
	std::cout << "Constructeur Outil" << std::endl;
	m_currentAliment = nullptr;
	m_libre = true;
	std::cout << "Outil OK" << std::endl;
}

bool Outil::Est_libre()
{
	return m_libre;
}