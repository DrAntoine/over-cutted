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
    int tabmap[16][16] =
    {
        {8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8},
        {8,1,2,1,1,1,1,1,1,6,7,1,1,1,1,8},
        {8,1,0,0,0,0,0,0,0,0,0,0,0,0,1,8},
        {8,1,0,0,0,0,0,0,0,0,0,0,0,0,1,8},
        {8,1,0,0,0,0,0,0,0,0,0,0,0,0,1,8},
        {8,2,0,0,0,0,0,0,0,0,0,0,0,0,1,8},
        {8,1,0,0,0,0,0,0,0,0,0,0,0,0,1,8},
        {8,1,0,0,0,0,0,4,5,0,0,0,0,0,1,8},
        {8,1,0,0,0,0,0,6,6,0,0,0,0,0,2,8},
        {8,1,0,0,0,0,0,0,0,0,0,0,0,0,3,8},
        {8,1,0,0,0,0,0,0,0,0,0,0,0,0,1,8},
        {8,1,0,0,0,0,0,0,0,0,0,0,0,0,1,8},
        {8,1,0,0,0,0,0,0,0,0,0,0,0,0,1,8},
        {8,1,0,0,0,0,0,0,0,0,0,0,0,0,1,8},
        {8,1,1,1,1,1,2,1,1,1,1,1,1,1,1,8},
        {8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8},
    };
    sf::RenderWindow* m_ptrApp;
    TextureManager* m_texturePointeur;
    std::vector<Tuile*> tuiles;
    std::vector<Deplacable*>* m_element;
    std::vector<Poubelle*> m_poubelles;
    std::vector<Stock*> m_stocks;
    std::vector<Planche*> m_planches;
    std::vector<OuvertureSalle*> m_ouvertureSalle;
public:
    //Map();
    Map(sf::RenderWindow*, TextureManager*, std::vector<Deplacable*>*);
    ~Map();
	void initmap();
    void drawmap();
    int getTabMapValue(int y, int x);
    std::vector<Tuile*> getMapTile();
    Stock* getStock(sf::Vector2u);
    Poubelle* getPoubelle(sf::Vector2u);
    Planche* getPlanche(sf::Vector2u);
    OuvertureSalle* getOuvertureSalle(sf::Vector2u);
};

