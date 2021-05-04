#include <SFML/Graphics.hpp>
#include"Perso.h"
#include"Map.h"
#include "Event.h"
int main()
{

    sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");
    Perso player("textures/sprite_player_1.png");
    Map carte;
    Event test;
    window.setFramerateLimit(60);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        player.move();
        test.poisson();

        window.clear(sf::Color::White);
        carte.dessinMap(&window),
            window.draw(player.GetSprite());
        window.display();
    }

    return 0;
}