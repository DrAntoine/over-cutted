#pragma once
#include <SFML/Graphics.hpp>

#include "Game.h"

int main()
{
    std::cout << "Source" << std::endl;
    sf::RenderWindow window(sf::VideoMode(1100, 800), "SFML works!");
    window.setFramerateLimit(60);
    sf::Clock horloge;
    sf::Time tempsEcoule;

    sf::Event event;
	Game game(&window, &event);
    

    while (window.isOpen())
    {
	   
        tempsEcoule = horloge.restart();
        
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            game.action(tempsEcoule, event); // appelle la fonction action du joueur
         
        }
       // game.update(tempsEcoule);
        window.clear();
		game.draw();
        window.display();
    }
    std::cout << "Source Ok" << std::endl;
    return 0;
}