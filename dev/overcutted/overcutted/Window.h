#pragma once
#include <SFML/Graphics.hpp>

class Window
{
public:
	Window();
	Window(const std::string& l_title, const sf::Vector2u& l_size);
	~Window();

	void BeginDraw();
	void Draw(sf::Drawable& l_drawable);
	void EndDraw();

	void Update();

	bool IsDone();
	bool IsFullscreen();
	void ToggleFullscreen();
	sf::Vector2u GetWindowSize();

	sf::RenderWindow* GetRenderWindow();

private:
	void Setup(const std::string& l_title, const sf::Vector2u& l_size);
	void Destroy();
	void Create();

	sf::RenderWindow m_window;
	sf::Vector2u m_windowSize;
	std::string m_windowTitle;
	bool m_IsDone;
	bool m_IsFullScreen;
};

