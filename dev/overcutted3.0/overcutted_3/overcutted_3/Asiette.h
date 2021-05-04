#pragma once
#include "Deplacable.h"

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

