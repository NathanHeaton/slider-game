#include "player.h"

Player::Player()
{
	setupSprite();
	m_growAmount = 0.5;
	m_size = 3;
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
		m_playerSprite.setScale(m_size, m_size);
	}	
	if (m_direction == SOUTH)
	{
		m_location.y += m_velo;
	}	
	if (m_direction == WEST)
	{
		m_location.x -= m_velo;
		m_playerSprite.setScale(-m_size, m_size);// flisp sprite along y axis
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
	// changes the texture that is shown depending on the frame
	m_playerSprite.setTextureRect(sf::IntRect(m_col * FISH_WIDTH, 0, FISH_WIDTH, FISH_HEIGHT));//changes the frame
}

void Player::keepInBounds() // makes sure player stays within the game screen
{
	if (m_location.x >= SCREEN_WIDTH - FISH_WIDTH)
	{
		m_location.x = SCREEN_WIDTH - FISH_WIDTH;
	}
	if (m_location.x < 0)
	{
		m_location.x = 0;
	}
	if (m_location.y > SCREEN_HEIGHT - FISH_HEIGHT)
	{
		m_location.y = SCREEN_HEIGHT - FISH_HEIGHT;
	}
	if (m_location.y < 0)
	{
		m_location.y = 0;
	}
	m_playerSprite.setPosition(m_location);

}

void Player::Update()
{
	if (m_moving)
	{
		keepInBounds();
		animation(m_direction);
		m_moving = false;
	}
}

void Player::grow()
{
	m_size += m_growAmount;
	if (m_direction == WEST) // if sprite is facing other direction increase size on that side to
	{
		m_playerSprite.setScale(-m_size, m_size);
	}
	else
	{
		m_playerSprite.setScale(m_size, m_size);
	}

}

