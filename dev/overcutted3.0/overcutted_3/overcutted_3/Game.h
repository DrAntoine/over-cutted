#pragma once
#include <SFML/Graphics.hpp>
#include "Map.h"
#include "Perso.h"
#include "TextureManager.h"
#include "DeplacableManager.h"
#include "Recette.h"
//#include "Deplacable.h"
//#include "Entite.h"



class Game
{
private:
	TextureManager m_textureManager;
	DeplacableManager m_deplacableManager;
	//std::vector<Deplacable*> m_elements;
	Perso* m_perso;
	sf::RenderWindow* m_pointeurFenetre;
	Map* m_map; //les tuiles (+ les outils et stock)
	Recette* m_recette;
	sf::Event* m_event;
	sf::Time timeTest;
	sf::Vector2f m_tileSize;
	
public:
	Game();
	virtual ~Game();
	Game(sf::RenderWindow*, sf::Event*);
	void action(sf::Time, sf::Event);
	void draw();//window* w, m_gameClock



	void update(sf::Time tempsEcoule);
	//void update_ListeDeplacable();
	//std::vector<Deplacable*> purgeVecteur(std::vector<Deplacable*>);
};

