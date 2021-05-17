#pragma once
#include <SFML/Graphics.hpp>
#include "Map.h"
#include "Perso.h"
#include "TextureManager.h"
#include "DeplacableManager.h"
#include "RecetteManager.h"
#include "Minuteur.h"
//#include "Deplacable.h"
//#include "Entite.h"



class Game
{
private:
	Minuteur minuteur;
	TextureManager m_textureManager;
	DeplacableManager* m_deplacableManager;
	Perso* m_perso;
	sf::RenderWindow* m_pointeurFenetre;
	Map* m_map; //les tuiles (+ les outils et stock)
	RecetteManager* m_recetteManager;
	sf::Event* m_event;
	sf::Time timeTest;
	sf::Vector2f m_tileSize;


	int* m_score;

public:
	//Game();
	virtual ~Game();
	Game(sf::RenderWindow*, sf::Event*, int*);
	void action(sf::Time);
	void draw();
	void update(sf::Time tempsEcoule);
};

