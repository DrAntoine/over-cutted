#include<iostream>
#include<vector>

#ifndef sfml
#include <SFML/Graphics.hpp>
#endif // !sfml

#include "TextureManager.h"

class Entite
{
protected:
	TextureManager* m_textureManager;
	sf::Vector2f m_taille;
	sf::Vector2f m_position;
	sf::Sprite m_sprite;
public:
	Entite();
	virtual void draw(sf::RenderWindow* app);
	virtual void update();
	void setTextureManagerAddresse(TextureManager*);

};

enum class AlimentEtat { intacte, couper, cuit };
enum class DeplacableType { none, poisson, crevette, assiette };
enum class TuileType { Sol, Plan_Travail, Planche_decoupe, Stock, Poubelle, Ouverture_Salle };
