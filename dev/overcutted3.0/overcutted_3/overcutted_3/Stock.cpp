#include "Stock.h"

Stock::Stock(sf::Vector2u positionCarte, DeplacableType typeAlimentAFournir, std::vector<Deplacable*>* pointeurListeElement, TextureManager* pointeurTexture) : Outil(pointeurTexture)
{
	std::cout << "Constructeur Stock (positionCarte, typeAlimentAFournir, std::vector<Deplacable*>*" << std::endl;
	m_pointeurListeElement = pointeurListeElement;
	m_positionMap = positionCarte;
	m_position = convert_posMap_to_pos(m_positionMap);
	m_marchable = false;
	m_typeTuile = TuileType::Stock;
	m_ressourceAFournir = typeAlimentAFournir;

	switch (typeAlimentAFournir)
	{
	case DeplacableType::poisson:
		m_sprite = m_textureManager->getTexture(TextureType::Outils, sf::Vector2u(1, 1));
		break;
	case DeplacableType::crevette:
		m_sprite = m_textureManager->getTexture(TextureType::Outils, sf::Vector2u(0, 1));
		break;
	case DeplacableType::assiette:
		m_sprite = m_textureManager->getTexture(TextureType::Outils, sf::Vector2u(2, 1));
		break;
	default:
		m_sprite = m_textureManager->getTexture(TextureType::Outils, sf::Vector2u(0, 0));
		break;
	}
	std::cout << "Stock OK" << std::endl;
}

void Stock::Interaction()
{
	if (m_libre)
	{
		switch (m_ressourceAFournir)
		{
		case DeplacableType::none:
			break;
		case DeplacableType::poisson:
			m_pointeurListeElement->push_back(new Poisson(m_position, m_textureManager));
			break;
		case DeplacableType::crevette:
			m_pointeurListeElement->push_back(new Crevette(m_position, m_textureManager));
			break;
		case DeplacableType::assiette:
			m_pointeurListeElement->push_back(new Assiette(m_position, m_textureManager));
			break;
		default:
			break;
		}
	}
}

