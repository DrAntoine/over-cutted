#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "Game.h"


int main()
{
    std::cout << "Source" << std::endl;
    enum class GameStatut { Intro, jeu, pause, fin };
    GameStatut jeuGameStatut = GameStatut::Intro;
    sf::Uint32 styleFenetre = sf::Style::Titlebar | sf::Style::Close;
    sf::RenderWindow window(sf::VideoMode(1100, 810), "Overcutted", styleFenetre);
    window.setFramerateLimit(60);
    sf::Clock horloge;
    sf::Time tempsEcoule;
    //===================== fonds
    sf::Texture textureFond;
    sf::Sprite spriteFond;
    textureFond.loadFromFile("Textures/fonds.png");
    spriteFond.setTexture(textureFond);
    //===================== pause
    sf::Texture texturepause;
    sf::Sprite spritepause;
    texturepause.loadFromFile("Textures/pause.png");
    spritepause.setTexture(texturepause);
    //===================== fin
    sf::Texture texturefin;
    sf::Sprite spritefin;
    texturefin.loadFromFile("Textures/fin.png");
    spritefin.setTexture(texturefin);
    std::string texte = "Score : ";
    sf::Text textfin;
    bool textDefini = false;

    int dureePartie = 1 * 30;
    sf::Time tempsRestant = sf::seconds(dureePartie);
    sf::RectangleShape timerRectangle;
    timerRectangle.setFillColor(sf::Color::Green);
    timerRectangle.setSize(sf::Vector2f(10, 1100));
    timerRectangle.setPosition(sf::Vector2f(0, 800));
    sf::Event event;
    sf::Font police;
    int score = 0;
	Game game(&window, &event, &score);

    while (window.isOpen())
    {
        tempsEcoule = horloge.restart();
        
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || jeuGameStatut == GameStatut::fin && event.type == sf::Event::EventType::KeyPressed && event.key.code == sf::Keyboard::Space)
                window.close();
            if (jeuGameStatut == GameStatut::jeu)
            {   
                if (event.type == sf::Event::EventType::KeyPressed && event.key.code == sf::Keyboard::Escape)
                {
                    jeuGameStatut = GameStatut::pause;
                }
                else game.action(tempsEcoule); // appelle la fonction action du joueur
            }
            if (jeuGameStatut == GameStatut::pause && event.type == sf::Event::EventType::KeyPressed)
            {
                if(event.key.code == sf::Keyboard::Space) jeuGameStatut = GameStatut::jeu;
            }
            if (jeuGameStatut == GameStatut::Intro && event.type == sf::Event::EventType::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Space) jeuGameStatut = GameStatut::jeu;
            }

        }
        if (jeuGameStatut == GameStatut::jeu) game.update(tempsEcoule);
        window.clear();
        switch (jeuGameStatut)
        {
        case GameStatut::Intro:
            window.draw(spriteFond);
            break;
        case GameStatut::jeu:
            tempsRestant -= tempsEcoule;
            if (tempsRestant.asSeconds() > sf::seconds(0).asSeconds())
            {
                float largeurTimer = 1100 * (tempsRestant.asSeconds() / sf::seconds(dureePartie).asSeconds());
                if (tempsRestant.asSeconds() < sf::seconds(30).asSeconds() && timerRectangle.getFillColor() == sf::Color::Green) timerRectangle.setFillColor(sf::Color::Yellow);
                if (tempsRestant.asSeconds() < sf::seconds(10).asSeconds() && timerRectangle.getFillColor() == sf::Color::Yellow) timerRectangle.setFillColor(sf::Color::Red);
                timerRectangle.setSize(sf::Vector2f(largeurTimer, 10));
                window.draw(timerRectangle);
                game.draw();
            }
            else
            {
                jeuGameStatut = GameStatut::fin;
            }
            break;
        case GameStatut::pause:
            window.draw(spritepause);
            break;
        case GameStatut::fin:
            window.draw(spritefin);
            if (!textDefini)
            {
                texte += std::to_string(score);
                textDefini = true;
            }
            textfin.setString(texte);
            textfin.setCharacterSize(24);
            textfin.setFillColor(sf::Color::Black);
            //textfin.setStyle(sf::Text::Bold);
            police.loadFromFile("Calibri Regular.ttf");
            textfin.setFont(police);
            textfin.setPosition(sf::Vector2f(500, 200));
            window.draw(textfin);
            break;
        default:
            break;
        } 
        window.display();
    }
    std::cout << "Source Ok" << std::endl;
    return 0;
}