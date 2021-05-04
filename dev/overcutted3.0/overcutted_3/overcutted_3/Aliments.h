#pragma once

#include "Deplacable.h"


enum class Etat { intacte, couper };
class Aliment : public Deplacable
{

protected:
	Etat m_etat;

public:
	Aliment();
	void setCoupe();
	//void melange();
};

