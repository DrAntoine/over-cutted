#pragma once
#include<iostream>
#include<vector>
#include <SFML/Graphics.hpp>
#include "TextureManager.h"

class Entite
{
protected:
	TextureManager* m_textureManager;
	sf::Vector2f m_taille;
	sf::Vector2f m_position;
	sf::Sprite m_sprite;
public:
	Entite(TextureManager*);
	virtual void draw(sf::RenderWindow* app);
	virtual void update();
};

enum class AlimentEtat { intacte, couper, cuit };
enum class DeplacableType { none, poisson, crevette, assiette };
enum class TuileType { None, Sol, Plan_Travail, Planche_decoupe, Stock, Poubelle, Ouverture_Salle, Mur };
