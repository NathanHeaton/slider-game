#pragma once


#include "SFML/Graphics.hpp" 
#include <iostream>
#include <cstdlib>  // include support for randomizing
#include <ctime>   // supports ctime function
#include "globals.h"
#include "Menu.h"
#include "Player.h"
#include "Food.h"

class Game
{
	Menu mainMenu;
	Player fish;
	Food food[MAX_FOOD];
private:

	sf::RenderWindow m_window;
	int m_screen = menu;//stores which screen we should be on

	// backgrounds and screens
	sf::RectangleShape m_sea;// temp background
	sf::RectangleShape m_pauseOverlay;// pause screen
	sf::RectangleShape m_playButton; // button to switch to gameplay

	// food stuff
	int m_foodSpawnTimer = 0;
	int m_activeFood = 0; // number of currently active piece of food


public:	  // declaration of member functions	
	Game(); // default constructor
	void loadContent();
	void run();
	void processEvents();
	void processKeys();
	void update();
	void draw();
	void SpawnFood();// decides when food should be spawned
	void foodPlayerCollision();// if player touches food

};

