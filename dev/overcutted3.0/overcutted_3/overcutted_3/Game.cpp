#include "Game.h"


Game::Game()
{
	std::cout << "Constructeur Game (Par defaut)" << std::endl;
	m_pointeurFenetre = nullptr;
	std::cout << "Game OK" << std::endl;
}
Game::Game(sf::RenderWindow* app)
{
	std::cout << "Constructeur Game (RenderWindow*)" << std::endl;
	m_pointeurFenetre = app;
	m_perso = new Perso(&m_textureManager);
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
	//app->draw();
	//m_map.drawmap();
	//for (elements) elements[i].draw(w)
		//perso.draw(w, clock);
		
}
void Game::update(sf::Time tempsEcoule)
{

}


