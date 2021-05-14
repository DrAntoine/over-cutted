#pragma once
#include "Outil.h"
#include "Recette.h"
#include "DeplacableManager.h"

class OuvertureSalle : public Outil
{
private:
	std::vector<Recette*> recettes;
	DeplacableManager* m_deplacableManager;
	//bool stateOuvSal; // A quoi il sert ? 
public:
	OuvertureSalle(sf::Vector2u , TextureManager*, DeplacableManager*);
	virtual ~OuvertureSalle();
	//void validation();
	//void supprimer();

};

