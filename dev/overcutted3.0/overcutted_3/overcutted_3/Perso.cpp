#include "Perso.h"

Perso::Perso(sf::RenderWindow* m_pointeurFenetre, TextureManager* pointeurTexture,sf::Vector2u initPosition, Perso_conf config, sf::Vector2f tileSize, Map* map) : Entite(pointeurTexture)
{
	std::cout << "Constructeur Perso" << std::endl;
	m_ptrApp = m_pointeurFenetre;	//pointeur vers la fenetre
	m_elements = nullptr;			// pointeur vers la liste des deplacable
	m_map = map;				// pointeur vers la carte
	m_objet_en_mains = nullptr;				// pointeur vers UN element deplacable que le perso à en mains
	m_tileSize = tileSize;			// Taille d'une tuile en px
	speed = 5 * m_tileSize.x;		// Vitesse du perso en tuile/seconde
	m_initPosition = initPosition;	// position de départ du personnage
	m_position = convert_posMap_to_pos(m_initPosition);	// convertion de la position sur la carte vers la fenetre: coord.tuile -> coord.px
	m_current_action = Perso_Action::idle;
	m_main_libre = true;
	Perso_Sens_regard m_regard = Perso_Sens_regard::bas;
	positionAnimaion = sf::Vector2u (0,0);
	m_sprite = m_textureManager->getTexture(TextureType::Personnage, sf::Vector2u(positionAnimaion));
	m_sprite.setPosition(m_position);
	m_config = config;
	std::cout << "Perso OK" << std::endl;
};

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
			if (m_eventPerso.type == sf::Event::EventType::KeyPressed)
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
			else if (m_eventPerso.type == sf::Event::EventType::KeyReleased)
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
			if (m_eventPerso.type == sf::Event::EventType::KeyPressed)
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
			else if (m_eventPerso.type == sf::Event::EventType::KeyReleased)
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
		if (!collision()) m_position.x -= dureeIteration.asSeconds() * speed;
	}
	if (m_current_action == Perso_Action::move_right)
	{
		m_regard = Perso_Sens_regard::droite;
		if (!collision())	m_position.x += dureeIteration.asSeconds() * speed;
		
	}
	if (m_current_action == Perso_Action::move_up)
	{
		m_regard = Perso_Sens_regard::haut;
		if (!collision()) m_position.y -= dureeIteration.asSeconds() * speed;
		
	}
	if (m_current_action == Perso_Action::move_down)
	{
		m_regard = Perso_Sens_regard::bas;
		if (!collision()) m_position.y += dureeIteration.asSeconds() * speed;
	}
	if (m_current_action == Perso_Action::TakeDrop)
	{
		prendre_deposer();
	}
	
	if (m_current_action == Perso_Action::move_down 
		|| m_current_action == Perso_Action::move_up 
		|| m_current_action == Perso_Action::move_left 
		|| m_current_action == Perso_Action::move_right)
	{
		animation();
		m_sprite.setPosition(m_position);
		if (!m_main_libre) m_objet_en_mains->setposition(m_position);
	}
}

void Perso::animation()
{
	positionAnimaion.x++;
	if (positionAnimaion.x > 2)
	{
		positionAnimaion.x = 0;
	}
	//unsigned int posY = 0;
	switch (m_regard)
	{
	case Perso_Sens_regard::bas:
		positionAnimaion.y = 0;
		break;
	case Perso_Sens_regard::gauche:
		positionAnimaion.y = 1;
		break;
	case Perso_Sens_regard::droite:
		positionAnimaion.y = 2;
		break;
	case Perso_Sens_regard::haut:
		positionAnimaion.y = 3;
		break;
	}
	m_sprite = m_textureManager->getTexture(TextureType::Personnage, sf::Vector2u(positionAnimaion));

}

void Perso::prendre_deposer()
{
	Tuile* frontTile = getFrontTile();
	if (m_main_libre) // si le perso à les mains libres
	{
		if (!frontTile->getLibre()) // si l'objet contient quelquechose
		{
			m_objet_en_mains = frontTile->PrendreSurTuile();
			m_main_libre = false;
			m_objet_en_mains->setposition(m_position);
		}
	}
	else // si le perso à un truc en main
	{
		if (frontTile->getLibre() || frontTile->getDeposable()) // si la tuile est libre et que l'on peut deposer quelquechose dessus
		{
			frontTile->DeposerSurTuile(m_objet_en_mains);
			m_objet_en_mains = nullptr;
			m_main_libre = true;
		}
	}
}


bool Perso::collision()
{
	Tuile* frontTuile = getFrontTile();
	if (frontTuile->getMarchable()) return false;
	else
	{
		std::cout << "Collision en " << frontTuile->getMapPos().x << "; " << frontTuile->getMapPos().y << std::endl;
		return true;
	}
}


Tuile* Perso::getFrontTile()
{
	sf::Vector2u positionMap(0, 0);
	sf::Vector2u nextTuile(0, 0);
	switch (m_regard)
	{
	case Perso_Sens_regard::bas:
		positionMap = sf::Vector2u((unsigned int)((m_position.x + (m_tileSize.x / 2)) / m_tileSize.x), (unsigned int)((m_position.y) / m_tileSize.y));
		nextTuile.x = positionMap.x;
		nextTuile.y = positionMap.y + 1;
		break;
	case Perso_Sens_regard::gauche:
		positionMap = sf::Vector2u((unsigned int)((m_position.x + (m_tileSize.x)) / m_tileSize.x), (unsigned int)((m_position.y + (m_tileSize.y / 2)) / m_tileSize.y));
		nextTuile.x = positionMap.x - 1;
		nextTuile.y = positionMap.y;
		break;
	case Perso_Sens_regard::droite:
		positionMap = sf::Vector2u((unsigned int)((m_position.x) / m_tileSize.x), (unsigned int)((m_position.y + (m_tileSize.y / 2)) / m_tileSize.y));
		nextTuile.x = positionMap.x + 1;
		nextTuile.y = positionMap.y;
		break;
	case Perso_Sens_regard::haut:
		positionMap = sf::Vector2u((unsigned int)((m_position.x + (m_tileSize.x / 2)) / m_tileSize.x), (unsigned int)((m_position.y + m_tileSize.y) / m_tileSize.y));
		nextTuile.x = positionMap.x;
		nextTuile.y = positionMap.y - 1;
		break;
	}
	std::vector<Tuile*> localMap = m_map->getMapTile();
	int mapSize = localMap.size();
	for (int i = 0; i < mapSize; i++)
	{
		if (localMap[i]->getMapPos() == nextTuile)
		{
			return localMap[i];
		}
		else
		{
			continue;
		}
	}
}