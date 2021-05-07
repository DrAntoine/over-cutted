#pragma once
#include <SFML/Graphics.hpp>
#include "Entite.h"


class Tuile : public Entite
{
public:
	TuileType getTypeTuile();
protected:
	/* hérité de entite
	sf::Vector2f taille;
	sf::Vector2f Position;
	sf::Sprite mysprite;
	sf::Texture mytexture;
	*/
	bool m_libre; //deposer
	TuileType m_type;
	bool m_marchable;
};

