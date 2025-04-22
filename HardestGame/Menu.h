#pragma once
class Menu
{
public:
	Menu();

	//need to return from main menu function bool values for: play, select level, rules, and exit
	bool isMainMenu();
	bool isPauseMenu();
	int selectLevel();
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

