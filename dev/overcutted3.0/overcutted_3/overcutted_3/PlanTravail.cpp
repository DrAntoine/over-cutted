#include "PlanTravail.h"

PlanTravail::PlanTravail(sf::Vector2u position)
{
	m_positionMap = position;
	m_type = TuileType::Plan_Travail;
	m_marchable = false;
	m_sprite = m_textureManager->getTexture(TextureType::Outils, sf::Vector2u(0,0)); //TODO definir la position dans le fichier de sprite
}