#pragma once
#include "Aliments.h"

enum class typeSpriteAssiette { vide, poisson, crevette, poisson_crevette };

class Assiette : public Deplacable
{
private:
	std::vector<Aliment*> m_contenu;
	typeSpriteAssiette m_SpriteAssiette;
	void updateSprite();
	//d::vector<Deplacable*>* m_element;
public:
	Assiette(sf::Vector2f, TextureManager*, int);
	virtual ~Assiette();
	bool DeposerSurAssiette(Aliment* x);
	bool checkAjoutAliment(Aliment* aAjouter);
	bool checkAlimentTypeEtat(Aliment* aVerif);
	int getNombreAliment();
	Deplacable* getAliment(int);
	bool estIdentique(Assiette &const B);
};

bool operator==(Assiette &const a, Assiette &const b);
