// Player class declaration


#pragma once
#include "SFML/Graphics.hpp" 
#include "Globals.h"
#include <iostream>


class Player
{
	// private data members
	sf::Texture m_playerTexture;// base fish texture with no evolutions
	sf::Texture m_speedEvolution1Texture;// Texture for fish if he evolves for speed
	sf::Sprite m_playerSprite;

	//movement
	float m_velo{ 6.5 };
	sf::Vector2f m_location{};
	int m_direction;
	bool m_moving=false;

	//animation 

	float m_frameIncremnet{ 0.2f };

	float m_frame{ 0 };

	int m_row = 0;

	int m_col = 0;

	// eating
	float m_growAmount;
	float m_size;

	// evolutions

	bool m_evolving = false;
	int m_evolveCounter = 0; // stores how many times player has evolved
	bool m_evolveFlash = false;

public:
	Player();
	void setupSprite();
	sf::Sprite getPlayerSprite();
	bool ismoving();
	void movement(int t_direction);
	void animation(int t_direction);
	void keepInBounds();
	void Update();
	void grow();// player grows when food is eaten
	bool isEvolving(); // get the state of evolution
	void Evolve(int t_option); // handles evolutions and changes players stats
};
