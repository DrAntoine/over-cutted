#pragma once
//#include "Entite.h"
#include "Deplacable.h"


class Tuile : public Entite
{
public:
	Tuile(TextureManager*);
	virtual ~Tuile();
	TuileType getTypeTuile();
	bool getMarchable();
	bool getLibre();
	bool getDeposable();
	bool getPrenable();
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
	bool m_prenable;		// Peut on y prendre un truc ?
	bool m_interagissable;	//peut on interagir avec ?
};

