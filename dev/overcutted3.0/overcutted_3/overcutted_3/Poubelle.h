#pragma once

#include "Outil.h"

class Poubelle : public Outil
{
private:
	//bool statepoubelle; (Pourquoi cet ligne ?)
	/* hérité de entite
	sf::Vector2f taille;
	sf::Vector2f Position;
	sf::Sprite mysprite;
	sf::Texture mytexture;
	herité de outil
	bool m_libre; // ne sera jamais à false 
	TypeObjet m_type;*/

public:
	Poubelle();
	void supprimer(Aliment*);

};

