// Contains the game globals
#pragma once
#include "SFML/Graphics.hpp" 
//The direction the sprite is moving in
const int static WEST = 1;
const int static EAST = 2;
const int static NORTH = 3; // direction north
const int static SOUTH = 4;
const int static IDLE = 0; // if no input

const float SCREEN_WIDTH = 1880;   // the size of the screen in pixels used in the game
const float SCREEN_HEIGHT = 980;

const int FISH_WIDTH = 64;
const int FISH_HEIGHT = 48;

enum menus {
	none,
	menu,
	gameplay,
	pause,
	instruction,
	gameOver


};