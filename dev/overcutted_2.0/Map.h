#pragma once


#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string.h>
#include<vector>
#include <array>

class Map
{
public:
    Map();
    void dessinMap(sf::RenderWindow* app);

    int getTabMapValue(int y, int x);

    int getBlockSize();
private:
    int tabmap[16][16] =
    {
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,0},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
        {2,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
        {1,1,1,1,1,1,2,1,1,1,1,1,1,1,1,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    };
    int blocksize = 50;
    std::vector< sf::RectangleShape > vecbox;
};