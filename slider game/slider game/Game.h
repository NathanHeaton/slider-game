#pragma once


#include "SFML/Graphics.hpp" 
#include <iostream>
#include <cstdlib>  // include support for randomizing
#include <ctime>   // supports ctime function
#include "globals.h"
#include "Menu.h"

enum menus {
	none,
	menu,
	gameplay,
	pause,
	instruction,
	gameOver


};
class Game
{
	Menu mainMenu;

private:

	sf::RenderWindow m_window;
	int m_screen = menu;//stores which screen we should be on




public:	  // declaration of member functions	
	Game(); // default constructor
	void loadContent();
	void run();
	void processEvents();
	void update();
	void draw();

};

