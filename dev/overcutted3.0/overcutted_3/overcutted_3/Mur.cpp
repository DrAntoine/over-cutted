#include "Mur.h"
Mur::Mur(sf::Vector2u positionCarte, TextureManager* pointeurText) : Tuile(pointeurText)
{
	std::cout << "Constructeur Mur (positionCarte, TextureManager)*" << std::endl;
	//m_textureManager = pointeurText;
	m_typeTuile = TuileType::Mur;
	m_marchable = false;
	m_positionMap = positionCarte;
	m_position = convert_posMap_to_pos(m_positionMap);
	m_sprite = m_textureManager->getTexture(TextureType::Outils, sf::Vector2u(2, 0));
	m_sprite.setPosition(m_position);
	std::cout << "Mur OK" << std::endl;
}