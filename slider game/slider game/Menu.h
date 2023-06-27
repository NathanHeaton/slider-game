#pragma once

#include "SFML/Graphics.hpp" 
#include "globals.h"
#include <iostream>

class Menu
{

private:
	// assests
	// background for main menu
	sf::Texture m_backgroundTexture;
	sf::Sprite m_backgroundSprite;
	// Text for main menu
	sf::Text m_menuText;
	sf::Font m_font;

public:

	Menu();
	void loadContent();
	void processEvents();
	void update();
	void draw(sf::RenderWindow& t_window);
};

