#include "Level.hpp"

bool checkWallCollision(Sprite* player, const std::vector<sf::RectangleShape*>& walls, sf::Vector2f offset)
{
    for (auto& wall : walls)
    {
        if (player->isCWall(*wall, offset))
            return true;
    }
    return false;
}

bool levelOne(sf::RenderWindow& window, sf::Sprite& backgroundTexture, sf::Text& lvlMsg)
{
    bool state = false;
    sf::Clock clock;
    float displaytime = 4.0f;
    Sprite* player = new Sprite();
    int enemyDir = 1;

    sf::CircleShape enemy1(20.f);
    enemy1.setFillColor(sf::Color::Blue);
    enemy1.setPosition({ 160.f, 21.f });
    sf::CircleShape enemy2(20.f);
    enemy2.setFillColor(sf::Color::Blue);
    enemy2.setPosition({ 240.f, 539.f });
    sf::CircleShape enemy3(20.f);
    enemy3.setFillColor(sf::Color::Blue);
    enemy3.setPosition({ 320.f, 21.f });
    sf::CircleShape enemy4(20.f);
    enemy4.setFillColor(sf::Color::Blue);
    enemy4.setPosition({ 400.f, 539.f });
    sf::CircleShape enemy5(20.f);
    enemy5.setFillColor(sf::Color::Blue);
    enemy5.setPosition({ 480.f, 21.f });
    sf::CircleShape enemy6(20.f);
    enemy6.setFillColor(sf::Color::Blue);
    enemy6.setPosition({ 560.f, 539.f });
    sf::CircleShape enemy7(20.f);
    enemy7.setFillColor(sf::Color::Blue);
    enemy7.setPosition({ 640.f, 21.f });
    std::vector<sf::CircleShape*> enemies = { &enemy1, &enemy2, &enemy3, &enemy4, &enemy5, &enemy6, &enemy7 };
    bool cEnemy = false;

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
            lvlMsg.setString("Level 1");
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
            window.draw(enemy1);
            window.draw(enemy2);
            window.draw(enemy3);
            window.draw(enemy4);
            window.draw(enemy5);
            window.draw(enemy6);
            window.draw(enemy7);
            window.display();
        }

        // move enemys
        // Reverse direction if any enemy hits top or bottom bounds
        for (auto& enemy : enemies)
        {
            float y = enemy->getPosition().y;
            if (y <= 20.f || y >= 540.f)
            {
                enemyDir *= -1;
                break; // Reverse direction only once
            }
        }
        for (size_t i = 0; i < enemies.size(); ++i)
        {
            float patternDir = (i % 2 == 0) ? 1.f : -1.f; // even index goes down, odd goes up
            enemies[i]->move({ 0.f, 0.13f * patternDir * enemyDir });
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) && player->getSprite().getPosition().y < 540.0f)
        {
            cEnemy = player->isCEnemy(enemy1, { 0.f, 0.15f }) || player->isCEnemy(enemy2, { 0.f, 0.15f }) || player->isCEnemy(enemy3, { 0.f, 0.15f }) || player->isCEnemy(enemy4, { 0.f, 0.15f }) || player->isCEnemy(enemy5, { 0.f, 0.15f }) || player->isCEnemy(enemy6, { 0.f, 0.15f }) || player->isCEnemy(enemy7, { 0.f, 0.15f });
            if (!cEnemy)
            {
                player->updateY(0.15f);
            }
            else
            {
                player->getSprite().setPosition({ 30.0f, 280.0f });
                player->setX(30.0f);
                player->setY(280.0f);
                cEnemy = false;
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && player->getSprite().getPosition().y > 20.0f)
        {
            cEnemy = player->isCEnemy(enemy1, { 0.f, -0.15f }) || player->isCEnemy(enemy2, { 0.f, -0.15f }) || player->isCEnemy(enemy3, { 0.f, -0.15f }) || player->isCEnemy(enemy4, { 0.f, -0.15f }) || player->isCEnemy(enemy5, { 0.f, -0.15f }) || player->isCEnemy(enemy6, { 0.f, -0.15f }) || player->isCEnemy(enemy7, { 0.f, -0.15f });
            if (!cEnemy)
            {
                player->updateY(-0.15f);
            }
            else
            {
                player->getSprite().setPosition({ 30.0f, 280.0f });
                player->setX(30.0f);
                player->setY(280.0f);
                cEnemy = false;
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        { 
            cEnemy = player->isCEnemy(enemy1, { 0.15f, 0.f }) || player->isCEnemy(enemy2, { 0.15f, 0.f }) || player->isCEnemy(enemy3, { 0.15f, 0.f }) || player->isCEnemy(enemy4, { 0.15f, 0.f }) || player->isCEnemy(enemy5, { 0.15f, 0.f }) || player->isCEnemy(enemy6, { 0.15f, 0.f }) || player->isCEnemy(enemy7, { 0.15f, 0.f });
            if (!cEnemy)
            {
                player->updateX(0.15f);
            }
            else
            {
                player->getSprite().setPosition({ 30.0f, 280.0f });
                player->setX(30.0f);
                player->setY(280.0f);
                cEnemy = false;
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) && player->getSprite().getPosition().x > 20.0f)
        {
            cEnemy = player->isCEnemy(enemy1, { -0.15f, 0.f }) || player->isCEnemy(enemy2, { -0.15f, 0.f }) || player->isCEnemy(enemy3, { -0.15f, 0.f }) || player->isCEnemy(enemy4, { -0.15f, 0.f }) || player->isCEnemy(enemy5, { -0.15f, 0.f }) || player->isCEnemy(enemy6, { -0.15f, 0.f }) || player->isCEnemy(enemy7, { -0.15f, 0.f });
            if (!cEnemy)
            {
                player->updateX(-0.15f);
            }
            else
            {
                player->getSprite().setPosition({ 30.0f, 280.0f });
                player->setX(30.0f);
                player->setY(280.0f);
                cEnemy = false;
            }
        }

        cEnemy = player->isCEnemy(enemy1, { 0.f, 0.f }) || player->isCEnemy(enemy2, { 0.f, 0.f }) || player->isCEnemy(enemy3, { 0.f, 0.f }) || player->isCEnemy(enemy4, { 0.f, 0.f }) || player->isCEnemy(enemy5, { 0.f, 0.f }) || player->isCEnemy(enemy6, { 0.f, 0.f }) || player->isCEnemy(enemy7, { 0.f, 0.f });
        if (cEnemy)
        {
            player->getSprite().setPosition({ 30.0f, 280.0f });
            player->setX(30.0f);
            player->setY(280.0f);
            cEnemy = false;
        }

        if (player->getPoint(0).x >= 700)
        {
            return true;
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
                        clock.restart();
                        clock.stop();
                        return false;
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
        window.draw(player->getSprite());
        window.draw(enemy1);
        window.draw(enemy2);
        window.draw(enemy3);
        window.draw(enemy4);
        window.draw(enemy5);
        window.draw(enemy6);
        window.draw(enemy7);
        window.display();
    }
    return false;
}

bool levelTwo(sf::RenderWindow& window, sf::Sprite& backgroundTexture, sf::Text& lvlMsg)
{
    bool cEnemy = false;
    bool state = false;
    sf::Clock clock;
    float displaytime = 4.0f;
    Sprite* player = new Sprite();
    sf::RectangleShape wall1({ 40.f, 520.f });
    wall1.setPosition(sf::Vector2f(360.0, 100.0));
    wall1.setFillColor(sf::Color::Black);
    sf::RectangleShape wall2({ 20.f, 480.f });
    wall2.setPosition(sf::Vector2f(100.0, 20.0));
    wall2.setFillColor(sf::Color::Black);
    sf::RectangleShape wall3({ 20.f, 480.f });
    wall3.setPosition(sf::Vector2f(680.0, 20.0));
    wall3.setFillColor(sf::Color::Black);
    std::vector<sf::RectangleShape*> walls = { &wall1, &wall2, &wall3 };

    // part one 
    sf::CircleShape enemy1(20.f);
    enemy1.setFillColor(sf::Color::Blue);
    enemy1.setPosition({ 160.f, 21.f });
    sf::CircleShape enemy2(20.f);
    enemy2.setFillColor(sf::Color::Blue);
    enemy2.setPosition({ 240.f, 539.f });
    sf::CircleShape enemy3(20.f);
    enemy3.setFillColor(sf::Color::Blue);
    enemy3.setPosition({ 320.f, 21.f });
    int enemyVdir = 1;

    std::vector<sf::CircleShape*> enemysV = { &enemy1, &enemy2, &enemy3 };

    //part two
    sf::CircleShape enemy4(20.f);
    enemy4.setFillColor(sf::Color::Blue);
    enemy4.setPosition({ 401.f, 100.f });
    sf::CircleShape enemy5(20.f);
    enemy5.setFillColor(sf::Color::Blue);
    enemy5.setPosition({ 639.f, 180.f });
    sf::CircleShape enemy6(20.f);
    enemy6.setFillColor(sf::Color::Blue);
    enemy6.setPosition({ 401.f, 260.f });
    sf::CircleShape enemy7(20.f);
    enemy7.setFillColor(sf::Color::Blue);
    enemy7.setPosition({ 639.f, 340.f });
    sf::CircleShape enemy8(20.f);
    enemy8.setFillColor(sf::Color::Blue);
    enemy8.setPosition({ 401.f, 420.f });
    int enemyHdir = 1;

    std::vector<sf::CircleShape*> enemysH = { &enemy4, &enemy5, &enemy6, &enemy7, &enemy8 };

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
            lvlMsg.setString("Level 2");
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
            window.draw(wall1);
            window.draw(wall2);
            window.draw(wall3);
            window.draw(enemy1);
            window.draw(enemy2);
            window.draw(enemy3);
            window.draw(enemy4);
            window.draw(enemy5);
            window.draw(enemy6);
            window.draw(enemy7);
            window.draw(enemy8);
            window.draw(player->getSprite());
            window.display();
        }



        for (auto& enemyV : enemysV)
        {
            float yV = enemyV->getPosition().y;
            if (yV <= 20.f || yV >= 540.f)
            {
                enemyVdir *= -1;
                break; // Reverse direction only once
            }
        }
        for (size_t i = 0; i < enemysV.size(); ++i)
        {
            float patternDirV = (i % 2 == 0) ? 1.f : -1.f; // even index goes down, odd goes up
            enemysV[i]->move({ 0.f, 0.13f * patternDirV * enemyVdir });
        }

        for (auto& enemyH : enemysH)
        {
            float xH = enemyH->getPosition().x;
            if (xH <= 400.f || xH >= 640.f)
            {
                enemyHdir *= -1;
                break; // Reverse direction only once
            }
        }
        for (size_t a = 0; a < enemysH.size(); ++a)
        {
            float patternDirH = (a % 2 == 0) ? 1.f : -1.f; // even index goes down, odd goes up
            enemysH[a]->move({ 0.09f * patternDirH * enemyHdir, 0.f });
        }


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) && player->getSprite().getPosition().y < 540.0f)
        {
            
            cEnemy = player->isCEnemy(enemy1, { 0.f, 0.15f }) || player->isCEnemy(enemy2, { 0.f, 0.15f }) || player->isCEnemy(enemy3, { 0.f, 0.15f }) || player->isCEnemy(enemy4, { 0.f, 0.15f }) || player->isCEnemy(enemy5, { 0.f, 0.15f }) || player->isCEnemy(enemy6, { 0.f, 0.15f }) || player->isCEnemy(enemy7, { 0.f, 0.15f }) || player->isCEnemy(enemy8, { 0.f, 0.15f });
            if (!cEnemy)
            {
                if (!checkWallCollision(player, walls, { 0.f, 0.15f }))
                {
                    player->updateY(0.15f);
                }
            }
            else
            {
                player->getSprite().setPosition({ 30.0f, 280.0f });
                player->setX(30.0f);
                player->setY(280.0f);
                cEnemy = false;
            }
            
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && player->getSprite().getPosition().y > 20.0f)
        {
            cEnemy = player->isCEnemy(enemy1, { 0.f, -0.15f }) || player->isCEnemy(enemy2, { 0.f, -0.15f }) || player->isCEnemy(enemy3, { 0.f, -0.15f }) || player->isCEnemy(enemy4, { 0.f, -0.15f }) || player->isCEnemy(enemy5, { 0.f, -0.15f }) || player->isCEnemy(enemy6, { 0.f, -0.15f }) || player->isCEnemy(enemy7, { 0.f, -0.15f }) || player->isCEnemy(enemy8, { 0.f, -0.15f });
            if (!cEnemy)
            {
                if (!checkWallCollision(player, walls, { 0.f, -0.15f }))
                {
                    player->updateY(-0.15f);
                }
            }
            else
            {
                player->getSprite().setPosition({ 30.0f, 280.0f });
                player->setX(30.0f);
                player->setY(280.0f);
                cEnemy = false;
            }
            
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) && player->getPoint(2).x < 780.0)
        {
            cEnemy = player->isCEnemy(enemy1, { 0.15f, 0.f }) || player->isCEnemy(enemy2, { 0.15f, 0.f }) || player->isCEnemy(enemy3, { 0.15f, 0.f }) || player->isCEnemy(enemy4, { 0.15f, 0.f }) || player->isCEnemy(enemy5, { 0.15f, 0.f }) || player->isCEnemy(enemy6, { 0.15f, 0.f }) || player->isCEnemy(enemy7, { 0.15f, 0.f }) || player->isCEnemy(enemy8, { 0.15f, 0.f });
            if (!cEnemy)
            {
                if (!checkWallCollision(player, walls, { 0.15f, 0.f }))
                {
                    player->updateX(0.15f);
                }
            }
            else
            {
                player->getSprite().setPosition({ 30.0f, 280.0f });
                player->setX(30.0f);
                player->setY(280.0f);
                cEnemy = false;
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) && player->getSprite().getPosition().x > 20.0f)
        {
            cEnemy = player->isCEnemy(enemy1, { -0.15f, 0.f }) || player->isCEnemy(enemy2, { -0.15f, 0.f }) || player->isCEnemy(enemy3, { -0.15f, 0.f }) || player->isCEnemy(enemy4, { -0.15f, 0.f }) || player->isCEnemy(enemy5, { -0.15f, 0.f }) || player->isCEnemy(enemy6, { -0.15f, 0.f }) || player->isCEnemy(enemy7, { -0.15f, 0.f }) || player->isCEnemy(enemy8, { -0.15f, 0.f });
            if (!cEnemy)
            {
                if (!checkWallCollision(player, walls, { -0.15f, 0.f }))
                {
                    player->updateX(-0.15f);
                }
            }
            else
            {
                player->getSprite().setPosition({ 30.0f, 280.0f });
                player->setX(30.0f);
                player->setY(280.0f);
                cEnemy = false;
            }
            
        }

        if (player->getPoint(2).x >= 745.0)
        {
            return true;
        }

        cEnemy = player->isCEnemy(enemy1, { 0.f, 0.f }) || player->isCEnemy(enemy2, { 0.f, 0.f }) || player->isCEnemy(enemy3, { 0.f, 0.f }) || player->isCEnemy(enemy4, { 0.f, 0.f }) || player->isCEnemy(enemy5, { 0.f, 0.f }) || player->isCEnemy(enemy6, { 0.f, 0.f }) || player->isCEnemy(enemy7, { 0.f, 0.f }) || player->isCEnemy(enemy8, {0.f, 0.f});

        if (cEnemy)
        {
            player->getSprite().setPosition({ 30.0f, 280.0f });
            player->setX(30.0f);
            player->setY(280.0f);
            cEnemy = false;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
        {
            bool resume = false, resumebounds = false, exit = false;
            sf::Font font;
            font.openFromFile("arial_narrow_7.ttf");
            sf::Text text(font), text2(font), text3(font);
            sf::RectangleShape pause({ 300.f, 300.0f });
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
                        else if (355 < mouseMoved->position.y && mouseMoved->position.y < 390 && 285 < mouseMoved->position.x && mouseMoved->position.x < 350)
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
                        clock.restart();
                        clock.stop();
                        return false;
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
        window.draw(wall1);
        window.draw(wall2);
        window.draw(wall3);
        window.draw(enemy1);
        window.draw(enemy2);
        window.draw(enemy3);
        window.draw(enemy4);
        window.draw(enemy5);
        window.draw(enemy6);
        window.draw(enemy7);
        window.draw(enemy8);
        window.draw(player->getSprite());

        window.display();
    }
    return false;
}
bool levelThree(sf::RenderWindow& window, sf::Sprite& backgroundTexture, sf::Text& lvlMsg)
{
    bool cEnemy = false;
    bool state = false;
    sf::Clock clock;
    float displaytime = 4.0f;
    Sprite* player = new Sprite();
    sf::RectangleShape wall1({ 470.f, 10.f });
    wall1.setPosition(sf::Vector2f(100.0, 330.0));
    wall1.setFillColor(sf::Color::Black);
    sf::RectangleShape wall2({ 20.f, 250.f });
    wall2.setPosition(sf::Vector2f(100.0, 20.0));
    wall2.setFillColor(sf::Color::Black);
    sf::RectangleShape wall3({ 20.f, 250.f });
    wall3.setPosition(sf::Vector2f(100.0, 330.0));
    wall3.setFillColor(sf::Color::Black);
    sf::RectangleShape wall4({ 20.f, 480.f });
    wall4.setPosition(sf::Vector2f(680.0, 20.0));
    wall4.setFillColor(sf::Color::Black);
    sf::RectangleShape wall5({ 400.f, 10.f });
    wall5.setPosition(sf::Vector2f(100.0, 230.0));
    wall5.setFillColor(sf::Color::Black);
    sf::RectangleShape wall6({ 10.f, 220.f });
    wall6.setPosition(sf::Vector2f(570.0, 120.0));
    wall6.setFillColor(sf::Color::Black);
    sf::RectangleShape wall7({ 380.f, 10.f });
    wall7.setPosition(sf::Vector2f(190.0, 120.0));
    wall7.setFillColor(sf::Color::Black);
    sf::RectangleShape wall8({ 440.f, 10.f });
    wall8.setPosition(sf::Vector2f(240.0, 450.0));
    wall8.setFillColor(sf::Color::Black);
    std::vector<sf::RectangleShape*> walls = { &wall1, &wall2, &wall3, &wall4, &wall5, &wall6, &wall7, &wall8 };

    //part one
    sf::CircleShape enemy1(20.f);
    enemy1.setFillColor(sf::Color::Blue);
    enemy1.setPosition({ 121.f, 240.f });
    sf::CircleShape enemy2(20.f);
    enemy2.setFillColor(sf::Color::Blue);
    enemy2.setPosition({ 529.f, 290.f });


    //part two
    sf::CircleShape enemy3(20.f);
    enemy3.setFillColor(sf::Color::Blue);
    enemy3.setPosition({ 121.f, 130.f });
    sf::CircleShape enemy4(20.f);
    enemy4.setFillColor(sf::Color::Blue);
    enemy4.setPosition({ 529.f, 190.f });

    //part three
    sf::CircleShape enemy5(20.f);
    enemy5.setFillColor(sf::Color::Blue);
    enemy5.setPosition({ 121.f, 20.f });
    sf::CircleShape enemy6(20.f);
    enemy6.setFillColor(sf::Color::Blue);
    enemy6.setPosition({ 529.f, 80.f });
    //part four
    sf::CircleShape enemy7(20.f);
    enemy7.setFillColor(sf::Color::Blue);
    enemy7.setPosition({ 585.f, 21.f });
    sf::CircleShape enemy8(20.f);
    enemy8.setFillColor(sf::Color::Blue);
    enemy8.setPosition({ 635.f, 409.f });

    //part five                                                    
    sf::CircleShape enemy9(20.f);
    enemy9.setFillColor(sf::Color::Blue);
    enemy9.setPosition({ 534.f, 400.f });
    sf::CircleShape enemy10(20.f);
    enemy10.setFillColor(sf::Color::Blue);
    enemy10.setPosition({ 240.f, 350.f });

    // part six 
    sf::CircleShape enemy11(20.f);
    enemy11.setFillColor(sf::Color::Blue);
    enemy11.setPosition({ 130.f, 341.f });
    sf::CircleShape enemy12(20.f);
    enemy12.setFillColor(sf::Color::Blue);
    enemy12.setPosition({ 180.f, 539.f });

    //part seven
    sf::CircleShape enemy13(20.f);
    enemy13.setFillColor(sf::Color::Blue);
    enemy13.setPosition({ 629.f, 470.f });
    sf::CircleShape enemy14(20.f);
    enemy14.setFillColor(sf::Color::Blue);
    enemy14.setPosition({ 240.f, 530.f });


    int enemyVdir1 = 1;
    int enemyVdir2 = 1;
    std::vector<sf::CircleShape*> enemysV1 = { &enemy7, &enemy8 };
    std::vector<sf::CircleShape*> enemysV2 = { &enemy11, &enemy12 };

    int enemyHdir1 = 1;
    int enemyHdir2 = 1;
    int enemyHdir3 = 1;
    std::vector<sf::CircleShape*> enemysH1 = { &enemy1, &enemy2, &enemy3, &enemy4, &enemy5, &enemy6 };
    std::vector<sf::CircleShape*> enemysH2 = { &enemy9, &enemy10 };
    std::vector<sf::CircleShape*> enemysH3 = { &enemy13, &enemy14 };


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
            lvlMsg.setString("Level 3");
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
            window.draw(wall1);
            window.draw(wall2);
            window.draw(wall3);
            window.draw(wall4);
            window.draw(wall5);
            window.draw(wall6);
            window.draw(wall7);
            window.draw(wall8);
            window.draw(enemy1);
            window.draw(enemy2);
            window.draw(enemy3);
            window.draw(enemy4);
            window.draw(enemy5);
            window.draw(enemy6);
            window.draw(enemy7);
            window.draw(enemy8);
            window.draw(enemy9);
            window.draw(enemy10);
            window.draw(enemy11);
            window.draw(enemy12);
            window.draw(enemy13);
            window.draw(enemy14);
            window.draw(player->getSprite());
            window.display();
        }



        for (auto& enemyV1 : enemysV1)
        {
            float yV1 = enemyV1->getPosition().y;
            if (yV1 <= 20.f || yV1 >= 410.f)
            {
                enemyVdir1 *= -1;
                break; // Reverse direction only once
            }
        }
        for (size_t i = 0; i < enemysV1.size(); ++i)
        {
            float patternDirV1 = (i % 2 == 0) ? 1.f : -1.f; // even index goes down, odd goes up
            enemysV1[i]->move({ 0.f, 0.13f * patternDirV1 * enemyVdir1 });
        }
        for (auto& enemyV2 : enemysV2)
        {
            float yV2 = enemyV2->getPosition().y;
            if (yV2 <= 340.f || yV2 >= 540.f)
            {
                enemyVdir2 *= -1;
                break; // Reverse direction only once
            }
        }
        for (size_t i = 0; i < enemysV2.size(); ++i)
        {
            float patternDirV2 = (i % 2 == 0) ? 1.f : -1.f; // even index goes down, odd goes up
            enemysV2[i]->move({ 0.f, 0.13f * patternDirV2 * enemyVdir2 });
        }

        for (auto& enemyH1 : enemysH1)
        {
            float xH1 = enemyH1->getPosition().x;
            if (xH1 <= 120.f || xH1 >= 540.f)
            {
                enemyHdir1 *= -1;
                break; // Reverse direction only once
            }
        }
        for (size_t a = 0; a < enemysH1.size(); ++a)
        {
            float patternDirH1 = (a % 2 == 0) ? 1.f : -1.f; // even index goes down, odd goes up
            enemysH1[a]->move({ 0.09f * patternDirH1 * enemyHdir1, 0.f });
        }
        for (auto& enemyH2 : enemysH2)
        {
            float xH2 = enemyH2->getPosition().x;
            if (xH2 <= 190.f || xH2 >= 535.f)
            {
                enemyHdir2 *= -1;
                break; // Reverse direction only once
            }
        }
        for (size_t a = 0; a < enemysH2.size(); ++a)
        {
            float patternDirH2 = (a % 2 == 0) ? 1.f : -1.f; // even index goes down, odd goes up
            enemysH2[a]->move({ 0.09f * patternDirH2 * enemyHdir2, 0.f });
        }
        for (auto& enemyH3 : enemysH3)
        {
            float xH3 = enemyH3->getPosition().x;
            if (xH3 <= 190.f || xH3 >= 630.f)
            {
                enemyHdir3 *= -1;
                break; // Reverse direction only once
            }
        }
        for (size_t a = 0; a < enemysH3.size(); ++a)
        {
            float patternDirH3 = (a % 2 == 0) ? 1.f : -1.f; // even index goes down, odd goes up
            enemysH3[a]->move({ 0.09f * patternDirH3 * enemyHdir3, 0.f });
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) && player->getSprite().getPosition().y < 540.0f)
        {

            cEnemy = player->isCEnemy(enemy1, { 0.f, 0.15f }) || player->isCEnemy(enemy2, { 0.f, 0.15f }) || player->isCEnemy(enemy3, { 0.f, 0.15f }) || player->isCEnemy(enemy4, { 0.f, 0.15f }) || player->isCEnemy(enemy5, { 0.f, 0.15f }) || player->isCEnemy(enemy6, { 0.f, 0.15f }) || player->isCEnemy(enemy7, { 0.f, 0.15f }) || player->isCEnemy(enemy8, { 0.f, 0.15f }) || player->isCEnemy(enemy9, { 0.f, 0.15f }) || player->isCEnemy(enemy10, { 0.f, 0.15f }) || player->isCEnemy(enemy11, { 0.f, 0.15f }) || player->isCEnemy(enemy12, { 0.f, 0.15f }) || player->isCEnemy(enemy13, { 0.f, 0.15f }) || player->isCEnemy(enemy14, { 0.f, 0.15f });
            if (!cEnemy)
            {
                if (!checkWallCollision(player, walls, { 0.f, 0.15f }))
                {
                    player->updateY(0.15f);
                }
            }
            else
            {
                player->getSprite().setPosition({ 30.0f, 280.0f });
                player->setX(30.0f);
                player->setY(280.0f);
                cEnemy = false;
            }

        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && player->getSprite().getPosition().y > 20.0f)
        {
            cEnemy = player->isCEnemy(enemy1, { 0.f, -0.15f }) || player->isCEnemy(enemy2, { 0.f, -0.15f }) || player->isCEnemy(enemy3, { 0.f, -0.15f }) || player->isCEnemy(enemy4, { 0.f, -0.15f }) || player->isCEnemy(enemy5, { 0.f, -0.15f }) || player->isCEnemy(enemy6, { 0.f, -0.15f }) || player->isCEnemy(enemy7, { 0.f, -0.15f }) || player->isCEnemy(enemy8, { 0.f, -0.15f }) || player->isCEnemy(enemy9, { 0.f, -0.15f }) || player->isCEnemy(enemy10, { 0.f, -0.15f }) || player->isCEnemy(enemy11, { 0.f, -0.15f }) || player->isCEnemy(enemy12, { 0.f, -0.15f }) || player->isCEnemy(enemy13, { 0.f, -0.15f }) || player->isCEnemy(enemy14, { 0.f, -0.15f });
            if (!cEnemy)
            {
                if (!checkWallCollision(player, walls, { 0.f, -0.15f }))
                {
                    player->updateY(-0.15f);
                }
            }
            else
            {
                player->getSprite().setPosition({ 30.0f, 280.0f });
                player->setX(30.0f);
                player->setY(280.0f);
                cEnemy = false;
            }

        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) && player->getPoint(2).x < 780.0)
        {
            cEnemy = player->isCEnemy(enemy1, { 0.15f, 0.f }) || player->isCEnemy(enemy2, { 0.15f, 0.f }) || player->isCEnemy(enemy3, { 0.15f, 0.f }) || player->isCEnemy(enemy4, { 0.15f, 0.f }) || player->isCEnemy(enemy5, { 0.15f, 0.f }) || player->isCEnemy(enemy6, { 0.15f, 0.f }) || player->isCEnemy(enemy7, { 0.15f, 0.f }) || player->isCEnemy(enemy8, { 0.15f, 0.f }) || player->isCEnemy(enemy9, { 0.15f, 0.f }) || player->isCEnemy(enemy10, { 0.15f, 0.f }) || player->isCEnemy(enemy11, { 0.15f, 0.f }) || player->isCEnemy(enemy12, { 0.15f, 0.f }) || player->isCEnemy(enemy13, { 0.15f, 0.f }) || player->isCEnemy(enemy14, { 0.15f, 0.f });
            if (!cEnemy)
            {
                if (!checkWallCollision(player, walls, { 0.15f, 0.f }))
                {
                    player->updateX(0.15f);
                }
            }
            else
            {
                player->getSprite().setPosition({ 30.0f, 280.0f });
                player->setX(30.0f);
                player->setY(280.0f);
                cEnemy = false;
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) && player->getSprite().getPosition().x > 20.0f)
        {
            cEnemy = player->isCEnemy(enemy1, { -0.15f, 0.f }) || player->isCEnemy(enemy2, { -0.15f, 0.f }) || player->isCEnemy(enemy3, { -0.15f, 0.f }) || player->isCEnemy(enemy4, { -0.15f, 0.f }) || player->isCEnemy(enemy5, { -0.15f, 0.f }) || player->isCEnemy(enemy6, { -0.15f, 0.f }) || player->isCEnemy(enemy7, { -0.15f, 0.f }) || player->isCEnemy(enemy8, { -0.15f, 0.f }) || player->isCEnemy(enemy9, { -0.15f, 0.f }) || player->isCEnemy(enemy10, { -0.15f, 0.f }) || player->isCEnemy(enemy11, { -0.15f, 0.f }) || player->isCEnemy(enemy12, { -0.15f, 0.f }) || player->isCEnemy(enemy13, { -0.15f, 0.f }) || player->isCEnemy(enemy14, { -0.15f, 0.f });
            if (!cEnemy)
            {
                if (!checkWallCollision(player, walls, { -0.15f, 0.f }))
                {
                    player->updateX(-0.15f);
                }
            }
            else
            {
                player->getSprite().setPosition({ 30.0f, 280.0f });
                player->setX(30.0f);
                player->setY(280.0f);
                cEnemy = false;
            }

        }

        if (player->getPoint(2).x >= 745.0)
        {
            return true;
        }

        cEnemy = player->isCEnemy(enemy1, { 0.f, 0.f }) || player->isCEnemy(enemy2, { 0.f, 0.f }) || player->isCEnemy(enemy3, { 0.f, 0.f }) || player->isCEnemy(enemy4, { 0.f, 0.f }) || player->isCEnemy(enemy5, { 0.f, 0.f }) || player->isCEnemy(enemy6, { 0.f, 0.f }) || player->isCEnemy(enemy7, { 0.f, 0.f }) || player->isCEnemy(enemy8, { 0.f, 0.f }) || player->isCEnemy(enemy9, { 0.f, 0.f }) || player->isCEnemy(enemy10, { 0.f, 0.f }) || player->isCEnemy(enemy11, { 0.f, 0.f }) || player->isCEnemy(enemy12, { 0.f, 0.f }) || player->isCEnemy(enemy13, { 0.f, 0.f }) || player->isCEnemy(enemy14, { 0.f, 0.f });

        if (cEnemy)
        {
            player->getSprite().setPosition({ 30.0f, 280.0f });
            player->setX(30.0f);
            player->setY(280.0f);
            cEnemy = false;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
        {
            bool resume = false, resumebounds = false, exit = false;
            sf::Font font;
            font.openFromFile("arial_narrow_7.ttf");
            sf::Text text(font), text2(font), text3(font);
            sf::RectangleShape pause({ 300.f, 300.0f });
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
                        else if (355 < mouseMoved->position.y && mouseMoved->position.y < 390 && 285 < mouseMoved->position.x && mouseMoved->position.x < 350)
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
                        clock.restart();
                        clock.stop();
                        return false;
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
        window.draw(wall1);
        window.draw(wall2);
        window.draw(wall3);
        window.draw(wall4);
        window.draw(wall5);
        window.draw(wall6);
        window.draw(wall7);
        window.draw(wall8);
        window.draw(enemy1);
        window.draw(enemy2);
        window.draw(enemy3);
        window.draw(enemy4);
        window.draw(enemy5);
        window.draw(enemy6);
        window.draw(enemy7);
        window.draw(enemy8);
        window.draw(enemy9);
        window.draw(enemy10);
        window.draw(enemy11);
        window.draw(enemy12);
        window.draw(enemy13);
        window.draw(enemy14);
        window.draw(player->getSprite());

        window.display();
    }

    return false;
}
