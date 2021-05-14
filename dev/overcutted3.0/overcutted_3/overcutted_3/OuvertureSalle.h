#pragma once
#include "Outil.h"
#include "Recette.h"

class OuvertureSalle : public Outil
{
private:
	std::vector<Recette*> recettes;
	//bool stateOuvSal; // A quoi il sert ? 
public:
	OuvertureSalle(sf::Vector2u , TextureManager*);
	virtual ~OuvertureSalle();
	//void validation();
	//void supprimer();

};

