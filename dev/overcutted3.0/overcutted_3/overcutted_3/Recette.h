#pragma once
#include "Entite.h"
#include "Assiette.h"

class Recette :public Entite
{
private:
    sf::Vector2f m_taille;
   // sf::Vector2f m_position;
    sf::Sprite m_sprite;
    //std::vector<>recette;
    int choix;
    std::vector<Recette*>m_Recettes;
    TextureManager* m_texturePointeur;
    sf::RenderWindow* m_ptrwindow;
    sf::Vector2u m_positiontest;


public:

    Recette(TextureManager*, sf::Vector2u);
    void typeRecette();
    void CreationRecettes();
    void drawRecette(sf::RenderWindow*);
    void ValidationRecette(Assiette*);

	virtual ~Recette();

};

