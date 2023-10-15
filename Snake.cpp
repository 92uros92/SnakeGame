#include <iostream>
#include "Snake.h"

// Map detail
const int row = 25;
const int colum = 25;
int headX = row / 2;
int headY = colum / 2;
const int size = row * colum;
int map[size];
//int tailX[size];
//int tailY[size];
int nTail = 25;

// Random foof generator
int foodX = rand() % row;
int foodY = rand() % colum;

// if game is running
bool GameOver;


void printField()
{
	clearScreen();

	for (int i = 0; i < row; i++)
	{
		std::cout << "=";
	}
	std::cout << "\n";

	for (int i = 0; i < colum; i++)
	{
		for (int j = 0; j < row; j++)
		{
			if (j == 0)
			{
				std::cout << "|";
			}
			if (i == headY && j == headX)
			{
				std::cout << "O";
			}
			if (j == row - 1)
			{
				std::cout << "|";
			}
			else
				std::cout << " ";

		}
		std::cout << "\n";
	}

	for (int i = 0; i < row; i++)
	{
		std::cout << "=";
	}
	std::cout << "\n";

}

void clearScreen()
{
	system("cls");
}
