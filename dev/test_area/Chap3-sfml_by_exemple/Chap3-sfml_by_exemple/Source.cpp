#include <SFML/Graphics.hpp>
#include "Game.h"

void main(int argc, char** argv[])
{
	Game game;

	while (!game.GetWindow()->IsDone())
	{
		game.HandleInput();
		game.Update();
		game.Render();
		//sf::sleep(sf::seconds(0.2));
		game.RestartClock();
	}
	/*sf::RenderWindow window(sf::VideoMode(640, 480), "Boucing Mushroom");
	sf::Texture mushroomTexture;
	mushroomTexture.loadFromFile("textures/50px_champi.png");
	sf::Sprite mushroom(mushroomTexture);
	sf::Vector2u size = mushroomTexture.getSize();
	mushroom.setOrigin(size.x / 2, size.y / 2);
	sf::Vector2f increment(0.4f, 0.4f);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}
		if ((mushroom.getPosition().x + (size.x / 2) > window.getSize().x && increment.x > 0) || (mushroom.getPosition().x - (size.x / 2) < 0 && increment.x < 0))
		{
			increment.x = -increment.x;
		}
		if ((mushroom.getPosition().y + (size.y / 2) > window.getSize().y && increment.y > 0) || (mushroom.getPosition().y - (size.y / 2) < 0 && increment.y < 0))
		{
			increment.y = -increment.y;
		}
		mushroom.setPosition(mushroom.getPosition() + increment);

		window.clear(sf::Color(16, 16, 16, 255));
		window.draw(mushroom);
		window.display();

	}*/
}