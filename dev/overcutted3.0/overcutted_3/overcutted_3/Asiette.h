#pragma once
#include "Deplacable.h"
#include"Aliments.h"


class Asiette : public Deplacable
{
private:
	std::vector<Aliment*> contenu;
	
public:
	Asiette();
	void deposer(Aliment* x);
	void checkAliment();


};

