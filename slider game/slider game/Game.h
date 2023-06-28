#pragma once


#include "SFML/Graphics.hpp" 
#include <iostream>
#include <cstdlib>  // include support for randomizing
#include <ctime>   // supports ctime function
#include "globals.h"
#include "Menu.h"
#include "Player.h"
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
	Player fish;

private:

	sf::RenderWindow m_window;
	int m_screen = gameplay;//stores which screen we should be on




public:	  // declaration of member functions	
	Game(); // default constructor
	void loadContent();
	void run();
	void processEvents();
	void processKeys();
	void update();
	void draw();

};

