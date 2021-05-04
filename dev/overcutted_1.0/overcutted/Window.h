#pragma once
#include <SFML/Graphics.hpp>
#include "EventManager.h"

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
	void ToggleFullscreen(EventDetails* l_details);
	sf::Vector2u GetWindowSize();

	sf::RenderWindow* GetRenderWindow();

	bool IsFocused();
	EventManager* GetEventManager();
	void Close(EventDetails* l_details = nullptr);

private:
	void Setup(const std::string& l_title, const sf::Vector2u& l_size);
	void Destroy();
	void Create();

	sf::RenderWindow m_window;
	sf::Vector2u m_windowSize;
	std::string m_windowTitle;
	bool m_IsDone;
	bool m_IsFullScreen;

	EventManager m_eventManager;
	bool m_isFocused;
};

