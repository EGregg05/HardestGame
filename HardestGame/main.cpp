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
#include "Level.hpp"
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
    sf::Text text(font)/*worlds hardest game*/, text2(font)/*Play*/, text3(font)/*Rules*/
        , text4(font)/*Exit*/, text5(font)/*Rule 1*/, text6(font)/*Rule 2*/, text7(font) /*Back*/, text8(font); //different texts

    //define the texts (we may want to add a text class later)
    text.setString("Worlds Hardest Game");
    text.setCharacterSize(70); // in pixels
    text.setFillColor(sf::Color::Red);
    text.setPosition(sf::Vector2f(75, 50));
    text.setStyle(sf::Text::Bold | sf::Text::Underlined);
    text2.setString("Play");
    text2.setCharacterSize(50); // in pixels
    text2.setFillColor(sf::Color::Red);
    text2.setPosition(sf::Vector2f(340, 180));
    text8.setString("Select Level");
    text8.setCharacterSize(50);
    text8.setFillColor(sf::Color::Red);
    text8.setPosition(sf::Vector2f(340, 210));
    text3.setString("Rules");
    text3.setCharacterSize(50); // in pixels
    text3.setFillColor(sf::Color::Red);
    text3.setPosition(sf::Vector2f(340, 300));
    text4.setString("Exit");
    text4.setCharacterSize(50); // in pixels
    text4.setFillColor(sf::Color::Red); //text color
    text4.setPosition(sf::Vector2f(340, 420)); // text position
    
    sf::Text LvlOneMsg(font); // create a text with the font
    LvlOneMsg.setString("Level 1");// the text
    LvlOneMsg.setCharacterSize(80); // text size in pixels
    LvlOneMsg.setFillColor(sf::Color::White); // Text color
    LvlOneMsg.setPosition(sf::Vector2f(280.f, 220.f)); // location for the text

    sf::Text LvlTwoMsg(font);
    LvlTwoMsg.setString("Level 2");
    LvlTwoMsg.setCharacterSize(80);
    LvlTwoMsg.setFillColor(sf::Color::White);
    LvlTwoMsg.setPosition(sf::Vector2f(280.f, 220.f));

    //declare all the bools to allow us to click on the words
    bool play = false, rules = false, exit = false, back = false, backbounds = false;

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }

            if (const auto* mouseMoved = event->getIf<sf::Event::MouseMoved>())
            {
                // use this code if you ever need to check the x and y values of the mouse position
                /*std::cout << "new mouse x: " << mouseMoved->position.x << std::endl;
                std::cout << "new mouse y: " << mouseMoved->position.y << std::endl;*/
                if (180 < mouseMoved->position.y && mouseMoved->position.y < 230 && 340 < mouseMoved->position.x && mouseMoved->position.x < 430)
                {
                    //highlight play if hovering over it
                    text2.setFillColor(sf::Color::Green);
                    text2.setCharacterSize(55);

                    // allows us to click play
                    play = true;
                    
                }
                else if (300 < mouseMoved->position.y && mouseMoved->position.y < 350 && 340 < mouseMoved->position.x && mouseMoved->position.x < 455)
                {
                    //highlight rules if hovering over it
                    text3.setFillColor(sf::Color::Green);
                    text3.setCharacterSize(55);

                    // allows us to click rules
                    rules = true;
                }
                else if (420 < mouseMoved->position.y && mouseMoved->position.y < 470 && 340 < mouseMoved->position.x && mouseMoved->position.x < 470)
                {
                    //highlight exit if hovering over it
                    text4.setFillColor(sf::Color::Green);
                    text4.setCharacterSize(55);

                    // allows us to click exit
                    exit = true;
                }
                else
                {
                    // reset play, rules, and exit text
                    text2.setCharacterSize(50); // in pixels
                    text2.setFillColor(sf::Color::Red);
                    text3.setCharacterSize(50); // in pixels
                    text3.setFillColor(sf::Color::Red);
                    text4.setCharacterSize(50); // in pixels
                    text4.setFillColor(sf::Color::Red);
                    play = false;
                    rules = false;
                    exit = false;
                }
            }

            // Play Loop
            if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && play) // we may need to implement a "pause" or a back button to the gameplay later
            {
                sf::Clock clock;
                float displaytime = 2.0f; // time for prelevel text duration
                int levelTracker = 1;
                bool levelCheck;
                bool playLevel = true;

                while (window.isOpen() && playLevel)
                {
                   
                    switch (levelTracker)
                    {
                    case 1:
                        levelCheck = levelOne(window, gameBackground, LvlOneMsg);
                        if (levelCheck)
                        {
                            levelTracker++;
                            clock.restart();
                        }
                        else
                        {
                            playLevel = false;
                        }
                        break;
                    case 2:
                        levelCheck = levelTwo(window, gameBackground, LvlTwoMsg);
                        if (levelCheck)
                        {
                            levelTracker++;
                            clock.restart();
                        }
                        else
                        {
                            playLevel = false;
                        }
                        // call levelTwo() here
                        break;
                  
                        // etc.
                    }
                }
            }
            
            // Rules loop
            if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && rules) //access the rules tab
            {
                // setting the texts for the rules
                text3.setCharacterSize(60);
                text3.setPosition(sf::Vector2f(350, 50));
                text3.setFillColor(sf::Color::Red);
                text5.setString("Rule 1: DONT TOUCH THE BLUE BALLS.");
                text5.setCharacterSize(40); // in pixels
                text5.setFillColor(sf::Color::Red); //text color
                text5.setPosition(sf::Vector2f(100, 200)); // text position
                text6.setString("Rule 2: Pass the level by making it\n            to the green section.");
                text6.setCharacterSize(40); // in pixels
                text6.setFillColor(sf::Color::Red); //text color
                text6.setPosition(sf::Vector2f(100, 300)); // text position
                text7.setString("Back");
                text7.setCharacterSize(30); // in pixels
                text7.setFillColor(sf::Color::Red); //text color
                text7.setPosition(sf::Vector2f(50, 50)); // text position

                // make sure back is always false once entering the rules again
                back = false;

                while (back == false) // exit rules when back is true
                {
                    while (const std::optional event = window.pollEvent())
                    {
                        if (event->is<sf::Event::Closed>())
                            window.close();
                        if (const auto* mouseMoved = event->getIf<sf::Event::MouseMoved>())
                        {
                            //use for mouse coordinates
                            /*std::cout << "new mouse x: " << mouseMoved->position.x << std::endl;
                            std::cout << "new mouse y: " << mouseMoved->position.y << std::endl;*/
                            if (45 < mouseMoved->position.y && mouseMoved->position.y < 85 && 45 < mouseMoved->position.x && mouseMoved->position.x < 110)
                            {
                                // highlight the back button if mouse is in bounds
                                text7.setFillColor(sf::Color::Green);
                                text7.setCharacterSize(32);

                                // allow us to click back
                                backbounds = true;
                            }
                            else 
                            {
                                // reset back and backbounds if mouse is not hovering over back
                                text7.setFillColor(sf::Color::Red);
                                text7.setCharacterSize(30);
                                backbounds = false;
                            }
                            
                        }

                        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && backbounds) //exit rules
                        {
                            text3.setCharacterSize(50);
                            text3.setPosition(sf::Vector2f(340, 300));
                            text3.setFillColor(sf::Color::Red);
                            back = true;
                            backbounds = false;
                        }
                        
                    }
                   
                    window.clear();
                    window.draw(text3);
                    window.draw(text5);
                    window.draw(text6);
                    window.draw(text7);
                    window.display();
                }
            }

            //Exit 
            if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && exit) // end the program
            {
                window.close();
            }
           
        }
      
        window.clear();
        window.draw(menuBackground);
        window.draw(text);
        window.draw(text2);
        window.draw(text3);
        window.draw(text4);

        window.display();
    }
    
};
