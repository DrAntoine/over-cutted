#pragma once

#include "Entite.h"


class Deplacable : public Entite
{
private:
	static int dernierIdDeplacable;
protected:
	static int getNewId();
	DeplacableType m_type;
	int m_Deplacable_id;
public:
	int getId();
	Deplacable(TextureManager*);
	virtual ~Deplacable();
	DeplacableType getType();
	void setposition(sf::Vector2f newPostion);
};

