#include "Recette.h"

Recette::Recette()
{
	std::cout << "Constructeur Recette" << std::endl;
	m_taille = sf::Vector2f(0, 0);
	m_position = sf::Vector2f(0, 0);
	std::cout << "Recette OK" << std::endl;
}

Recette::~Recette()
{
}
