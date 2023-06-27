#include "Menu.h"


Menu::Menu()
{
	loadContent();


}

void Menu::loadContent()
{
	if (!m_backgroundTexture.loadFromFile("ASSETS/IMAGES/tempBackground.png"))
	{
		std::cout << "error with bullet file";
	}
	// set up bullet
	m_backgroundSprite.setTexture(m_backgroundTexture);
	m_backgroundSprite.setTextureRect(sf::IntRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT));
	m_backgroundTexture.setRepeated(true);
	m_backgroundSprite.setScale(2.1, 2.1);

	// sets up text
	if (!m_font.loadFromFile("ASSETS/FONTS/BebasNeue.otf"))
	{
		std::cout << "error with font file";
	}

}

void Menu::processEvents()
{
}

void Menu::update()
{
}

void Menu::draw(sf::RenderWindow& t_window)
{
	t_window.clear();


	t_window.draw(m_backgroundSprite);
	t_window.display();
}