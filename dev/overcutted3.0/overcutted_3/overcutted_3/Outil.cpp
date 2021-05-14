#include "Outil.h"

Outil::Outil(TextureManager* pointeurTexture) : Tuile(pointeurTexture)
{
	std::cout << "Constructeur Outil" << std::endl;
	m_currentAliment = nullptr;
	m_libre = true;
	std::cout << "Outil OK" << std::endl;
}

Outil::~Outil()
{
}

bool Outil::Est_libre()
{
	return m_libre;
}