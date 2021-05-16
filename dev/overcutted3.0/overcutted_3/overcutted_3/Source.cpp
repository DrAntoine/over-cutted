#pragma once
#include <SFML/Graphics.hpp>

#include "Game.h"

int main()
{
    std::cout << "Source" << std::endl;
    enum statut {Intro, jeu, pause};
    statut jeuStatut = statut::Intro;
    sf::Uint32 styleFenetre = sf::Style::Titlebar | sf::Style::Close;
    sf::RenderWindow window(sf::VideoMode(1100, 800), "Overcutted", styleFenetre);
    window.setFramerateLimit(60);
    sf::Clock horloge;
    sf::Time tempsEcoule;
    //===================== fonds
    sf::Texture textureFond;
    sf::Sprite spriteFond;
    bool fondActif;
    fondActif = true;
    textureFond.loadFromFile("Textures/fonds.png");
    spriteFond.setTexture(textureFond);
    //===================== pause
    sf::Texture texturepause;
    sf::Sprite spritepause;
    bool pauseActif;
    pauseActif = false;
    texturepause.loadFromFile("Textures/pause.png");
    spritepause.setTexture(texturepause);


    sf::Event event;
	Game game(&window, &event);
    

    while (window.isOpen())
    {
        tempsEcoule = horloge.restart();
        
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (jeuStatut == statut::jeu)
            {   
                if (event.type == sf::Event::EventType::KeyPressed && event.key.code == sf::Keyboard::Escape)
                {
                    jeuStatut = statut::pause;
                }
                else game.action(tempsEcoule); // appelle la fonction action du joueur
            }
            if (jeuStatut == statut::pause && event.type == sf::Event::EventType::KeyPressed)
            {
                if(event.key.code == sf::Keyboard::Space) jeuStatut = statut::jeu;
            }
            if (jeuStatut == statut::Intro && event.type == sf::Event::EventType::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Space) jeuStatut = statut::jeu;
            }

        }
        if (jeuStatut == statut::jeu) game.update(tempsEcoule);
        window.clear();
        switch (jeuStatut)
        {
        case Intro:
            window.draw(spriteFond);
            break;
        case jeu:
            game.draw();
            break;
        case pause:
            window.draw(spritepause);
            break;
        default:
            break;
        } 
        window.display();
    }
    std::cout << "Source Ok" << std::endl;
    return 0;
}