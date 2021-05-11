#pragma once
#include <SFML/Graphics.hpp>

#include "Game.h"

int main()
{
    std::cout << "Source" << std::endl;
    sf::RenderWindow window(sf::VideoMode(900, 900), "SFML works!");
    sf::Clock horloge;
    sf::Time tempsEcoule;


	Game game(&window);
    

    while (window.isOpen())
    {
	   
        tempsEcoule = horloge.restart();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
         //game.action(event); // appelle la fonction action du joueur
         //game.update(tempsEcoule);
        }

        window.clear();
		game.draw();
        window.display();
    }
    std::cout << "Source Ok" << std::endl;
    return 0;
}