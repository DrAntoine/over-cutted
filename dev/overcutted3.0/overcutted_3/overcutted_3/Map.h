#pragma once
#include<iostream>
//#include<string>
//#ifndef sfml
//#include <SFML/Graphics.hpp>
//#endif // !sfml

//#include "Tuile.h"

//#ifndef entite
//#include "Entite.h"
//#endif // !entite

/*#include"PlanTravail.h"
#include "Planche.h"
#include "OuvertureSalle.h"
#include "Poubelle.h"
#include "Stock.h"
#include"Sol.h"*/

/**/

class Map
{
private:
	std::vector<Tuile*> tuiles;
    int tabmap[16][16] =
    {
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,0},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
        {2,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
        {1,1,1,1,1,1,2,1,1,1,1,1,1,1,1,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    };
public:
	
	//sf::Vector2i ou_suis_je(sf::Vector2f Position); // réponse tuile 0,4
    Map();
	void drawmap();


};

