#include "Sprite.hpp"
#include <iostream>
using std::cout;

int main()
{
    sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "HardGam");
    Sprite* player = new Sprite;

    //Background
    sf::Texture texture;
    texture.loadFromFile("Background.png");
    sf::Vector2u size = texture.getSize();
    sf::Sprite background(texture);

    //Font

    sf::Font Arial;//load the font file
        if (!Arial.openFromFile("arial.ttf"))
        {
        //prints meassage if error automatically
        }

    sf::Text LvlOneMsg(Arial); // create a text with the font
    LvlOneMsg.setString("You Dead Ass aint \nready for this shit");// the text
    LvlOneMsg.setCharacterSize(48); // text size in pixels
    LvlOneMsg.setFillColor(sf::Color::White); // Text color
    LvlOneMsg.setPosition(sf::Vector2f(200.f, 200.f)); // location for the text

    //clock for displaying text before level

    sf::Clock clock;
    float displaytime = 3.0f; // time for prelevel text duration
    bool showLevelText = true;
    
    
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) //check for closing game
        {
            window.close(); //close game
        }

        //Shows text before a level for certain time
        if (showLevelText)
        {
            if (clock.getElapsedTime().asSeconds() < displaytime)
            {
                window.draw(LvlOneMsg); // draws the msg
                window.display(); // displays

                continue; //doesnt do anything else til time has passed
            }
            else
            {
                LvlOneMsg.setString("");// removes the text
                showLevelText = false; //done showing message
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) 
        {
            if (player->getY() < 540.0f) //prevents player from leaving screen vertically
            {
                player->updateY(0.11f);// player speed down
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
        {
            if (player->getY() > 20.0f) //prevents player from leaving screen vertically
            {
                player->updateY(-0.11f);// player speed up
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        {
            if (player->getX() < 740.0f) //prevents player from leaving screen horizontaly
            {
                player->updateX(0.11f);// player speed right
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
        {
            if (player->getX() > 20.0f)//prevents player from leaving screen horizontaly
            {
                player->updateX(-0.11f);// player speed left
            }
        }


        
        window.clear();
        //


        window.draw(background);
        window.draw(LvlOneMsg);
        window.draw(player->getSprite());


        //
        window.display();

    }
}
