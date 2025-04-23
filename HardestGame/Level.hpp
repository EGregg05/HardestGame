#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Sprite.hpp"
#include <iostream>
 
bool checkWallCollision(Sprite* player, const std::vector<sf::RectangleShape*>& walls, sf::Vector2f offset);

bool levelOne(sf::RenderWindow& window, sf::Sprite& backgroundTexture, sf::Text& lvlMsg);

bool levelTwo(sf::RenderWindow& window, sf::Sprite& backgroundTexture, sf::Text& lvlMsg);

