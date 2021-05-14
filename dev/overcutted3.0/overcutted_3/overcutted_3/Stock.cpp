#include "Stock.h"

Stock::Stock(sf::Vector2u positionCarte, DeplacableType typeAlimentAFournir, DeplacableManager* deplacableManager, TextureManager* pointeurTexture) : Outil(pointeurTexture)
{
	std::cout << "Constructeur Stock (positionCarte, typeAlimentAFournir, std::vector<Deplacable*>*" << std::endl;
	m_deplacableManager = deplacableManager;
	m_positionMap = positionCarte;
	m_position = convert_posMap_to_pos(m_positionMap);
	m_marchable = false;
	m_typeTuile = TuileType::Stock;
	m_libre = false;
	m_deposable = false;
	m_prenable = true;
	m_interagissable = false;
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
	m_sprite.setPosition(m_position);
	std::cout << "Stock OK" << std::endl;
}

Stock::~Stock()
{
}

Deplacable* Stock::PrendreSurTuile()
{
	std::cout << "stock prendre" << std::endl;
	Deplacable* objet = m_deplacableManager->CreateElement(m_ressourceAFournir, m_position, m_textureManager);
	std::cout << "Creation nouveau Deplacable" << std::endl;
	return objet;
}
