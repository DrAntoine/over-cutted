#pragma once
#include<SFML/Graphics.hpp>
#include "Entite.h"

class Aliment : public Deplacable
{
protected:
	bool cuit;
	bool coupe;

public:
	Aliment() : Deplacable()
	{
		coupe = false;
	}
	void melange();

	void setCoupe() { coupe = true; }
};

