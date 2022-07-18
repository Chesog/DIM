#include "gameplay.h"

int gameplay()
{
	bool gameplayOn = true;
	const int maxRows = 28;
	const int maxColumns = 133;
	int board[maxRows][maxColumns];
	system("cls");
	hidecursor();
	showHud();
	boardReset(maxRows,maxColumns,board);
	do
	{
		mapDisplay(maxRows, maxColumns, board);
		showPlayerStats();
	} while (gameplayOn);

	return 0;
}
void showHud()
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
		if (rows == 28)
		{
			cout << verticalConection;
		}
		else
		{
			cout << verticalColumn;
		}
		for (int columns = 0; columns < maxBoardSizeColumns; columns++)
		{

			if (rows < 28 && columns == maxBoardSizeColumns - 1)
			{
				cout << empty << verticalColumn;
			}
			else if (rows == 28 && columns == maxBoardSizeColumns - 1)
			{
				cout << horizontalRow << horizontalConection;
			}
			else if (rows == 28)
			{
				cout << horizontalRow;
			}
			else if (rows > 28 && columns == maxBoardSizeColumns - 1)
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
void showPlayerStats()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	gotoXY(20, 30);
	SetConsoleTextAttribute(h, 14);
	cout << "Nombre ";
	SetConsoleTextAttribute(h, 12);
	cout << "Jugador 1" << endl;

	gotoXY(20, 31);
	SetConsoleTextAttribute(h, 14);
	cout << "Vida ";
	SetConsoleTextAttribute(h, 10);
	cout << " ==================== " << endl;

	gotoXY(20, 32);
	SetConsoleTextAttribute(h, 14);
	cout << "Mana ";
	SetConsoleTextAttribute(h, 11);
	cout << " ==================== " << endl;

	gotoXY(20, 33);
	SetConsoleTextAttribute(h, 14);
	cout << "Deff ";
	SetConsoleTextAttribute(h, 15);
	cout << " 100 / 100 " << endl;
}
void boardReset(int maxRows,int maxColumns,int board[28][133]) 
{
	for (int rows = 0; rows < maxRows; rows++)
	{
		for (int columns = 0; columns < maxColumns; columns++)
		{
			board[rows][columns] = 0;
		}
	}
}
void mapDisplay(int maxRows, int maxColumns, int board[28][133])
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 12);
	int x = 18;
	int y = 1;
	char empty = 32;	// valor vacio en el tablero
	gotoXY(x,y);
	for (int rows = 0; rows < maxRows; rows++)
	{
		for (int columns = 0; columns < maxColumns; columns++)
		{
			gotoXY((x+columns),(y+rows));
			if (board[rows][columns] == 0)
			{
				cout << "x";
			}
			else
			{
				cout << empty;
			}
		}
		cout << endl;
	}
}