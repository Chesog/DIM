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

struct Snake 
{
	int positionX{};
	int positionY{};
	bool isDead{};
};
struct Food 
{
	int foodPositionX{};
	int foodPositionY{};
};

enum class Directions {Stop,Left,Right,Up,Down};

int gameplay();
void setUp(bool& gameOver, int& currentDirection, Snake& snake, int whidth, int height, Food& snakeFood, int& score, bool& backToMenu,int& lastDirection);
void drawGame();
void drawGame(int score);
void drawGame(Snake snake, Food snakeFood, int currentDirection,int lastDirection);
void playerInput(int& currentDirection, bool& backToMenu,int& lastDirection);
void gameLogic(int& currentDirection, Snake& snake, Food& snakeFood, const int whidth, const int height,int& score,int& tailLenght);
Food randomiceSnakeFood(int whidth, int height);