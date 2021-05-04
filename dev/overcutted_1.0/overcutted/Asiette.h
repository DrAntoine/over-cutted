#pragma once
#include "Entite.h"
#include "Aliments.h"
class Asiette : public Deplacable
{
private:
	bool remplie;
	std::vector< *Aliment> contenu;
	
public:
	void deposer(Aliment* x)
	{
		contenu.push_back(x);
	}


};

