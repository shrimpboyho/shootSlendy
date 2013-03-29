#include <iostream>
#include <string>
#include <Windows.h>
#include <MMSystem.h>
#include "controlWindows.h"


void controlWindows::setWindows(string element, string customization){

	if(element == "color"){
		string command = element + " " + customization;
		system(command.c_str());
	}
	if(element == "title"){
		SetConsoleTitle(customization.c_str());
	}
	if(element == "backgroundMusic"){
		PlaySound(TEXT(customization.c_str()),  NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
	}
	

}
