#include "Game.h"


/*Game::Game()
{
	std::cout << "Constructeur Game (Par defaut)" << std::endl;
	m_pointeurFenetre = nullptr;
	m_tileSize = sf::Vector2f(50, 50);
	std::cout << "Game OK" << std::endl;
}*/

Game::Game(sf::RenderWindow* app, sf::Event* m_EventPointeur)
{
	std::cout << "Constructeur Game (RenderWindow*)" << std::endl;
	m_pointeurFenetre = app;
	m_event = m_EventPointeur;
	m_tileSize = sf::Vector2f(50, 50);
	m_map = new Map(m_pointeurFenetre, &m_textureManager, &m_elements);
	m_perso = new Perso(m_pointeurFenetre, &m_textureManager,sf::Vector2u(4,4), Perso_conf::zqsdae, m_tileSize, m_map);
	std::cout << "Game OK" << std::endl;
}

Game::~Game()
{
	delete m_perso;
	delete m_map;
	for (int i = m_elements.size() - 1; i > -1; i--)
	{
		delete m_elements[i];
	}
}

void Game::draw()//window* w, m_gameClock
{
	m_map->drawmap();
	m_perso->draw(m_pointeurFenetre);
	int m_elementSize = m_elements.size();
	for (int i = 0; i < m_elementSize; i++)
	{
		m_elements[i]->draw(m_pointeurFenetre);
	}
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


