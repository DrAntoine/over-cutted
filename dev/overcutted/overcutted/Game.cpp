#include "Game.h"
#include "Window.h"


Game::Game() : m_window("Overcutted", sf::Vector2u(1000, 700)) // si on prend des cases de 75px et que la carte fait 8x13 on a besoin d'une fenetre de 600*975px min
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
	/*Attention en vue de 3/4 il faut faire le rendu du perso en même temps que le monde pour gérer la superposition des cases (si le personnage passe derrière un meuble il doit dessiné avan le meuble*/
	//rendu des ustensiles de cuisine (casserole (pê le faire dans world)
	m_window.EndDraw();
}

Window* Game::GetWindow()
{
	return &m_window;
}

sf::Time Game::GetElapsedTime()
{
	return m_elapsedTime;
}

void Game::RestartClock()
{
	m_elapsedTime = m_clock.restart();
}
