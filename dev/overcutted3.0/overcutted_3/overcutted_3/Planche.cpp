#include "Planche.h"
#include "DeplacableManager.h"

Planche::Planche(sf::Vector2u position, TextureManager* pointeurTexture, DeplacableManager* deplacableManager) : Outil(pointeurTexture)
{
	std::cout << "Constructeur Planche (position)" << std::endl;
	m_positionMap = position;
	m_position = convert_posMap_to_pos(m_positionMap);
	m_typeTuile = TuileType::Planche_decoupe;
	m_marchable = false;
	m_libre = true;
	m_deposable = true;
	m_prenable = true;
	m_interagissable = true;
	m_deplacableManager = deplacableManager;
	m_sprite = m_textureManager->getTexture(TextureType::Outils, sf::Vector2u(4, 0));
	m_sprite.setPosition(m_position);
	bool m_fini = false;
	m_alimentSurPlanche = nullptr;
	m_temps_animation = sf::seconds(2);
	std::cout << "Planche OK" << std::endl;
}

Planche::~Planche()
{
}

bool Planche::DeposerSurTuile(Deplacable* ptrObjet)
{
	if (m_libre)
	{
		m_objetSurTuile = ptrObjet;
		m_libre = false;
		m_objetSurTuile->setposition(m_position);
		return true;
	}
	else if (!m_libre && m_objetSurTuile->getType() == DeplacableType::assiette)
	{
		Assiette* assiette = nullptr;
		assiette = m_deplacableManager->getAssiette(m_objetSurTuile->getId());
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

Deplacable* Planche::PrendreSurTuile()
{
	Deplacable* objetARendre = m_objetSurTuile;
	m_objetSurTuile = nullptr;
	m_libre = true;
	if (m_fini) m_fini = false;
	if (m_alimentSurPlanche != nullptr) m_alimentSurPlanche = nullptr;
	m_interagissable = true;
	return objetARendre;
}

bool Planche::getLibre()
{
	return m_libre;
}

void Planche::interact(sf::Time temps_ecoule)
{
	std::cout << "Planche Interaction" << std::endl;
	if (!m_libre && !m_fini && m_alimentSurPlanche == nullptr)
	{
		std::cout << "Planche : Recup obj :";
		DeplacableType typeObjetTuile = m_objetSurTuile->getType();
		Aliment* aliment = nullptr;
		if (typeObjetTuile == DeplacableType::poisson) aliment = m_deplacableManager->getPoisson(m_objetSurTuile->getId());
		if (typeObjetTuile == DeplacableType::crevette) aliment = m_deplacableManager->getCrevette(m_objetSurTuile->getId());
		if (aliment != nullptr && aliment->estCoupable() && !aliment->estCouper())
		{
			m_alimentSurPlanche = aliment;
			m_fini = false;
			m_prenable = false;
		}
		std::cout << " OK" << std::endl;
	}
	if (m_alimentSurPlanche != nullptr && !m_fini)
	{
		std::cout << "Planche en cours d'utilisation" << std::endl;
		
			m_temps_ecoule += temps_ecoule;
			if (m_temps_ecoule >= m_temps_animation)
			{
				m_fini = true;
				m_interagissable = false;
				m_prenable = true;
				m_temps_ecoule = sf::seconds(0);
				m_alimentSurPlanche->setCoupe();
				std::cout << "Planche Fini" << std::endl;
			}
		
	}
	else
	{
		std::cout << "Ne peut pas interagir" << std::endl;
		m_fini = true;
	}
}

bool Planche::estFini()
{
	return m_fini;
}