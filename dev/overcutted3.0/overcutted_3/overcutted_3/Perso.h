#pragma once
#include "Entite.h"

class Perso:public Entite
{
private:
	Map *map; //les tuiles et les outils et stock
	std::vector<Deplacable*> *elements;
	enum Dir{ down, up, left, right};
	int px, py;
	sf::Vector2f previous;
	Deplacable *en_mains;
	bool a_un_truc_en_main;
	void animation();
	void utiliser();//sur planche
	void prendre();//dans stock
	void déposer();//sur plan de travail
	void prendre();//sur plan de travail
	void collision();

	utiliser_stock()
	{
		Aliment* a = stockx->destocker();
		elements->push_back(a);
	}
public:
	void move();
	
	void action()
	{
		sfVector2i coord_tuile = map->ousuisje(this->Position)

			map->coord[][] ... ahh c'est un stock'
			utiliser_stock();
			


	}


};

