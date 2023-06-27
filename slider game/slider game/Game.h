#pragma once


#include "SFML/Graphics.hpp" 
#include <iostream>
#include <cstdlib>  // include support for randomizing
#include <ctime>   // supports ctime function
#include "globals.h"

class Game
{


private:
	sf::RenderWindow m_window;





public:	  // declaration of member functions	
	Game(); // default constructor
	void loadContent();
	void run();
	void processEvents();
	void update();
	void draw();

};

