#pragma once

#include "Deplacable.h"


enum class Etat { intacte, couper,cuit};
enum class Type {none,poisson,crevette};
class Aliment : public Deplacable
{

protected:
	Etat m_etat;
	Type m_type;
	bool m_coupable;
	//bool m_cuisable;

public:
	Aliment();
	void setCoupe();
	//void setCuit();
	//void melange();
};

