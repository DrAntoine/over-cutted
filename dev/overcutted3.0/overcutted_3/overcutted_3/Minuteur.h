#pragma once
#include<SFML/Graphics.hpp>
class Minuteur
{
private:
    int minutes, secondes;
    sf::Clock tempsJeu;
    sf::Time duree;
    sf::Font font;
    sf::Text text;
    sf::Text text1;
    sf::Text text2;
    std::string seconde;
    std::string minute;
    sf::RenderWindow* m_ptrFenetre;

public:
    Minuteur();
    void décompte();
    void drawMinuteur(sf::RenderWindow*);
    int finDuJeu();
};

