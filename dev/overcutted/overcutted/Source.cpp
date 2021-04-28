#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.h"

int main()
{
	Game game;
	const int level[] =
	{
		0,1,1,2,2,2,1,1,3,4,4,1,0,
		0,5,5,5,5,5,5,5,5,5,5,5,0,
		0,5,5,5,5,5,5,5,5,5,5,5,0,
		0,5,5,5,5,6,1,6,5,5,5,5,0,
		0,5,5,5,5,5,5,5,5,5,5,5,0,
		0,5,5,5,5,5,5,5,5,5,5,5,0,
		0,5,5,5,5,5,5,5,5,5,5,5,0,
		0,1,1,1,1,7,1,1,1,1,1,1,0,
	};

	if (game.LoadMap(level))
	{
		while (!game.GetWindow()->IsDone())
		{
			//game.HandleInput();
			game.Update();
			game.Render();
			game.RestartClock();
		}
	}
	return 0;
}