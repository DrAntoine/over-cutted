#pragma once

#include "Entite.h"


class Deplacable : public Entite
{
private:
protected:
	DeplacableType m_type;
	int m_Deplacable_id;
public:
	int getId();
	Deplacable(TextureManager*, int);
	virtual ~Deplacable();
	DeplacableType getType();
	void setposition(sf::Vector2f newPostion);
};

