#include <iostream>
#include <string>
#include <Windows.h>
#include <MMSystem.h>

// Include the classes:

#include "controlWindows.h"



int main(){
	
	// Set the console object
	controlWindows currentConsole;
	
	// Set up teh current console
	
	currentConsole.setWindows("title","Shoot SlenderMan");
	currentConsole.setWindows("color","A1");
	currentConsole.setWindows("backgroundMusic","theme.wav");
	
	// Set the first console text
	currentConsole.setTextColor(1);
	std::cout << "Shoot Slenderman!" << endl;

	system("pause");
	return 0;

}

