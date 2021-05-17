#pragma once
#include <SFML/Graphics.hpp>


struct SnakeSegment
{
	SnakeSegment(int x, int y) : position(x, y) {}
	sf::Vector2i position;
};

using SnakeContainer = std::vector<SnakeSegment>;

enum class Direction { None, Up, Down, Right, Left };

class Snake
{
public:
	Snake(int l_blockSize);
	~Snake();

	//Helper methods.
	void SetDirection(Direction l_dir);
	Direction GetDirection();
	int GetSpeed();
	sf::Vector2i GetPosition();
	int GetLives();
	int GetScore();
	void IncreaseScore();
	bool HasLost();

	void Lose();
	void ToggleLost();

	void Extend();
	void Reset();

	void Move();
	void Tick(); //update method
	void Cut(int l_segments); // Method for cutting snake
	void Render(sf::RenderWindow& l_window);
private:
	void CheckCollision();

	SnakeContainer m_snakeBody; //Segment vector
	int m_size; //size of the graphics
	Direction m_dir; // Current direction
	int m_speed; // Speed of the snake
	int m_lives; // Lives
	int m_score; // Score
	bool m_lost;
	sf::RectangleShape m_bodyRect; // Shape used in rendering
};
