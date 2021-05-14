#include "Poubelle.h"

Poubelle::Poubelle(sf::Vector2u positionCarte, TextureManager* pointeurTexture, std::vector<Deplacable*>* pointeurElement) : Outil(pointeurTexture)
{
	std::cout << "Constructeur Poubelle (positionCarte)" << std::endl;
	m_positionMap = positionCarte;
	m_element = pointeurElement;
	m_position = convert_posMap_to_pos(m_positionMap);
	m_typeTuile = TuileType::Poubelle;
	m_marchable = false;
	m_prenable = false;
	m_deposable = true;
	m_interagissable = false;
	m_libre = true;
	m_sprite = m_textureManager->getTexture(TextureType::Outils, sf::Vector2u(5, 0));
	m_sprite.setPosition(m_position);
	std::cout << "Poubelle OK" << std::endl;
}




Poubelle::~Poubelle()
{
}

void Poubelle::DeposerSurTuile(Deplacable* objet)
{
	Deplacable* nullpointeur = nullptr;
	Deplacable* objetADelete = nullptr;
	for (unsigned int i = 0; i < m_element->size(); i++)
	{
		if (m_element->at(i)->getId() == objet->getId())
		{
			objetADelete = m_element->at(i);
			m_element->at(i) = nullpointeur;
		}
	}

	// =============================================== 
	delete objetADelete; //entite semble toujours là		HELPPPPPPPP		HELPPPPPPPP		HELPPPPPPPP		HELPPPPPPPP
	// =============================================== 
}

Deplacable* Poubelle::PrendreSurTuile()
{
	Deplacable* pointeurVide = nullptr;
	return pointeurVide; //pointeur null car on ne reprend rien dans la poubelle
}

bool Poubelle::getLibre()
{
	return m_libre;
}

void Poubelle::UpdatePointeurM_Element(std::vector<Deplacable*>* nouveauPointeur)
{
	m_element = nouveauPointeur;
}

