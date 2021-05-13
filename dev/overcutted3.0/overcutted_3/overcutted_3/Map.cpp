#include "Map.h"

//Map::Map()
//{
//	std::cout << "Constructeur Map (par defaut)" << std::endl;
//	m_ptrApp = nullptr;
//	std::cout << "Map OK" << std::endl;
//}

Map::Map(sf::RenderWindow* appPtr, TextureManager* pointeurText, std::vector<Deplacable*>* ListeElements)
{
	std::cout << "Constructeur Map (RenderWindow*, TextureManager*" << std::endl;
	m_texturePointeur = pointeurText;
	m_ptrApp = appPtr;// pointeur vers la fenetre
	m_element = ListeElements;
	initmap();
	std::cout << "Map OK" << std::endl;
}

Map::~Map()
{
	for (int i = tuiles.size() - 1; i > -1; i--)
	{
		delete tuiles[i];
	}
}

std::vector<Tuile*> Map::getMapTile()
{
	return tuiles;
}

void Map::initmap()
{
	for (int y = 0; y < 16; y++)
	{ 
		for (int x = 0; x < 16 ;x++)
		{

			switch (tabmap[y][x])
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
				tuiles.push_back(new Stock(sf::Vector2u(x, y), DeplacableType::crevette, m_element, m_texturePointeur)); //passer le pointeur vers la liste de déplacable et le texture manager
				break;
			case 5:
				tuiles.push_back(new Stock(sf::Vector2u(x, y), DeplacableType::poisson, m_element, m_texturePointeur)); //passer le pointeur vers la liste de déplacable et le texture manager
				break;
			case 6:
				tuiles.push_back(new Stock(sf::Vector2u(x, y),DeplacableType::assiette, m_element, m_texturePointeur)); //passer le pointeur vers la liste de déplacable et le texture manager
				break;
			case 7:
				tuiles.push_back(new Poubelle(sf::Vector2u(x, y), m_texturePointeur));//2 fois poubelle?
				break;
			case 8:
				tuiles.push_back(new OuvertureSalle(sf::Vector2u(x, y), m_texturePointeur));
				break;
			case 9:
				tuiles.push_back(new Mur(sf::Vector2u(x, y), m_texturePointeur));
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

int Map::getTabMapValue(int y, int x)
{
	return this->tabmap[y][x];
}

