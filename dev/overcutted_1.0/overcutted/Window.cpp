#include "Window.h"

Window::Window()
{
	Setup("Overcutted", sf::Vector2u(640, 480));
}

Window::Window(const std::string& l_title, const sf::Vector2u& l_size)
{
	Setup(l_title, l_size);
}

Window::~Window()
{
	Destroy();
}

void Window::BeginDraw()
{
	m_window.clear(sf::Color::Black);
}

void Window::Draw(sf::Drawable& l_drawable)
{
	m_window.draw(l_drawable);
}

void Window::EndDraw()
{
	m_window.display();
}

void Window::Update()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		/*if (event.type == sf::event::closed)
		{
			m_isdone = true;
		}
		else if (event.type == sf::event::keypressed && event.key.code == sf::keyboard::f5)
		{
			togglefullscreen();
		}*/
		if (event.type == sf::Event::LostFocus) {
			m_isFocused = false;
			m_eventManager.SetFocus(false);
		}
		else if (event.type == sf::Event::GainedFocus) {
			m_isFocused = true;
			m_eventManager.SetFocus(true);
		}
		m_eventManager.Update();
	}
}

bool Window::IsDone()
{
	return m_IsDone;
}

bool Window::IsFullscreen()
{
	return m_IsFullScreen;
}

void Window::ToggleFullscreen(EventDetails* l_event)
{
	m_IsFullScreen = !m_IsFullScreen;
	Destroy();
	Create();
}

sf::Vector2u Window::GetWindowSize()
{
	return m_windowSize;
}

sf::RenderWindow* Window::GetRenderWindow()
{
	return &m_window;
}

void Window::Close(EventDetails* l_details)
{
	m_IsDone = true;
}

void Window::Setup(const std::string& l_title, const sf::Vector2u& l_size)
{
	m_windowTitle = l_title;
	m_windowSize = l_size;
	m_IsFullScreen = false;
	m_window.setFramerateLimit(60);
	m_isFocused = true; // valeur par défaut du drapeau focus
	m_eventManager.AddCallBack("Fullscreen_toggle", &Window::ToggleFullscreen, this); //Dans le fichier de config, l'event toggle fullscreen à la position 5 et la touche F5 correspond au code 89 d'où la ligne "Fullscreen_toggle 5:89" dans le fichier de config
	m_eventManager.AddCallBack("Window_Close", &Window::Close, this);
	Create();
}

void Window::Destroy()
{
	m_window.close();
}

void Window::Create()
{
	auto style = (m_IsFullScreen ? sf::Style::Fullscreen : sf::Style::Default);
	m_window.create({ m_windowSize.x, m_windowSize.y, 32 }, m_windowTitle, style);
}

EventManager* Window::GetEventManager()
{
	return &m_eventManager;
}

bool Window::IsFocused()
{
	return m_isFocused;
}