#pragma once

#include <SFML/Graphics.hpp>
#include "Window.h"
#include "World.h"

struct SharedContext
{
	SharedContext():m_window(nullptr), m_world(nullptr)
	{}
	World* m_world;
	Window* m_window;
};

class Game
{
public:
	Game();
	~Game();

	void HandleInput();
	void Update();
	void Render();
	bool LoadMap(const int*);

	Window* GetWindow();
	sf::Time GetElapsedTime();
	void RestartClock();
private:
	Window m_window;
	sf::Clock m_clock;
	sf::Time m_elapsedTime;
	World m_world;
};

