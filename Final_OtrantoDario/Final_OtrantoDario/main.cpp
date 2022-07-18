#include "program.h"
#include <time.h>


int main()
{
	float frameRate;
	frameRate = clock() % 10 == 0;
	mainMenu(frameRate);
}
