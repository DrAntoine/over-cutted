#include "Perso.h"

Perso::Perso(Map *map, std::vector<Deplacable*>* elements)
{
	speed = 42;

	m_elements = elements;
	m_map = map;

	positionAnimationX = 0;

	m_current_action = Perso_Action::idle;
	m_sprite = m_textureManager->getTexture(TextureType::Personnage, sf::Vector2u(positionAnimationX, 0));
}

void Perso::action(sf::Time dureeIteration)
{
	if (sf::Event::EventType::KeyPressed)
	{
		animation();
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
			case sf::Keyboard::E:
				m_current_action = Perso_Action::interact;
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
		case sf::Keyboard::E:
			m_current_action = Perso_Action::idle;
			break;
		default:
			break;
		}
	}
	if (m_current_action==Perso_Action::move_left) m_sprite.move(dureeIteration.asSeconds() * -speed,0);
	if (m_current_action == Perso_Action::move_right) m_sprite.move(dureeIteration.asSeconds() * speed,0);
	if (m_current_action == Perso_Action::move_up) m_sprite.move(0, dureeIteration.asSeconds() * -speed);
	if (m_current_action == Perso_Action::move_down) m_sprite.move(0, dureeIteration.asSeconds() * speed);
}

void Perso::animation()
{
	positionAnimationX++;
	if (positionAnimationX > 3)
	{
		positionAnimationX = 0;
	}
	if (m_current_action == Perso_Action::move_down)
	{
		m_sprite = m_textureManager->getTexture(TextureType::Personnage,sf::Vector2u(positionAnimationX,0));
	}
	if (m_current_action == Perso_Action::move_up)
	{
		m_sprite = m_textureManager->getTexture(TextureType::Personnage, sf::Vector2u(positionAnimationX,3));
	}
	if (m_current_action == Perso_Action::move_left)
	{
		m_sprite = m_textureManager->getTexture(TextureType::Personnage, sf::Vector2u(positionAnimationX,1));
	}
	if (m_current_action == Perso_Action::move_right)
	{
		m_sprite = m_textureManager->getTexture(TextureType::Personnage, sf::Vector2u(positionAnimationX,2));
	}
	
}
//void Perso::action()
//{
//	if (m_current_action == Perso_Action::interact)
//	{
//
//	}
//}
void Perso::collision()
{

}
