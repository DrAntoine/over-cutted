#pragma once
#include "Aliments.h"


class Poisson:public Aliment
{
private:

public:
	Poisson(sf::Vector2f, TextureManager*, int);
	virtual ~Poisson();
	sf::Sprite spritePoisson();
};

