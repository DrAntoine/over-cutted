#pragma once
#include "Entite.h"
#include "Assiette.h"
#include "DeplacableManager.h"

enum class typeRecette {CarpacioPoisson, CarpacioCrevette, CarpacioCrevettePoisson};
enum class etatRecette { Neutre, Erreur, Temps_Reduit, Echec, Valide, disparue, apparition };

class Recette :public Entite
{
private:
    //sf::Vector2f m_taille;
    sf::Sprite m_sprite;
    TextureManager* m_texturePointeur;
    DeplacableManager* m_deplacableManager;
    int m_idRecette;
    Assiette* assietteAPresenter;
    sf::Vector2f m_position;
    etatRecette m_etatRecette;
    sf::Time erreurTime;
    sf::Time tempsDispoRecette;
    sf::Vector2u m_positionSprite;
    bool m_reussi;
    bool m_erreur;
public:
    Recette(TextureManager*, DeplacableManager* ,typeRecette, int);
    void drawRecette(sf::RenderWindow*);
    void updateRecette(sf::Time);
    bool ValidationRecette(Assiette*);
    etatRecette getEtat();
    void setEtat(etatRecette);
    void setPos(sf::Vector2f);
    sf::Vector2f getPos();
    int getid();
    bool getReussi();
    virtual ~Recette();
    bool getErreur();
};

