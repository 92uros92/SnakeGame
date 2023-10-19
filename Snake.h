#pragma once
#include <cstdlib>
#include <time.h>
#include <conio.h>


/*
	FUNCTIONS
*/

// Clears the screen
void clearScreen();

// Prints the map to console
void printField();

// Change direction
void changeDirection();

// Directig the snake and updating its direction
void gameRunning();

// Main function of the game
void moveSnake();
