#include "Menu.h"


bool Menu::isMainMenu(sf::RenderWindow &window, sf::Sprite gameBack, sf::Sprite menuBack, sf::Font font)
{

    sf::Text text(font)/*worlds hardest game*/, text2(font)/*Play*/, text3(font)/*Rules*/
        , text4(font)/*Exit*/, text5(font)/*Rule 1*/, text6(font)/*Rule 2*/, text7(font) /*Back*/, text8(font)/*Select Level*/, text9(font)/*moving instructions*/;
       // , text10(font)/*Level 1 select*/, text11(font)/*level 2 select*/; //different texts
    Menu selectMenu;

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
    text8.setPosition(sf::Vector2f(250, 280));
    text3.setString("Rules");
    text3.setCharacterSize(50); // in pixels
    text3.setFillColor(sf::Color::Red);
    text3.setPosition(sf::Vector2f(325, 380));
    text4.setString("Exit");
    text4.setCharacterSize(50); // in pixels
    text4.setFillColor(sf::Color::Red); //text color
    text4.setPosition(sf::Vector2f(340, 480)); // text position

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

    bool play = false, rules = false, exit = false, back = false, backbounds = false, select = false, lvl1bounds = false, lvl2bounds = false;

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
                else if (280 < mouseMoved->position.y && mouseMoved->position.y < 330 && 250 < mouseMoved->position.x && mouseMoved->position.x < 560)
                {
                    text8.setFillColor(sf::Color::Green);
                    text8.setCharacterSize(55);

                    select = true;

                }
                else if (380 < mouseMoved->position.y && mouseMoved->position.y < 430 && 325 < mouseMoved->position.x && mouseMoved->position.x < 455)
                {
                    //highlight rules if hovering over it
                    text3.setFillColor(sf::Color::Green);
                    text3.setCharacterSize(55);

                    // allows us to click rules
                    rules = true;
                }
                else if (480 < mouseMoved->position.y && mouseMoved->position.y < 530 && 340 < mouseMoved->position.x && mouseMoved->position.x < 470)
                {
                    //highlight exit if hovering over it
                    text4.setFillColor(sf::Color::Green);
                    text4.setCharacterSize(55);

                    // allows us to click exit
                    exit = true;
                }
                else
                {
                    //is this needed??? - yes definitely needed!!
                    // reset play, rules, and exit text
                    text2.setCharacterSize(50); // in pixels
                    text2.setFillColor(sf::Color::Red);
                    text8.setCharacterSize(50);
                    text8.setFillColor(sf::Color::Red);
                    text3.setCharacterSize(50); // in pixels
                    text3.setFillColor(sf::Color::Red);
                    text4.setCharacterSize(50); // in pixels
                    text4.setFillColor(sf::Color::Red);
                    play = false;
                    select = false;
                    rules = false;
                    exit = false;
                }
            }
            if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && select)
            {
                selectMenu.selectLevel(window, back, menuBack, gameBack, LvlOneMsg, LvlTwoMsg, text8, font);
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
                        levelCheck = levelOne(window, gameBack, LvlOneMsg);
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
                        levelCheck = levelTwo(window, gameBack, LvlTwoMsg);
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
                    case 3:
                        playLevel = false;
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
                //add keys used to play
                text9.setString("(To move use keys W, A, S, & D)");
                text9.setCharacterSize(30);
                text9.setFillColor(sf::Color::Red);
                text9.setPosition(sf::Vector2f(200, 500));


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
                            text3.setPosition(sf::Vector2f(325, 380));
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
                    window.draw(text9);
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
        window.draw(menuBack);
        window.draw(text);
        window.draw(text2);
        window.draw(text8);
        window.draw(text3);
        window.draw(text4);

        window.display();
    }

    return true;
}

bool Menu::isPauseMenu()
{
	return false;
}

void Menu::selectLevel(sf::RenderWindow &window, bool &back, sf::Sprite menuBack, sf::Sprite gameBack, sf::Text LvlOneMsg, sf::Text LvlTwoMsg, sf::Text &selectButton, sf::Font font)
{
    sf::Text text1(font), text2(font), text3(font);
    bool backbounds = false, lvl1bounds = false, lvl2bounds = false;

    text1.setString("Back");
    text1.setCharacterSize(30); // in pixels
    text1.setFillColor(sf::Color::Red); //text color
    text1.setPosition(sf::Vector2f(50, 50)); // text position
    text2.setString("lvl 1");
    text2.setCharacterSize(40); // in pixels
    text2.setFillColor(sf::Color::Red); //text color
    text2.setPosition(sf::Vector2f(100, 100)); // text position
    text3.setString("lvl 2");
    text3.setCharacterSize(40); // in pixels
    text3.setFillColor(sf::Color::Red); //text color
    text3.setPosition(sf::Vector2f(250, 100)); // text position

    back = false;

    while (back == false)
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
                    text1.setFillColor(sf::Color::Green);
                    text1.setCharacterSize(32);

                    // allow us to click back
                    backbounds = true;
                }
                else if (110 < mouseMoved->position.y && mouseMoved->position.y < 145 && 90 < mouseMoved->position.x && mouseMoved->position.x < 175)
                {
                    text2.setFillColor(sf::Color::Green);
                    text2.setCharacterSize(42);

                    lvl1bounds = true;
                }
                else if (110 < mouseMoved->position.y && mouseMoved->position.y < 145 && 245 < mouseMoved->position.x && mouseMoved->position.x < 335)
                {
                    text3.setFillColor(sf::Color::Green);
                    text3.setCharacterSize(42);

                    lvl2bounds = true;
                }
                else
                {
                    // reset back and backbounds if mouse is not hovering over back
                    text1.setFillColor(sf::Color::Red);
                    text1.setCharacterSize(30);
                    text3.setCharacterSize(40); // in pixels
                    text3.setFillColor(sf::Color::Red); //text color
                    text2.setCharacterSize(40); // in pixels
                    text2.setFillColor(sf::Color::Red); //text color
                    backbounds = false;
                    lvl1bounds = false;
                    lvl2bounds = false;
                }

            }

            if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && backbounds) //exit level select
            {
                selectButton.setCharacterSize(50);
                selectButton.setPosition(sf::Vector2f(250, 280));
                selectButton.setFillColor(sf::Color::Red);
                back = true;
                backbounds = false;
            }
            else if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && lvl1bounds)
            {
                text2.setCharacterSize(40); // in pixels
                text2.setFillColor(sf::Color::Red); //text color
                text2.setPosition(sf::Vector2f(100, 100));

                levelOne(window, gameBack, LvlOneMsg);

                lvl1bounds = false;
            }
            else if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && lvl2bounds)
            {
                text3.setCharacterSize(40); // in pixels
                text3.setFillColor(sf::Color::Red); //text color
                text3.setPosition(sf::Vector2f(250, 100)); // text position

                levelTwo(window, gameBack, LvlTwoMsg);

                lvl2bounds = false;
            }

        }

        window.clear();
        window.draw(menuBack);
        window.draw(text1);
        window.draw(text2);
        window.draw(text3);
        window.display();
    }
}

void Menu::displayRules()
{
}
