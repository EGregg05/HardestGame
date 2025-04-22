#pragma once
class Menu
{
public:
	Menu();

	bool isMainMenu();
	bool isPauseMenu();
	int selectLevel();

private:
	bool mainMenu;
	bool pauseMenu;
	int level;
};

