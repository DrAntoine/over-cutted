#pragma once
#include<SFML/Graphics.hpp>
class Minuteur
{
private:
    int minutes, secondesUnite,secondesDizaine;
    sf::Clock tempsJeu;
    sf::Time duree;
    sf::Font font;
    sf::Text text;
    sf::Text text1;
    sf::Text text2;
    sf::Text text3;
    sf::RenderWindow* m_ptrFenetre;

public:
    Minuteur();
    void decompte();
    void drawMinuteur(sf::RenderWindow*);
    int finDuJeu();
};

