#pragma once
#include <string>

#ifndef sfml
#include <SFML/Graphics.hpp>
#endif // !sfml

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
	sf::Sprite getTexture(TextureType m_type, sf::Vector2u positionInFile);

private:
	sf::Texture m_textPerso;
	sf::Texture m_textOutils;
	sf::Texture m_textAliments;
	
	sf::Sprite m_sprite;

	sf::Vector2u m_imageSize;
};

