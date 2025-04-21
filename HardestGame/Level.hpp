#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Sprite.hpp"
#include <iostream>
 
bool levelOne(sf::RenderWindow& window,Sprite* player, sf::Sprite& backgroundTexture, sf::Text& lvlMsg);


bool levelTwo(sf::RenderWindow& window, sf::Sprite& backgroundTexture, sf::Text& lvlMsg);

bool collisionWall(sf::RectangleShape& wall, Sprite* player);

bool collisionEnemy(sf::CircleShape& enemy, Sprite* player);