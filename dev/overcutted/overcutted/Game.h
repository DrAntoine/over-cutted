#pragma once

#include <SFML/Graphics.hpp>
#include "Window.h"

class Game
{
public:
	Game();
	~Game();

	void HandleInput();
	void Update();
	void Render();

	Window* GetWindow();
	sf::Time GetElapsedTime();
	void RestartClock();
private:
	Window m_window;
	sf::Clock m_clock;
	sf::Time m_elapsedTime;
	//World m_world;
};

