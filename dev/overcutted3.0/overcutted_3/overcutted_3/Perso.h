#pragma once

#include "Deplacable.h"
#include "Map.h"
#include "Stock.h"
#include "Poubelle.h"

enum class Perso_Action { move_down, move_up, move_left, move_right, interact, idle, TakeDrop };
enum class Perso_Sens_regard { bas = 0, gauche = 1, droite = 2, haut = 3 };

class Perso : public Entite
{
private:
	Map* m_map; //les tuiles et les outils et stock
	std::vector<Deplacable*> *m_elements;
	// ===================================
	
	sf::Vector2u m_initPosition;
	sf::Vector2f previousPosition;
	Deplacable *m_objet_en_mains;
	Deplacable* m_objet_sur_tuile;
	Perso_Action m_current_action;
	sf::Sprite* ptrsprite;
	
	// ===================================
	sf::Vector2f m_tileSize;
	Perso_conf m_config;
	Perso_Sens_regard m_regard;
	Tuile* getFrontTile();
	Stock* getStockTile(sf::Vector2u);
	// ===================================
	
	bool m_main_libre;
	int speed, blockSize;
	sf::Vector2u positionAnimation;
	//propre au personnage
	sf::RenderWindow* m_ptrApp;
	float couldown_takeDown;
	bool couldown_actif;
	int m_etatAnimation;
public:
	Perso(sf::RenderWindow*, TextureManager*, sf::Vector2u, Perso_conf, sf::Vector2f, Map*);
	virtual ~Perso();
	//Perso(Map *m_map, std::vector<Deplacable*>* m_elements); //HELP MEEEE
	//void drawperso();
	void action(sf::Time, sf::Event*);

	void interact(sf::Time);
	void animation();
	void update(sf::Time);

	//interaction avec la map
	bool collision();

	////action
	///*
	//Touche E relié à la fonction utiliser
	//Touche A relié à la fonction prendre/deposer
	//Quand la fonction utiliser est appelée elle consulte si l'objet est utilisable (item dessus et action pas encore réalisée)
	//*/

	void prendre_deposer();
	//void utiliser();//sur planche,mettre la clock
	void draw(sf::RenderWindow*);
};

