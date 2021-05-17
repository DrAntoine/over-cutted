#include <iostream>

#include "Game.h"
#include "Window.h"
#include "Snake.h"
#include "World.h"

Game::Game() : m_window("Chapter 3", sf::Vector2u(800, 600)), m_snake(m_world.GetBlockSize()), m_world(sf::Vector2u(800,600))
{
	/*m_mushroomTexture.loadFromFile("textures/50px_champi.png");
	m_mushroom.setTexture(m_mushroomTexture);
	m_increment = sf::Vector2i(400, 400);*/
}

Game::~Game()
{
	//nothing to destroy
}  

void Game::Update()
{
	m_window.Update();
	//MoveMushroom();
	float timestep = 1.0f / m_snake.GetSpeed();
	if (m_elapsed.asMilliseconds() >= timestep) 
	{
		std::cout << "tick" << std::endl;
		m_snake.Tick();
		m_world.Update(m_snake);
		m_elapsed -= sf::milliseconds(timestep);
		if (m_snake.HasLost()) {
			m_snake.Reset();
		}
	}
}

/*void Game::MoveMushroom()
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
	float fElapsed = m_elapsed.asSeconds();
	m_mushroom.setPosition(m_mushroom.getPosition().x + (m_increment.x * fElapsed), m_mushroom.getPosition().y + (m_increment.y * fElapsed));
}*/
void Game::Render()
{
	m_window.BeginDraw();
	m_world.Render(*m_window.GetRenderWindow());
	m_snake.Render(*m_window.GetRenderWindow());
	//m_window.Draw(m_mushroom);
	m_window.EndDraw();
	//std::cout << "update" << std::endl;
}

Window* Game::GetWindow()
{
	return &m_window;
}

void Game::HandleInput()
{
	void Game::HandleInput()
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && m_snake.GetDirection() != Direction::Down && m_snake.GetDirection() != Direction::Up)
		{
			m_snake.SetDirection(Direction::Up);
			std::cout << "up" << std::endl;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && m_snake.GetDirection() != Direction::Up && m_snake.GetDirection() != Direction::Down)
		{
			m_snake.SetDirection(Direction::Down);
			std::cout << "down" << std::endl;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && m_snake.GetDirection() != Direction::Right && m_snake.GetDirection() != Direction::Left)
		{
			m_snake.SetDirection(Direction::Left);
			std::cout << "left" << std::endl;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && m_snake.GetDirection() != Direction::Left && m_snake.GetDirection() != Direction::Right)
		{
			m_snake.SetDirection(Direction::Right);
			std::cout << "right" << std::endl;
		}
	}
}

sf::Time Game::GetElapsed()
{
	return m_elapsed;
}

void Game::RestartClock()
{
	m_elapsed = m_clock.restart();
}