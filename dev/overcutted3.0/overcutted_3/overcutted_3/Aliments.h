#pragma once
#include<SFML/Graphics.hpp>
#include "Deplacable.h"

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

