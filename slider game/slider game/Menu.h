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

	// buttons
	sf::RectangleShape m_playButton; // button to switch to gameplay

	int m_mousePosX = 0;
	int m_mousePosy = 0;

public:

	Menu();
	void loadContent();
	int processEvents(sf::Event t_event);
	void update();
	void draw(sf::RenderWindow& t_window);
};

