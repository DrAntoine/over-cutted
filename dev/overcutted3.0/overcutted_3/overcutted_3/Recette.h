#pragma once
#ifndef sfml
#include <SFML/Graphics.hpp>
#endif // !sfml

class Recette
{
private:
	sf::Vector2f m_taille;
	sf::Vector2f m_position;
	sf::Sprite m_sprite;
	//std::vector<>recette;

public:
	Recette();
};

