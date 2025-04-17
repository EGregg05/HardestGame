#include "Sprite.hpp"
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "HardGam");
    Sprite* player = new Sprite;

 

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
        {
            player->updateY(0.11);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
        {
            player->updateY(-0.11);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        {
            player->updateX(0.11);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
        {
            player->updateX(-0.11);
        }



        window.clear();
        window.draw(player->getSprite());
        window.display();

    }
}
