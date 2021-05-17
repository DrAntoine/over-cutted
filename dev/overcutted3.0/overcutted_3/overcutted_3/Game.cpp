#include "Game.h"


Game::Game(sf::RenderWindow* app, sf::Event* m_EventPointeur, int* score, sf::Time* tempsRestant)
{
	std::cout << "Constructeur Game (RenderWindow*)" << std::endl;
	m_pointeurFenetre = app;
	m_score = score;
	m_event = m_EventPointeur;
	minuteur = new Minuteur(tempsRestant);
	m_tileSize = sf::Vector2f(50, 50);
	m_deplacableManager = new DeplacableManager();
	m_recetteManager = new RecetteManager(&m_textureManager, m_deplacableManager, score);
	m_map = new Map(m_pointeurFenetre, &m_textureManager, m_deplacableManager, m_recetteManager);
	m_vectPerso.push_back(new Perso(m_pointeurFenetre, &m_textureManager,sf::Vector2u(3,4), Perso_conf::zqsdae, m_tileSize, m_map));
	m_vectPerso.push_back(new Perso(m_pointeurFenetre, &m_textureManager,sf::Vector2u(3,3), Perso_conf::ijkluo, m_tileSize, m_map));
	m_vectPerso.push_back(new Perso(m_pointeurFenetre, &m_textureManager,sf::Vector2u(2,4), Perso_conf::arrowsMajCtrl, m_tileSize, m_map));
	m_vectPerso.push_back(new Perso(m_pointeurFenetre, &m_textureManager,sf::Vector2u(2,3), Perso_conf::numpad, m_tileSize, m_map));
	std::cout << "Game OK" << std::endl;


}

Game::~Game()
{
	for (int i = 0; i < m_vectPerso.size(); i++)
	{
		delete m_vectPerso[i];
	}
	//delete m_perso;
	delete m_map;
}

void Game::draw()//window* w, m_gameClock
{
	//m_map->drawmap(); // debug pour afficher recette sur map
	m_recetteManager->drawRecette(m_pointeurFenetre);
	m_map->drawmap();
	for (int i = 0; i < m_vectPerso.size(); i++)
	{
		m_vectPerso[i]->draw(m_pointeurFenetre);
	}
	m_deplacableManager->DrawDeplacable(m_pointeurFenetre);
	minuteur->drawMinuteur(m_pointeurFenetre);
}

void Game::action(sf::Time elapsedTime)
{
	for (int i = 0; i < m_vectPerso.size(); i++)
	{
		m_vectPerso[i]->action(elapsedTime, m_event);
	}
}

void Game::update(sf::Time elaspsedTime)
{
	for (int i = 0; i < m_vectPerso.size(); i++)
	{
		m_vectPerso[i]->update(elaspsedTime);
	}
	m_recetteManager->updateRecette(elaspsedTime);
	minuteur->decompte();
	//std::cout << "Game score " << *m_score << std::endl;
}


