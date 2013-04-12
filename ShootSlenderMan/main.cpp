#include <iostream>
#include <string>
#include <Windows.h>
#include <MMSystem.h>
#include <conio.h>
#include <fstream>

// Include the classes:

#include "controlWindows.h"

// Set up function prototypes

int setMenu();

int main(){
	
	setMenu();
	return 0;

}

int setMenu(){

	// Set the console object
	controlWindows currentConsole;

	// Set up the menuScreenOptionsVector

	vector <string> menuScreenOptionsVector;

	// Set up the indexnumber

	int indexnumber;

	// Set up the key click variable and the splash screen variable
	
	char ch;
	string splashstring;

	// Set up the current console
	
	currentConsole.setWindows("title","Shoot SlenderMan");
	currentConsole.setWindows("color","C");
	currentConsole.setWindows("backgroundMusic","theme.wav");
	
	// Set the first title screen
	
	currentConsole.createScreen("title","\n\n\n\n\t\t\t\tSHOOT SLENDERMAN\n\n\n\n\n\n\t\t\t\tAn 8-Bit Game (press Enter)");
	currentConsole.swapScreen("title");
	getchar();


	// Create the menuOptions screens and load them into the vector
	
	currentConsole.createScreen("menuOnPlay","\n\n\n\t\t=====================================\n\n\t\t\t\tMENU\n\n\n\t\t\t\t->Play\n\t\t\t\tHelp\n\t\t\t\tExit\n\t\t=====================================\n");
	menuScreenOptionsVector.push_back("menuOnPlay");

		// Switch to first menu options screen
		currentConsole.swapScreen("menuOnPlay");

	currentConsole.createScreen("menuOnHelp","\n\n\n\t\t=====================================\n\n\t\t\t\tMENU\n\n\n\t\t\t\tPlay\n\t\t\t\t->Help\n\t\t\t\tExit\n\t\t=====================================\n");
	menuScreenOptionsVector.push_back("menuOnHelp");
		
	currentConsole.createScreen("menuOnExit","\n\n\n\t\t=====================================\n\n\t\t\t\tMENU\n\n\n\t\t\t\tPlay\n\t\t\t\tHelp\n\t\t\t\t->Exit\n\t\t=====================================\n");
	menuScreenOptionsVector.push_back("menuOnExit");
	
	ifstream in("splash.txt");
	getline(in , splashstring);
	
	currentConsole.createScreen("splashScreen",splashstring);


	while(1==1){

		if(_kbhit()){
			
			ch = getch();
			
			// Code for down key press
			
			if(ch == 's'){
				
				// Find the position of the current screen in our screen number vector
				
				indexnumber = currentConsole.findPositionOf(menuScreenOptionsVector, currentConsole.getCurrentScreen());	
				
				// Swap to the next screen (next menu item)

				if(currentConsole.getCurrentScreen() != "menuOnExit"){          /*ONLY IF WE DON'T GO OUT OF VECTOR RANGE*/
				
					currentConsole.swapScreen(menuScreenOptionsVector[indexnumber+1]);
				}
			
			}

			// Code for up key press
			
			if(ch == 'w'){
				
				// Find the position of the current screen in our screen number vector
				
				indexnumber = currentConsole.findPositionOf(menuScreenOptionsVector, currentConsole.getCurrentScreen());	
				
				// Swap to the previous screen (previous menu item)

				if(currentConsole.getCurrentScreen() != "menuOnPlay"){          /*ONLY IF WE DON'T GO OUT OF VECTOR RANGE*/
					currentConsole.swapScreen(menuScreenOptionsVector[indexnumber-1]);	
				}
			}

			if((int)ch == 13){
				
				if(currentConsole.getCurrentScreen() == "menuOnPlay"){
					currentConsole.swapScreen("splashScreen");			
				}

				if(currentConsole.getCurrentScreen() == "menuOnExit"){
					return 0;			
				}
					
			
			}
		}
	
	}


}