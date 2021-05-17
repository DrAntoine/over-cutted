#pragma once
#include "Outil.h"
//#include "Poisson.h"
//#include "Crevette.h"
//#include "Assiette.h"
#include "DeplacableManager.h"

class Stock : public Outil
{
private:
	DeplacableType m_ressourceAFournir;
	DeplacableManager* m_deplacableManager;

public:
	Stock(sf::Vector2u , DeplacableType ,DeplacableManager* , TextureManager*);
	virtual ~Stock();
	Deplacable* PrendreSurTuile();
};

