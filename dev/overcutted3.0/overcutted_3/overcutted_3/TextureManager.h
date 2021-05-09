#pragma once
#include <string>
#include <SFML/Graphics.hpp>

enum class TextureType
{
	Personnage,
	Aliments, 
	Outils
};

class TextureManager
{
public:
	TextureManager(const std::string PersoPath, const std::string OutilsPath, const std::string AlimentsPath);
	void getTexture(TextureType m_type, sf::Vector2u positionInFile);
	sf::Sprite getSprite();
private:
	sf::Texture m_textPerso;
	sf::Texture m_textOutils;
	sf::Texture m_textAliments;
	
	sf::Sprite m_sprite;

	sf::Vector2u m_imageSize;
};

