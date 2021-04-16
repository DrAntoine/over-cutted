#include "Game.h"
#include "Window.h"


Game::Game() : m_window("Overcutted", sf::Vector2u(800, 600)), m_tick(0)
{

}

Game::~Game()
{

}

void Game::HandleInput()
{

}

void Game::Update()
{
	m_window.Update();

}

void Game::Render()
{
	m_window.BeginDraw();
	//rendu monde "m_world"
	//rendu perso(s)
	/*Attention en vue de 3/4 il faut faire le rendu du perso en m�me temps que le monde pour g�rer la superposition des cases (si le personnage passe derri�re un meuble il doit dessin� avan le meuble*/
	//rendu des ustensiles de cuisine (casserole (p� le faire dans world)
	m_window.EndDraw();
}

Window* Game::GetWindow()
{
	return &m_window;
}

sf::Time Game::GetElapsedTime()
{
	return m_total_elapsed;
}

unsigned int Game::GetTick()
{
	return m_tick;
}

void Game::RestartClock()
{
	m_total_elapsed += m_clock.restart();
}
