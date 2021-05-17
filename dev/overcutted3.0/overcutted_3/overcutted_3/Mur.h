#pragma once
#include"Tuile.h"


class Mur :public Tuile
{
private:
	//TextureManager* m_texture;
public:
	Mur(sf::Vector2u position, TextureManager* pointeurText);
	virtual ~Mur();
};