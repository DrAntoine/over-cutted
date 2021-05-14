#pragma once
#include "Assiette.h"
#include "Crevette.h"
#include "Poisson.h"
//#include "Casserole.h"

class DeplacableManager
{
private:
	std::vector<Deplacable*> m_elementsDeplacable;
	std::vector<Assiette*> m_assiettes;
	std::vector<Poisson*> m_poissons;
	std::vector<Crevette*> m_crevettes;
	int nombreInstance;
	int GetInstanceID();
	void purgeVecteur(DeplacableType);
public:
	DeplacableManager();
	virtual ~DeplacableManager();
	void DeleteElement(Deplacable*);
	Deplacable* CreateElement(DeplacableType, sf::Vector2f, TextureManager* );
	Assiette* getAssiette(int);
	//Casserole* getCasserole(int);
	Crevette* getCrevette(int);
	Poisson* getPoisson(int);
	void DrawDeplacable(sf::RenderWindow*);
};

