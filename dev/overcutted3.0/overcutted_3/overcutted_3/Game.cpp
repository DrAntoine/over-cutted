#include "Game.h"

Game::Game()
{
	m_pointeurFenetre = nullptr;
	m_map = nullptr;
}
Game::Game(sf::RenderWindow* app)
{
	m_pointeurFenetre = app;
	//Perso m_perso(&m_map, &m_elements);
	//Perso m_perso();
	m_map=new Map(m_pointeurFenetre);
}

void Game::draw()//window* w, m_gameClock
{	
	//app->draw();
	m_map->drawmap();
	//for (elements) elements[i].draw(w)
		//perso.draw(w, clock);
		
}
void Game::update(sf::Time tempsEcoule)
{

}
void Game::action(sf::Event event)
{

}


