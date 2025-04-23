#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Sprite : sf::Shape
{
public:
	Sprite();

	~Sprite();

	bool isCWall(sf::RectangleShape& wall, sf::Vector2f offset);

	bool isCEnemy(sf::CircleShape& wall, sf::Vector2f offset);

	float getX();

	float getY();

	void updateX(float addx);

	void updateY(float addy);

	void setX(float nx);

	void setY(float ny);

	sf::RectangleShape& getSprite();

	virtual std::size_t getPointCount() const override;

	virtual sf::Vector2f getPoint(std::size_t index) const override;

private:
	int coin;
	float x;
	float y; 
	sf::RectangleShape object;
};