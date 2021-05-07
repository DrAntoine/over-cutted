#pragma once
#include "Entite.h"
#include "Deplacable.h"
#include "Aliments.h"
#include "Map.h"
#include "stock.h"

enum class Perso_Action { move_down, move_up, move_left, move_right, interact, idle };

class Perso:public Entite
{
private:
	Map *map; //les tuiles et les outils et stock
	std::vector<Deplacable*> *elements;
	int px, py;
	sf::Vector2f previous;
	Deplacable *en_mains;
	bool a_un_truc_en_main;
	Perso_Action current_action;
	sf::Clock clockPerso;
	bool moveleft, moveright, moveup, movedown;
	//propre au personnage
public:
	Perso(*elements,*map);
	void move();
	void action();
	void animation();


	//interaction avec la map
	void collision();

	//action
	/*
	Touche E relié à la fonction utiliser
	Touche A relié à la fonction prendre/deposer
	Quand la fonction utiliser est appelée elle consulte si l'objet est utilisable (item dessus et action pas encore réalisée)
	*/

	void prendre_deposer(int* outil);
	void utiliser(int *outil);//sur planche,mettre la clock
	//void destocker(int *tuile);//dans stock
	//void déposer(int *deplacable);//sur plan de travail
	//void prendre(int *deplacable);//sur plan de travail

	/*utiliser_stock()
	{
		Aliment* a = Stock->destocker();
		elements->push_back(a);
	}*/
public:

	/*
	void action()
	{
		sfVector2i coord_tuile = map->ousuisje(this->Position)

			map->coord[][] ... ahh c'est un stock'
			utiliser_stock();
			


	}
	*/

};

