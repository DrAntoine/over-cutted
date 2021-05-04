#pragma once
#include <SFML/Graphics.hpp>
#include "Entite.h"


enum class TypeObjet { Sol, Plan_Travail, Planche_decoupe, Stock, Poubelle, Ouverture_Salle };

class Tuile : public Entite
{
public:
	TypeObjet getTypeObjet();
protected:
	bool libre; //deposer
	TypeObjet m_type;

};

