#pragma once  
#include <SFML/Graphics.hpp>  
#include <SFML/Window.hpp>  
// #include <type_traits> // For std::is_default_constructible and static_assert


template <class NODETYPE>
class Sprite : public sf::Shape
{
public:
    Sprite() : sprite() {}

    ~Sprite()
    {

    }

    virtual float getX()
    {
    }

    virtual float getY()
    {
    }

    virtual void updateX(float addx)
    {
    }

    virtual void updateY(float addy)
    {
    }

    virtual sf::RectangleShape& getSprite()
    {
    }

    virtual std::size_t getPointCount() const override
    {
    }
    virtual sf::Vector2f getPoint(std::size_t index) const override
    {
    }

protected:

    NODETYPE sprite;
};