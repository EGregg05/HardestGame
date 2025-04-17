#include "Sprite.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "HardGam");
    Sprite* player = new Sprite;


    
    sf::Font font;
    font.openFromFile("C:\\Users\\ajayr\\source\\repos\\HardestGame\\HardestGame\\arial_narrow_7.ttf");
    sf::Text text(font);
    text.setString("Worlds Hardest Game");
    text.setCharacterSize(24); // in pixels
    text.setFillColor(sf::Color::Red);

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
        window.draw(text);
        window.draw(player->getSprite());
        window.display();

    }
}
