#include "Game.h"


Game::Game()
{
	std::cout << "Constructeur Game (Par defaut)" << std::endl;
	m_pointeurFenetre = nullptr;
	m_tileSize = sf::Vector2f(50, 50);
	std::cout << "Game OK" << std::endl;
}
Game::Game(sf::RenderWindow* app, sf::Event* m_EventPointeur)
{
	std::cout << "Constructeur Game (RenderWindow*)" << std::endl;
	m_pointeurFenetre = app;
	m_event = m_EventPointeur;
	m_tileSize = sf::Vector2f(50, 50);
	m_perso = new Perso(m_pointeurFenetre, &m_textureManager,sf::Vector2u(4,4), Perso_conf::zqsdae, m_tileSize);
	m_map = new Map(m_pointeurFenetre, &m_textureManager, &m_elements);
	//m_map = &map;
	std::cout << "Game OK" << std::endl;
}
Game::~Game()
{
	delete m_perso;
	delete m_map;
}

void Game::draw()//window* w, m_gameClock
{
	m_map->drawmap();
	m_perso->draw(m_pointeurFenetre);
	//app->draw();
	//m_map.drawmap();
	//for (elements) elements[i].draw(w)
		//perso.draw(w, clock);
		
}

void Game::action(sf::Time elapsedTime, sf::Event event)
{
	m_perso->action(elapsedTime, event);
}


/*void Game::update(sf::Time tempsEcoule)
{
	timeTest = tempsEcoule;
	m_perso->action(timeTest, m_event);
}*/


