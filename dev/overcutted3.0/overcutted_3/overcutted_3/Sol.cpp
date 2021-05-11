#include "Sol.h"
Sol::Sol(sf::Vector2u positionCarte, TextureManager* pointeurText): Tuile(pointeurText)
{
	std::cout << "Constructeur Sol (positionCarte, TextureManager*)" << std::endl;
	//m_textureManager = pointeurText;
	m_typeTuile = TuileType::Sol;
	m_marchable = true;
	m_positionMap = positionCarte;
	m_position = convert_posMap_to_pos(m_positionMap);
	m_sprite = m_textureManager->getTexture(TextureType::Outils, sf::Vector2u(1, 0));
	m_sprite.setPosition(m_position);
	std::cout << "Sol OK" << std::endl;
}
