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
	m_deplacableManager = deplacableManager;
	std::cout << "PlanTravail OK" << std::endl;
}
PlanTravail::~PlanTravail()
{
}
bool PlanTravail::DeposerSurTuile(Deplacable* ptrObjet)
{
	/*m_objetSurTuile = ptrObjet;
	m_libre = false;
	m_objetSurTuile->setposition(m_position);
	return true;*/
	if (m_libre)
	{
		m_objetSurTuile = ptrObjet;
		m_libre = false;
		m_objetSurTuile->setposition(m_position);
		return true;
	}
	else if (!m_libre && m_objetSurTuile->getType() == DeplacableType::assiette)
	{
		Assiette* assiette = m_deplacableManager->getAssiette(m_objetSurTuile->getId());
		DeplacableType objet = ptrObjet->getType();
		if (objet == DeplacableType::crevette || objet == DeplacableType::poisson)
		{
			Aliment* aliment = nullptr;
			if (objet == DeplacableType::crevette) aliment = m_deplacableManager->getCrevette(ptrObjet->getId());
			if (objet == DeplacableType::poisson) aliment = m_deplacableManager->getPoisson(ptrObjet->getId());
			return assiette->DeposerSurAssiette(aliment);
		}
		else return false;
	}
	else
	{
		return false;
	}
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