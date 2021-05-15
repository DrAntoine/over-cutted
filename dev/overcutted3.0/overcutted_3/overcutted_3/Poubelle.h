#pragma once
#include "Outil.h"
#include "DeplacableManager.h"

class Poubelle : public Outil
{
private:
	//bool statepoubelle; (Pourquoi cet ligne ?)
	/* h�rit� de entite
	sf::Vector2f taille;
	sf::Vector2f Position;
	sf::Sprite mysprite;
	sf::Texture mytexture;
	herit� de outil
	bool m_libre; // ne sera jamais � false 
	TypeObjet m_type;*/

	DeplacableManager* m_deplacableManager;

public:
	Poubelle(sf::Vector2u, TextureManager*, DeplacableManager*);
	virtual ~Poubelle();
	bool DeposerSurTuile(Deplacable*);
	Deplacable* PrendreSurTuile();
	bool getLibre();
	//void UpdatePointeurM_Element(std::vector<Deplacable*>*);

};

