#pragma once

#include "Deplacable.h"

class Aliment : public Deplacable
{

protected:
	AlimentEtat m_etat;
	AlimentType m_type;
	bool m_coupable;
	//bool m_cuisable;

public:
	Aliment();
	//~Aliment();
	void setCoupe();
	//void setCuit();


	AlimentType getType();
};

