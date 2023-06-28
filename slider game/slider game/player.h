// Player class declaration


#pragma once
#include "SFML/Graphics.hpp" 
#include "Globals.h"
#include <iostream>


class Player
{
	// private data members
	sf::Texture m_playerTexture;
	sf::Sprite m_playerSprite;

	//movement
	float m_velo{ 3.5 };
	sf::Vector2f m_location{};
	int m_direction;
	bool m_moving=false;

	bool m_speedBuff = 0;

	//animation 

	float m_frameIncremnet{ 0.2f };

	float m_frame{ 0 };

	int m_row = 0;

	int m_col = 0;

	int m_idleCount = 0; //after 5 frames the player is set to idle of there is no input
public:
	Player();
	void setupSprite();
	sf::Sprite getPlayerSprite();
	bool ismoving();
	void movement(int t_direction);
	void animation(int t_direction);
	void keepInBounds();
	void Update();

};
