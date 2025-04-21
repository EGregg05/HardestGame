#include "Level.hpp"



bool levelOne(sf::RenderWindow& window,Sprite* player, sf::Sprite& backgroundTexture, sf::Text& lvlMsg)
{
    bool state = false;
    sf::Clock clock;
    float displaytime = 2.0f;
    player->getSprite().setPosition(sf::Vector2f(50.0, 280.0));
    sf::RectangleShape tempWall({ 50.f, 50.f });
    tempWall.setPosition(sf::Vector2f(300.0, 200.0));
    tempWall.setFillColor(sf::Color::Black);
    





 






    while (window.isOpen())
    {
        // Poll events
        while (const std::optional<sf::Event> event = window.pollEvent()) 
        {
            if (event->is<sf::Event::Closed>()) 
            {
                window.close();
            }
        }

        // Shows level start message
        if (clock.getElapsedTime().asSeconds() < displaytime)
        {
            window.clear();
            window.draw(lvlMsg); // draws the msg
            window.display(); // displays

            continue; //doesnt do anything else til time has passed
        }
        else
        {
            lvlMsg.setString("");// removes the text
            window.clear();
            window.draw(backgroundTexture);
            window.draw(tempWall);
            window.draw(player->getSprite());
            window.display();
        }
    
        // Player Movement Input
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) && player->getY() < 540.0f)
        {
            
            if (player->getSprite().getGlobalBounds().findIntersection(tempWall.getGlobalBounds()))
            {
                collisionWall(tempWall, player);
            }
            else
            {
                player->getSprite().move(sf::Vector2f(0.0f, 0.11f)); // Move down
            }
            
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && player->getY() > 20.0f)
        {
            if (player->getSprite().getGlobalBounds().findIntersection(tempWall.getGlobalBounds()))
            {
                collisionWall(tempWall, player);
            }
            else
            {
                player->getSprite().move(sf::Vector2f(0.0f, -0.11f)); // Move up
            }
            
            
            
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        {

            if (player->getSprite().getGlobalBounds().findIntersection(tempWall.getGlobalBounds()))
            {
                collisionWall(tempWall, player);
            }
            else
            {
                if (player->getX() < 740.0f)
                {
                    player->getSprite().move(sf::Vector2f(0.11f, 0.0f));
                }
            }
            if (player->getX() > 685.0f)
            {
                return true; // Player completed the level
            }

        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) && player->getX() > 20.0f)
        {

            if (player->getSprite().getGlobalBounds().findIntersection(tempWall.getGlobalBounds()))
            {
                collisionWall(tempWall, player);
            }
            else
            {
                player->getSprite().move(sf::Vector2f(-0.11f, 0.0f)); // Move left
            }
            
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
        {
            bool resume = false, resumebounds = false, exit = false;
            sf::Font font;
            font.openFromFile("arial_narrow_7.ttf");
            sf::Text text(font), text2(font), text3(font);
            sf::RectangleShape pause({ 300.f, 300.0f});
            pause.setFillColor(sf::Color::Black);
            pause.setPosition(sf::Vector2f(240.0, 150.0));
            text.setString("Paused");
            text.setCharacterSize(60); // in pixels
            text.setFillColor(sf::Color::Red);
            text.setPosition(sf::Vector2f(290.0, 200.0));
            text.setStyle(sf::Text::Bold | sf::Text::Underlined);
            text2.setString("Resume");
            text2.setCharacterSize(40); // in pixels
            text2.setFillColor(sf::Color::Red);
            text2.setPosition(sf::Vector2f(290, 300));
            text3.setString("Exit");
            text3.setCharacterSize(40); // in pixels
            text3.setFillColor(sf::Color::Red);
            text3.setPosition(sf::Vector2f(290, 350));
            while (resume == false)
            {
                while (const std::optional event = window.pollEvent())
                {
                    if (event->is<sf::Event::Closed>())
                        window.close();
                    if (const auto* mouseMoved = event->getIf<sf::Event::MouseMoved>())
                    {
                       /* std::cout << "new mouse x: " << mouseMoved->position.x << std::endl;
                        std::cout << "new mouse y: " << mouseMoved->position.y << std::endl;*/
                        if (305 < mouseMoved->position.y && mouseMoved->position.y < 345 && 285 < mouseMoved->position.x && mouseMoved->position.x < 420)
                        {
                            // highlight the back button if mouse is in bounds
                            text2.setFillColor(sf::Color::Green);
                            text2.setCharacterSize(42);

                            // allow us to click resume
                            resumebounds = true;
                        }
                        else if(355 < mouseMoved->position.y && mouseMoved->position.y < 390 && 285 < mouseMoved->position.x && mouseMoved->position.x < 350)
                        {
                            text3.setFillColor(sf::Color::Green);
                            text3.setCharacterSize(42);

                            // allow us to click exit
                            exit = true;
                        }
                        else
                        {
                            text2.setFillColor(sf::Color::Red);
                            text2.setCharacterSize(40);
                            resumebounds = false;
                            text3.setFillColor(sf::Color::Red);
                            text3.setCharacterSize(40);
                            exit = false;
                        }
                        
                    }
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && resumebounds) //unpause
                    {
                        resume = true;
                        resumebounds = false;
                    }
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && exit) // for now exit is going to resume as well until we can figure out how to return to main menu
                    {
                        resume = true;
                        exit = false;
                    }
                }
                window.draw(pause);
                window.draw(text);
                window.draw(text2);
                window.draw(text3);
                window.display();
            }
        }

        // Draw everything
        window.clear();
        window.draw(backgroundTexture);
        window.draw(tempWall);
        window.draw(player->getSprite());
        window.display();
    }
    return false;
}

bool collisionWall(sf::RectangleShape& wall, Sprite* player)
{

    return false;
}

bool collisionEnemy(sf::CircleShape& enemy, Sprite* player)
{

    return false;
}
