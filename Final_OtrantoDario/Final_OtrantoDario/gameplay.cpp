#include "gameplay.h"

int gameplay(int winPoints,int headColor,int bodyColor,int foodColor)
{
	system("cls");
	bool gameOver;
	bool backToMenu;
	bool gameInPause;
	bool winCondition = false;

	int whidth = 42;
	int height = 33;
	int score;
	int pointerCursor;
	int currentDirection;
	int lastDirection;

	Snake snake;
	Food snakeFood;

	setUp(gameOver, currentDirection, snake, whidth, height, snakeFood, score, backToMenu, lastDirection, gameInPause, pointerCursor);
	drawGame();
	do
	{
		playerInput(currentDirection, backToMenu, lastDirection, gameInPause);
		if (clock() % 10 == 0)
		{
			drawGame(score, currentDirection);
			if (!gameInPause)
			{
				drawGame(snake, snakeFood, currentDirection, lastDirection,headColor,bodyColor,foodColor);
			}
			gameLogic(currentDirection, snake, snakeFood, whidth, height, score, lastDirection);
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
		if (score == winPoints)
		{
			winCondition = true;
			gameOver = true;
		}
	} while (!gameOver);
	int playerAnsw;
	drawGame(snake, snakeFood, currentDirection, lastDirection,headColor,bodyColor,foodColor);
	playerAnsw = secondWill(score, pointerCursor, winCondition);
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
void setUp(bool& gameOver, int& currentDirection, Snake& snake, int whidth, int height, Food& snakeFood, int& score, bool& backToMenu, int& lastDirection, bool& gamInPause, int& pointerCursor)
{
	whidth = 42;
	height = 33;
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
	gamInPause = true;
	pointerCursor = 1;
}
void drawGame()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 15);
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

	SetConsoleTextAttribute(h, 9);
	gotoXY(103, 17);
	cout << uperLeftCorner;
	for (int i = 0; i < 11; i++)
	{
		cout << horizontalRow;
	}
	cout << uperRightCorner;
	gotoXY(103, 18);
	cout << verticalColumn << " Controles " << verticalColumn << endl;
	gotoXY(103, 19);
	cout << lowerLeftCorner;
	for (int i = 0; i < 11; i++)
	{
		cout << horizontalRow;
	}
	cout << lowerRightCorner;

	int maxBoardSizeColumns2 = 39;
	int maxBoardSizeRows2 = 13;
	int xValue = 75;
	int yValue = 21;

	gotoXY(75, 20);
	cout << uperLeftCorner;
	for (int i = 0; i < maxBoardSizeColumns2; i++)
	{
		cout << horizontalRow;
	}
	cout << uperRightCorner;
	gotoXY(xValue, yValue);
	for (int rows = 0; rows < maxBoardSizeRows2; rows++)
	{
		for (int columns = 0; columns < maxBoardSizeColumns2; columns++)
		{
			gotoXY(xValue + columns, yValue + rows);
			if (columns == 0)
			{
				cout << verticalColumn;
			}
			if (columns == maxBoardSizeColumns2 - 1)
			{
				cout << empty << empty << verticalColumn;
			}
			else
			{
				cout << empty;
			}
		}
		cout << endl;
	}
	gotoXY(75, 34);
	cout << lowerLeftCorner;
	for (int i = 0; i < maxBoardSizeColumns2; i++)
	{
		cout << horizontalRow;
	}
	cout << lowerRightCorner;
}
void drawGame(int score, int currentDirection)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

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

	SetConsoleTextAttribute(h, 10);
	gotoXY(65, 0);
	cout << "  ________   _____  ___         __       __   ___    _______    " << endl;
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

	int scoreLenght = 0;

	if (score < 10)
	{
		scoreLenght = 17;
	}
	else if (score >= 10 && score < 100)
	{
		scoreLenght = 18;
	}
	else
	{
		scoreLenght = 19;
	}
	SetConsoleTextAttribute(h, 32);
	gotoXY(75, 17);
	cout << uperLeftCorner;
	for (int i = 0; i < scoreLenght; i++)
	{
		cout << horizontalRow;
	}
	cout << uperRightCorner;
	gotoXY(75, 18);
	cout << verticalColumn << " Player Score: " << score << " " << verticalColumn << endl;
	gotoXY(75, 19);
	cout << lowerLeftCorner;
	for (int i = 0; i < scoreLenght; i++)
	{
		cout << horizontalRow;
	}
	cout << lowerRightCorner;

	if (currentDirection == (int)Directions::Up)
	{
		SetConsoleTextAttribute(h, 10);
	}
	else
	{
		SetConsoleTextAttribute(h, 9);
	}
	gotoXY(93, 22);
	cout << uperLeftCorner << horizontalRow << horizontalRow << horizontalRow << uperRightCorner << endl;
	gotoXY(93, 23);
	cout << verticalColumn << " ^ " << verticalColumn << endl;
	gotoXY(93, 24);
	cout << lowerLeftCorner << horizontalRow << horizontalRow << horizontalRow << lowerRightCorner << endl;

	if (currentDirection == (int)Directions::Left)
	{
		SetConsoleTextAttribute(h, 10);
	}
	else
	{
		SetConsoleTextAttribute(h, 9);
	}
	gotoXY(88, 25);
	cout << uperLeftCorner << horizontalRow << horizontalRow << horizontalRow << uperRightCorner << endl;
	gotoXY(88, 26);
	cout << verticalColumn << " < " << verticalColumn << endl;
	gotoXY(88, 27);
	cout << lowerLeftCorner << horizontalRow << horizontalRow << horizontalRow << lowerRightCorner << endl;


	if (currentDirection == (int)Directions::Down)
	{
		SetConsoleTextAttribute(h, 10);
	}
	else
	{
		SetConsoleTextAttribute(h, 9);
	}
	gotoXY(93, 25);
	cout << uperLeftCorner << horizontalRow << horizontalRow << horizontalRow << uperRightCorner << endl;
	gotoXY(93, 26);
	cout << verticalColumn << " v " << verticalColumn << endl;
	gotoXY(93, 27);
	cout << lowerLeftCorner << horizontalRow << horizontalRow << horizontalRow << lowerRightCorner << endl;

	if (currentDirection == (int)Directions::Right)
	{
		SetConsoleTextAttribute(h, 10);
	}
	else
	{
		SetConsoleTextAttribute(h, 9);
	}
	gotoXY(98, 25);
	cout << uperLeftCorner << horizontalRow << horizontalRow << horizontalRow << uperRightCorner << endl;
	gotoXY(98, 26);
	cout << verticalColumn << " > " << verticalColumn << endl;
	gotoXY(98, 27);
	cout << lowerLeftCorner << horizontalRow << horizontalRow << horizontalRow << lowerRightCorner << endl;
	SetConsoleTextAttribute(h, 9);

	gotoXY(82, 21);
	cout << "Movimiento de la Serpiente" << endl;

	if (currentDirection == (int)Directions::Stop)
	{
		SetConsoleTextAttribute(h, 96);
		gotoXY(23, 15);
		cout << uperLeftCorner;
		for (int i = 0; i < 30; i++)
		{
			cout << horizontalRow;
		}
		cout << uperRightCorner << endl;
		gotoXY(23, 16);
		cout << verticalColumn << "        Juego en Pausa        " << verticalColumn << endl;
		gotoXY(23, 17);
		cout << verticalColumn << "      Precione una tecla      " << verticalColumn << endl;
		gotoXY(23, 18);
		cout << verticalColumn << " De Movimiento para Continuar " << verticalColumn << endl;
		gotoXY(23, 19);
		cout << lowerLeftCorner;
		for (int i = 0; i < 30; i++)
		{
			cout << horizontalRow;
		}
		cout << lowerRightCorner << endl;
		SetConsoleTextAttribute(h, 10);
	}
	else
	{
		SetConsoleTextAttribute(h, 9);
	}
	gotoXY(80, 28);
	cout << uperLeftCorner << horizontalRow << horizontalRow << horizontalRow << horizontalRow << horizontalRow << horizontalRow << horizontalRow << uperRightCorner << endl;
	gotoXY(80, 29);
	cout << verticalColumn << " Space " << verticalColumn << endl;
	gotoXY(80, 30);
	cout << lowerLeftCorner << horizontalRow << horizontalRow << horizontalRow << horizontalRow << horizontalRow << horizontalRow << horizontalRow << lowerRightCorner << endl;
	SetConsoleTextAttribute(h, 9);
	gotoXY(90, 29);
	cout << "Pausar el Juego" << endl;

	gotoXY(80, 31);
	cout << uperLeftCorner << horizontalRow << horizontalRow << horizontalRow << horizontalRow << horizontalRow << uperRightCorner << endl;
	gotoXY(80, 32);
	cout << verticalColumn << " Esc " << verticalColumn << endl;
	gotoXY(80, 33);
	cout << lowerLeftCorner << horizontalRow << horizontalRow << horizontalRow << horizontalRow << horizontalRow << lowerRightCorner << endl;
	gotoXY(90, 32);
	cout << "Volver al Menu Principal" << endl;
}
void drawGame(Snake snake, Food snakeFood, int currentDirection, int lastDirection,int headColor,int bodyColor,int foodColor)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	//SetConsoleTextAttribute(h, 14);

	char empty = 32;	// valor vacio en el tablero 
	char cherry = 162;
	char snakeDeadHead = 120;
	char snakeHeadUp = 118;
	char snakeHeadDown = 94;
	char snakeHeadLeft = 62;
	char snakeHeadRight = 60;
	char snakeBodyChar = 245;
	char snakeDeadBodyChar = 43;
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
					SetConsoleTextAttribute(h, headColor);
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
					SetConsoleTextAttribute(h, 12);
					cout << snakeDeadHead;
				}
			}
			else if (rows == snakeFood.foodPositionY && columns == snakeFood.foodPositionX)
			{
				SetConsoleTextAttribute(h, foodColor);
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
							SetConsoleTextAttribute(h, 12);
							cout << snakeDeadBodyChar;
						}
						SetConsoleTextAttribute(h, bodyColor);
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
void playerInput(int& currentDirection, bool& backToMenu, int& lastDirection, bool& gamInPause)
{
	char playerInput;
	if (_kbhit())
	{
		playerInput = _getch();
		switch (playerInput)
		{
		case SPACE:
		{
			currentDirection = (int)Directions::Stop;
			gamInPause = true;
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
			gamInPause = false;
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
			gamInPause = false;
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
			gamInPause = false;
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
			gamInPause = false;
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
int secondWill(int score, int& pointerCursor, bool winCondition)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

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

	bool secondWillSelection = false;
	int playerSecondWillSelection;
	do
	{
		if (winCondition)
		{
			SetConsoleTextAttribute(h, 160);
			gotoXY(23, 15);
			cout << uperLeftCorner;
			for (int i = 0; i < 30; i++)
			{
				cout << horizontalRow;
			}
			cout << uperRightCorner << endl;
			gotoXY(23, 16);
			cout << verticalColumn << "          Game  Win!          " << verticalColumn << endl;
			gotoXY(23, 17);
			cout << verticalColumn << "       player Score: " << score;
			if (score < 10)
			{
				cout << "        ";
			}
			else if (score >= 10 && score < 100)
			{
				cout << "       ";
			}
			else
			{
				cout << "      ";
			}
			cout << verticalColumn << endl;
			gotoXY(23, 18);
			cout << verticalColumn << "       Volver a Jugar ?       " << verticalColumn << endl;
			gotoXY(23, 19);
			cout << verticalColumn;
			if (pointerCursor == 1)
			{
				SetConsoleTextAttribute(h, 10);
			}
			cout << "              Si              ";
			SetConsoleTextAttribute(h, 160);
			cout << verticalColumn << endl;
			gotoXY(23, 20);
			cout << verticalColumn;
			if (pointerCursor == 2)
			{
				SetConsoleTextAttribute(h, 10);
			}
			cout << "              No              ";
			SetConsoleTextAttribute(h, 160);
			cout << verticalColumn << endl;
			gotoXY(23, 21);
			cout << lowerLeftCorner;
			for (int i = 0; i < 30; i++)
			{
				cout << horizontalRow;
			}
			cout << lowerRightCorner << endl;

			playerSecondWillSelection = pointer(2, 1, pointerCursor);
		}
		else
		{

			SetConsoleTextAttribute(h, 192);
			gotoXY(23, 15);
			cout << uperLeftCorner;
			for (int i = 0; i < 30; i++)
			{
				cout << horizontalRow;
			}
			cout << uperRightCorner << endl;
			gotoXY(23, 16);
			cout << verticalColumn << "          Game  Over          " << verticalColumn << endl;
			gotoXY(23, 17);
			cout << verticalColumn << "       player Score: " << score;
			if (score < 10)
			{
				cout << "        ";
			}
			else if (score >= 10 && score < 100)
			{
				cout << "       ";
			}
			else
			{
				cout << "      ";
			}
			cout << verticalColumn << endl;
			gotoXY(23, 18);
			cout << verticalColumn << "       Volver a Jugar ?       " << verticalColumn << endl;
			gotoXY(23, 19);
			cout << verticalColumn;
			if (pointerCursor == 1)
			{
				SetConsoleTextAttribute(h, 12);
			}
			cout << "              Si              ";
			SetConsoleTextAttribute(h, 192);
			cout << verticalColumn << endl;
			gotoXY(23, 20);
			cout << verticalColumn;
			if (pointerCursor == 2)
			{
				SetConsoleTextAttribute(h, 12);
			}
			cout << "              No              ";
			SetConsoleTextAttribute(h, 192);
			cout << verticalColumn << endl;
			gotoXY(23, 21);
			cout << lowerLeftCorner;
			for (int i = 0; i < 30; i++)
			{
				cout << horizontalRow;
			}
			cout << lowerRightCorner << endl;

			playerSecondWillSelection = pointer(2, 1, pointerCursor);
		}

		if (playerSecondWillSelection != 0)
		{
			secondWillSelection = true;
		}
		SetConsoleTextAttribute(h, 12);
	} while (!secondWillSelection);

	system("cls");
	if (playerSecondWillSelection == 1)
	{
		return playerSecondWillSelection;
	}
	else if (playerSecondWillSelection == 2)
	{
		return 0;
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