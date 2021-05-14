#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include <iostream>


enum class TextureType
{
	Personnage,
	Aliments, 
	Outils
};

class TextureManager
{
public:
	TextureManager();
	virtual ~TextureManager();
	sf::Sprite getTexture(TextureType m_type, sf::Vector2u positionInFile);

private:
	sf::Texture m_textPerso;
	sf::Texture m_textOutils;
	sf::Texture m_textAliments;
	
	sf::Sprite m_sprite;

	sf::Vector2u m_imageSize;
};

