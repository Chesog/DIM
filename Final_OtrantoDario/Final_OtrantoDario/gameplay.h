#pragma once
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "globals.h"
using namespace std;

int gameplay();
void showHud();
void showPlayerStats();
void boardReset(int maxRows, int maxColumns, int board[28][133]);
void mapDisplay(int maxRows, int maxColumns, int board[28][133]);