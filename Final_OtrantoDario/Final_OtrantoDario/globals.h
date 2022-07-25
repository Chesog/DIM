#pragma once
#include <iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;

#define ARRIBA 72
#define IZQUIERDA 75
#define DERECHA 77
#define ABAJO 80
#define ESC 27
#define SPACE 32

void gotoXY(int X, int Y);
void hidecursor();
int pointer(int maxOption, int minOption, int& pointerCursor);