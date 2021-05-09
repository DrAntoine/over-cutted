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
				tuiles.push_back(new planDeTravail());
			case 2: 
				tuiles.push_back(new Planche()); 
			case 3: 
				tuiles.push_back(new Poubelle());
			case 4: 
				tuiles.push_back(new stock());
			}
		}
	}

}