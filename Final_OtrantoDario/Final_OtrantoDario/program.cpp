#include "program.h"

void mainMenu()		// para navegar los distintos estados del menu
{
	hidecursor();
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
	SetConsoleTitle((L"Descend Into Madness Snake Edition"));
	bool gameOn = true;
	int menuAnsw = 0;
	int pointerCursor = 1;
	int winPoints = 100;
	int foodColor = 12;
	int headColor = 15;
	int bodyColor = 10;
	do
	{
		switch (menuAnsw)
		{
		case (int)MenuStates::MainMenu:
			menuAnsw = showMainMenu(pointerCursor);
			break;
		case (int)MenuStates::Gameplay:
			menuAnsw = gameplay(winPoints, headColor, bodyColor, foodColor);
			break;
		case (int)MenuStates::Options:
			menuAnsw = optionsMenu(winPoints, headColor, bodyColor, foodColor, pointerCursor);
			break;
		case (int)MenuStates::Rules:
			menuAnsw = showRules();
			break;
		case (int)MenuStates::Credits:
			menuAnsw = credits();
			break;
		case (int)MenuStates::Exit:
			gameOn = showExitScreen();
			break;
		default:
			break;
		}
	} while (gameOn);
}
int showMainMenu(int& pointerCursor)	// Funcion para el dibujado del Menu Principal
{
	gotoXY(0, 0);
	char uperLeftCorner = 201; // esquina superior izquierda ╔ 
	char uperRightCorner = 187; // esquina superior derecha ╗ 
	char lowerLeftCorner = 200; // esquina inferior izquierda ╚ 
	char lowerRightCorner = 188; // esquina inferior Derecha ╝ 
	char horizontalRow = 205;	// linea horizontal ═ 
	char verticalColumn = 186; // linea vertical ║ 
	char empty = 32;	// valor vacio en el tablero 
	hidecursor();
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	int answ;
	SetConsoleTextAttribute(h, 10);
	cout << R"(
		 ________     _______	  ________   ______     _______   _____  ___    ________	  __      _____  ___    ___________      ______ 
		|"      "\   /"     "|	 /"       ) /" _  "\   /"     "| (\"   \|"  \  |"      "\	 |" \    (\"   \|"  \  ("     _   ")    /    " \
		(.  ___  :) (: ______)	(:   \___/ (: ( \___) (: ______) |.\\   \    | (.  ___  :)	 ||  |   |.\\   \    |  )__/  \\__/    // ____  \ 
		|: \   ) ||  \/    |	 \___  \    \/ \       \/    |   |: \.   \\  | |: \   ) ||	 |:  |   |: \.   \\  |     \\_ /      /  /    ) :) 
		(| (___\ ||  // ___)_	  __/  \\   //  \ _    // ___)_  |.  \    \. | (| (___\ ||	 |.  |   |.  \    \. |     |.  |     (: (____/ // 
		|:       :) (:      "|	 /" \   :) (:   _) \  (:      "| |    \    \ | |:       :)	 /\  |\  |    \    \ |     \:  |      \        /
		(________/   \_______)	(_______/   \_______)  \_______)  \___|\____\) (________/	(__\_|_)  \___|\____\)      \__|       \"_____/ 
                                                                       )" << endl;
	cout << R"( 
					 ___      ___       __       ________    _____  ___     _______    ________    ________  
					|"  \    /"  |     /""\     |"      "\  (\"   \|"  \   /"     "|  /"       )  /"       ) 
					 \   \  //   |    /    \    (.  ___  :) |.\\   \    | (: ______) (:   \___/  (:   \___/  
					 /\\  \/.    |   /' /\  \   |: \   ) || |: \.   \\  |  \/    |    \___  \     \___  \    
					|: \.        |  //  __'  \  (| (___\ || |.  \    \. |  // ___)_    __/  \\     __/  \\   
					|.  \    /:  | /   /  \\  \ |:       :) |    \    \ | (:      "|  /" \   :)   /" \   :)  
					|___|\__/|___|(___/    \___)(________/   \___|\____\)  \_______) (_______/   (_______/   
					                                                                                 )" << endl;

	int maxBoardSizeColumns = 44;
	int maxBoardSizeRows = 20;

	int xValue = 65;
	int yValue = 19;

	gotoXY(64, 21);
	SetConsoleTextAttribute(h, 224);
	cout << uperLeftCorner;
	for (int i = 0; i < 31; i++)
	{
		cout << horizontalRow;
	}
	cout << uperRightCorner << endl;
	gotoXY(64, 22);
	cout << verticalColumn;
	if (pointerCursor == (int)MenuStates::Gameplay)
	{
		SetConsoleTextAttribute(h, 14);
	}
	cout << "             Jugar             ";
	SetConsoleTextAttribute(h, 224);
	cout << verticalColumn << endl;
	gotoXY(64, 23);
	cout << verticalColumn;
	if (pointerCursor == (int)MenuStates::Options)
	{
		SetConsoleTextAttribute(h, 14);
	}
	cout << "            Opciones           ";
	SetConsoleTextAttribute(h, 224);
	cout << verticalColumn << endl;
	gotoXY(64, 24);
	cout << verticalColumn;
	if (pointerCursor == (int)MenuStates::Rules)
	{
		SetConsoleTextAttribute(h, 14);
	}
	cout << "           Reglamento          ";
	SetConsoleTextAttribute(h, 224);
	cout << verticalColumn << endl;
	gotoXY(64, 25);
	cout << verticalColumn;
	if (pointerCursor == (int)MenuStates::Credits)
	{
		SetConsoleTextAttribute(h, 14);
	}
	cout << "            Creditos           ";
	SetConsoleTextAttribute(h, 224);
	cout << verticalColumn << endl;
	gotoXY(64, 26);
	cout << verticalColumn;
	if (pointerCursor == (int)MenuStates::Exit)
	{
		SetConsoleTextAttribute(h, 14);
	}
	cout << "             Salir             ";
	SetConsoleTextAttribute(h, 224);
	cout << verticalColumn << endl;
	gotoXY(64, 27);
	cout << lowerLeftCorner;
	for (int i = 0; i < 31; i++)
	{
		cout << horizontalRow;
	}
	cout << lowerRightCorner << endl;

	SetConsoleTextAttribute(h, 15);
	showKeys(10, 30);

	if (_kbhit)
	{
		answ = pointer((int)MenuStates::Exit, (int)MenuStates::Gameplay, pointerCursor);
		return answ;
	}
}
int optionsMenu(int& winPoints, int& headColor, int& bodyColor, int& foodColor, int& pointerCursor) // Funcion para el dibujado y funcionamiento del menu de Opciones
{
	bool exitMenu = false;
	system("cls");
	pointerCursor = 1;
	int optionsAnsw = 0;
	do
	{
		gotoXY(0, 0);
		char uperLeftCorner = 201; // esquina superior izquierda ╔ 
		char uperRightCorner = 187; // esquina superior derecha ╗ 
		char lowerLeftCorner = 200; // esquina inferior izquierda ╚ 
		char lowerRightCorner = 188; // esquina inferior Derecha ╝ 
		char horizontalRow = 205;	// linea horizontal ═ 
		char verticalColumn = 186; // linea vertical ║ 
		char empty = 32;	// valor vacio en el tablero 
		int maxWinPoints = 1235;

		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(h, 10);
		cout << R"(
					    ______       _______     ______     __         ______     _____  ___     _______    ________  
					   /    " \     |   __ "\   /" _  "\   |" \       /    " \   (\"   \|"  \   /"     "|  /"       ) 
					  // ____  \    (. |__) :) (: ( \___)  ||  |     // ____  \  |.\\   \    | (: ______) (:   \___/  
					 /  /    ) :)   |:  ____/   \/ \       |:  |    /  /    ) :) |: \.   \\  |  \/    |    \___  \    
					(: (____/ //    (|  /       //  \ _    |.  |   (: (____/ //  |.  \    \. |  // ___)_    __/  \\   
					 \        /    /|__/ \     (:   _) \   /\  |\   \        /   |    \    \ | (:      "|  /" \   :)  
					  \"_____/    (_______)     \_______) (__\_|_)   \"_____/     \___|\____\)  \_______) (_______/   
				                                                                                                  )" << endl;
		if (optionsAnsw == 0) // Dibujado de el menu de opciones
		{

			gotoXY(64, 14);
			SetConsoleTextAttribute(h, 224);
			cout << uperLeftCorner;
			for (int i = 0; i < 40; i++)
			{
				cout << horizontalRow;
			}
			cout << uperRightCorner << endl;
			gotoXY(64, 15);
			cout << verticalColumn;
			if (pointerCursor == (int)OptionsMenuStates::WinPointsCant)
			{
				SetConsoleTextAttribute(h, 14);
			}
			cout << "      Cantidad de Puntos para Ganar     ";
			SetConsoleTextAttribute(h, 224);
			cout << verticalColumn << endl;
			gotoXY(64, 16);
			cout << verticalColumn;
			if (pointerCursor == (int)OptionsMenuStates::SnakeColor)
			{
				SetConsoleTextAttribute(h, 14);
			}
			cout << "          Color de la Serpiente         ";
			SetConsoleTextAttribute(h, 224);
			cout << verticalColumn << endl;
			gotoXY(64, 17);
			cout << verticalColumn;
			if (pointerCursor == (int)OptionsMenuStates::FruitColor)
			{
				SetConsoleTextAttribute(h, 14);
			}
			cout << "            Color de la Fruta           ";
			SetConsoleTextAttribute(h, 224);
			cout << verticalColumn << endl;
			gotoXY(64, 18);
			cout << verticalColumn;
			if (pointerCursor == (int)OptionsMenuStates::ExitToMainMenu)
			{
				SetConsoleTextAttribute(h, 14);
			}
			cout << "        Volver al Menu Principal        ";
			SetConsoleTextAttribute(h, 224);
			cout << verticalColumn << endl;
			gotoXY(64, 19);
			cout << lowerLeftCorner;


			for (int i = 0; i < 40; i++)
			{
				cout << horizontalRow;
			}
			cout << lowerRightCorner << endl;
		}
		else if (optionsAnsw == (int)OptionsMenuStates::WinPointsCant) // Logica y dibujado para el cambio de la condicion de victoria
		{
			pointerCursor = 1;
			int answ = 0;
			do
			{
				gotoXY(64, 14);
				SetConsoleTextAttribute(h, 224);
				cout << uperLeftCorner;
				for (int i = 0; i < 40; i++)
				{
					cout << horizontalRow;
				}
				cout << uperRightCorner << endl;
				gotoXY(64, 15);
				cout << verticalColumn << " Puntos Actuales para la Victoria ";
				if (winPoints < 10)
				{
					cout << "    ";
				}
				else if (winPoints >= 10 && winPoints < 100)
				{
					cout << "   ";
				}
				else if (winPoints >= 100 && winPoints < 1000)
				{
					cout << "  ";
				}
				else
				{
					cout << " ";
				}
				cout << winPoints << " " << verticalColumn << endl;
				gotoXY(64, 16);
				cout << verticalColumn << "      Puntos Maximos para Setear   " << maxWinPoints << " " << verticalColumn << endl;
				gotoXY(64, 17);
				cout << verticalColumn << "                                        " << verticalColumn << endl;
				gotoXY(64, 18);
				cout << verticalColumn;
				if (pointerCursor == 1)
				{
					SetConsoleTextAttribute(h, 14);
				}
				cout << "    Setear Nuevo Puntaje de Victoria    ";
				SetConsoleTextAttribute(h, 224);
				cout << verticalColumn << endl;
				gotoXY(64, 19);
				cout << verticalColumn;
				if (pointerCursor == 2)
				{
					SetConsoleTextAttribute(h, 14);
				}
				cout << "        Setear Puntaje al Default       ";
				SetConsoleTextAttribute(h, 224);
				cout << verticalColumn << endl;
				gotoXY(64, 20);
				cout << verticalColumn;
				if (pointerCursor == 3)
				{
					SetConsoleTextAttribute(h, 14);
				}
				cout << "       Volver al Menu de Opciones       ";
				SetConsoleTextAttribute(h, 224);
				cout << verticalColumn << endl;
				gotoXY(64, 21);
				cout << lowerLeftCorner;


				for (int i = 0; i < 40; i++)
				{
					cout << horizontalRow;
				}
				cout << lowerRightCorner << endl;

				if (_kbhit())
				{
					answ = pointer(3, 1, pointerCursor);
				}
				if (answ == 1)
				{
					bool correctSet = false;
					int newWinPoints = 0;
					do
					{
						SetConsoleTextAttribute(h, 14);
						gotoXY(64, 23);
						cout << "Ingrese un Nuevo Valor" << endl;
						gotoXY(64, 24);
						cout << "User ---> ";
						cin >> newWinPoints;
						//if (isdigit(newWinPoints))
						//{
						if (newWinPoints > maxWinPoints)
						{
							gotoXY(64, 26);
							cout << "Ingrese un numero Valido" << endl;
							gotoXY(64, 24);
							cout << "                                   ";
						}
						else
						{
							winPoints = newWinPoints;
							correctSet = true;
						}
						//}
					} while (!correctSet);
					answ = 3;
				}
				else if (answ == 2)
				{
					SetConsoleTextAttribute(h, 14);
					gotoXY(64, 23);
					cout << "Puntos Para la Victoria Seteados en 100" << endl;
					winPoints = 100;
					answ = 3;
					gotoXY(34, 24);
					system("pause");
				}

			} while (answ != 3);
			pointerCursor = 1;
			SetConsoleTextAttribute(h, 10);
			system("cls");
			optionsAnsw = 0;
		}
		else if (optionsAnsw == (int)OptionsMenuStates::SnakeColor) // Logica y dibujado para el cambio de coloor de la serpiente
		{
			pointerCursor = 1;
			int answ = 0;
			bool colorSelected = false;
			do
			{
				char snakeHeadRight = 60;
				char snakeBodyChar = 245;
				gotoXY(64, 14);
				SetConsoleTextAttribute(h, 128);
				cout << uperLeftCorner;
				for (int i = 0; i < 40; i++)
				{
					cout << horizontalRow;
				}
				cout << uperRightCorner << endl;
				gotoXY(64, 15);
				cout << verticalColumn << "  Seleccione el Color De la Serpiente   " << verticalColumn << endl;
				gotoXY(64, 16);
				cout << verticalColumn << "                                        " << verticalColumn << endl;
				gotoXY(64, 17);
				cout << verticalColumn;
				if (pointerCursor == 1)
				{
					SetConsoleTextAttribute(h, 10);
				}
				else
				{
					SetConsoleTextAttribute(h, 128);
				}
				cout << "                  " << snakeBodyChar << snakeBodyChar << snakeBodyChar;
				if (pointerCursor == 1)
				{
					SetConsoleTextAttribute(h, 15);
				}
				else
				{
					SetConsoleTextAttribute(h, 128);
				}
				cout << snakeHeadRight << "                  ";
				SetConsoleTextAttribute(h, 128);
				cout << verticalColumn << endl;
				gotoXY(64, 18);
				cout << verticalColumn;
				if (pointerCursor == 2)
				{
					SetConsoleTextAttribute(h, 14);
				}
				else
				{
					SetConsoleTextAttribute(h, 128);
				}
				cout << "                  " << snakeBodyChar << snakeBodyChar << snakeBodyChar;
				if (pointerCursor == 2)
				{
					SetConsoleTextAttribute(h, 10);
				}
				else
				{
					SetConsoleTextAttribute(h, 128);
				}
				cout << snakeHeadRight << "                  ";
				SetConsoleTextAttribute(h, 128);
				cout << verticalColumn << endl;

				gotoXY(64, 19);
				cout << verticalColumn;
				if (pointerCursor == 3)
				{
					SetConsoleTextAttribute(h, 13);
				}
				else
				{
					SetConsoleTextAttribute(h, 128);
				}
				cout << "                  " << snakeBodyChar << snakeBodyChar << snakeBodyChar;
				if (pointerCursor == 3)
				{
					SetConsoleTextAttribute(h, 6);
				}
				else
				{
					SetConsoleTextAttribute(h, 128);
				}
				cout << snakeHeadRight << "                  ";
				SetConsoleTextAttribute(h, 128);
				cout << verticalColumn << endl;

				gotoXY(64, 20);
				cout << verticalColumn;
				if (pointerCursor == 4)
				{
					SetConsoleTextAttribute(h, 12);
				}
				else
				{
					SetConsoleTextAttribute(h, 128);
				}
				cout << "                  " << snakeBodyChar << snakeBodyChar << snakeBodyChar;
				if (pointerCursor == 4)
				{
					SetConsoleTextAttribute(h, 11);
				}
				else
				{
					SetConsoleTextAttribute(h, 128);
				}
				cout << snakeHeadRight << "                  ";
				SetConsoleTextAttribute(h, 128);
				cout << verticalColumn << endl;

				gotoXY(64, 21);
				cout << verticalColumn;
				if (pointerCursor == 5)
				{
					SetConsoleTextAttribute(h, 11);
				}
				else
				{
					SetConsoleTextAttribute(h, 128);
				}
				cout << "                  " << snakeBodyChar << snakeBodyChar << snakeBodyChar;
				if (pointerCursor == 5)
				{
					SetConsoleTextAttribute(h, 9);
				}
				else
				{
					SetConsoleTextAttribute(h, 128);
				}
				cout << snakeHeadRight << "                  ";
				SetConsoleTextAttribute(h, 128);
				cout << verticalColumn << endl;

				gotoXY(64, 22);
				cout << verticalColumn;
				if (pointerCursor == 6)
				{
					SetConsoleTextAttribute(h, 15);
				}
				else
				{
					SetConsoleTextAttribute(h, 128);
				}
				cout << "                  " << snakeBodyChar << snakeBodyChar << snakeBodyChar;
				if (pointerCursor == 6)
				{
					SetConsoleTextAttribute(h, 13);
				}
				else
				{
					SetConsoleTextAttribute(h, 128);
				}
				cout << snakeHeadRight << "                  ";
				SetConsoleTextAttribute(h, 128);
				cout << verticalColumn << endl;

				gotoXY(64, 23);
				cout << lowerLeftCorner;


				for (int i = 0; i < 40; i++)
				{
					cout << horizontalRow;
				}
				cout << lowerRightCorner << endl;

				if (_kbhit())
				{
					answ = pointer(6, 1, pointerCursor);
				}

				if (answ == 1)
				{
					bodyColor = 10;
					headColor = 15;
					colorSelected = true;
					gotoXY(64, 25);
					cout << "Color Seleccionado" << endl;
					gotoXY(64, 26);
					system("pause");
				}
				else if (answ == 2)
				{
					bodyColor = 14;
					headColor = 10;
					colorSelected = true;
					gotoXY(64, 25);
					cout << "Color Seleccionado" << endl;
					gotoXY(64, 26);
					system("pause");
				}
				else if (answ == 3)
				{
					bodyColor = 13;
					headColor = 6;
					colorSelected = true;
					gotoXY(64, 25);
					cout << "Color Seleccionado" << endl;
					gotoXY(64, 26);
					system("pause");
				}
				else if (answ == 4)
				{
					bodyColor = 12;
					headColor = 11;
					colorSelected = true;
					gotoXY(64, 25);
					cout << "Color Seleccionado" << endl;
					gotoXY(64, 26);
					system("pause");
				}
				else if (answ == 5)
				{
					bodyColor = 11;
					headColor = 9;
					colorSelected = true;
					gotoXY(64, 25);
					cout << "Color Seleccionado" << endl;
					gotoXY(64, 26);
					system("pause");
				}
				else if (answ == 6)
				{
					bodyColor = 15;
					headColor = 13;
					colorSelected = true;
					gotoXY(64, 25);
					cout << "Color Seleccionado" << endl;
					gotoXY(64, 26);
					system("pause");
				}

			} while (!colorSelected);
			pointerCursor = 2;
			SetConsoleTextAttribute(h, 10);
			system("cls");
			optionsAnsw = 0;
		}
		else if (optionsAnsw == (int)OptionsMenuStates::FruitColor) // Logica y dibujado para el cambio de color de la fruta
		{
			pointerCursor = 1;
			int answ = 0;
			bool colorSelected = false;
			do
			{
				char cherry = 162;
				gotoXY(64, 14);
				SetConsoleTextAttribute(h, 128);
				cout << uperLeftCorner;
				for (int i = 0; i < 40; i++)
				{
					cout << horizontalRow;
				}
				cout << uperRightCorner << endl;
				gotoXY(64, 15);
				cout << verticalColumn << "    Seleccione el Color De la Fruta     " << verticalColumn << endl;
				gotoXY(64, 16);
				cout << verticalColumn << "                                        " << verticalColumn << endl;
				gotoXY(64, 17);
				cout << verticalColumn;
				if (pointerCursor == 1)
				{
					SetConsoleTextAttribute(h, 12);
				}
				else
				{
					SetConsoleTextAttribute(h, 128);
				}
				cout << "                    " << cherry << "                   ";
				SetConsoleTextAttribute(h, 128);
				cout << verticalColumn << endl;
				gotoXY(64, 18);
				cout << verticalColumn;
				if (pointerCursor == 2)
				{
					SetConsoleTextAttribute(h, 13);
				}
				else
				{
					SetConsoleTextAttribute(h, 128);
				}
				cout << "                    " << cherry << "                   ";
				SetConsoleTextAttribute(h, 128);
				cout << verticalColumn << endl;

				gotoXY(64, 19);
				cout << verticalColumn;
				if (pointerCursor == 3)
				{
					SetConsoleTextAttribute(h, 14);
				}
				else
				{
					SetConsoleTextAttribute(h, 128);
				}
				cout << "                    " << cherry << "                   ";
				SetConsoleTextAttribute(h, 128);
				cout << verticalColumn << endl;

				gotoXY(64, 20);
				cout << verticalColumn;
				if (pointerCursor == 4)
				{
					SetConsoleTextAttribute(h, 15);
				}
				else
				{
					SetConsoleTextAttribute(h, 128);
				}
				cout << "                    " << cherry << "                   ";
				SetConsoleTextAttribute(h, 128);
				cout << verticalColumn << endl;

				gotoXY(64, 21);
				cout << verticalColumn;
				if (pointerCursor == 5)
				{
					SetConsoleTextAttribute(h, 11);
				}
				else
				{
					SetConsoleTextAttribute(h, 128);
				}
				cout << "                    " << cherry << "                   ";
				SetConsoleTextAttribute(h, 128);
				cout << verticalColumn << endl;

				gotoXY(64, 22);
				cout << verticalColumn;
				if (pointerCursor == 6)
				{
					SetConsoleTextAttribute(h, 6);
				}
				else
				{
					SetConsoleTextAttribute(h, 128);
				}
				cout << "                    " << cherry << "                   ";
				SetConsoleTextAttribute(h, 128);
				cout << verticalColumn << endl;

				gotoXY(64, 23);
				cout << lowerLeftCorner;


				for (int i = 0; i < 40; i++)
				{
					cout << horizontalRow;
				}
				cout << lowerRightCorner << endl;

				if (_kbhit())
				{
					answ = pointer(6, 1, pointerCursor);
				}

				if (answ == 1)
				{
					foodColor = 12;
					colorSelected = true;
					gotoXY(64, 25);
					cout << "Color Seleccionado" << endl;
					gotoXY(64, 26);
					system("pause");
				}
				else if (answ == 2)
				{
					foodColor = 13;
					colorSelected = true;
					gotoXY(64, 25);
					cout << "Color Seleccionado" << endl;
					gotoXY(64, 26);
					system("pause");
				}
				else if (answ == 3)
				{
					foodColor = 14;
					colorSelected = true;
					gotoXY(64, 25);
					cout << "Color Seleccionado" << endl;
					gotoXY(64, 26);
					system("pause");
				}
				else if (answ == 4)
				{
					foodColor = 15;
					colorSelected = true;
					gotoXY(64, 25);
					cout << "Color Seleccionado" << endl;
					gotoXY(64, 26);
					system("pause");
				}
				else if (answ == 5)
				{
					foodColor = 11;
					colorSelected = true;
					gotoXY(64, 25);
					cout << "Color Seleccionado" << endl;
					gotoXY(64, 26);
					system("pause");
				}
				else if (answ == 6)
				{
					foodColor = 6;
					colorSelected = true;
					gotoXY(64, 25);
					cout << "Color Seleccionado" << endl;
					gotoXY(64, 26);
					system("pause");
				}

			} while (!colorSelected);
			pointerCursor = 3;
			SetConsoleTextAttribute(h, 10);
			system("cls");
			optionsAnsw = 0;
		}
		else if (optionsAnsw == (int)OptionsMenuStates::ExitToMainMenu) // Volver al menu principal
		{
			exitMenu = true;
		}

		SetConsoleTextAttribute(h, 15);
		showKeys(10, 30);

		if (_kbhit())
		{
			optionsAnsw = pointer((int)OptionsMenuStates::ExitToMainMenu, (int)OptionsMenuStates::WinPointsCant, pointerCursor);
		}
	} while (!exitMenu);
	system("cls");
	pointerCursor = 2;
	return 0;
}
int credits() // Funcion con el dibujado de los creditos
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	hidecursor();
	int creditsAnsw = 0;
	int returnValue = 0;
	system("cls");
	SetConsoleTextAttribute(h, 9);
	cout << R"( 
								/ \--------------------------------------, 
								\_,|                                     | 
								   |   Juego hecho por : Dario Otranto   |
								   |	 Alias :                         |
								   |  ,------------------------------------
								   \_/___________________________________/ )" << endl;
	cout << endl;
	SetConsoleTextAttribute(h, 10);
	cout << R"(
								_________  /\                          
								\_   ___ \|  |__   ____   ______ ____  
								/    \  \/|  |  \_/ __ \ /  ___// __ \ 
								\     \____      \  ___/_\___ \(  \_\ )
								 \______  /___|  /\___  /____  \\____/ 
								        \/     \/     \/     \/        )" << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "\t" R"(
		.-------------------------------.
		| Pulsa Esc para volver al Menu |
		'-------------------------------')";

	if (!_kbhit())
	{  // Input asinc
		creditsAnsw = _getch();
	}
	if (creditsAnsw == ESC)
	{
		system("cls");
		returnValue = 0;
		return returnValue;
	}
	else
	{
		returnValue = 4;
		return returnValue;
	}
}
int showRules() // Funcion para mostrar el reglamento del juego
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	bool backToMainMenu = false;
	char point = 254;
	char horizontalRow = 205;	// linea horizontal ═
	char verticalColumn = 186; // linea vertical ║ 
	char uperLeftCorner = 201; // esquina superior izquierda ╔ 
	char uperRightCorner = 187; // esquina superior derecha ╗ 
	char lowerLeftCorner = 200; // esquina inferior izquierda ╚ 
	char lowerRightCorner = 188; // esquina inferior Derecha ╝ 

	system("cls");
	do
	{
		gotoXY(0,0);
		SetConsoleTextAttribute(h, 10);
		cout << R"(
						  _______     _______    _______    ___             __        ________  
						 /"      \   /"     "|  /" _   "|  |"  |           /""\      /"       ) 
						|:        | (: ______) (: ( \___)  ||  |          /    \    (:   \___/  
						|_____/   )  \/    |    \/ \       |:  |         /' /\  \    \___  \    
						 //      /   // ___)_   //  \ ___   \  |___     //  __'  \    __/  \\   
						|:  __   \  (:      "| (:   _(  _| ( \_|:  \   /   /  \\  \  /" \   :)  
						|__|  \___)  \_______)  \_______)   \_______) (___/    \___)(_______/   
						                                                                        )" << endl;
		SetConsoleTextAttribute(h, 14);
		gotoXY(45, 10);
		cout << point << " ";
		cout << "El juego consiste en hacer que la serpiente coma la fruta" << endl;
		gotoXY(45, 12);
		cout << point << " ";
		cout << "Cada vez que la serpiente coma una fruta la puntuacion de jugador aumenta" << endl;
		gotoXY(47, 13);
		cout << "Y la propia serpiente tambien aumenta en su tamanio , haciendo mas dificil el moverse" << endl;
		gotoXY(45, 15);
		cout << point << " ";
		cout << "La serpiente se mueve con las flechas del teclado < ^ v >" << endl;
		gotoXY(45, 17);
		cout << point << " ";
		cout << "Cuando la serpiente llega a el borde del tablero saldra por el lado contrario" << endl;
		gotoXY(45, 19);
		cout << point << " ";
		cout << "La serpiente no podra moverse a la direccion contraria a la direccion actual" << endl;
		gotoXY(47, 20);
		cout << "Es decir si estoy lledo para la derecha no puedo inmediatamente ir a la izquierda" << endl;
		gotoXY(47, 21);
		cout << "Tengo que primero cambiar mi direccion para arriba o abajo para poder ir a la izquierda" << endl;
		gotoXY(45, 23);
		cout << point << " ";
		cout << "Si la serpiente come su propio cuerpo muere y termina la partida" << endl;
		gotoXY(45, 25);
		cout << point << " ";
		cout << "Otra forma para ganar es llegando al puntaje de victoria que por default es 100" << endl;
		gotoXY(47, 26);
		cout << "Pero este valor como el color de la serpiente y el de la fruta son modificables" << endl;
		gotoXY(47, 27);
		cout << "En el menu de Opciones" << endl;
		gotoXY(45, 29);
		cout << point << " ";
		cout << "Mientras se esta jugando el jugador puede optar por pausar el juego con la barra espaciadora" << endl;
		gotoXY(47, 30);
		cout << "O si preciona el esc podra volver al menu principal" << endl;

		SetConsoleTextAttribute(h, 15);
		gotoXY(30, 33);
		cout << uperLeftCorner << horizontalRow << horizontalRow << horizontalRow << horizontalRow << horizontalRow << uperRightCorner << endl;
		gotoXY(30, 34);
		cout << verticalColumn << " Esc " << verticalColumn << " Volver al Menu Principal " << endl;
		gotoXY(30, 35);
		cout << lowerLeftCorner << horizontalRow << horizontalRow << horizontalRow << horizontalRow << horizontalRow << lowerRightCorner << endl;

		if (_kbhit())
		{
			char playerInput = _getch();
			if (playerInput == ESC)
			{
				backToMainMenu = true;
			}
		}
	} while (!backToMainMenu);
	system("cls");
	return 0;
}
bool showExitScreen() // muestra el mensaje de salida
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 12);
	system("cls");
	cout << R"(
					  .-')       ('-.                             ('-.        .-') _   _ .-') _                
					 ( OO ).    ( OO ).-.                       _(  OO)      ( OO ) ) ( (  OO) )               
					(_)---\_)   / . --. /  ,--.        ,-.-')  (,------. ,--./ ,--,'   \     .'_   .-'),-----. 
					/    _ |    | \-.  \   |  |.-')    |  |OO)  |  .---' |   \ |  |\   ,`'--..._) ( OO'  .-.  '
					\  :` `.  .-'-'  |  |  |  | OO )   |  |  \  |  |     |    \|  | )  |  |  \  ' /   |  | |  |
					 '..`''.)  \| |_.'  |  |  |`-' |   |  |(_/ (|  '--.  |  .     |/   |  |   ' | \_) |  |\|  |
					.-._)   \   |  .-.  | (|  '---.'  ,|  |_.'  |  .--'  |  |\    |    |  |   / :   \ |  | |  |
					\       /   |  | |  |  |      |  (_|  |     |  `---. |  | \   |    |  '--'  /    `'  '-'  '
					 `-----'    `--' `--'  `------'    `--'     `------' `--'  `--'    `-------'       `-----' )" << endl;
	system("pause");
	return false;
}
void showKeys(int xValue, int yValue)  // Funcion para mostrar los controles en el menu
{
	char uperLeftCorner = 201; // esquina superior izquierda ╔ 
	char uperRightCorner = 187; // esquina superior derecha ╗ 
	char lowerLeftCorner = 200; // esquina inferior izquierda ╚ 
	char lowerRightCorner = 188; // esquina inferior Derecha ╝ 
	char horizontalRow = 205;	// linea horizontal ═ 
	char verticalColumn = 186; // linea vertical ║ 
	char empty = 32;	// valor vacio en el tablero 

	gotoXY(xValue, yValue++);
	cout << uperLeftCorner << horizontalRow << horizontalRow << horizontalRow << uperRightCorner << endl;
	gotoXY(xValue, yValue++);
	cout << verticalColumn << " ^ " << verticalColumn << " Para Subir" << endl;
	gotoXY(xValue, yValue++);
	cout << lowerLeftCorner << horizontalRow << horizontalRow << horizontalRow << lowerRightCorner << endl;
	gotoXY(xValue, yValue++);
	cout << uperLeftCorner << horizontalRow << horizontalRow << horizontalRow << uperRightCorner << endl;
	gotoXY(xValue, yValue++);
	cout << verticalColumn << " v " << verticalColumn << " Para Bajar" << endl;
	gotoXY(xValue, yValue++);
	cout << lowerLeftCorner << horizontalRow << horizontalRow << horizontalRow << lowerRightCorner << endl;
	gotoXY(xValue - 2, yValue++);
	cout << uperLeftCorner << horizontalRow << horizontalRow << horizontalRow << horizontalRow << horizontalRow << horizontalRow << horizontalRow << uperRightCorner << endl;
	gotoXY(xValue - 2, yValue++);
	cout << verticalColumn << " Space " << verticalColumn << " Para Seleccionar" << endl;
	gotoXY(xValue - 2, yValue++);
	cout << lowerLeftCorner << horizontalRow << horizontalRow << horizontalRow << horizontalRow << horizontalRow << horizontalRow << horizontalRow << lowerRightCorner << endl;
}