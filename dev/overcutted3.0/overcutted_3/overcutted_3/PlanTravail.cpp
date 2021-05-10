#include "PlanTravail.h"

PlanTravail::PlanTravail(sf::Vector2u position)
{
	m_positionMap = position;
	m_typeTuile = TuileType::Plan_Travail;
	m_marchable = false;
	m_sprite = m_textureManager->getTexture(TextureType::Outils, sf::Vector2u(3,0)); //TODO definir la position dans le fichier de sprite
}