#pragma once
#include "Tuile.h"
#include "Poisson.h"


class Stock : public Tuile
{
private:
	DeplacableType m_ressourceAFournir;
	std::vector<Deplacable*>* m_pointeurListeElement;

public:
	Stock(sf::Vector2u position, DeplacableType typeAlimentAFournir,std::vector<Deplacable*>* pointeurListeElement);
	void Interaction();
	void Poser(Deplacable*);
	Deplacable* Reprendre();
};

