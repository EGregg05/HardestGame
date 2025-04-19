#include "Sprite.hpp"

class Player : public Sprite <class NODETYPE>
{
public: 
	Player()
	{
		this->coin = 0;
		this->x = 20.0f;
		this->y = 20.0f;
		this->object.setSize(sf::Vector2f(40.0f, 40.0f));
		this->object.setFillColor(sf::Color::Red);
		this->object.setPosition(sf::Vector2f(20.0f, 20.0f));
    }

   ~Player();

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
	   this->object.move(sf::Vector2f(addx, 0.0f));
   }
   void updateY(float addy)
   {
	   this->y += addy;
	   this->object.move(sf::Vector2f(0.0f, addy));
   }
   sf::RectangleShape& getSprite()
   {
	   return this->object;
   }
   virtual std::size_t getPointCount() const override
   {
	   return 4;
   }
   sf::Vector2f getPoint(std::size_t index) const override
   {
	   switch (index)
	   {
	   case 0: return sf::Vector2f(this->sprite.x, this->sprite.y); // Top Left Corner  
	   case 1: return sf::Vector2f(this->sprite.x + this->sprite.object.getSize().x, this->sprite.y);  // Top-right corner  
	   case 2: return sf::Vector2f(this->sprite.x + this->sprite.object.getSize().x, this->sprite.y + this->sprite.object.getSize().y);  // Bottom-right corner  
	   case 3: return sf::Vector2f(this->sprite.x, this->sprite.y + this->sprite.object.getSize().y);  // Bottom-left corner  
	   default: return sf::Vector2f(0.0f, 0.0f);  // Just in case, shouldn't be reached  
	   }
   }
protected: 
   sf::RectangleShape object; 
   int coin;
   float x;
   float y;
};