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
	sf::Time m_temps_animation;
	sf::Time m_temps_ecoule;
	DeplacableManager* m_deplacableManager;
	Aliment* m_alimentSurPlanche;
	bool m_fini;
public:
	Planche(sf::Vector2u position, TextureManager*, DeplacableManager*);
	virtual ~Planche();
	bool DeposerSurTuile(Deplacable*);
	Deplacable* PrendreSurTuile();
	bool getLibre();
	void interact(sf::Time);
	bool estFini();
};
