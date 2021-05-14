#pragma once
#include"Tuile.h"


class Sol:public Tuile
{
private:
	//TextureManager m_texture;
public:
	Sol(sf::Vector2u position, TextureManager* pointeurText);
	virtual ~Sol();
};

