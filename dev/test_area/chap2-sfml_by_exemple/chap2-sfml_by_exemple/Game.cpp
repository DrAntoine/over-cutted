#include "Game.h"

Game::Game() : m_window("Chapter 2", sf::Vector2u(800, 600))
{
	m_mushroomTexture.loadFromFile("textures/50px_champi_red.png");
	m_mushroomTextureBlue.loadFromFile("textures/50px_champi_blue.png");
	m_mushroom.setTexture(m_mushroomTexture);
	m_increment = sf::Vector2i(400, 400);
	m_mushroom_blue = false;
	m_frametime = 1.0f / 60.f;
	m_nb_frame = 0;
}

Game::~Game()
{
	//nothing to destroy
}

void Game::Update()
{
	m_window.Update();
	MoveMushroom();
	if (m_elapsed.asSeconds() >= m_frametime)
	{
		m_elapsed -= sf::seconds(m_frametime);
		m_nb_frame += 1;
	}
	if (m_nb_frame >= 60 * 5)
	{
		Change_mushroom_color();
		m_nb_frame -= 60 * 5;
	}
}

void Game::MoveMushroom()
{
	sf::Vector2u l_windSize = m_window.GetWindowSize();
	sf::Vector2u l_textSize = m_mushroomTexture.getSize();

	if ((m_mushroom.getPosition().x > l_windSize.x - l_textSize.x && m_increment.x > 0) || (m_mushroom.getPosition().x < 0 && m_increment.x < 0))
	{
		m_increment.x = -m_increment.x;
	}
	if ((m_mushroom.getPosition().y > l_windSize.y - l_textSize.y && m_increment.y > 0) || (m_mushroom.getPosition().y < 0 && m_increment.y < 0))
	{
		m_increment.y = -m_increment.y;
	}
	float fElapsed = f_elapsed.asSeconds();
	m_mushroom.setPosition(m_mushroom.getPosition().x + (m_increment.x*fElapsed), m_mushroom.getPosition().y + (m_increment.y*fElapsed));
}
void Game::Render()
{
	m_window.BeginDraw();
	m_window.Draw(m_mushroom);
	m_window.EndDraw();
}

Window* Game::GetWindow()
{
	return &m_window;
}

void Game::HandleInput()
{

}

sf::Time Game::GetElapsed()
{
	return m_elapsed;
}

void Game::RestartClock()
{
	f_elapsed = m_clock.restart();
	m_elapsed += f_elapsed;
}

void Game::Change_mushroom_color()
{
	m_mushroom_blue = !m_mushroom_blue;
	if (m_mushroom_blue)
	{
		m_mushroom.setTexture(m_mushroomTextureBlue);
	}
	else
	{
		m_mushroom.setTexture(m_mushroomTexture);
	}
}