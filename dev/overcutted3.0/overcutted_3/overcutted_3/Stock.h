#pragma once
#include "Outil.h"
#include "Poisson.h"
#include "Crevette.h"
#include "Assiette.h"


class Stock : public Outil
{
private:
	DeplacableType m_ressourceAFournir;
	std::vector<Deplacable*>* m_pointeurListeElement;

public:
	Stock(sf::Vector2u , DeplacableType ,std::vector<Deplacable*>* , TextureManager*);
	Deplacable* PrendreSurTuile();
	/*void Interaction();
	void Poser(Deplacable*);
	Deplacable* Reprendre();*/
};

