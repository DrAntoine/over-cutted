#pragma once
#include "Outil.h"
#include "Recette.h"
#include "DeplacableManager.h"
#include "RecetteManager.h"

class OuvertureSalle : public Outil
{
private:
	RecetteManager* m_recetteManager;
	DeplacableManager* m_deplacableManager;
	//bool stateOuvSal; // A quoi il sert ? 
public:
	OuvertureSalle(sf::Vector2u , TextureManager*, DeplacableManager*, RecetteManager*);
	virtual ~OuvertureSalle();
	bool DeposerSurTuile(Deplacable*);
	//void validation();
	//void supprimer();

};

