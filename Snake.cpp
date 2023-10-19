#include <iostream>
#include "Snake.h"

enum direction
{
	STOP = 0,
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

// Snake detail
int tailX[200];
int tailY[200];
int snakeBody;

// Random food generator
int foodX = rand() % (row - 2);
int foodY = rand() % (colum - 2);

int score = 0;

// If game is running
bool GameOver;


void printField()
{
	clearScreen();

	// Placed top wall
	for (int i = 0; i < row; i++)
	{
		std::cout << "=";
	}
	std::cout << "\n";

	// Places right and left wall
	for (int i = 0; i < colum; i++)
	{
		for (int j = 0; j < row; j++)
		{
			// Left wall
			if (j == 0)
			{
				std::cout << "|";
			}
			// Right wall
			if (j == row - 1)
			{
				std::cout << "|";
			}
			// Places the initial head location in middle of map
			if (i == headX && j == headY)
			{
				std::cout << "O";
			}
			// Places food randomly on the map
			else if (i == foodX && j == foodY)
			{
				std::cout << "~";
			}
			// If you pick up food, the snake gets an extra body if it doesn't draw an empty field
			else
			{
				bool addSnakeTail = true;
				for (int k = 0; k < snakeBody; k++)
				{
					if (tailX[k] == i && tailY[k] == j)
					{
						std::cout << "o";
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

	// Places bottom wall
	for (int i = 0; i < row; i++)
	{
		std::cout << "=";
	}
	std::cout << "\n";

	std::cout << "Your score: " << score << "\n";

}

void clearScreen()
{
	system("cls");
}

void gameRunning()
{
	
	GameOver = false;
	snakeMovement = STOP;

	while (!GameOver)
	{
		printField();
		changeDirection();
		moveSnake();
	}

}

void changeDirection()
{
	// If the key is pressed
	if (_kbhit)
	{
		switch (_getch())
		{
		case 'w':
			snakeMovement = UP;
			break;
		case 's':
			snakeMovement = DOWN;
			break;
		case 'd':
			snakeMovement = RIGHT;
			break;
		case 'a':
			snakeMovement = LEFT;
			break;
		default:
			break;
		}

	}
}

void moveSnake()
{
	// Adding body to snake
	for (int i = snakeBody - 1; i > 0; i--)
	{
		tailX[i] = tailX[i - 1];
		tailY[i] = tailY[i - 1];
	}
	
	tailX[0] = headX;
	tailY[0] = headY;

	switch (snakeMovement)
	{
	case UP:
		headX--;
		break;
	case DOWN:
		headX++;
		break;
	case RIGHT:
		headY++;
		break;
	case LEFT:
		headY--;
		break;
	default:
		break;
	}

	// When you out of the border --> Game Over
	if (headX < 0 || headX > row - 1 || headY < 0 || headY > colum - 2)
	{
		GameOver = true;
	}
	
	// If you hit your tail --> Game Over
	for (int i = 0; i < snakeBody; i++)
	{
		if (tailX[i] == headX && tailY[i] == headY)
		{
			GameOver = true;
		}
	}

	// When you collected the food --> get score, food is randomly generated again and snake body incrised
	if (headX == foodX && headY == foodY)
	{
		score += 1;
		foodX = rand() % (row - 2);
		foodY = rand() % (colum - 2);
		snakeBody++;
	}
}