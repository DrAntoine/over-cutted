#include "Map.h"

Map::Map()
{
	std::cout << "Constructeur Map (par defaut)" << std::endl;
	m_ptrApp = nullptr;
	std::cout << "Map OK" << std::endl;
}
Map::Map(sf::RenderWindow* appPtr, TextureManager* pointeurText )
{
	std::cout << "Constructeur Map (RenderWindow*, TextureManager*" << std::endl;
	m_texturePointeur = pointeurText;
	m_ptrApp = appPtr;// pointeur vers la fenetre
	initmap();
	std::cout << "Map OK" << std::endl;
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
				tuiles.push_back(new Sol(sf::Vector2u(x, y), m_texturePointeur));
				break;
			case 1: 
				tuiles.push_back(new PlanTravail(sf::Vector2u(x, y), m_texturePointeur));
				break;
			case 2: 
				tuiles.push_back(new Planche(sf::Vector2u(x, y), m_texturePointeur));
				break;
			case 3: 
				tuiles.push_back(new Poubelle(sf::Vector2u(x, y), m_texturePointeur));
				break;
			case 4: 
				//tuiles.push_back(new Stock(sf::Vector2u(x, y), DeplacableType::crevette)); //passer le pointeur vers la liste de déplacable et le texture manager
				break;
			case 5:
				//tuiles.push_back(new Stock(sf::Vector2u(x, y), DeplacableType::poisson)); //passer le pointeur vers la liste de déplacable et le texture manager
				break;
			case 6:
				//tuiles.push_back(new Stock(sf::Vector2u(x, y),DeplacableType::assiette)); //passer le pointeur vers la liste de déplacable et le texture manager
				break;
			case 7:
				tuiles.push_back(new Poubelle(sf::Vector2u(x, y), m_texturePointeur));
				break;
			case 8:
				tuiles.push_back(new OuvertureSalle(sf::Vector2u(x, y), m_texturePointeur));
				break;
			}
		}
	}

}

void Map::drawmap()
{
	//tuiles.clear();
	//initmap();
	for (unsigned int i = 0; i < tuiles.size(); i++)
	{
		tuiles[i]->draw(m_ptrApp);
	}
}