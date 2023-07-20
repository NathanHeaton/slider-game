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
	// button in pause menu to go back to gameplpay
	m_playButton.setFillColor(sf::Color::Black);
	m_playButton.setPosition(sf::Vector2f((SCREEN_WIDTH / 2) - 100, 400));
	m_playButton.setSize(sf::Vector2f(200, 100));

	//sets different food types
	for (int i = 0; i < MAX_FOOD; i++)// loops for max amount of food
	{
		speedFruits[i].setType(speedFruit);// sets food to be of type speed fruit
		food[i].setType(pellet);// sets food to be pellet
	}
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
			if (m_screen == pause) // code reused as button is in the same place
			{
				if (mainMenu.processEvents(newEvent) == 2)// process mouse presses in pause menu if 2 is returned gameplay button was clicked
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

		// if player is evolving
		if (fish.isEvolving())
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
			{
				fish.Evolve(1); // first evolution path
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
			{
				fish.Evolve(2); // second evolution path
			}
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

	if (m_screen == gameplay)//renders game assest when paused or while playing
	{
		// updates the fishes animations and boudary checks
		fish.Update();
		SpawnFood();
		for (int i = 0; i <= m_activeFood; i++)// loops for active amount of food
		{
			food[i].update();
			speedFruits[i].update();
		}
		foodPlayerCollision();// checks if player collide with food
	}



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

			for (int i = 0; i <= m_activeFood; i++)// loops for active amount of food
			{
				if (food[i].isActive())// checks if the food is active
				{
				m_window.draw(food[i].getFood());// gets food sprite and reders it

				}
				if (speedFruits[i].isActive())// checks if the food is active
				{
					m_window.draw(speedFruits[i].getFood());// gets food sprite and reders it

				}
			}

		}
		if (m_screen == pause) // renders pause overlay on top of gameplay
		{
			m_window.draw(m_pauseOverlay);
			m_window.draw(m_playButton);
		}
		m_window.display();
	}
}

void Game::SpawnFood()
{
	for (int i = 0; i <= m_activeFood; i++)// loops for active amount of food
	{
		//spawns food pellets
		if (m_foodSpawnTimer <= 0)
		{
			// pellets
			if (!food[i].isActive())
			{
				food[i].spawn();
			}
			else if (m_activeFood < MAX_FOOD - 1)// if all of the food is active spawn new food
			{
				food[m_activeFood].spawn();
				m_activeFood++; // increase active food
			}

			// speed fruit
			if (!speedFruits[i].isActive())
			{
				speedFruits[i].spawn();
			}
			else if (m_activeFood < MAX_FOOD - 1)// if all of the food is active spawn new food
			{
				speedFruits[m_activeFood].spawn();
				m_activeFood++; // increase active food
			}//

			m_foodSpawnTimer = rand() % 30 + 30;
			break;// only spawns 1 piece of food
		}
		else
		{
			break; // if timer is not 0 or the max amount of food is reached breaks out
		}
	}

	m_foodSpawnTimer--;

}

void Game::foodPlayerCollision()
{
	for (int i = 0; i <= m_activeFood; i++)// loops for all food
	{
		if (food[i].isActive())
		{
			if (fish.getPlayerSprite().getGlobalBounds().intersects(food[i].getFood().getGlobalBounds()))// checks is player and any food intercect
			{
				food[i].despawn();// despawns collect food
				fish.grow();// grows player
			}
		}
	}



}
