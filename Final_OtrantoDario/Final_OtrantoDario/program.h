#pragma once
#include <iostream>
#include <Windows.h>   
#include <conio.h>
#include "globals.h"
#include "gameplay.h"

using namespace std;    // std::cout, std::cin
void mainMenu();
int showMainMenu(int& pointerCursor);
int credits();
int optionsMenu(int& winPoints, int& headColor, int& bodyColor,int& foodColor,int& pointerCursor);
bool showExitScreen();
enum class MenuStates { MainMenu, Gameplay,Options, Rules, Credits, Exit };
enum class OptionsMenuStates { WinPointsCant = 1,SnakeColor,FruitColor,ExitToMainMenu};