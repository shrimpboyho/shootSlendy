#include <iostream>
#include <string>
#include <Windows.h>
#include <vector>
#include <MMSystem.h>
#include "controlWindows.h"

// Methods that use std:

using namespace std;

void controlWindows::setTextColor(int colorcmd){

	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hcon,colorcmd);

}

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


void controlWindows::flush(){
	system("cls");
}

void controlWindows::createScreen(string screenName, string screenContent){

	screenNameStorage.push_back(screenName);
	screenContentStorage.push_back(screenContent);

}

void controlWindows::swapScreen(string specificName){

	int i;

	for(i = 0; i < screenNameStorage.size(); i++){

		if(specificName == screenNameStorage[i]){
			break;
		}

	}
	
	flush();
	std::cout << screenContentStorage[i];
	currentScreen = screenNameStorage[i];

}

string controlWindows::getCurrentScreen(){
	return currentScreen;
}

int controlWindows::findPositionOf(vector<string> bankgiven,string stringgiven){
	
	int position;
	int i;

	for(i = 0; i < bankgiven.size(); i++){

		if(bankgiven[i] == stringgiven){			
			position = i;
			break;		
		}

	}

	return position;
}