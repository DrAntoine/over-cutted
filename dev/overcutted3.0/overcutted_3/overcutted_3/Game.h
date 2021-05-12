#pragma once
#include <SFML/Graphics.hpp>
#include "Map.h"
#include "Perso.h"
#include "TextureManager.h"
//#include "Deplacable.h"
//#include "Entite.h"



class Game
{
private:
	TextureManager m_textureManager;
	std::vector<Deplacable*> m_elements; 
	Perso* m_perso;
	sf::RenderWindow* m_pointeurFenetre;
	Map* m_map; //les tuiles (+ les outils et stock)
	sf::Event* m_event;
	sf::Time timeTest;

	//envoyer la clock � perso ou directement envoyer le temps �coul� � chaque objet qui en � besoin
	// perso pour le deplacement, outil pour la gestion du temps de pr�paration etc
	
public:
	Game();
	~Game();
	Game(sf::RenderWindow*, sf::Event*);
	//void action(sf::Event);
	void draw();//window* w, m_gameClock
	void update(sf::Time tempsEcoule);
};

