#pragma once

#include "Deplacable.h"
#include "Map.h"
#include "Stock.h"

enum class Perso_Action { move_down, move_up, move_left, move_right, interact, idle };

class Perso : public Entite
{
private:
	Map* m_map; //les tuiles et les outils et stock
	std::vector<Deplacable*> *m_elements;

	// ===================================
	int px, py; // Ca correspond � quoi ? 
	// ===================================

	sf::Vector2f previous;
	Deplacable *en_mains;
	Perso_Action m_current_action;
	
	// ===================================
	sf::Event m_eventPerso; // � remettre
	// ===================================
	
	bool m_main_libre;
	int speed, positionAnimationX;
	//propre au personnage
public:

	Perso(TextureManager*); //HELP MEEEE
	//Perso(Map *m_map, std::vector<Deplacable*>* m_elements); //HELP MEEEE

	void action(sf::Time dureeIteration);
	void animation();


	//interaction avec la map
	void collision();

	////action
	///*
	//Touche E reli� � la fonction utiliser
	//Touche A reli� � la fonction prendre/deposer
	//Quand la fonction utiliser est appel�e elle consulte si l'objet est utilisable (item dessus et action pas encore r�alis�e)
	//*/

	void prendre_deposer(int* outil);
	void utiliser(int *outil);//sur planche,mettre la clock
	//void destocker(int *tuile);//dans stock
	//void d�poser(int *deplacable);//sur plan de travail
	//void prendre(int *deplacable);//sur plan de travail

};

