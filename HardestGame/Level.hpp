#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Sprite.hpp"
#include <iostream>
 
bool levelOne(sf::RenderWindow& window, sf::Sprite& backgroundTexture, sf::Text& lvlMsg);

bool levelTwo(sf::RenderWindow& window, sf::Sprite& backgroundTexture, sf::Text& lvlMsg);


// make part of Sprite class
bool collisionWall(sf::RectangleShape& wall, Sprite* player);

bool collisionEnemy(sf::CircleShape& enemy, Sprite* player);