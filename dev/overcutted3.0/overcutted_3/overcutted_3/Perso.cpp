#include "Perso.h"

Perso::Perso(sf::RenderWindow* m_pointeurFenetre, TextureManager* pointeurTexture,sf::Vector2u initPosition, Perso_conf config, sf::Event* eventPointeur) : Entite(pointeurTexture)
{
	std::cout << "Constructeur Perso" << std::endl;
	m_ptrApp = m_pointeurFenetre;
	m_elements = nullptr;
	m_map = nullptr;
	speed = 10;
	m_initPosition = initPosition;
	m_position = convert_posMap_to_pos(m_initPosition);
	px = 10;
	py = 10;
	m_current_action = Perso_Action::idle;
	m_main_libre = true;
	Perso_Sens_regard m_regard = Perso_Sens_regard::bas;
	positionAnimationX = 0;
	en_mains = nullptr; //a verifier
	m_sprite = m_textureManager->getTexture(TextureType::Personnage, sf::Vector2u(positionAnimationX, 0));
	m_sprite.setPosition(m_position);
	m_eventPerso = eventPointeur;
	m_config = config;
	std::cout << "Perso OK" << std::endl;
};


/*Perso::Perso(Map *map, std::vector<Deplacable*>* elements)
{
	speed = 42;

	//m_elements = elements;
	//m_map = map;

	positionAnimationX = 0;

	m_current_action = Perso_Action::idle;
	m_sprite = m_textureManager->getTexture(TextureType::Personnage, sf::Vector2u(positionAnimationX, 0));
}*/

