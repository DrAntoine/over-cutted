#pragma once
#include "Outil.h"
#include "Recette.h"

class OuvertureSalle : public Tuile
{
private:
	std::vector<Recette*> recettes;
	//bool stateOuvSal; // A quoi il sert ? 
public:
	OuvertureSalle(sf::Vector2u positionCarte);
	//void validation();
	//void supprimer();

};

