#include <iostream>
#include "Snake.h"

// Map detail
const int row = 25;
const int colum = 25;
int headX = row / 2;
int headY = colum / 2;
const int size = row * colum;
int map[size];

// Snake detail
int tailX[size];
int tailY[size];
int update;
int upDown;
int rightLeft;


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
			if (j == row - 1)
			{
				std::cout << "|";
			}
			if (i == headX && j == headY)
			{
				std::cout << "O";
			}
			else if (i == foodX && j == foodY)
			{
				std::cout << "~";
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

//void foodOnField()
//{
//	if (foodX)
//}

void changeDirection(char pressKey)
{
	switch (pressKey)
	{
	case 'w':
		std::cout << "UP";
		break;
	case 's':
		std::cout << "DOWN";
		break;
	case 'd':
		std::cout << "RIGHT";
		break;
	case 'a':
		std::cout << "LEFT";
		break;
	default:
		break;
	}
}

void gameRunning()
{
	GameOver = false;
	while (!GameOver)
	{
		if (_kbhit)
		{
			changeDirection(_getch());
		}
	}
	


}