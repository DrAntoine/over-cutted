#include<SFML/Graphics.hpp>
#include<iostream>
#include<vector>

enum class AlimentEtat { intacte, couper, cuit };
enum class AlimentType { none, poisson, crevette };
enum class TuileType { Sol, Plan_Travail, Planche_decoupe, Stock, Poubelle, Ouverture_Salle };

class Entite
{
protected:
	sf::Vector2f taille;
	sf::Vector2f Position;
	sf::Sprite mysprite;
	sf::Texture mytexture;
public:
	//draw(window *w)
		//w->draw(Sprite);

};



