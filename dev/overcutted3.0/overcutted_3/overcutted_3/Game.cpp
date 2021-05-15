#include "Game.h"


Game::Game(sf::RenderWindow* app, sf::Event* m_EventPointeur)
{
	std::cout << "Constructeur Game (RenderWindow*)" << std::endl;
	m_pointeurFenetre = app;
	m_event = m_EventPointeur;
	m_tileSize = sf::Vector2f(50, 50);
	m_deplacableManager = new DeplacableManager();
	m_map = new Map(m_pointeurFenetre, &m_textureManager, m_deplacableManager);
	m_perso = new Perso(m_pointeurFenetre, &m_textureManager,sf::Vector2u(3,4), Perso_conf::zqsdae, m_tileSize, m_map);
	m_recette = new Recette(&m_textureManager, sf::Vector2u(4, 4));
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
	m_recette->drawRecette(m_pointeurFenetre);
	m_deplacableManager->DrawDeplacable(m_pointeurFenetre);
}

void Game::action(sf::Time elapsedTime, sf::Event event)
{
	m_perso->action(elapsedTime, event);
	m_recette->CreationRecettes();
}




