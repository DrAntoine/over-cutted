#include "Perso.h"

Perso::Perso(Map *map, std::vector<Deplacable*>* elements)
{
	speed = 42;
	m_elements = elements;
	m_map = map;

}

void Perso::move()
{
	if (sf::Event::EventType::KeyPressed)
	{
		switch(m_eventPerso.key.code)
		{
			case sf::Keyboard::Right:
				m_current_action = Perso_Action::move_right;
				break;
			case sf::Keyboard::Left:
				m_current_action = Perso_Action::move_left;
				break;
			case sf::Keyboard::Up:
				m_current_action = Perso_Action::move_up;
				break;
			case sf::Keyboard::Down:
				m_current_action = Perso_Action::move_down;
				break;
			default:
				break;
		}
	}
	if (sf::Event::EventType::KeyReleased)
	{
		switch (m_eventPerso.key.code)
		{
		case sf::Keyboard::Right:
			m_current_action = Perso_Action::idle;
			break;
		case sf::Keyboard::Left:
			m_current_action = Perso_Action::idle;
			break;
		case sf::Keyboard::Up:
			m_current_action = Perso_Action::idle;
			break;
		case sf::Keyboard::Down:
			m_current_action = Perso_Action::idle;
			break;
		default:
			break;
		}
	}
	if (m_current_action==Perso_Action::move_left) mysprite.move(dureeItération.asSecondes() * -speed,0);
	if (m_current_action == Perso_Action::move_right) mysprite.move(dureeItération.asSecondes() * speed,0);
	if (m_current_action == Perso_Action::move_up) mysprite.move(0,dureeItération.asSecondes() * -speed);
	if (m_current_action == Perso_Action::move_down) mysprite.move(0,dureeItération.asSecondes() * speed);
}
