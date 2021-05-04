#pragma once
#include <SFML/Graphics.hpp>

enum class TileType{
	Sol = 0,
	Plan_travail = 1,
	Caisse = 2,
	Planche_decoupe = 3
};

class Tile
{
public:
	Tile(int type, sf::Texture tile_texture, );
private:
	TileType m_type;
	bool m_walkable;
	bool m_letGoOn;
	sf::Texture m_texture;
	sf::Vector2u m_position;
	sf::Vector2u m_size;
};

