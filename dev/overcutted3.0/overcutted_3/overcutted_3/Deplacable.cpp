#include "Deplacable.h"

int Deplacable::getId()
{
	return m_Deplacable_id;
}

Deplacable::Deplacable(TextureManager* pointeurText, int deplacableID) : Entite(pointeurText)
{
	std::cout << "Constructeur Deplacable" << std::endl;
	m_Deplacable_id = deplacableID;
	m_type = DeplacableType::none;
	std::cout << "Deplacable OK" << std::endl;
	m_visible = true;
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

void Deplacable::Togglevisible()
{
	m_visible = !m_visible;
}

bool Deplacable::getVisible()
{
	return m_visible;
}
