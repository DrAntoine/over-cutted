#pragma once
#include "Outil.h"
#include "DeplacableManager.h"

class PlanTravail : public Outil

{
private:
	DeplacableManager* m_deplacableManager;
	/* h?rit? de entite
	sf::Vector2f m_taille;
	sf::Vector2f m_position;
	sf::Sprite m_sprite;
	herit? de outil
	bool m_libre; 
	TypeObjet m_type;*/
public:
	PlanTravail(sf::Vector2u, TextureManager*, DeplacableManager*);
	virtual ~PlanTravail();
	bool DeposerSurTuile(Deplacable*);
	Deplacable* PrendreSurTuile();
	bool getLibre();
};

