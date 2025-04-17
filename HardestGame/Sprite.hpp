#pragma once
#include <SFML/Graphics.hpp>

class Sprite : sf::Shape
{
public:
	Sprite()
	{
		this->coin = 0;
		this->x = 0.0f;
		this->y = 0.0f;
		this->object.setSize(sf::Vector2f(40.0, 40.0));
		this->object.setFillColor(sf::Color::Red);
		this->object.setPosition(sf::Vector2f(0.0, 0.0));
	}

	~Sprite()
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
		this->x += addx; 
		this->object.move(sf::Vector2f(addx, 0.0));
	}

	void updateY(float addy)
	{
		this->y += addy; 
		this->object.move(sf::Vector2f(0.0, addy));
	}

	sf::RectangleShape& getSprite()
	{
		return this->object;
	}

	virtual std::size_t getPointCount() const override
	{
		return 4;
	}

	virtual sf::Vector2f getPoint(std::size_t index) const override
	{
		switch (index)
		{
		case 0: return sf::Vector2f(this->x, this->y); // Top Left Corner
		case 1: return sf::Vector2f(this->x + this->object.getSize().x, this->y);  // Top-right corner
		case 2: return sf::Vector2f(this->x + this->object.getSize().x, this->y + this->object.getSize().y);  // Bottom-right corner
		case 3: return sf::Vector2f(this->x, this->y + this->object.getSize().y);  // Bottom-left corner
		default: return sf::Vector2f(0, 0);  // Just in case, shouldn't be reached
		}
	}

private:
	int coin;
	float x;
	float y; 
	sf::RectangleShape object;
};