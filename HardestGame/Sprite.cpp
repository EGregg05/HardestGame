#include "Sprite.hpp"

Sprite::Sprite()
{
	this->coin = 0;
	this->x = 20.0f;
	this->y = 20.0f;
	this->object.setSize(sf::Vector2f(40.0f, 40.0f));
	this->object.setFillColor(sf::Color::Red);
	this->object.setPosition(sf::Vector2f(20.0f, 20.0f));
}

Sprite::~Sprite()
{
}

bool Sprite::isCWall(sf::RectangleShape& wall)
{
    return false;
}

bool Sprite::isCEnemy(sf::CircleShape& wall)
{
    return false;
}

float Sprite::getX()
{
	return this->x;
}

float Sprite::getY()
{
	return this->y;
}

void Sprite::updateX(float addx)
{
	this->x += addx;
	this->object.move(sf::Vector2f(addx, 0.0f));
}

void Sprite::updateY(float addy)
{
	this->y += addy;
	this->object.move(sf::Vector2f(0.0f, addy));
}

sf::RectangleShape& Sprite::getSprite()
{
	return this->object;
}

std::size_t Sprite::getPointCount() const
{
	return 4;
}

sf::Vector2f Sprite::getPoint(std::size_t index) const
{
	switch (index)
	{
	case 0: return sf::Vector2f(this->x, this->y); // Top Left Corner
	case 1: return sf::Vector2f(this->x + this->object.getSize().x, this->y);  // Top-right corner
	case 2: return sf::Vector2f(this->x + this->object.getSize().x, this->y + this->object.getSize().y);  // Bottom-right corner
	case 3: return sf::Vector2f(this->x, this->y + this->object.getSize().y);  // Bottom-left corner
	default: return sf::Vector2f(0.0f, 0.0f);  // Just in case, shouldn't be reached
	}
}