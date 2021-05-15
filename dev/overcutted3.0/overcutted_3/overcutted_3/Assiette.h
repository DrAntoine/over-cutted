#pragma once

#include"Aliments.h"


class Assiette : public Deplacable
{
private:
	std::vector<Aliment*> m_contenu;
	//d::vector<Deplacable*>* m_element;
public:
	Assiette(sf::Vector2f, TextureManager*, int);
	virtual ~Assiette();
	void DeposerSurAssiette(Deplacable* x);
	bool checkAjoutAliment(Aliment* aAjouter);
	bool checkAlimentTypeEtat(Aliment* aVerif);
	int getNombreAliment();
	bool estIdentique(Assiette &const B);

};

bool operator==(Assiette &const a, Assiette &const b);
