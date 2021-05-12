#include "Entite.h"

Entite::Entite(TextureManager* pointeurText)
{
	std::cout << "Constructeur Entite" << std::endl;
	m_textureManager = pointeurText; //new TextureManager("Textures/persotext.png", "Textures/decors.png", "Textures/aliments.png");
	m_sprite = sf::Sprite();
	m_position = sf::Vector2f(1, 1);
	m_taille = sf::Vector2f(50, 50);
	std::cout << "Entite OK" << std::endl;
}

sf::Vector2f Entite::convert_posMap_to_pos(sf::Vector2u m_positionMap)
{
	sf::Vector2f position = sf::Vector2f(m_positionMap.x * m_taille.x, m_positionMap.y * m_taille.y);
	return position;
}

//void Entite::setTextureManagerAddresse(TextureManager* textureManagerAddr)
//{
//	m_textureManager = textureManagerAddr;
//}
void Entite::draw(sf::RenderWindow* app)
{
	app->draw(m_sprite);
}
void Entite::update()
{

}