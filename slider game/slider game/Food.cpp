#include "Food.h"

Food::Food()
{
	loadContent();
	m_active = false;
	m_despawnTimer = 200;

}

void Food::loadContent()
{
	//decalartion
	m_foodPellet.setFillColor(sf::Color(230, 230, 40));

}

void Food::setType(foods t_type) // turns food into correct type
{
	m_type = t_type;

	if (m_type == speedFruit)// if the food type is speed fruit
	{
		m_foodPellet.setFillColor(sf::Color(230, 40, 40));// makes food into speed fruit / red
	}
	else
	{
		m_foodPellet.setFillColor(sf::Color(230, 230, 40));// makes food into pellet / yellow
	}
}

void Food::spawn()
{
	//decalartion
	int foodSize = 0;
	int xPos = 0;
	int yPos = 0;

	if (m_type == speedFruit)
	{
		foodSize = rand() % 10 + 10;// randomise food size
	}
	else if (m_type == pellet)
	{
		foodSize = rand() % 10 + 5;// randomise food size
	}

	// random position along the screen minus the very edges
	xPos = (rand() % ((int)SCREEN_WIDTH - 10)) + 20; 
	yPos = (rand() % ((int)SCREEN_HEIGHT - 10)) + 20;

	m_location = sf::Vector2f(xPos, yPos);

	// sets things food pellet atrbites
	m_foodPellet.setSize(sf::Vector2f(foodSize, foodSize));
	m_foodPellet.setPosition(m_location);
	m_active = true;
}

void Food::despawn()
{
	m_despawnTimer = 200;
	m_active = false;

}


void Food::update()
{
	if (m_despawnTimer <= 0)
	{
		despawn(); // despawns food after timer runs out
		
	}
	m_despawnTimer--;
}

sf::RectangleShape Food::getFood()
{
	return m_foodPellet;
}

bool Food::isActive()
{
	return m_active;
}
