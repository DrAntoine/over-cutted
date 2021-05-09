#include "Map.h"
Map::Map()
{

}

void Map::drawmap()
{
	for (int y = 0; y < 16; y++)
	{ 
		for (int x = 0; x < 16 ;x++)
		{

			switch (tabmap[x][y])
			{
			case 1: 
				tuiles.push_back(new PlanTravail(sf::Vector2f(x, y)));
			case 2: 
				tuiles.push_back(new Planche(sf::Vector2f(x, y)));
			case 3: 
				tuiles.push_back(new Poubelle(sf::Vector2f(x, y)));
			case 4: 
				tuiles.push_back(new stock(sf::Vector2f(x, y)));
			}
		tuiles.push_back(new tuiles(sf::Vector2f(x, y)));
		}
	}

}