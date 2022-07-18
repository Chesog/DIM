#include "gameplay.h"

int gameplay()
{
	system("cls");
	bool gameOver;
	bool backToMenu;

	const int whidth = 135;
	const int height = 38;

	int score;
	int currentDirection;

	SnakeHead snake;
	Food snakeFood;

	setUp(gameOver,currentDirection,snake,whidth,height,snakeFood,score,backToMenu);
	do
	{
		draw(snake,snakeFood);
		playerInput(currentDirection,backToMenu);
		gameLogic();
		if (backToMenu)
		{
			return 0;
		}
	} while (!gameOver);
	return 0;
}
void setUp(bool& gameOver,int& currentDirection,SnakeHead& snake,int whidth,int height,Food& snakeFood,int& score, bool& backToMenu)
{
	gameOver = false;
	backToMenu = false;
	currentDirection = (int)Directions::Stop;
	snake.positionX = whidth / 2;
	snake.positionY = height / 2;
	snakeFood.foodPositionX = rand() % whidth;
	snakeFood.foodPositionY = rand() % height;
	score = 0;
}
void draw(SnakeHead snake,Food snakeFood) 
{
	gotoXY(0,0);
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

	int maxBoardSizeColumns = 135;
	int maxBoardSizeRows = 38;
	int attkPly = 1;
	int specialAttk = 2;
	int deffPly = 3;
	int backToMenu = 4;

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
			if (rows == snake.positionY && columns == snake.positionX)
			{
				cout << "{";
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
void playerInput(int& currentDirection, bool& backToMenu)
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
			currentDirection = (int)Directions::Up;
		}
		break;
		case IZQUIERDA:
		{
			currentDirection = (int)Directions::Left;
		}
		break;
		case DERECHA:
		{
			currentDirection = (int)Directions::Right;
		}
		break;
		case ABAJO:
		{
			currentDirection = (int)Directions::Down;
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
void gameLogic() 
{

}