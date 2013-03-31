#include <iostream>
#include <string>
#include <Windows.h>
#include <MMSystem.h>
#include <conio.h>

// Include the classes:

#include "controlWindows.h"



int main(){
	
	// Set the console object
	controlWindows currentConsole;

	// Set up the key click variable
	
	char ch;

	// Set up teh current console
	
	currentConsole.setWindows("title","Shoot SlenderMan");
	currentConsole.setWindows("color","C");
	currentConsole.setWindows("backgroundMusic","theme.wav");
	
	// Set the first title screen
	
	currentConsole.createScreen("title","\n\n\n\n\t\t\t\tSHOOT SLENDERMAN\n\n\n\n\n\n\t\t\t\tAn 8-Bit Game (press Enter)");
	currentConsole.swapScreen("title");
	getchar();
	currentConsole.createScreen("menuOnPlay","\n\n\n\t\t=====================================\n\n\t\t\t\tMENU\n\n\n\t\t\t\t->Play\n\t\t\t\tExit\n\t\t=====================================\n");
	currentConsole.swapScreen("menuOnPlay");
	currentConsole.createScreen("menuOnExit","\n\n\n\t\t=====================================\n\n\t\t\t\tMENU\n\n\n\t\t\t\tPlay\n\t\t\t\t->Exit\n\t\t=====================================\n");
	
	while(1==1){

		if(_kbhit()){
			
			ch = getch();
			
			if(ch == 's'){
				currentConsole.swapScreen("menuOnExit");
				
			}
			if(ch == 'w'){
				currentConsole.swapScreen("menuOnPlay");
				
			}
		}
	
	}

	system("pause");
	return 0;

}

