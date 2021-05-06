#include <SFML/Graphics.hpp>
#include "Game.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

	Game game;
    

    while (window.isOpen())
    {
		clock();

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
			game.move(event); //appelle la fonction move(event) du joueur


			if (SPACE) game.action(); // appelle la fonction action du joueur
        }

        window.clear();
		game.draw(&window);
        window.display();
    }

    return 0;
}