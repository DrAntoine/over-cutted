#pragma once
#include "Deplacable.h"
#include"Aliments.h"


class Asiette : public Deplacable
{
private:
	std::vector<Aliment*> m_contenu;
	
public:
	Asiette();
	void deposer(Aliment* x);
	bool checkAliment(Aliment* aAjouter);


};

