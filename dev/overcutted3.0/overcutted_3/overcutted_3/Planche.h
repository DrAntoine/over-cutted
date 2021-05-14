#pragma once
#include "Outil.h"
#include "DeplacableManager.h"


class Planche: public Outil
{
private:
	/* hérité de entite
	sf::Vector2f taille;
	sf::Vector2f Position;
	sf::Sprite mysprite;
	sf::Texture mytexture;
	herité de outil
	bool m_libre;
	TypeObjet m_type;*/
	
	/*
	virtual void utiliser(std::vector<Aliment *> aliments)
	{
		//anim...
		if(anim terminee) aliment[0]->setCoupe();
	}*/
	DeplacableManager* m_deplacableManager;
public:
	Planche(sf::Vector2u position, TextureManager*, DeplacableManager*);
	virtual ~Planche();
	void DeposerSurTuile(Deplacable*);
	Deplacable* PrendreSurTuile();
	bool getLibre();
};
