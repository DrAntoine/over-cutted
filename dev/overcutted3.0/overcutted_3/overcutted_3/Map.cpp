#include "Map.h"

Map::Map()
{
	m_ptrApp = nullptr;
}
Map::Map(sf::RenderWindow* appPtr )
{
	m_ptrApp = appPtr;// pointeur vers la fenetre
}

void Map::initmap()
{
	for (int y = 0; y < 16; y++)
	{ 
		for (int x = 0; x < 16 ;x++)
		{

			switch (tabmap[x][y])
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
				//tuiles.push_back(new Stock(sf::Vector2u(x, y), DeplacableType::crevette));
				break;
			case 5:
				//tuiles.push_back(new Stock(sf::Vector2u(x, y), DeplacableType::poisson));
				break;
			case 6:
				//tuiles.push_back(new Stock(sf::Vector2u(x, y),DeplacableType::assiette));
				break;
			case 7:
				tuiles.push_back(new Poubelle(sf::Vector2u(x, y)));
				break;
			case 8:
				tuiles.push_back(new OuvertureSalle(sf::Vector2u(x, y)));
				break;
			}
		}
	}

}

void Map::drawmap()
{
	for (int i = 0; i < tuiles.size(); i++)
	{
		tuiles[i]->draw(m_ptrApp);
	}


}