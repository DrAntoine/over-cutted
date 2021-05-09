#pragma once
#include <SFML/Graphics.hpp>
#include "Entite.h"


class Tuile : public Entite
{
public:
	Tuile();
	TuileType getTypeTuile();
protected:
	/* h�rit� de entite
	sf::Vector2f taille;
	sf::Vector2f Position;
	sf::Sprite mysprite;
	sf::Texture mytexture;
	*/
	sf::Vector2u m_positionMap;
	bool m_libre; //deposer
	TuileType m_type;
	bool m_marchable;
};

