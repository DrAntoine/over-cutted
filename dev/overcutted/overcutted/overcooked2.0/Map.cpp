#include "Map.h"
Map::Map()
{

}


void Map::dessinMap(sf::RenderWindow* app)
{
    vecbox.clear();
    for (int y = 0; y < 16; y++)
    {
        for (int x = 0; x < 16; x++)
        {

            if (tabmap[y][x] == 1)
            {
                sf::RectangleShape box(sf::Vector2f(blocksize, blocksize));
                box.setFillColor(sf::Color::Red);
                box.setPosition(sf::Vector2f(x * blocksize, y * blocksize));
                vecbox.push_back(box);
            }
            if (tabmap[y][x] == 2)
            {
                sf::RectangleShape vide(sf::Vector2f(blocksize, blocksize));
                vide.setFillColor(sf::Color::Blue);
                vide.setPosition(sf::Vector2f(x * blocksize, y * blocksize));
                vecbox.push_back(vide);
            }

        }
    }
    for (int i = 0; i < vecbox.size(); i++)
    {
        app->draw(vecbox[i]);
    }
}

int Map::getTabMapValue(int y, int x)
{
    return this->tabmap[y][x];
}

int Map::getBlockSize()
{
    return blocksize;
}


