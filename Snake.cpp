#include <iostream>
#include "Snake.h"

enum class direction
{
	UP,
	DOWN,
	RIGHT,
	LEFT
};
direction snakeMovement;


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
int snakeBody;


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
			if (j == row - 2)
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
			{
				bool addSnakeTail = true;
				for (int k = 0; k < snakeBody; k++)
				{
					if (tailX[k] == i && tailY[k] == j)
					{
						std::cout << "°";
						addSnakeTail = false;
					}
					
				}
				if (addSnakeTail)
				{
					std::cout << " ";
				}
			}

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

	updateSnakePosition();

}

void changeDirection(char pressKey)
{
	switch (pressKey)
	{
	case 'w':
		snakeMovement = direction::UP;
		break;
	case 's':
		snakeMovement = direction::DOWN;
		break;
	case 'd':
		snakeMovement = direction::RIGHT;
		break;
	case 'a':
		snakeMovement = direction::LEFT;
		break;
	default:
		break;
	}
}

void moveSnake(int upDown, int rightLeft)
{
	int newHeadX = headX + upDown;
	int newHeadY = headY + rightLeft;

	headX = newHeadX;
	headY = newHeadY;
}

void updateSnakePosition()
{
	switch (snakeMovement)
	{
	case direction::UP:
		moveSnake(1, 0);
		break;
	case direction::DOWN:
		moveSnake(-1, 0);
		break;
	case direction::RIGHT:
		moveSnake(0, 1);
		break;
	case direction::LEFT:
		moveSnake(0, -1);
		break;
	default:
		break;
	}

	//if (x > row || )
}