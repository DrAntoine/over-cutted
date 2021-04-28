#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

enum class TileType
{
	Sol,
	Mur,
	Plan_travail,
	Reception_assiette,
	Envoi_assiette,
	Poubelle,
	Ressource_poisson,
	Ressource_crevette,
	Planche_decoupe
};

class Tile
{
public:
	Tile(int numberSprite, std::vector<sf::Vector2u> spritePosition, TileType type);
	int getTileSize();
	void Update_tile();
	void SetTexture(sf::Vector2u texturePosition);
	void GetTexture();
private:
	sf::Vector2u m_tileSize;
	sf::Vector2u m_position; // position sur la carte (ex 1;1) en terme de tuile et non de px
	sf::Texture m_texture;
	TileType m_tileType;
	int m_usageStep; // sera utilisé pour déterminer quelle texture appliquer à une tuile en fonction de son niveau d'utilisation (pour les différents sprite de la planche de découpe par ex)
	int m_numberSprite; 
};

