#pragma once
#include "Outil.h"

class PlanTravail : public Outil

{
private:
	/* hérité de entite
	sf::Vector2f m_taille;
	sf::Vector2f m_position;
	sf::Sprite m_sprite;
	herité de outil
	bool m_libre; 
	TypeObjet m_type;*/
public:
	PlanTravail(sf::Vector2u, TextureManager*);
};

