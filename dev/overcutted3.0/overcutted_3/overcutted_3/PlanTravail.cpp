#include "PlanTravail.h"

PlanTravail::PlanTravail(sf::Vector2u position, TextureManager* pointeurTexture, DeplacableManager* deplacableManager) : Outil(pointeurTexture)
{
	std::cout << "Constructeur PlanTravail (position)" << std::endl;
	m_positionMap = position;
	m_position = convert_posMap_to_pos(m_positionMap);
	m_typeTuile = TuileType::Plan_Travail;
	m_marchable = false;
	m_libre = true;
	m_deposable = true;
	m_prenable = true;
	m_sprite = m_textureManager->getTexture(TextureType::Outils, sf::Vector2u(3,0));
	m_sprite.setPosition(m_position);
	std::cout << "PlanTravail OK" << std::endl;
}
PlanTravail::~PlanTravail()
{
}
void PlanTravail::DeposerSurTuile(Deplacable* ptrObjet)
{
	m_objetSurTuile = ptrObjet;
	m_libre = false;
	m_objetSurTuile->setposition(m_position);
}

Deplacable* PlanTravail::PrendreSurTuile()
{
	Deplacable* objetARendre = m_objetSurTuile;
	m_objetSurTuile = nullptr;
	m_libre = true;
	return objetARendre;
}


bool PlanTravail::getLibre()
{
	return m_libre;
}