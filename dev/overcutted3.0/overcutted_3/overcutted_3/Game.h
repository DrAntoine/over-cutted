#pragma once
#include "SFML/Graphics.hpp"
#include "Map.h"
#include "Perso.h"
#include "Deplacable.h"
#include "Entite.h"


class Game
{
private:
	Map map; //les tuiles (+ les outils et stock)
	std::vector<Deplacable*> elements; 
	Perso perso(elements, map);
	sf::Clock m_gameClock;
	//envoyer la clock à perso ou directement envoyer le temps écoulé à chaque objet qui en à besoin
	// perso pour le deplacement, outil pour la gestion du temps de préparation etc
	
public:
	void init_clock();
	void draw(sf::RenderWindow* app);//window* w, m_gameClock
};

