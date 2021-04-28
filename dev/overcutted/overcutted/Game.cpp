#include "Game.h"
#include "Window.h"


Game::Game() : m_window("Overcutted", sf::Vector2u(800, 600)), m_world("textures/decors_test", sf::Vector2u(50,50), sf::Vector2u(13,8))
{
	
}

bool Game::LoadMap(const int* RefMap)
{
	if (m_world.load(RefMap))
		return true;
	else
		return false;
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
	m_window.Draw(m_world);
	//rendu monde "m_map"
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
	return m_elapsedTime;
}

void Game::RestartClock()
{
	m_elapsedTime = m_clock.restart();
}
