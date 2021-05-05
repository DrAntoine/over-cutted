#pragma once

#include "Deplacable.h"


enum class Etat { intacte, couper };
enum class Type {poisson,crevette};
class Aliment : public Deplacable
{

protected:
	Etat m_etat;
	Type m_type;

public:
	Aliment();
	void setCoupe();
	//void melange();
};

