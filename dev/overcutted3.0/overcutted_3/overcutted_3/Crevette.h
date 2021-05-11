#pragma once
#include "Aliments.h"
class Crevette : public Aliment
{
private:

public:
	Crevette(sf::Vector2f, TextureManager*);
	sf::Sprite spriteCrevette();
};

