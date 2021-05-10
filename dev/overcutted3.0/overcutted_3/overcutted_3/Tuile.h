#pragma once
#include "Entite.h"



class Tuile : public Entite
{
public:
	Tuile();
	TuileType getTypeTuile();
protected:
	sf::Vector2u m_positionMap;
	bool m_libre; 
	TuileType m_typeTuile;
	bool m_marchable;
};

