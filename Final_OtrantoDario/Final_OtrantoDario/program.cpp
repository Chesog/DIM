#include "program.h"

void mainMenu()
{
	hidecursor();
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
	SetConsoleTitle((L"Descend Into Madness"));
	bool gameOn = true;
	int menuAnsw = 0;
	int pointerCursor = 1;
	do
	{
		switch (menuAnsw)
		{
		case (int)MenuStates::MainMenu:
			menuAnsw = showMainMenu(pointerCursor);
			break;
		case (int)MenuStates::Gameplay:
			menuAnsw = gameplay();
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
	char verticalColumn = 186; // linea vertical ║ 
	char horizontalRow = 205;	// linea horizontal ═ 
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
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	if (pointerCursor == (int)MenuStates::Gameplay)
	{
		SetConsoleTextAttribute(h, 160);
	}
	gotoXY(80, 19);
	cout << ".-------." << endl;
	gotoXY(80, 20);
	cout << "| Jugar |" << endl;
	gotoXY(80, 21);
	cout << "'-------'" << endl;
	cout << endl;
	SetConsoleTextAttribute(h, 10);
	if (pointerCursor == (int)MenuStates::Rules)
	{
		SetConsoleTextAttribute(h, 160);
	}
	gotoXY(80, 23);
	cout << ".--------." << endl;
	gotoXY(80, 24);
	cout << "| Reglas |" << endl;
	gotoXY(80, 25);
	cout << "'--------'" << endl;
	cout << endl;
	SetConsoleTextAttribute(h, 10);
	if (pointerCursor == (int)MenuStates::Credits)
	{
		SetConsoleTextAttribute(h, 160);
	}
	gotoXY(79, 27);
	cout << ".----------." << endl;
	gotoXY(79, 28);
	cout << "| Creditos |" << endl;
	gotoXY(79, 29);
	cout << "'----------'" << endl;
	cout << endl;
	SetConsoleTextAttribute(h, 10);
	if (pointerCursor == (int)MenuStates::Exit)
	{
		SetConsoleTextAttribute(h, 160);
	}
	gotoXY(80, 31);
	cout << ".-------." << endl;
	gotoXY(80, 32);
	cout << "| Salir |" << endl;
	gotoXY(80, 33);
	cout << "'-------'" << endl;
	cout << endl;
	SetConsoleTextAttribute(h, 10);
	gotoXY(130,20);
	cout << uperLeftCorner << horizontalRow << horizontalRow << horizontalRow << uperRightCorner << endl;
	gotoXY(130, 21);
	cout << verticalColumn << " ^ " << verticalColumn << " Para Subir" << endl;
	gotoXY(130, 22);
	cout << lowerLeftCorner << horizontalRow << horizontalRow << horizontalRow << lowerRightCorner << endl;
	gotoXY(130, 23);
	cout << uperLeftCorner << horizontalRow << horizontalRow << horizontalRow << uperRightCorner << endl;
	gotoXY(130, 24);
	cout << verticalColumn << " v " << verticalColumn << " Para Bajar" << endl;
	gotoXY(130, 25);
	cout << lowerLeftCorner << horizontalRow << horizontalRow << horizontalRow << lowerRightCorner << endl;
	gotoXY(128, 26);
	cout << uperLeftCorner << horizontalRow << horizontalRow << horizontalRow << horizontalRow << horizontalRow << horizontalRow << horizontalRow << uperRightCorner << endl;
	gotoXY(128, 27);
	cout << verticalColumn << " Space " << verticalColumn << " Para Seleccionar" << endl;
	gotoXY(128, 28);
	cout << lowerLeftCorner << horizontalRow << horizontalRow << horizontalRow << horizontalRow << horizontalRow << horizontalRow << horizontalRow << lowerRightCorner << endl;

	if (_kbhit)
	{
		answ = pointer((int)MenuStates::Exit, (int)MenuStates::Gameplay, pointerCursor);
		return answ;
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
	cout << "\t" R"(
		.-----------------------------.
		| Pulsa P para volver al Menu |
		'-----------------------------')";

	if (!_kbhit())
	{  // Input asinc
		creditsAnsw = _getch();
	}
	if (creditsAnsw == 'P')
	{
		system("cls");
		returnValue = 0;
		return returnValue;
	}
	else if (creditsAnsw == 'p')
	{
		system("cls");
		returnValue = 0;
		return returnValue;
	}
	else
	{
		returnValue = 3;
		return returnValue;
	}
}



//_kbhit(); -> Retorna verdadero o falso si la consola registra una tecla en el buffer.

//_getch(); -> Saca la tecla en el buffer del teclado.

 //while (!_kbhit())
 //        _cputs("Hit me!! ");

	 /* Use _getch to throw the key away. */
 //    printf("\nKey struck was '%c'\n", _getch());

//_putch(); -> escribe caracteres de unicode en la consola. 
//_ungetch(); -> Pone un carácter de vuelta al buffer de teclado