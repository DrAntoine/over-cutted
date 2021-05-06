#pragma once
#include "Tuile.h"

class Stock : public Tuile
{
private:
	AlimentType m_typeAlimentAFournir;
	/* hérité de entite
	sf::Vector2f taille;
	sf::Vector2f Position;
	sf::Sprite mysprite;
	sf::Texture mytexture;
	herité de outil
	bool m_libre; //deposer
	TypeObjet m_type;*/

public:
	Stock(AlimentType typeAlimentAFournir);
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

