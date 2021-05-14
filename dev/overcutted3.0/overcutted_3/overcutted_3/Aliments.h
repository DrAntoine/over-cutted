#pragma once

#include "Deplacable.h"

class Aliment : public Deplacable
{

protected:
	AlimentEtat m_etat;
	bool m_coupable;
	//bool m_cuisable;

public:
	Aliment(TextureManager*, int);
	virtual ~Aliment();
	void setCoupe();
	//void setCuit();

};

