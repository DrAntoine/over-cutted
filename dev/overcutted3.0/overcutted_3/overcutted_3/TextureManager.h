#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include <iostream>


enum class TextureType
{
	Personnage,
	Aliments, 
	Outils,
	Recette
};

class TextureManager
{
public:
	TextureManager();
	virtual ~TextureManager();
	sf::Sprite getTexture(TextureType m_type, sf::Vector2u positionInFile);
	//sf::Sprite getTexture(TextureType m_type, sf::Vector2u positionInFile, sf::Vector2f imageSize);

private:
	sf::Texture m_textPerso;
	sf::Texture m_textOutils;
	sf::Texture m_textAliments;
	sf::Texture m_textRecette;
	
	sf::Sprite m_sprite;

	sf::Vector2u m_imageSize;
};

