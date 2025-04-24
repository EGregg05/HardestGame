#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stack>
#include <ctime>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Sprite.hpp"
#include "Level.hpp"

class Menu
{
public:
	Menu()
	{
		mainMenu = false;
		pauseMenu = false;
		level = 0;
	}

	//need to return from main menu function bool values for: play, select level, rules, and exit
	bool isMainMenu(sf::RenderWindow& window, sf::Sprite gameBack, sf::Sprite menuBack, sf::Font font);
	void selectLevel(sf::RenderWindow& window, bool& back, sf::Sprite menuBack, sf::Sprite gameBack, sf::Text LvlOneMsg, sf::Text LvlTwoMsg, sf::Text LvlThreeMsg, sf::Text& selectButton, sf::Font font);
	bool isPauseMenu();
	void displayRules();


private:
	//used in main menu function
	//use in place of if else statements???
	//bool isPlay();
	//bool isSelectLevel();
	//bool isRule();
	//bool isExit();


	bool mainMenu;
	bool pauseMenu;
	int level;
};

