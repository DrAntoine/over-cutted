#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string.h>
#include"Map.h"

class Perso
{
public:
	Perso();
	Perso(const std::string filepath);
	sf::Sprite setSprite(int x, int y);
	sf::Sprite GetSprite();

	void move();
	void animation();
	sf::Texture GetTexture();
	void collision();

private:
	enum Dir { Down, Left, Right, Up };
	sf::Texture myTexture;
	sf::Sprite mySprite;
	sf::Vector2i anim;




	float speed = 5, px = 300, py = 200;
	sf::Vector2f previous = sf::Vector2f(px, py);
	Map map;
};



