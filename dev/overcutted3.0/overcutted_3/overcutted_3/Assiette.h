#pragma once
#include "Deplacable.h"
#include"Aliments.h"


class Assiette : public Deplacable
{
private:
	std::vector<Aliment*> m_contenu;
	
public:
	Assiette();
	void deposer(Aliment* x);
	bool checkAliment(Aliment* aAjouter);


};

