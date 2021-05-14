#pragma once
#include "Aliments.h"
class Crevette : public Aliment
{
private:

public:
	Crevette(sf::Vector2f, TextureManager*, int);
	virtual ~Crevette();
	sf::Sprite spriteCrevette();
};

