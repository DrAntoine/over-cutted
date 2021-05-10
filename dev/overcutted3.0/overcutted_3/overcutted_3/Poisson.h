#pragma once
#include "Aliments.h"


class Poisson:public Aliment
{
private:

public:
	Poisson(sf::Vector2f position);
	sf::Sprite spritePoisson();
};

