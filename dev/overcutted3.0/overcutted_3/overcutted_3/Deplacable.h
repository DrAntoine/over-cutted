#pragma once

#include "Entite.h"


class Deplacable : public Entite
{
protected:
	DeplacableType m_type;

public:
	Deplacable(TextureManager*);
	DeplacableType getType();
	void setposition(sf::Vector2f newPostion);
};

