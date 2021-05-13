#pragma once
#include<iostream>
#include<string>
#include <SFML/Graphics.hpp>

//#include "Tuile.h"

//#include "Entite.h"

#include"PlanTravail.h"
#include "Planche.h"
#include "OuvertureSalle.h"
#include "Poubelle.h"
#include "Stock.h"
#include "Sol.h"
#include "Mur.h"

class Map
{
private:
	std::vector<Tuile*> tuiles;
    int tabmap[16][16] =
    {
        {9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
        {9,1,2,1,1,1,1,1,1,6,8,1,1,1,1,9},
        {9,1,0,0,0,0,0,0,0,0,0,0,0,0,1,9},
        {9,1,0,0,0,0,0,0,0,0,0,0,0,0,1,9},
        {9,1,0,0,0,0,0,0,0,0,0,0,0,0,1,9},
        {9,2,0,0,0,0,0,0,0,0,0,0,0,0,1,9},
        {9,1,0,0,0,0,0,0,0,0,0,0,0,0,1,9},
        {9,1,0,0,0,0,0,4,5,0,0,0,0,0,1,9},
        {9,1,0,0,0,0,0,6,6,0,0,0,0,0,2,9},
        {9,1,0,0,0,0,0,0,0,0,0,0,0,0,3,9},
        {9,1,0,0,0,0,0,0,0,0,0,0,0,0,1,9},
        {9,1,0,0,0,0,0,0,0,0,0,0,0,0,1,9},
        {9,1,0,0,0,0,0,0,0,0,0,0,0,0,1,9},
        {9,1,0,0,0,0,0,0,0,0,0,0,0,0,1,9},
        {9,1,1,1,1,1,2,1,1,1,1,1,1,1,1,9},
        {9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
    }; 
    sf::RenderWindow* m_ptrApp;
    TextureManager* m_texturePointeur;
    std::vector<Deplacable*>* m_element;
public:
    //Map();
    Map(sf::RenderWindow*, TextureManager*, std::vector<Deplacable*>*);
    ~Map();
    std::vector<Tuile*> getMapTile();
	void initmap();
    void drawmap();
    int getTabMapValue(int y, int x);
};

