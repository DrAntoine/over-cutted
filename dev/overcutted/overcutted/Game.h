#pragma once

#include <SFML/Graphics.hpp>
#include "Window.h"
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
	sf::Time GetElapsedTime();
	unsigned int GetTick();
	void RestartClock();
private:
	Window m_window;
	sf::Clock m_clock;
	sf::Time m_total_elapsed;
	unsigned int m_tick; // =4294967295 si on raffraichi à 60Hz ça nous laisse 828J de tick avant de dépasser le seuil limite du type.
	//World m_world;
};

