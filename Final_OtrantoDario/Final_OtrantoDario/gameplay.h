#pragma once
#include "globals.h"
#include <windows.h>
#include <iostream>
#include <conio.h>

#define ARRIBA 72
#define IZQUIERDA 75
#define DERECHA 77
#define ABAJO 80
#define ESC 27
#define SPACE 32

struct SnakeHead 
{
	int positionX{};
	int positionY{};
};
struct Food 
{
	int foodPositionX{};
	int foodPositionY{};
};

enum class Directions {Stop,Left,Right,Up,Down};

int gameplay();
void setUp(bool& gameOver, int& currentDirection, SnakeHead& snake, int whidth, int height, Food& snakeFood, int& score);
void draw(SnakeHead snake, Food snakeFood);
void playerInput(int& currentDirection, bool& backToMenu);
void gameLogic();