#pragma once
#include "Outil.h"

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

	std::vector<Deplacable*>* m_element;

public:
	Poubelle(sf::Vector2u, TextureManager*, std::vector<Deplacable*>*);
	virtual ~Poubelle();
	void DeposerSurTuile(Deplacable*);
	Deplacable* PrendreSurTuile();
	bool getLibre();
	void UpdatePointeurM_Element(std::vector<Deplacable*>*);

};

