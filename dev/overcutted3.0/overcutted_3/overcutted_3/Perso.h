#pragma once

#include "Deplacable.h"
#include "Map.h"
#include "Stock.h"

enum class Perso_Action { move_down, move_up, move_left, move_right, interact, idle, TakeDrop };
enum class Perso_Sens_regard { bas = 0, gauche = 1, droite = 2, haut = 3 };

class Perso : public Entite
{
private:
	Map* m_map; //les tuiles et les outils et stock
	Map map;
	std::vector<Deplacable*> *m_elements;
	// ===================================
	
	sf::Vector2u m_initPosition;
	sf::Vector2f previousPosition;
	Deplacable *en_mains;
	Perso_Action m_current_action;
	sf::Sprite* ptrsprite;
	
	// ===================================
	sf::Event* m_eventPerso;
	Perso_conf m_config;
	Perso_Sens_regard m_regard;
	// ===================================
	
	bool m_main_libre;
	int speed, blockSize;
	sf::Vector2u positionAnimaion;
	//propre au personnage
	sf::RenderWindow* m_ptrApp;
public:
	Perso(sf::RenderWindow*, TextureManager*, sf::Vector2u, Perso_conf, sf::Event*); //HELP MEEEE
	//Perso(Map *m_map, std::vector<Deplacable*>* m_elements); //HELP MEEEE
	//void drawperso();
	void action(sf::Time, sf::Event);
	void animation();


	//interaction avec la map
	void collision();

	////action
	///*
	//Touche E relié à la fonction utiliser
	//Touche A relié à la fonction prendre/deposer
	//Quand la fonction utiliser est appelée elle consulte si l'objet est utilisable (item dessus et action pas encore réalisée)
	//*/

	void prendre_deposer(int* outil);
	void utiliser(int *outil);//sur planche,mettre la clock
	//void destocker(int *tuile);//dans stock
	//void déposer(int *deplacable);//sur plan de travail
	//void prendre(int *deplacable);//sur plan de travail

};

