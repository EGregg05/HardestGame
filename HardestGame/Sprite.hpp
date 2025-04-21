#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Sprite : sf::Shape
{
public:
	Sprite();

	~Sprite();

	bool isCWall(sf::RectangleShape& wall);

	bool isCEnemy(sf::CircleShape& wall);

	float getX();

	float getY();

	void updateX(float addx);

	void updateY(float addy);

	sf::RectangleShape& getSprite();

	virtual std::size_t getPointCount() const override;

	virtual sf::Vector2f getPoint(std::size_t index) const override;

private:
	int coin;
	float x;
	float y; 
	sf::RectangleShape object;
};