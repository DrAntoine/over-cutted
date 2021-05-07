#include<iostream>
#include<vector>

#include<SFML/Graphics.hpp>

#include "TextureManager.h"

enum class AlimentEtat { intacte, couper, cuit };
enum class AlimentType { none, poisson, crevette };
enum class TuileType { Sol, Plan_Travail, Planche_decoupe, Stock, Poubelle, Ouverture_Salle };

class Entite
{
protected:
	TextureManager* m_textureManager;
	sf::Vector2f m_taille;
	sf::Vector2f m_position;
	sf::Sprite m_sprite;
public:
	//draw(window *w)
		//w->draw(Sprite);
	void setTextureManagerAddresse(TextureManager*);
	Entite();
};



