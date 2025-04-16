#include "Sprite.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "HardGam");
    sf::RectangleShape sprite(sf::Vector2f(40.0, 40.0));
    sprite.setFillColor(sf::Color::Green);


    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
        {
            sprite.move(sf::Vector2f(0.0, 0.11));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
        {
            sprite.move(sf::Vector2f(0.0, -0.11));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        {
            sprite.move(sf::Vector2f(0.11, 0.0));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
        {
            sprite.move(sf::Vector2f(-0.11, 0.0));
        }

        window.clear();
        window.draw(sprite);
        window.display();

    }
}
