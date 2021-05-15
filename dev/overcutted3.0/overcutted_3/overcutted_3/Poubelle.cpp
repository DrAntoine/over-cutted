#include "Poubelle.h"

Poubelle::Poubelle(sf::Vector2u positionCarte, TextureManager* pointeurTexture, DeplacableManager* deplacableManager) : Outil(pointeurTexture)
{
	std::cout << "Constructeur Poubelle (positionCarte)" << std::endl;
	m_positionMap = positionCarte;
	m_deplacableManager = deplacableManager;
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

bool Poubelle::DeposerSurTuile(Deplacable* objet)
{
	m_deplacableManager->DeleteElement(objet);
	return true;
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
