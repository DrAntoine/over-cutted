#pragma once
#ifndef sfml
#include <SFML/Graphics.hpp>
#endif // !sfml

#ifndef map
#include "Map.h"
#endif // !map

#include "Perso.h"
//#include "Deplacable.h"
//#include "Entite.h"



class Game
{
private:
	Map map; //les tuiles (+ les outils et stock)
	std::vector<Deplacable*> elements; 
	Perso perso;
	//envoyer la clock � perso ou directement envoyer le temps �coul� � chaque objet qui en � besoin
	// perso pour le deplacement, outil pour la gestion du temps de pr�paration etc
	
public:
	Game();
	void action(sf::Event);
	void draw(sf::RenderWindow* app);//window* w, m_gameClock
	void update(sf::Time tempsEcoule);
};

