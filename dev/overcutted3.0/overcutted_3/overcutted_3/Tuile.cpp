#include "Tuile.h"
Tuile::Tuile(TextureManager* pointeurText) : Entite(pointeurText)
{
	std::cout << "Constructeur Tuile" << std::endl;
	m_sprite = m_textureManager->getTexture(TextureType::Outils, sf::Vector2u(0, 0));
	m_position = sf::Vector2f(50, 50);
	m_libre = true;
	m_marchable = true;
	m_typeTuile = TuileType::None;
	m_objetSurTuile = nullptr;
	std::cout << "Tuile OK" << std::endl;
}

TuileType Tuile::getTypeTuile()
{
	return m_typeTuile;
}

bool Tuile::getMarchable()
{
	return m_marchable;
}

bool Tuile::getLibre()
{
	return m_libre;
}

bool Tuile::getDeposable()
{
	return m_deposable;
}

bool Tuile::getInteragissable()
{
	return m_interagissable;
}

void Tuile::DeposerSurTuile(Deplacable* ptrObjet)
{
	m_objetSurTuile = ptrObjet;
	m_libre = false;
	m_objetSurTuile->setposition(m_position);
}

Deplacable* Tuile::PrendreSurTuile()
{
	Deplacable* objetADonner = m_objetSurTuile;
	m_objetSurTuile = nullptr;
	m_libre = true;
	return objetADonner;
}

sf::Vector2u Tuile::getMapPos()
{
	return m_positionMap;
}


