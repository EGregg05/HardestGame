#include <SFML/Graphics.hpp>

class Sprite : sf::Shape
{
public:
	Sprite()
	{

	}

	float getX()
	{
		return this->x;
	}

	float getY()
	{
		return this->y;
	}

	void updateX(float addx)
	{
		this->x + addx;
	}

	void updateY(float addy)
	{
		this->y + addy;
	}



private:
	float x;
	float y; 
};