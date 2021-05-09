#pragma once
//#ifndef entite
#include "Entite.h"
//#endif // !entite

class Deplacable : public Entite
{
protected:
	DeplacableType m_type;

public:
	Deplacable();
	DeplacableType getType();
	void setposition(sf::Vector2f newPostion);


};

