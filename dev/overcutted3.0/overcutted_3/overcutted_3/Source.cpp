#pragma once
#include <SFML/Graphics.hpp>

#include "Game.h"

int main()
{
    std::cout << "Source" << std::endl;
    sf::Uint32 styleFenetre = sf::Style::Titlebar | sf::Style::Close;
    sf::RenderWindow window(sf::VideoMode(1100, 800), "Overcutted - The game that is not over yet because we are Overcutted ;)", styleFenetre);
    window.setFramerateLimit(60);
    sf::Clock horloge;
    sf::Time tempsEcoule;

    sf::Event event;
	Game game(&window, &event);
    

    while (window.isOpen())
    {
        //sf::Event event;

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