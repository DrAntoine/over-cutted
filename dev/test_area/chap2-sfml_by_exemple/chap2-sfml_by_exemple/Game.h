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
	sf::Time GetElapsed();
	void RestartClock();
private:
	void MoveMushroom();
	void Change_mushroom_color();
	Window m_window;
	sf::Texture m_mushroomTexture;
	sf::Texture m_mushroomTextureBlue;
	sf::Sprite m_mushroom;
	bool m_mushroom_blue;
	sf::Vector2i m_increment;
	sf::Clock m_clock;
	sf::Time m_elapsed;
	sf::Time f_elapsed;
	float m_frametime;
	int m_nb_frame;
};

