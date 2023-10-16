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

// Creates the first food
/*void foodOnField()*/;

// Change direction
void changeDirection(char pressKey);

// Directig the snake and updating its direction
void gameRunning();