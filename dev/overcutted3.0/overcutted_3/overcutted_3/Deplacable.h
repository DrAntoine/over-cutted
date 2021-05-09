#pragma once
#include "Entite.h"
class Deplacable:public Entite
{
protected:
	DeplacableType m_type;

public:
	Deplacable();
	DeplacableType getType()
	//void prendre();
	//void déposer();
	//void position();

};

