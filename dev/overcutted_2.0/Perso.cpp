#include "Perso.h"
Perso::Perso()
{

}
Perso::Perso(const std::string filepath) {

	myTexture.loadFromFile(filepath);
	mySprite.setTexture(myTexture);
	this->setSprite(1, Down);
	//sf::Vector2f previous(px, py);
	mySprite.setPosition(px, py);

};

sf::Sprite Perso::setSprite(int x, int y)
{
	this->mySprite.setTextureRect(sf::IntRect(x * 50, y * 50, 50, 50));
	return this->mySprite;
}
sf::Sprite Perso::GetSprite()
{
	return this->mySprite;
}

sf::Texture Perso::GetTexture()
{
	return myTexture;
}

void Perso::move()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		animation();
		anim.y = Right;
		previous.x = mySprite.getPosition().x;
		px += speed;
		//previous.x = mySprite.getPosition().x;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		animation();
		anim.y = Left;
		previous.x = mySprite.getPosition().x;
		px -= speed;
		//previous.x = mySprite.getPosition().x;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		animation();
		anim.y = Up;
		previous.y = mySprite.getPosition().y;
		py -= speed;
		//previous.y = mySprite.getPosition().y;

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		animation();
		anim.y = Down;
		previous.y = mySprite.getPosition().y;
		py += speed;
		//previous.y = mySprite.getPosition().y;

	}
	/*if (sf::Joystick::hasAxis(0,sf::Joystick::X))
	{

		px += sf::Joystick::getAxisPosition(0, sf::Joystick::X)/20;
		py += sf::Joystick::getAxisPosition(0, sf::Joystick::Y)/20;
		previous.y = mySprite.getPosition().y;
		previous.x = mySprite.getPosition().x;
		if (sf::Joystick::getAxisPosition(0, sf::Joystick::Y) < -25
			|| sf::Joystick::getAxisPosition(0, sf::Joystick::Y) > 25
			|| sf::Joystick::getAxisPosition(0, sf::Joystick::X) < -25
			|| sf::Joystick::getAxisPosition(0, sf::Joystick::X) > 25)
		{
			animation();
		}

		if (sf::Joystick::getAxisPosition(0, sf::Joystick::Y) < -25)
		{
			anim.y = Up;

		}
		if (sf::Joystick::getAxisPosition(0, sf::Joystick::Y) > 25)
		{
			anim.y = Down;

		}
		if (sf::Joystick::getAxisPosition(0, sf::Joystick::X) < -25)
		{
			anim.y = Left;

		}
		if (sf::Joystick::getAxisPosition(0, sf::Joystick::X) > 25)
		{
			anim.y = Right;

		}

	}*/

	collision();

}

void Perso::animation()
{
	anim.x++;
	if (anim.x * 50 >= GetTexture().getSize().x)
	{
		anim.x = 0;
	}
	setSprite(anim.x, anim.y);
}

void Perso::collision()
{
	for (int y = 0; y < 16; y++)
	{
		for (int x = 0; x < 16; x++)
		{

			/*sf::RectangleShape vide(sf::Vector2f(map.getBlockSize(),map.getBlockSize()));
			vide.setPosition(sf::Vector2f(x * map.getBlockSize(), y * map.getBlockSize()));
			if (map.getTabMapValue(y, x) != 0 && mySprite.getGlobalBounds( ).intersects(vide.getGlobalBounds( )))
			{
				px = previous.x;
				py = previous.y;
				std::cout << "collision" << std::endl;
			}*/

			int top = y * map.getBlockSize();
			int bottom = (y * map.getBlockSize()) + map.getBlockSize();
			int left = x * map.getBlockSize();
			int right = (x * map.getBlockSize()) + map.getBlockSize();
			if (map.getTabMapValue(y, x) != 0 && px + map.getBlockSize() >= left
				&& px <= right
				&& py + map.getBlockSize() >= top
				&& py <= bottom)
			{

				px = previous.x;
				py = previous.y;
			}


		}
	}
	mySprite.setPosition(sf::Vector2f(px, py));


}




