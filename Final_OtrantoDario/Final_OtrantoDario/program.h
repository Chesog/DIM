#pragma once
#include <iostream>
#include <Windows.h>   
#include <conio.h>
#include "globals.h"
#include "gameplay.h"

using namespace std;    // std::cout, std::cin
void mainMenu();
int showMainMenu(int& pointerCursor);
bool showExitScreen();
int credits();
enum class MenuStates { MainMenu, Gameplay, Rules, Credits, Exit };