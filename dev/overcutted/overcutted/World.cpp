#include "World.h"

World::World(const std::string pathTextureMap, sf::Vector2u blockSize, sf::Vector2u mapSize)
{
	m_blockSize = blockSize;
	m_pathTextureMap = pathTextureMap;
	m_mapSize = mapSize;
	m_vertices.setPrimitiveType(sf::Quads);
	m_vertices.resize(m_mapSize.x * m_mapSize.y * 4);
}

World::~World()
{

}

bool World::load(const int* refMap)
{
	if (!m_textureMap.loadFromFile(m_pathTextureMap))
	{
		return false;
	}
	for (unsigned int i = 0; i < m_mapSize.x; i++)
	{
		for (unsigned int j = 0; j < m_mapSize.y; j++)
		{
			//Récupération du type de la tuile dans la refMap[]
			int tileNumber = refMap[i + j * m_mapSize.y];

			//Récupération de la position dans la texture
			int textX = tileNumber % (m_textureMap.getSize().x / m_blockSize.x);
			int textY = tileNumber / (m_textureMap.getSize().x / m_blockSize.x);

			//récupération d'un pointeru vers le quad à définir dans le tableau de vertex
			sf::Vertex* quad = &m_vertices[(i + j * m_mapSize.y) * 4];

			// définition des 4 coins
			quad[0].position = sf::Vector2f(i * m_blockSize.x, j * m_blockSize.y);
			quad[1].position = sf::Vector2f((i + 1) * m_blockSize.x, j * m_blockSize.y);
			quad[2].position = sf::Vector2f((i + 1) * m_blockSize.x, (j + 1) * m_blockSize.y);
			quad[3].position = sf::Vector2f(i * m_blockSize.x, (j + 1) * m_blockSize.y);

			//definition de la texture
			quad[0].texCoords = sf::Vector2f(textX * m_blockSize.x, textY * m_blockSize.y);
			quad[1].texCoords = sf::Vector2f((textX+1) * m_blockSize.x, textY * m_blockSize.y);
			quad[2].texCoords = sf::Vector2f((textX+1) * m_blockSize.x, (textY+1) * m_blockSize.y);
			quad[3].texCoords = sf::Vector2f(textX * m_blockSize.x, (textY+1) * m_blockSize.y);
		}
	}
	return true;
}

void World::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	//on applique la transformation, laquelle ?
	states.transform *= getTransform();

	//on applique la texture
	states.texture = &m_textureMap;

	//on dessine le tableau de vertex
	target.draw(m_vertices, states);
}