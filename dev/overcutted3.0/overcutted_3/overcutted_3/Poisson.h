#pragma once
#include "Aliments.h"


class Poisson:public Aliment
{
private:

public:
	Poisson(sf::Vector2f, TextureManager*);
	virtual ~Poisson();
	sf::Sprite spritePoisson();
};

