#include "globals.h"

void gotoXY(int X, int Y) // Funcion para Mover el cursor a distintas cordenadas del tablero
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { (short)X,(short)Y });
}
void hidecursor()	//Funcion para esconder el cursor
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
}
int pointer(int maxOption, int minOption, int& pointerCursor) // cursor para el menu
{
	COORD consolecursorposition = { 0,0 };

	int defaultOption = 0;
	int max = maxOption;
	int min = minOption;
	char cursor;
	cursor = _getch();
	switch (cursor)
	{
	case ARRIBA:
		pointerCursor--;
		if (pointerCursor < min)
		{
			pointerCursor = max;
		}
		return defaultOption;
		break;
	case ABAJO:
		pointerCursor++;
		if (pointerCursor > max)
		{
			pointerCursor = min;
		}
		return defaultOption;
		break;
	case SPACE:
		return pointerCursor;
		break;
	default:
		return defaultOption;
		break;
	}

}