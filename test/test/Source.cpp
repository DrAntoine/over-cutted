#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(900, 900), "SFML works!");
    sf::CircleShape shape(100.f);
    sf::Texture mytexture;
    sf::Sprite mysprite;
    mytexture.loadFromFile("Textures/decors.png");
    mysprite.setTexture(mytexture);
    mysprite.setTextureRect(sf::IntRect(50,50,50,50));
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(mysprite);
        window.display();
    }

    return 0;
}