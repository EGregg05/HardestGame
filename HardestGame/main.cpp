#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stack>
#include <ctime>
#include <cstdlib>
#include "Sprite.hpp"
#include "Level.hpp"

using std::cout;

int main()
{
    sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "HardGam");
    Sprite<Player>* player = new Sprite<Player>;

    //Background
    sf::Texture texture;
    texture.loadFromFile("BackgroundWEnds.png");
    sf::Sprite background(texture);

    // declare the fonts and declare the different texts
    sf::Font font;
    font.openFromFile("arial_narrow_7.ttf");
    sf::Text text(font)/*worlds hardest game*/, text2(font)/*Play*/, text3(font)/*Rules*/
        , text4(font)/*Exit*/, text5(font)/*Rule 1*/, text6(font)/*Rule 2*/, text7(font) /*Back*/; //different texts

    //define the texts (we may want to add a text class later)
    text.setString("Worlds Hardest Game");
    text.setCharacterSize(60); // in pixels
    text.setFillColor(sf::Color::Red);
    text.setPosition(sf::Vector2f(130, 50));
    text.setStyle(sf::Text::Bold | sf::Text::Underlined);
    text2.setString("Play");
    text2.setCharacterSize(40); // in pixels
    text2.setFillColor(sf::Color::Red);
    text2.setPosition(sf::Vector2f(350, 175));
    text3.setString("Rules");
    text3.setCharacterSize(40); // in pixels
    text3.setFillColor(sf::Color::Red);
    text3.setPosition(sf::Vector2f(350, 275));
    text4.setString("Exit");
    text4.setCharacterSize(40); // in pixels
    text4.setFillColor(sf::Color::Red); //text color
    text4.setPosition(sf::Vector2f(350, 375)); // text position
    
    sf::Text LvlOneMsg(font); // create a text with the font
    LvlOneMsg.setString("You Dead Ass aint \nready for this shit");// the text
    LvlOneMsg.setCharacterSize(48); // text size in pixels
    LvlOneMsg.setFillColor(sf::Color::White); // Text color
    LvlOneMsg.setPosition(sf::Vector2f(200.f, 200.f)); // location for the text

    //declare all the bools to allow us to click on the words
    bool play = false, rules = false, exit = false, back = false, backbounds = false;

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
            if (const auto* mouseMoved = event->getIf<sf::Event::MouseMoved>())
            {
                // use this code if you ever need to check the x and y values of the mouse position
               /* std::cout << "new mouse x: " << mouseMoved->position.x << std::endl;
                std::cout << "new mouse y: " << mouseMoved->position.y << std::endl;*/
                if (180 < mouseMoved->position.y && mouseMoved->position.y < 225 && 345 < mouseMoved->position.x && mouseMoved->position.x < 430)
                {
                    //highlight play if hovering over it
                    text2.setFillColor(sf::Color::Green);
                    text2.setCharacterSize(42);

                    // allows us to click play
                    play = true;
                    
                }
                else if (280 < mouseMoved->position.y && mouseMoved->position.y < 325 && 345 < mouseMoved->position.x && mouseMoved->position.x < 450)
                {
                    //highlight rules if hovering over it
                    text3.setFillColor(sf::Color::Green);
                    text3.setCharacterSize(42);

                    // allows us to click rules
                    rules = true;
                }
                else if (380 < mouseMoved->position.y && mouseMoved->position.y < 425 && 345 < mouseMoved->position.x && mouseMoved->position.x < 415)
                {
                    //highlight exit if hovering over it
                    text4.setFillColor(sf::Color::Green);
                    text4.setCharacterSize(42);

                    // allows us to click exit
                    exit = true;
                }
                else
                {
                    // reset play, rules, and exit text
                    text2.setCharacterSize(40); // in pixels
                    text2.setFillColor(sf::Color::Red);
                    text3.setCharacterSize(40); // in pixels
                    text3.setFillColor(sf::Color::Red);
                    text4.setCharacterSize(40); // in pixels
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

                while (window.isOpen())
                {
                    switch (levelTracker)
                    {
                    case 1:
                        levelCheck = levelOne(window, player, background, LvlOneMsg);
                        if (levelCheck) 
                        {
                            levelTracker++;
                            clock.restart();
                        }
                        break;

                    case 2:
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
                            text3.setCharacterSize(40);
                            text3.setPosition(sf::Vector2f(350, 275));
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
        window.draw(text);
        window.draw(text2);
        window.draw(text3);
        window.draw(text4);

        window.display();
    }
    
}
