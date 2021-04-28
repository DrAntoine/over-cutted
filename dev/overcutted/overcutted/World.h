#pragma once
#include <SFML/Graphics.hpp>

class World : sf::Drawable, sf::Transformable
{
public:
	World(const std::string pathTextureMap, sf::Vector2u blockSize, sf::Vector2u mapSize);
	~World();
	bool load(const int* refMap);
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	sf::Vector2u m_blockSize;
	std::string m_pathTextureMap;
	sf::Vector2u m_mapSize;
	sf::VertexArray m_vertices;
	sf::Texture m_textureMap;
};

