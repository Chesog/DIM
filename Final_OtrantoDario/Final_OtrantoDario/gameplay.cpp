#include "gameplay.h"

int gameplay()
{
	system("cls");
	bool gameOver;
	bool backToMenu;

	const int whidth = 42;
	const int height = 33;

	int score;
	int currentDirection;
	int lastDirection;

	Snake snake;
	Food snakeFood;

	setUp(gameOver, currentDirection, snake, whidth, height, snakeFood, score, backToMenu, lastDirection);
	drawGame();
	do
	{
		
		if (clock() % 100 == 0)
		{

			drawGame(score);
			drawGame(snake, snakeFood, currentDirection, lastDirection);
			playerInput(currentDirection, backToMenu, lastDirection);
			gameLogic(currentDirection, snake, snakeFood, whidth, height, score,lastDirection);
			if (backToMenu)
			{
				system("cls");
				return 0;
			}
			if (snake.isDead)
			{
				gameOver = true;
			}
		}
	} while (!gameOver);
	int playerAnsw;
	drawGame(snake, snakeFood, currentDirection, lastDirection);
	gotoXY(90,20);
	cout << "Volver a Jugar ?" << endl;
	gotoXY(90, 21);
	cout << "1 = Si" << endl;
	gotoXY(90, 22);
	cout << "2 = No" << endl;
	cin >> playerAnsw;
	if (playerAnsw == 1)
	{
		return 1;
	}
	else
	{
		system("cls");
		return 0;
	}
}
void setUp(bool& gameOver, int& currentDirection, Snake& snake, int whidth, int height, Food& snakeFood, int& score, bool& backToMenu, int& lastDirection)
{
	gameOver = false;
	backToMenu = false;
	currentDirection = (int)Directions::Stop;
	snake.positionX = whidth / 2;
	snake.positionY = height / 2;
	snake.isDead = false;
	snake.tailLenght = 4;
	snakeFood = randomiceSnakeFood(whidth, height);
	score = 0;
	lastDirection = (int)Directions::Right;
}
void drawGame()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	//SetConsoleTextAttribute(h, 14);
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

	int maxBoardSizeColumns = 44;
	int maxBoardSizeRows = 33;

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
	gotoXY(65,0);
	cout <<   "  ________   _____  ___         __       __   ___    _______    " << endl;
	gotoXY(65, 1);
	cout << R"( /"       ) (\"   \|"  \       /""\     |/"| /  ")  /"     "|    )" << endl;
	gotoXY(65, 2);
	cout << R"((:   \___/  |.\\   \    |     /    \    (: |/   /  (: ______)    )" << endl;
	gotoXY(65, 3);
	cout << R"( \___  \    |: \.   \\  |    /' /\  \   |    __/    \/    |      )" << endl;
	gotoXY(65, 4);
	cout << R"(  __/  \\   |.  \    \. |   //  __'  \  (// _  \    // ___)_     )" << endl;
	gotoXY(65, 5);
	cout << R"( /" \   :)  |    \    \ |  /   /  \\  \ |: | \  \  (:      "|    )" << endl;
	gotoXY(65, 6);
	cout << R"((_______/    \___|\____\) (___/    \___)(__|  \__)  \_______)    )" << endl;

	gotoXY(65, 8);
	cout << R"(  _______   ________     __      ___________    __         ______     _____  ___   )" << endl;
	gotoXY(65, 9);
	cout << R"( /"     "| |"      "\   |" \    ("     _   ")  |" \       /    " \   (\"   \|"  \  )" << endl;
	gotoXY(65, 10);
	cout << R"((: ______) (.  ___  :)  ||  |    )__/  \\__/   ||  |     // ____  \  |.\\   \    | )" << endl;
	gotoXY(65, 11);
	cout << R"( \/    |   |: \   ) ||  |:  |       \\_ /      |:  |    /  /    ) :) |: \.   \\  | )" << endl;
	gotoXY(65, 12);
	cout << R"( // ___)_  (| (___\ ||  |.  |       |.  |      |.  |   (: (____/ //  |.  \    \. | )" << endl;
	gotoXY(65, 13);
	cout << R"((:      "| |:       :)  /\  |\      \:  |      /\  |\   \        /   |    \    \ | )" << endl;
	gotoXY(65, 14);
	cout << R"( \_______) (________/  (__\_|_)      \__|     (__\_|_)   \"_____/     \___|\____\) )" << endl;
	gotoXY(90, 16);
	cout << "Player Score: " << score;
}
void drawGame(Snake snake, Food snakeFood, int currentDirection, int lastDirection)
{
	char empty = 32;	// valor vacio en el tablero 
	char cherry = 162;
	char snakeDeadHead = 120;
	char snakeHeadUp = 118;
	char snakeHeadDown = 94;
	char snakeHeadLeft = 62;
	char snakeHeadRight = 60;
	char snakeBodyChar = 245;
	char snakeDeadBodyChar = 88;
	int maxBoardSizeColumns = 42;
	int maxBoardSizeRows = 33;
	int xValue = 17;
	int yValue = 1;
	gotoXY(xValue, yValue);
	for (int rows = 0; rows < maxBoardSizeRows; rows++)
	{
		for (int columns = 0; columns < maxBoardSizeColumns; columns++)
		{
			gotoXY(xValue + columns, yValue + rows);
			if (rows == snake.positionY && columns == snake.positionX)
			{
				if (!snake.isDead)
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
				else
				{
					cout << snakeDeadHead;
				}
			}
			else if (rows == snakeFood.foodPositionY && columns == snakeFood.foodPositionX)
			{
				cout << cherry;
			}
			else
			{
				bool print = false;
				for (int i = 0; i < snake.tailLenght; i++)
				{
					print = false;
					if (snake.tailPositionX[i] == columns && snake.tailPositionY[i] == rows)
					{
						if (snake.isDead)
						{
							cout << snakeDeadBodyChar;
						}
						cout << snakeBodyChar;
						print = true;
					}
				}
				if (!print)
				{
					cout << empty;
				}
			}
		}
	}
}
void playerInput(int& currentDirection, bool& backToMenu, int& lastDirection)
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
void gameLogic(int& currentDirection, Snake& snake, Food& snakeFood, const int whidth, const int height, int& score, int lastDirection)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	int prevTailPositionX;
	int prevTailPositionY;
	int prevTailPosition2X;
	int prevTailPosition2Y;
	if (currentDirection != (int)Directions::Stop)
	{
		snake.tailPositionX[0] = snake.positionX;
		snake.tailPositionY[0] = snake.positionY;
		prevTailPositionX = snake.tailPositionX[0];  // posicion previa de la cola en x
		prevTailPositionY = snake.tailPositionY[0];  // posicion previa de la cola en y

		for (int i = 1; i < snake.tailLenght; i++)
		{
			prevTailPosition2X = snake.tailPositionX[i];
			prevTailPosition2Y = snake.tailPositionY[i];
			snake.tailPositionX[i] = prevTailPositionX;
			snake.tailPositionY[i] = prevTailPositionY;
			prevTailPositionX = prevTailPosition2X;
			prevTailPositionY = prevTailPosition2Y;
		}
	}


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
	for (int i = 0; i < snake.tailLenght; i++)
	{
		if (snake.tailPositionX[i] == snake.positionX && snake.tailPositionY[i] == snake.positionY)
		{
			snake.isDead = true;
		}
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
		snakeFood = randomiceSnakeFood(whidth, height);
		snake.tailLenght++;
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