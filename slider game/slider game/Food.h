#pragma once
#include "SFML/Graphics.hpp" 
#include "Globals.h"
#include <iostream>

class Food
{


private:
	// assests
	sf::RectangleShape m_foodPellet; // button to switch to gameplay
	
	sf::Vector2f m_location;
	bool m_active; // stores state of food 
	int m_despawnTimer; 


public:

	Food();
	void loadContent();
	void spawn();
	void despawn();
	void update();
	sf::RectangleShape getFood();
	bool isActive();

};

