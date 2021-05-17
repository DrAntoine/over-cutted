#include "OuvertureSalle.h"

OuvertureSalle::OuvertureSalle(sf::Vector2u positioncarte, TextureManager* pointeurTexture, DeplacableManager* deplacableManager, RecetteManager* recetteManager) : Outil(pointeurTexture)
{
	std::cout << "Constructeur OuvertureSalle (positioncarte)" << std::endl;
	m_typeTuile = TuileType::Ouverture_Salle;
	m_marchable = false;
	m_prenable = false;
	m_deposable = true;
	m_interagissable = false;
	m_libre = true;
	m_positionMap = positioncarte;
	m_deplacableManager = deplacableManager;
	m_recetteManager = recetteManager;
	m_position = convert_posMap_to_pos(m_positionMap);
	m_sprite = m_textureManager->getTexture(TextureType::Outils, sf::Vector2u(6, 0));
	m_sprite.setPosition(m_position);
	std::cout << "OuvertureSalle OK" << std::endl;
}

OuvertureSalle::~OuvertureSalle()
{
}

bool OuvertureSalle::DeposerSurTuile(Deplacable* objet)
{
	DeplacableType typeObjet = objet->getType();
	if (typeObjet == DeplacableType::assiette)
	{
		Assiette* assietteAValider = nullptr;
		assietteAValider = m_deplacableManager->getAssiette(objet->getId());
		m_recetteManager->validationRecette(assietteAValider);
		m_deplacableManager->DeleteElement(assietteAValider);
		return true;
	}
	else return false;
}
