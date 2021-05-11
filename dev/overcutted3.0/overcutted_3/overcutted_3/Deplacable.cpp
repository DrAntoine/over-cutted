#include "Deplacable.h"

Deplacable::Deplacable(TextureManager* pointeurText) : Entite(pointeurText)
{
	std::cout << "Constructeur Deplacable" << std::endl;
	m_type = DeplacableType::none;
	std::cout << "Deplacable OK" << std::endl;
}
DeplacableType Deplacable::getType()
{
	return m_type;
}

void Deplacable::setposition(sf::Vector2f newPostion)
{
	m_position = newPostion;
}