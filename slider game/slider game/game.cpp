//////////////////////////////////////////////////////////// 
// include correct library file for release and debug versions
//////////////////////////////////////////////////////////// 

#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-network-d.lib") 
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#endif 
#pragma comment(lib,"opengl32.lib") 
#pragma comment(lib,"glu32.lib")




#include "Game.h"   // include Game header file
#include <ctime>
#include <cstdlib>

int main()
{
	srand(time(nullptr));
	Game aGame;
	aGame.loadContent();
	aGame.run();

	return 0;
}

Game::Game() : m_window(sf::VideoMode(static_cast<int>(SCREEN_WIDTH), static_cast<int>(SCREEN_HEIGHT)), "Slider Game", sf::Style::Default)
// Default constructor
{
}

void Game::loadContent()
// Load the font file & setup the message string
{
	m_sea.setFillColor(sf::Color(59, 80, 255));
	m_sea.setPosition(0, 0);
	m_sea.setSize(sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));

	m_pauseOverlay.setFillColor(sf::Color(50, 50, 50, 100));
	m_pauseOverlay.setPosition(0, 0);
	m_pauseOverlay.setSize(sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
}

void Game::run()
// This function contains the main game loop which controls the game. 
{

	srand((int)time(nullptr)); // set the seed once

	sf::Time timePerFrame = sf::seconds(1.0f / 60.0f);

	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	// the clock object keeps the time.
	sf::Clock clock;


	clock.restart();

	while (m_window.isOpen())
	{
		processEvents();//checks constantly
		// check if the close window button is clicked on
		sf::Event event;
		while (m_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				m_window.close();
		}

		//get the time since last update and restart the clock
		timeSinceLastUpdate += clock.restart();

		//update every 60th of a second
		//only when the time since last update is greater than 1/60 update the world.
		if (timeSinceLastUpdate > timePerFrame)
		{

			update();
			draw();

			// reset the timeSinceLastUpdate to 0 
			timeSinceLastUpdate = sf::Time::Zero;
		}
	}  // end while loop

}

void Game::processEvents()
{

	sf::Event newEvent;
	while (m_window.pollEvent(newEvent))
	{
		if (sf::Event::MouseButtonPressed == newEvent.type) //user mouse down
		{
			if (m_screen == menu)
			{
				if (mainMenu.processEvents(newEvent) == 2)// process mouse presses in main menu if 2 is returned gameplay button was clicked
				{
					m_screen = gameplay;
				}
			}

		}


	}





}

void Game::processKeys()
{
	if (m_screen == gameplay)
	{
		//Wasd movement for fish
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			fish.movement(NORTH);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			fish.movement(EAST);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			fish.movement(SOUTH);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			fish.movement(WEST);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) // if escape key is presed game goes back to main menu
		{
			m_screen = pause;
		}
	}
	// when game is paused
	if (m_screen == pause)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::C)) // if escape key is presed game goes back to main menu
		{
			m_screen = gameplay;
		}
	}
}

void Game::update()
{
	processKeys();
	// updates the fishes animations and boudary checks
	fish.Update();

}

void Game::draw()
{
	
	if (m_screen == menu)
	{
		mainMenu.draw(m_window);
	}
	else // screen is on gameplay/pause
	{
		m_window.clear();
		if (m_screen == gameplay || m_screen == pause)//renders game assest when paused or while playing
		{

			m_window.draw(m_sea);
			m_window.draw(fish.getPlayerSprite());

		}
		if (m_screen == pause) // renders pause overlay on top of gameplay
		{
			m_window.draw(m_pauseOverlay);

		}
		m_window.display();
	}
}
