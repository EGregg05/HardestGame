#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stack>
#include <ctime>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Sprite.hpp"
//#include "Level.hpp"
#include "Menu.h"
using std::cout;

int main()
{
    sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "HardGame");
    Sprite* player = new Sprite;

    //Background
    sf::Texture texture;
    texture.loadFromFile("background.png");
    sf::Sprite gameBackground(texture);
    sf::Texture texture2;
    texture2.loadFromFile("MenuBackground.png");
    sf::Sprite menuBackground(texture2);

    // declare the fonts and declare the different texts
    sf::Font font;
    font.openFromFile("arial_narrow_7.ttf");

    Menu mainMenu;

    mainMenu.isMainMenu(window, gameBackground, menuBackground, font);

   
};
