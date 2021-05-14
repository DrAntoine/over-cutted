#pragma once

#include"Aliments.h"


class Assiette : public Deplacable
{
private:
	std::vector<Aliment*> m_contenu;
	
public:
	Assiette(sf::Vector2f, TextureManager*);
	virtual ~Assiette();
	void deposer(Aliment* x);
	bool checkAliment(Aliment* aAjouter);


};

