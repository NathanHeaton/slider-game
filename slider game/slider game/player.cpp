#include "player.h"

Player::Player()
{
	setupSprite();
}

void Player::setupSprite()
{
	// loads player sprite
	if (!m_playerTexture.loadFromFile("ASSETS/IMAGES/fish-Sheet.png"))
	{
		std::cout << "error with fish file\n";
	}
	m_playerSprite.setTexture(m_playerTexture);
	m_playerSprite.setOrigin(sf::Vector2f(FISH_WIDTH / 2.0, FISH_HEIGHT / 2.0));
	m_playerSprite.setTextureRect(sf::IntRect(0, 0, FISH_WIDTH, FISH_HEIGHT));
	m_playerSprite.setScale(3, 3);
	m_location = sf::Vector2f(500, 500);
	m_playerSprite.setPosition(m_location);
}

sf::Sprite Player::getPlayerSprite()
{
	return m_playerSprite;
}

bool Player::ismoving()
{
	return m_moving;
}

void Player::movement(int t_direction)
{
	m_direction = t_direction;
	// moves fish by velocity depending on input
	if (m_direction == NORTH)
	{
		m_location.y -= m_velo;
	}
	if (m_direction == EAST)
	{
		m_location.x += m_velo;
		m_playerSprite.setScale(3, 3);
	}	
	if (m_direction == SOUTH)
	{
		m_location.y += m_velo;
	}	
	if (m_direction == WEST)
	{
		m_location.x -= m_velo;
		m_playerSprite.setScale(-3, 3);
	}

	m_playerSprite.setPosition(m_location);
	//animation(m_direction);
	m_moving = true;
}

void Player::animation(int t_direction)
{
	int frame = 0;
	m_frame += m_frameIncremnet;
	frame = static_cast<int>(m_frame);


	m_col = frame;//sets the col to the next one across

	if (frame == 4)
	{
		m_frame = 0;
		frame = 0;
		m_col = 0;
	}

	m_playerSprite.setTextureRect(sf::IntRect(m_col * FISH_WIDTH, 0, FISH_WIDTH, FISH_HEIGHT));//changes the frame
}

void Player::keepInBounds()
{


}

void Player::Update()
{
	if (m_moving)
	{
		animation(m_direction);
		m_moving = false;
	}
}

