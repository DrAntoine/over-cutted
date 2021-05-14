#pragma once
//#include "Entite.h"
#include "Deplacable.h"


class Tuile : public Entite
{
public:
	Tuile(TextureManager*);
	TuileType getTypeTuile();
	bool getMarchable();
	bool getLibre();
	bool getDeposable();
	bool getInteragissable();
	void DeposerSurTuile(Deplacable*);
	Deplacable* PrendreSurTuile();
	void Interact();
	sf::Vector2u getMapPos();
protected:
	sf::Vector2u m_positionMap;
	TuileType m_typeTuile;
	Deplacable* m_objetSurTuile;
	Deplacable* objetADonner;
	bool m_libre;			// La tuile est elle libre ?
	bool m_marchable;		// Peut on marcher dessus ?
	bool m_deposable;		// Peut on deposer un truc dessus ?
	bool m_interagissable;	//peut on interagir avec ?
};

