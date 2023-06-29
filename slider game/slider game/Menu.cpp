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
	m_menuText.setCharacterSize(100U);
	m_menuText.setFont(m_font);
	m_menuText.setFillColor(sf::Color::White);
	m_menuText.setOutlineColor(sf::Color::Black);
	m_menuText.setOutlineThickness(6u);
	m_menuText.setPosition(sf::Vector2f((SCREEN_WIDTH / 2)-200, 200));
	m_menuText.setString("Main Menu");

	m_playButton.setFillColor(sf::Color::Black);
	m_playButton.setPosition(sf::Vector2f((SCREEN_WIDTH / 2) - 100, 400));
	m_playButton.setSize(sf::Vector2f(200, 100));

}

int Menu::processEvents(sf::Event t_event)
{
	m_mousePosX = t_event.mouseButton.x;
	m_mousePosy = t_event.mouseButton.y;

	if (m_mousePosX >= m_playButton.getPosition().x && m_mousePosX <= 200+(SCREEN_WIDTH / 2) && m_mousePosy >= 400 && m_mousePosy <=500)
	{
		return 2;
	}


	return 0;
}

void Menu::update()
{
}

void Menu::draw(sf::RenderWindow& t_window)
{
	t_window.clear();


	t_window.draw(m_backgroundSprite);
	t_window.draw(m_menuText);
	t_window.draw(m_playButton);
	t_window.display();
}
