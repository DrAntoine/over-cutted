#pragma once

#include "Deplacable.h"

class Aliment : public Deplacable
{

protected:
	AlimentEtat m_etat;
	bool m_coupable;
	bool m_couper;
	//bool m_cuisable;

public:
	Aliment(TextureManager*, int);
	virtual ~Aliment();
	void setCoupe();
	bool estCoupable();
	bool estCouper();
	//void setCuit();
	bool CompareEtatAliment(Aliment& const b);
};

bool operator==(Aliment& const a, Aliment& const b);
