#pragma once
#include "Entite.h"
#include "Deplacable.h"
#include "Aliments.h"
#include "Map.h"
#include "stock.h"


class Perso:public Entite
{
private:
	Map *map; //les tuiles et les outils et stock
	std::vector<Deplacable*> *elements;
	//enum Dir{ down, up, left, right};
	int px, py;
	sf::Vector2f previous;
	Deplacable *en_mains;
	bool a_un_truc_en_main;
	//propre au personnage
public:
	Perso(*elements, *map);
	void move();
	void animation();


	//interaction avec la map
	void collision();

	//action
	void utiliser(int *outil);//sur planche
	void destocker(int *tuile);//dans stock
	void déposer(int *deplacable);//sur plan de travail
	void prendre(int *deplacable);//sur plan de travail

	utiliser_stock()
	{
		Aliment* a = Stock->destocker();
		elements->push_back(a);
	}
public:

	
	void action()
	{
		sfVector2i coord_tuile = map->ousuisje(this->Position)

			map->coord[][] ... ahh c'est un stock'
			utiliser_stock();
			


	}


};

