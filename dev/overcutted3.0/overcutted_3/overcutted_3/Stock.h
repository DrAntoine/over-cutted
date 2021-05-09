#pragma once
#include "Tuile.h"
#include "Aliments.h"

class Stock : public Tuile
{
private:
	DeplacableType m_typeAlimentAFournir;
	/* hérité de entite
	sf::Vector2f taille;
	sf::Vector2f Position;
	sf::Sprite mysprite;
	sf::Texture mytexture;
	herité de outil
	bool m_libre; //deposer
	TypeObjet m_type;*/
	DeplacableType m_ressourceAFournir;

public:
	Stock(sf::Vector2u position, DeplacableType typeAlimentAFournir);
	Aliment* CreerNouvelAliment();
	/*Stock(int quoi) { type_aliment = quoi; }

	*Aliment void destocker()
	{
		Aliment* a;
		if(type_aliment==0) a=new Poisson()
		if (type_aliment == 1) a = new Crevette()
		
			Aliment->setPosition....

			Return a;
	}*/

};

