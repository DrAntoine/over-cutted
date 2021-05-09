#include "Entite.h"

Entite::Entite()
{
	m_textureManager = nullptr; //new TextureManager("Textures/persotext.png", "Textures/decors.png", "Textures/aliments.png");
	m_sprite = sf::Sprite();
	m_position = sf::Vector2f(1, 1);
	m_taille = sf::Vector2f(50, 50);
}

void Entite::setTextureManagerAddresse(TextureManager* textureManagerAddr)
{
	m_textureManager = textureManagerAddr;
}
void Entite::draw(sf::RenderWindow* app)
{
	app->draw(m_sprite);
}
void Entite::update()
{

}