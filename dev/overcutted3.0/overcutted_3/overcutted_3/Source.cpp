#pragma once
#include <SFML/Graphics.hpp>

#include "Game.h"

int main()
{
    std::cout << "Source" << std::endl;
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
        //sf::Event event;
        while (fondActif == true)
        {
            window.clear();
            window.draw(spriteFond);
            window.display();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            {
                fondActif = false;
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            pauseActif = true;
        }

        while (pauseActif == true)
        {
            window.clear();
            window.draw(spritepause);
            window.display();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            {
                pauseActif = false;
            }
        }

        tempsEcoule = horloge.restart();
        
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            game.action(tempsEcoule); // appelle la fonction action du joueur
         
        }
        game.update(tempsEcoule);
        window.clear();
		game.draw();
        window.display();
    }
    std::cout << "Source Ok" << std::endl;
    return 0;
}