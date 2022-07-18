#pragma once
#include <iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;

void gotoXY(int X, int Y);
void hidecursor();
int pointer(int maxOption, int minOption, int& pointerCursor);
int pointer(int maxOption, int minOption, int& cursorPositionX,int& cursorPositionY);