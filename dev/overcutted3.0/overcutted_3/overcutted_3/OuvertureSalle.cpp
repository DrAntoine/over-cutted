#include "OuvertureSalle.h"

OuvertureSalle::OuvertureSalle(sf::Vector2u positioncarte, TextureManager* pointeurTexture) : Outil(pointeurTexture)
{
	std::cout << "Constructeur OuvertureSalle (positioncarte)" << std::endl;
	m_positionMap = positioncarte;
	m_position = convert_posMap_to_pos(m_positionMap);
	m_sprite = m_textureManager->getTexture(TextureType::Outils, sf::Vector2u(7, 0));
	m_sprite.setPosition(m_position);
	std::cout << "OuvertureSalle OK" << std::endl;
}
