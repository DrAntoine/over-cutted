#include <SFML/Graphics.hpp>
#include<iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    int minutes, secondes;
    sf::Clock tempsJeu;
    minutes = 5;
    secondes = 0;
    sf::Time duree;
    sf::Font font;
    font.loadFromFile("font/Bebas-Regular.ttf");
    sf::Text text;
    text.setFont(font);
    sf::Text text1;
    text1.setFont(font);
    text1.setString(" : ");
    sf::Text text2;
    text2.setFont(font);
    std::string seconde;
    std::string minute;
    text2.setPosition(sf::Vector2f(25,0));
    text1.setPosition(sf::Vector2f(10,0));
    //text.setString("Hello world");



    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        duree= tempsJeu.getElapsedTime();
        if (duree.asSeconds() >= 1)
        {
            secondes -= 1;
            if (secondes < 0)
            {
                minutes -= 1;
                secondes = 59;
            }
            tempsJeu.restart();
        }


        text.setString(std::to_string(minutes));
        text2.setString(std::to_string(secondes));
        std::cout << minutes << ":" << secondes << std::endl;

        window.clear();
        window.draw(text);
        window.draw(text1);
        window.draw(text2);
        window.display();
    }

    return 0;
}