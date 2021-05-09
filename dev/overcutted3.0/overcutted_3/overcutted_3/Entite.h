#include<iostream>
#include<vector>

#include<SFML/Graphics.hpp>

#include "TextureManager.h"

enum class AlimentEtat { intacte, couper, cuit };
enum class DeplacableType { none, poisson, crevette, assiette };
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
	Entite();
	virtual void draw(sf::RenderWindow* app);
	void update();
	void setTextureManagerAddresse(TextureManager*);

};



