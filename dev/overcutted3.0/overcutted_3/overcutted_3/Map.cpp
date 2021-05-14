#include "Map.h"

//Map::Map()
//{
//	std::cout << "Constructeur Map (par defaut)" << std::endl;
//	m_ptrApp = nullptr;
//	std::cout << "Map OK" << std::endl;
//}

Map::Map(sf::RenderWindow* appPtr, TextureManager* pointeurText, std::vector<Deplacable*>* ListeElements)
{
	std::cout << "Constructeur Map (RenderWindow*, TextureManager*, std::vector<Deplacable*>*)" << std::endl;
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

Stock* Map::getStock(sf::Vector2u position)
{
	for (int i = 0; i < m_stocks.size(); i++)
	{
		if (m_stocks[i]->getMapPos() == position)
		{
			return m_stocks[i];
		}
	}
}

Poubelle* Map::getPoubelle(sf::Vector2u position)
{
	for (int i = 0; i < m_poubelles.size(); i++)
	{
		if (m_poubelles[i]->getMapPos() == position)
		{
			return m_poubelles[i];
		}
	}
}

Planche* Map::getPlanche(sf::Vector2u position)
{
	for (int i = 0; i < m_planches.size(); i++)
	{
		if (m_planches[i]->getMapPos() == position)
		{
			return m_planches[i];
		}
	}
}
PlanTravail* Map::getPlanTravail(sf::Vector2u position)
{
	for (int i = 0; i < m_PlanTravail.size(); i++)
	{
		if (m_PlanTravail[i]->getMapPos() == position)
		{
			return m_PlanTravail[i];
		}
	}
}

void Map::updateM_element(std::vector<Deplacable*>* pointeurListeElement)
{
	for (int i = 0; i < m_poubelles.size(); i++)
	{
		m_poubelles[i]->UpdatePointeurM_Element(pointeurListeElement);
	}
	for (int j = 0; j < m_stocks.size(); j++)
	{
		m_stocks[j]->UpdatePointeurM_Element(pointeurListeElement);
	}
}

void Map::initmap()
{
	Planche* planche = nullptr;
	PlanTravail* plantravail = nullptr;
	Poubelle* poubelle = nullptr;
	Stock* stock = nullptr;
	OuvertureSalle* ouverture = nullptr;
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
				plantravail=new PlanTravail(sf::Vector2u(x, y), m_texturePointeur);
				tuiles.push_back(plantravail);
				m_PlanTravail.push_back(plantravail);
				break;
			case 2: 
				planche = new Planche(sf::Vector2u(x, y), m_texturePointeur);
				tuiles.push_back(planche);
				m_planches.push_back(planche);
				break;
			case 3: 
				poubelle = new Poubelle(sf::Vector2u(x, y), m_texturePointeur, m_element);
				tuiles.push_back(poubelle);
				m_poubelles.push_back(poubelle);
				break;
			case 4: 
				stock = new Stock(sf::Vector2u(x, y), DeplacableType::crevette, m_element, m_texturePointeur);
				tuiles.push_back(stock); //passer le pointeur vers la liste de déplacable et le texture manager
				m_stocks.push_back(stock);
				break;
			case 5:
				stock = new Stock(sf::Vector2u(x, y), DeplacableType::poisson, m_element, m_texturePointeur);
				tuiles.push_back(stock); //passer le pointeur vers la liste de déplacable et le texture manager
				m_stocks.push_back(stock);
				break;
			case 6:
				stock = new Stock(sf::Vector2u(x, y), DeplacableType::assiette, m_element, m_texturePointeur);
				tuiles.push_back(stock); //passer le pointeur vers la liste de déplacable et le texture manager
				m_stocks.push_back(stock);
				break;
			case 7:
				ouverture = new OuvertureSalle(sf::Vector2u(x, y), m_texturePointeur);
				tuiles.push_back(ouverture);
				m_ouvertureSalle.push_back(ouverture);
				break;
			case 8:
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

