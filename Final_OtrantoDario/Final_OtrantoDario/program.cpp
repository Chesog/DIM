#include "program.h"

void mainMenu()
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
int showMainMenu(int& pointerCursor)
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
	xValue = 10;
	yValue = 30;
	gotoXY(xValue, yValue);
	cout << uperLeftCorner << horizontalRow << horizontalRow << horizontalRow << uperRightCorner << endl;
	gotoXY(xValue, yValue + 1);
	cout << verticalColumn << " ^ " << verticalColumn << " Para Subir" << endl;
	gotoXY(xValue, yValue + 2);
	cout << lowerLeftCorner << horizontalRow << horizontalRow << horizontalRow << lowerRightCorner << endl;
	gotoXY(xValue, yValue + 3);
	cout << uperLeftCorner << horizontalRow << horizontalRow << horizontalRow << uperRightCorner << endl;
	gotoXY(xValue, yValue + 4);
	cout << verticalColumn << " v " << verticalColumn << " Para Bajar" << endl;
	gotoXY(xValue, yValue + 5);
	cout << lowerLeftCorner << horizontalRow << horizontalRow << horizontalRow << lowerRightCorner << endl;
	gotoXY(xValue - 2, yValue + 6);
	cout << uperLeftCorner << horizontalRow << horizontalRow << horizontalRow << horizontalRow << horizontalRow << horizontalRow << horizontalRow << uperRightCorner << endl;
	gotoXY(xValue - 2, yValue + 7);
	cout << verticalColumn << " Space " << verticalColumn << " Para Seleccionar" << endl;
	gotoXY(xValue - 2, yValue + 8);
	cout << lowerLeftCorner << horizontalRow << horizontalRow << horizontalRow << horizontalRow << horizontalRow << horizontalRow << horizontalRow << lowerRightCorner << endl;

	if (_kbhit)
	{
		answ = pointer((int)MenuStates::Exit, (int)MenuStates::Gameplay, pointerCursor);
		return answ;
	}
}
int optionsMenu(int& winPoints, int& headColor, int& bodyColor, int& foodColor, int& pointerCursor)
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
		if (optionsAnsw == 0)
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
		else if (optionsAnsw == (int)OptionsMenuStates::WinPointsCant)
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
						if (newWinPoints > maxWinPoints)
						{
							gotoXY(64, 26);
							cout << "Ingrese un numero Valido" << endl;
							gotoXY(64, 27);
							cout << "Borre el Numero e Ingrese uno Nuevo" << endl;
						}
						else
						{
							winPoints = newWinPoints;
							correctSet = true;
						}
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
		else if (optionsAnsw == (int)OptionsMenuStates::SnakeColor)
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
					headColor = 19;
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
		else if (optionsAnsw == (int)OptionsMenuStates::FruitColor)
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
		else if (optionsAnsw == (int)OptionsMenuStates::ExitToMainMenu)
		{
			exitMenu = true;
		}

		SetConsoleTextAttribute(h, 15);
		int xValue = 10;
		int yValue = 30;
		gotoXY(xValue, yValue);
		cout << uperLeftCorner << horizontalRow << horizontalRow << horizontalRow << uperRightCorner << endl;
		gotoXY(xValue, yValue + 1);
		cout << verticalColumn << " ^ " << verticalColumn << " Para Subir" << endl;
		gotoXY(xValue, yValue + 2);
		cout << lowerLeftCorner << horizontalRow << horizontalRow << horizontalRow << lowerRightCorner << endl;
		gotoXY(xValue, yValue + 3);
		cout << uperLeftCorner << horizontalRow << horizontalRow << horizontalRow << uperRightCorner << endl;
		gotoXY(xValue, yValue + 4);
		cout << verticalColumn << " v " << verticalColumn << " Para Bajar" << endl;
		gotoXY(xValue, yValue + 5);
		cout << lowerLeftCorner << horizontalRow << horizontalRow << horizontalRow << lowerRightCorner << endl;
		gotoXY(xValue - 2, yValue + 6);
		cout << uperLeftCorner << horizontalRow << horizontalRow << horizontalRow << horizontalRow << horizontalRow << horizontalRow << horizontalRow << uperRightCorner << endl;
		gotoXY(xValue - 2, yValue + 7);
		cout << verticalColumn << " Space " << verticalColumn << " Para Seleccionar" << endl;
		gotoXY(xValue - 2, yValue + 8);
		cout << lowerLeftCorner << horizontalRow << horizontalRow << horizontalRow << horizontalRow << horizontalRow << horizontalRow << horizontalRow << lowerRightCorner << endl;

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




//_kbhit(); -> Retorna verdadero o falso si la consola registra una tecla en el buffer.

//_getch(); -> Saca la tecla en el buffer del teclado.

 //while (!_kbhit())
 //        _cputs("Hit me!! ");

	 /* Use _getch to throw the key away. */
 //    printf("\nKey struck was '%c'\n", _getch());

//_putch(); -> escribe caracteres de unicode en la consola. 
//_ungetch(); -> Pone un carácter de vuelta al buffer de teclado