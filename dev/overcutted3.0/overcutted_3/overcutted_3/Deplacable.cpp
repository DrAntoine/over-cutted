#include "Deplacable.h"

int Deplacable::dernierIdDeplacable = 0;


int Deplacable::getNewId()
{
	dernierIdDeplacable++;
	return dernierIdDeplacable;
}

int Deplacable::getId()
{
	return m_Deplacable_id;
}

Deplacable::Deplacable(TextureManager* pointeurText) : Entite(pointeurText)
{
	m_Deplacable_id = getNewId();
	std::cout << "Constructeur Deplacable" << std::endl;
	m_type = DeplacableType::none;
	std::cout << "Deplacable OK" << std::endl;
}
Deplacable::~Deplacable()
{
}
DeplacableType Deplacable::getType()
{
	return m_type;
}

void Deplacable::setposition(sf::Vector2f newPostion)
{
	m_position = newPostion;
	m_sprite.setPosition(m_position);
}