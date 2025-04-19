#include "Level.hpp"

bool levelOne(sf::RenderWindow& window, Sprite<Player>* player, sf::Sprite& backgroundTexture, sf::Text& lvlMsg)
{
    bool state = false;
    sf::Clock clock;
    float displaytime = 2.0f;

    while (window.isOpen())
    {
        // Poll events
        while (const std::optional<sf::Event> event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
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
            window.draw(player->getSprite());
            window.display();
        }

        // Player Movement Input
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) && player->getY() < 540.0f)
        {
            player->updateY(0.09f); // Move down
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && player->getY() > 20.0f)
        {
            player->updateY(-0.09f); // Move up
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        {
            if (player->getX() > 685.0f)
            {
                return true; // Player completed the level
            }
            if (player->getX() < 740.0f)
            {
                player->updateX(0.09f);
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) && player->getX() > 20.0f)
        {
            player->updateX(-0.09f); // Move left
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
        {
            // bring up pause menue
        }

        // Draw everything
        window.clear();
        window.draw(backgroundTexture);
        window.draw(player->getSprite());
        window.display();
    }
    return false;
}
