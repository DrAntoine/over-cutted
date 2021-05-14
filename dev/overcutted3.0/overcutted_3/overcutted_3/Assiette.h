#pragma once

#include"Aliments.h"


class Assiette : public Deplacable
{
private:
	std::vector<Aliment*> m_contenu;
	std::vector<Deplacable*>* m_element;
public:
	Assiette(sf::Vector2f, TextureManager*, int);
	virtual ~Assiette();
	void DeposerSurAssiette(Deplacable* x);
	bool checkAliment(Aliment* aAjouter);


};

