#include "Planche.h"

Planche::Planche(sf::Vector2u position, TextureManager* pointeurTexture) : Outil(pointeurTexture)
{
	std::cout << "Constructeur Planche (position)" << std::endl;
	m_positionMap = position;
	m_position = convert_posMap_to_pos(m_positionMap);
	m_typeTuile = TuileType::Planche_decoupe;
	m_marchable = false;
	m_libre = true;
	m_sprite = m_textureManager->getTexture(TextureType::Outils, sf::Vector2u(4, 0));
	m_sprite.setPosition(m_position);
	std::cout << "Planche OK" << std::endl;
}

void Planche::DeposerSurTuile(Deplacable* ptrObjet)
{
	m_objetSurTuile = ptrObjet;
	m_libre = false;
	m_objetSurTuile->setposition(m_position);
}

bool Planche::getLibre()
{
	return m_libre;
}