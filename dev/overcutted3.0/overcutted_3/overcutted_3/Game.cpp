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
	//Perso m_perso(&m_map, &m_elements);
	Perso m_perso();
	TextureManager m_textureManager();
	Map map(m_pointeurFenetre, &m_textureManager);
	m_map = &map;
	std::cout << "Game OK" << std::endl;
}

void Game::draw()//window* w, m_gameClock
{
	//app->draw();
	//m_map.drawmap();
	//for (elements) elements[i].draw(w)
		//perso.draw(w, clock);
		
}
void Game::update(sf::Time tempsEcoule)
{

}


