#ifndef sfml
#include <SFML/Graphics.hpp>
#endif // !sfml

#include "Game.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    sf::Clock horloge;
    sf::Time tempsEcoule;

	Game game;
    

    while (window.isOpen())
    {
	   
        tempsEcoule = horloge.restart();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
         game.action(event); // appelle la fonction action du joueur
         game.update(tempsEcoule);
        }

        window.clear();
		game.draw(&window);
        window.display();
    }

    return 0;
}