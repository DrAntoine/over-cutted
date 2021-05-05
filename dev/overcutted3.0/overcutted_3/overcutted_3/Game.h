#pragma once
#include "SFML/Graphics.hpp"
#include "Map.h"
#include "Perso.h"
#include "Deplacable.h"


class Game
{
private:
	Map map; //les tuiles et les outils et stock
	std::vector<Deplacable*> elements;
	Perso perso(*elements, *map);
	
public:



	 draw(window *w, clock)
	{
		map.draw(w);
		for (elements) elements[i].draw(w)
		perso.draw(w,clock);

	}
};

