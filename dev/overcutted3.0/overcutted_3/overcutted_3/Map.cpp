#ifndef map
#include "Map.h"
#endif // !map
#ifndef entite
#include "Entite.h"
#endif // !entite

#ifndef sfml
#include <SFML/Graphics.hpp>
#endif // !sfml

Map::Map()
{

}

void Map::drawmap()
{
	for (int y = 0; y < 16; y++)
	{ 
		for (int x = 0; x < 16 ;x++)
		{

			/*switch (tabmap[x][y])
			{
			case 0:
				tuiles.push_back(new Sol(sf::Vector2u(x, y)));
				break;
			case 1: 
				tuiles.push_back(new PlanTravail(sf::Vector2u(x, y)));
				break;
			case 2: 
				tuiles.push_back(new Planche(sf::Vector2u(x, y)));
				break;
			case 3: 
				tuiles.push_back(new Poubelle(sf::Vector2u(x, y)));
				break;
			case 4: 
				tuiles.push_back(new Stock(sf::Vector2u(x, y), DeplacableType::crevette));
				break;
			case 5:
				tuiles.push_back(new Stock(sf::Vector2u(x, y), DeplacableType::poisson));
				break;
			case 6:
				tuiles.push_back(new Stock(sf::Vector2u(x, y),DeplacableType::assiette));
				break;
			case 7:
				tuiles.push_back(new Poubelle(sf::Vector2u(x, y)));
				break;
			case 8:
				tuiles.push_back(new OuvertureSalle(sf::Vector2u(x, y)));
				break;
			}*/
		}
	}

}