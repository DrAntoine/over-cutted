#pragma once
#include <SFML/Graphics.hpp>
#include "Window.h"
#include "Snake.h"
#include "World.h"

class Game
{
public:
	Game();
	~Game();

	void HandleInput();
	void Update();
	void Render();
	Window* GetWindow();
	sf::Time GetElapsed();
	void RestartClock();
private:
	//void MoveMushroom();
	Window m_window;
	/*sf::Texture m_mushroomTexture;
	sf::Sprite m_mushroom;
	sf::Vector2i m_increment;*/
	sf::Clock m_clock;
	sf::Time m_elapsed;
	World m_world;
	Snake m_snake;
};

