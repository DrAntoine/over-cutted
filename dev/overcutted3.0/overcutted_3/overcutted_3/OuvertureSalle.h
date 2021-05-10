#pragma once
#include "Outil.h"
#include "Recette.h"

class OuvertureSalle : public Tuile
{
private:
	std::vector<Recette*> recettes;
	bool stateOuvSal;
public:
	OuvertureSalle();
	//void validation();
	//void supprimer();

};

