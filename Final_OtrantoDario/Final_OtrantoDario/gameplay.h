#pragma once
#include "globals.h"
#include <windows.h>
#include <iostream>
#include <conio.h>
#include <time.h>



struct Snake 
{
	int positionX{};
	int positionY{};
	int tailPositionX[100]{};
	int tailPositionY[100]{};
	int tailLenght{};
	bool isDead{};
};
struct Food 
{
	int foodPositionX{};
	int foodPositionY{};
};

enum class Directions {Stop,Left,Right,Up,Down};

int gameplay(int winPoints,int headColor,int bodyColor,int foodColor);
int secondWill(int score,int& pointerCursor,bool winCondition);
void setUp(bool& gameOver, int& currentDirection, Snake& snake, int whidth, int height, Food& snakeFood, int& score, bool& backToMenu,int& lastDirection, bool& gamInPause,int& pointerCursor);
void drawGame();
void drawGame(int score,int currentDirection);
void drawGame(Snake snake, Food snakeFood, int currentDirection,int lastDirection,int headColor,int bodyColor,int foodColor);
void playerInput(int& currentDirection, bool& backToMenu,int& lastDirection, bool& gamInPause);
void gameLogic(int& currentDirection, Snake& snake, Food& snakeFood, const int whidth, const int height,int& score,int lastDirection);
Food randomiceSnakeFood(int whidth, int height);