#include "gameplay.h"

int gameplay()
{
	system("cls");
	bool gameOver;
	bool backToMenu;

	const int whidth = 40;
	const int height = 30;

	int score;
	int currentDirection;
	int lastDirection;

	int tailPositionX[100]{};
	int tailPositionY[100]{};
	int tailLenght{};

	Snake snake;
	Food snakeFood;

	setUp(gameOver, currentDirection, snake, whidth, height, snakeFood, score, backToMenu,lastDirection);
	drawGame();
	do
	{
		if (clock() % 100 == 0)
		{

			drawGame(score);
			drawGame(snake, snakeFood,currentDirection,lastDirection);
			playerInput(currentDirection, backToMenu,lastDirection);
			gameLogic(currentDirection, snake,snakeFood,whidth,height,score,tailLenght);
			if (backToMenu)
			{
				system("cls");
				return 0;
			}
		}
	} while (!gameOver);
	system("cls");
	return 0;
}
void setUp(bool& gameOver, int& currentDirection, Snake& snake, int whidth, int height, Food& snakeFood, int& score, bool& backToMenu,int & lastDirection)
{
	gameOver = false;
	backToMenu = false;
	currentDirection = (int)Directions::Stop;
	snake.positionX = whidth / 2;
	snake.positionY = height / 2;
	snake.isDead = false;
	snakeFood = randomiceSnakeFood(whidth,height);
	score = 0;
	lastDirection = (int)Directions::Right;
}
void drawGame()
{
	gotoXY(0, 0);
	char uperLeftCorner = 201; // esquina superior izquierda ╔ 
	char uperRightCorner = 187; // esquina superior derecha ╗ 
	char lowerLeftCorner = 200; // esquina inferior izquierda ╚ 
	char lowerRightCorner = 188; // esquina inferior Derecha ╝ 
	char horizontalRow = 205;	// linea horizontal ═ 
	char verticalColumn = 186; // linea vertical ║ 
	char uperConection = 203; // conector superior ╦ 
	char lowerConection = 202; // conector inferior ╩ 
	char horizontalConection = 185; // conector derecho ╣ 
	char verticalConection = 204; // conector izquierdo ╠ 
	char crosConection = 206; // interseccion ╬ 
	char empty = 32;	// valor vacio en el tablero 
	char cherry = 162;

	int maxBoardSizeColumns = 42;
	int maxBoardSizeRows = 32;

	cout << "\t""\t" << uperLeftCorner;
	for (int i = 0; i < maxBoardSizeColumns; i++)
	{
		cout << horizontalRow;
	}
	cout << uperRightCorner;
	cout << endl;
	for (int rows = 0; rows < maxBoardSizeRows; rows++)
	{
		cout << "\t""\t";

		cout << verticalColumn;

		for (int columns = 0; columns < maxBoardSizeColumns; columns++)
		{
			if (columns == maxBoardSizeColumns - 1)
			{
				cout << empty << verticalColumn;
			}
			else
			{
				cout << empty;
			}
		}
		cout << endl;
	}
	cout << "\t""\t" << lowerLeftCorner;
	for (int i = 0; i < maxBoardSizeColumns; i++)
	{
		cout << horizontalRow;
	}
	cout << lowerRightCorner;
	cout << endl;
}
void drawGame(int score) 
{
	gotoXY(80,2);
	cout << "Player Score: " << score;
}
void drawGame(Snake snake, Food snakeFood,int currentDirection,int lastDirection)
{
	char empty = 32;	// valor vacio en el tablero 
	char cherry = 162;
	char snakeHeadUp = 118;
	char snakeHeadDown = 94;
	char snakeHeadLeft = 62;
	char snakeHeadRight = 60;
	char snakeBodyChar = 245; 
	int maxBoardSizeColumns = 40;
	int maxBoardSizeRows = 32;
	int xValue = 18;
	int yValue = 1;
	gotoXY(xValue, yValue);
	for (int rows = 0; rows < maxBoardSizeRows; rows++)
	{
		for (int columns = 0; columns < maxBoardSizeColumns; columns++)
		{
			gotoXY(xValue + columns, yValue + rows);
			if (rows == snake.positionY && columns == snake.positionX)
			{
				if (currentDirection == (int)Directions::Up)
				{
					cout << snakeHeadUp;
				}
				else if (currentDirection == (int)Directions::Down)
				{
					cout << snakeHeadDown;
				}
				else if (currentDirection == (int)Directions::Left)
				{
					cout << snakeHeadLeft;
				}
				else if (currentDirection == (int)Directions::Right)
				{
					cout << snakeHeadRight;
				}
				else
				{
					if (lastDirection == (int)Directions::Up)
					{
						cout << snakeHeadUp;
					}
					else if (lastDirection == (int)Directions::Down)
					{
						cout << snakeHeadDown;
					}
					else if (lastDirection == (int)Directions::Left)
					{
						cout << snakeHeadLeft;
					}
					else
					{
						cout << snakeHeadRight;
					}
				}
			}
			else if (rows == snakeFood.foodPositionY && columns == snakeFood.foodPositionX)
			{
				cout << cherry;
			}
			else
			{
				cout << empty;
			}
		}
	}
}
void playerInput(int& currentDirection, bool& backToMenu,int& lastDirection)
{
	char input;
	if (_kbhit())
	{
		input = _getch();
		switch (input)
		{
		case SPACE:
		{
			currentDirection = (int)Directions::Stop;
		}
		break;
		case ARRIBA:
		{
			if (currentDirection == (int)Directions::Down || lastDirection == (int)Directions::Down)
			{
				currentDirection = (int)Directions::Down;
				lastDirection = (int)Directions::Down;
			}
			else
			{
				currentDirection = (int)Directions::Up;
				lastDirection = (int)Directions::Up;
			}
		}
		break;
		case IZQUIERDA:
		{
			if (currentDirection == (int)Directions::Right || lastDirection == (int)Directions::Right)
			{
				currentDirection = (int)Directions::Right;
				lastDirection = (int)Directions::Right;
			}
			else
			{
				currentDirection = (int)Directions::Left;
				lastDirection = (int)Directions::Left;
			}
		}
		break;
		case DERECHA:
		{
			if (currentDirection == (int)Directions::Left || lastDirection == (int)Directions::Left)
			{
				currentDirection = (int)Directions::Left;
				lastDirection = (int)Directions::Left;
			}
			else
			{
				currentDirection = (int)Directions::Right;
				lastDirection = (int)Directions::Right;
			}
		}
		break;
		case ABAJO:
		{
			if (currentDirection == (int)Directions::Up || lastDirection == (int)Directions::Up)
			{
				currentDirection = (int)Directions::Up;
				lastDirection = (int)Directions::Up;
			}
			else
			{
				currentDirection = (int)Directions::Down;
				lastDirection = (int)Directions::Down;
			}
		}
		break;
		case ESC:
		{
			backToMenu = true;
		}
		break;
		default:
			break;
		}
	}
}
void gameLogic(int& currentDirection, Snake& snake, Food& snakeFood, const int whidth, const int height,int & score,int& tailLenght)
{
	switch (currentDirection)
	{
	case (int)Directions::Stop:
		snake.positionX;
		snake.positionY;
		break;
	case (int)Directions::Left:
		snake.positionX--;
		break;
	case (int)Directions::Right:
		snake.positionX++;
		break;
	case (int)Directions::Up:
		snake.positionY--;
		break;
	case (int)Directions::Down:
		snake.positionY++;
		break;
	default:
		break;
	}

	if (snake.positionX > whidth)
	{
		snake.positionX = 0;
	}
	else if (snake.positionX < 0)
	{
		snake.positionX = whidth;
	}
	if (snake.positionY < 0)
	{
		snake.positionY = height;
	}
	else if (snake.positionY > height)
	{
		snake.positionY = 0;
	}

	if (snake.positionX == snakeFood.foodPositionX && snake.positionY == snakeFood.foodPositionY)
	{
		score = score++;
		snakeFood = randomiceSnakeFood(whidth,height);
		tailLenght++;
	}
}
Food randomiceSnakeFood(int whidth, int height)
{
	srand(time(NULL));
	Food aux;
	aux.foodPositionX = rand() % whidth;
	aux.foodPositionY = rand() % height;
	return aux;
}