void Perso::action(sf::Time dureeIteration, sf::Event m_eventPerso)
{
	switch (m_config)
		{
		case Perso_conf::zqsdae:
			if(m_eventPerso.type == sf::Event::EventType::KeyPressed)
			{
				switch (m_eventPerso.key.code)
				{
				case sf::Keyboard::Z: //Marche Haut
					std::cout << "Touche Z pressee" << std::endl;
					m_current_action = Perso_Action::move_up;
					break;
				case sf::Keyboard::S: //Marche Bas
					std::cout << "Touche S pressee" << std::endl;
					m_current_action = Perso_Action::move_down;
					break;
				case sf::Keyboard::Q: //Marche Gauche
					std::cout << "Touche Q pressee" << std::endl;
					m_current_action = Perso_Action::move_left;
					break;
				case sf::Keyboard::D: //Marche Droite
					std::cout << "Touche D pressee" << std::endl;
					m_current_action = Perso_Action::move_right;
					break;
				case sf::Keyboard::A: //Prendre/Deposer
					std::cout << "Touche A pressee" << std::endl;
					m_current_action = Perso_Action::TakeDrop;
					break;
				case sf::Keyboard::E: //Interaction
					std::cout << "Touche E pressee" << std::endl;
					m_current_action = Perso_Action::interact;
					break;
				}
			}
			if (m_eventPerso.type == sf::Event::EventType::KeyReleased)
			{
				switch (m_eventPerso.key.code)
				{
				case sf::Keyboard::Z: //Marche Haut
					std::cout << "Touche Z relachee" << std::endl;
					m_current_action = Perso_Action::idle;
					break;
				case sf::Keyboard::S: //Marche Bas
					std::cout << "Touche S relachee" << std::endl;
					m_current_action = Perso_Action::idle;
					break;
				case sf::Keyboard::Q: //Marche Gauche
					std::cout << "Touche Q relachee" << std::endl;
					m_current_action = Perso_Action::idle;
					break;
				case sf::Keyboard::D: //Marche Droite
					std::cout << "Touche D relachee" << std::endl;
					m_current_action = Perso_Action::idle;
					break;
				case sf::Keyboard::A: //Prendre/Deposer
					std::cout << "Touche A relachee" << std::endl;
					m_current_action = Perso_Action::TakeDrop;
					break;
				case sf::Keyboard::E: //Interaction
					std::cout << "Touche E relachee" << std::endl;
					m_current_action = Perso_Action::interact;
					break;
				}
			}
			break;
		case Perso_conf::ijkluo:
			if (m_eventPerso.KeyPressed)
			{
				switch (m_eventPerso.key.code)
				{
				case sf::Keyboard::I: //Marche Haut
					std::cout << "Touche I pressee" << std::endl;
					m_current_action = Perso_Action::move_up;
					break;
				case sf::Keyboard::K: //Marche Bas
					std::cout << "Touche K pressee" << std::endl;
					m_current_action = Perso_Action::move_down;
					break;
				case sf::Keyboard::J: //Marche Gauche
					std::cout << "Touche J pressee" << std::endl;
					m_current_action = Perso_Action::move_left;
					break;
				case sf::Keyboard::L: //Marche Droite
					std::cout << "Touche L pressee" << std::endl;
					m_current_action = Perso_Action::move_right;
					break;
				case sf::Keyboard::U: //Prendre/Deposer
					std::cout << "Touche U pressee" << std::endl;
					m_current_action = Perso_Action::TakeDrop;
					break;
				case sf::Keyboard::O: //Interaction
					std::cout << "Touche O pressee" << std::endl;
					m_current_action = Perso_Action::interact;
					break;
				}
			}
			else if (m_eventPerso.KeyReleased)
			{
				switch (m_eventPerso.key.code)
				{
				case sf::Keyboard::I: //Marche Haut
					std::cout << "Touche I relachee" << std::endl;
					m_current_action = Perso_Action::idle;
					break;
				case sf::Keyboard::K: //Marche Bas
					std::cout << "Touche K relachee" << std::endl;
					m_current_action = Perso_Action::idle;
					break;
				case sf::Keyboard::J: //Marche Gauche
					std::cout << "Touche J relachee" << std::endl;
					m_current_action = Perso_Action::idle;
					break;
				case sf::Keyboard::L: //Marche Droite
					std::cout << "Touche L relachee" << std::endl;
					m_current_action = Perso_Action::idle;
					break;
				case sf::Keyboard::U: //Prendre/Deposer
					std::cout << "Touche U relachee" << std::endl;
					m_current_action = Perso_Action::TakeDrop;
					break;
				case sf::Keyboard::O: //Interaction
					std::cout << "Touche O relachee" << std::endl;
					m_current_action = Perso_Action::interact;
					break;
				}
			}
			break;
		case Perso_conf::arrowsMajCtrl:
			if (m_eventPerso.KeyPressed)
			{
				switch (m_eventPerso.key.code)
				{
				case sf::Keyboard::Up: //Marche Haut
					std::cout << "Touche ->Up pressee" << std::endl;
					m_current_action = Perso_Action::move_up;
					break;
				case sf::Keyboard::Down: //Marche Bas
					std::cout << "Touche ->Down pressee" << std::endl;
					m_current_action = Perso_Action::move_down;
					break;
				case sf::Keyboard::Left: //Marche Gauche
					std::cout << "Touche <- pressee" << std::endl;
					m_current_action = Perso_Action::move_left;
					break;
				case sf::Keyboard::Right: //Marche Droite
					std::cout << "Touche -> pressee" << std::endl;
					m_current_action = Perso_Action::move_right;
					break;
				case sf::Keyboard::RControl: //Prendre/Deposer
					std::cout << "Touche RCtrl pressee" << std::endl;
					m_current_action = Perso_Action::TakeDrop;
					break;
				case sf::Keyboard::RShift: //Interaction
					std::cout << "Touche RMaj pressee" << std::endl;
					m_current_action = Perso_Action::interact;
					break;
				}
			}
			else if (m_eventPerso.KeyReleased)
			{
				switch (m_eventPerso.key.code)
				{
				case sf::Keyboard::Up: //Marche Haut
					std::cout << "Touche ->Up relachee" << std::endl;
					m_current_action = Perso_Action::idle;
					break;
				case sf::Keyboard::Down: //Marche Bas
					std::cout << "Touche ->Down relachee" << std::endl;
					m_current_action = Perso_Action::idle;
					break;
				case sf::Keyboard::Left: //Marche Gauche
					std::cout << "Touche <- relachee" << std::endl;
					m_current_action = Perso_Action::idle;
					break;
				case sf::Keyboard::Right: //Marche Droite
					std::cout << "Touche -> relachee" << std::endl;
					m_current_action = Perso_Action::idle;
					break;
				case sf::Keyboard::RControl: //Prendre/Deposer
					std::cout << "Touche RCtrl relachee" << std::endl;
					m_current_action = Perso_Action::TakeDrop;
					break;
				case sf::Keyboard::RShift: //Interaction
					std::cout << "Touche RMaj relachee" << std::endl;
					m_current_action = Perso_Action::interact;
					break;
				}
			}
			break;
		default:
			break;
		
	}

	if (m_current_action == Perso_Action::move_left)
	{
		m_regard = Perso_Sens_regard::gauche;
		sf::Vector2f test = m_sprite.getPosition();
		m_position.x -= speed;
		//m_sprite.move(/*dureeIteration.asSeconds() * */-speed, 0);
		std::cout << test.x << " " << test.y << std::endl;
		
	}
	if (m_current_action == Perso_Action::move_right)
	{
		m_regard = Perso_Sens_regard::droite;
		//m_sprite.move(/*dureeIteration.asSeconds()* */ speed, 0);
		m_position.x += speed;
		
	}
	if (m_current_action == Perso_Action::move_up)
	{
		m_regard = Perso_Sens_regard::haut;
		//m_sprite.move(0, /*dureeIteration.asSeconds() **/ -speed);
		m_position.y -= speed;
		
	}
	if (m_current_action == Perso_Action::move_down)
	{
		m_regard = Perso_Sens_regard::bas;
		//m_sprite.move(0, /*dureeIteration.asSeconds() **/ speed);
		m_position.y += speed;
	}
	if (m_current_action == Perso_Action::move_down 
		|| m_current_action == Perso_Action::move_up 
		|| m_current_action == Perso_Action::move_left 
		|| m_current_action == Perso_Action::move_right)
	{
		animation();
	}
}

void Perso::animation()
{
	positionAnimationX++;
	if (positionAnimationX > 3)
	{
		positionAnimationX = 0;
	}
	unsigned int posY = 0;
	switch (m_regard)
	{
	case Perso_Sens_regard::bas:
		posY = 0;
		break;
	case Perso_Sens_regard::gauche:
		posY = 1;
		break;
	case Perso_Sens_regard::droite:
		posY = 2;
		break;
	case Perso_Sens_regard::haut:
		posY = 3;
		break;
	}
	m_sprite = m_textureManager->getTexture(TextureType::Personnage, sf::Vector2u(positionAnimationX, posY));
	m_sprite.setPosition(m_position);
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
