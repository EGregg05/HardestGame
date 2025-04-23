#include "Sprite.hpp"

Sprite::Sprite()
{
	this->coin = 0;
	this->x = 20.0f;
	this->y = 20.0f;
	this->object.setSize(sf::Vector2f(40.0f, 40.0f));
	this->object.setFillColor(sf::Color::Red);
	this->object.setPosition(sf::Vector2f(30.0f, 280.0f));
}

Sprite::~Sprite()
{
}

// bounding box collision detection (1 means overlap in x dir, 2 mean overlap in y dir, 0 means no overlap))
bool Sprite::isCWall(sf::RectangleShape& wall, sf::Vector2f offset)
{
	sf::Vector2f newPos = this->object.getPosition() + offset;
	sf::Vector2f size = this->object.getSize();
	sf::Vector2f wallPos = wall.getPosition();
	sf::Vector2f wallSize = wall.getSize();

	bool overlapX = (newPos.x < wallPos.x + wallSize.x) && (newPos.x + size.x > wallPos.x);
	bool overlapY = (newPos.y < wallPos.y + wallSize.y) && (newPos.y + size.y > wallPos.y);

	return overlapX && overlapY;
}

bool Sprite::isCEnemy(sf::CircleShape& circle, sf::Vector2f offset)
{
	sf::Vector2f rectPos = this->object.getPosition() + offset;
	sf::Vector2f rectSize = this->object.getSize();

	float radius = circle.getRadius();
	sf::Vector2f circlePos = circle.getPosition();
	sf::Vector2f circleCenter(circlePos.x + radius, circlePos.y + radius);

	// Find the closest point on the rectangle to the circle center
	float closestX = std::clamp(circleCenter.x, rectPos.x, rectPos.x + rectSize.x);
	float closestY = std::clamp(circleCenter.y, rectPos.y, rectPos.y + rectSize.y);

	// Distance from circle center to closest point
	float dx = circleCenter.x - closestX;
	float dy = circleCenter.y - closestY;

	// If distance is less than the radius, there's a collision
	return (dx * dx + dy * dy) < (radius * radius);
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

void Sprite::setX(float nx)
{
	this->x = nx;
}

void Sprite::setY(float ny)
{
	this->y = ny;
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