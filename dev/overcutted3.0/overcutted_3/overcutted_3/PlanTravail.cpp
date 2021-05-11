#include "PlanTravail.h"

PlanTravail::PlanTravail(sf::Vector2u position, TextureManager* pointeurTexture) : Outil(pointeurTexture)
{
	std::cout << "Constructeur PlanTravail (position)" << std::endl;
	m_positionMap = position;
	m_position = convert_posMap_to_pos(m_positionMap);
	m_typeTuile = TuileType::Plan_Travail;
	m_marchable = false;
	m_sprite = m_textureManager->getTexture(TextureType::Outils, sf::Vector2u(3,0));
	std::cout << "PlanTravail OK" << std::endl;
}