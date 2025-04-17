#include "Sprite.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "HardGam");
    Sprite* player = new Sprite;

    sf::Texture texture;
    texture.loadFromFile("Background.png");
    sf::Vector2u size = texture.getSize();
    sf::Sprite background(texture);
    

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) 
        {
            if (player->getY() < 540.0f)
            {
                player->updateY(0.11f);
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
        {
            if (player->getY() > 20.0f)
            {
                player->updateY(-0.11f);
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        {
            if (player->getX() < 740.0f)
            {
                player->updateX(0.11f);
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
        {
            if (player->getX() > 20.0f)
            {
                player->updateX(-0.11f);
            }
        }



        window.clear();
        window.draw(background);
        window.draw(player->getSprite());
        window.display();

    }
}
