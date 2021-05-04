#pragma once

#include "Outil.h"

class Poubelle : public Outil
{
private:
	bool statepoubelle;
	sf::Vector2f taille;
	sf::Vector2f Position;
	sf::Sprite mysprite;

public:
	void supprimer();

};

