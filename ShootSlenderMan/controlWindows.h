#ifndef CONTROLWINDOWS_H
#define CONTROLWINDOWS_H

#include <vector>
using namespace std;

class controlWindows{

	private:
		vector<string> screenNameStorage;
		vector<string> screenContentStorage;
		string currentScreen;                   // A variable used to store the current screen index
	
	public:
		controlWindows(){};
		void setWindows(string,string);
		void setTextColor(int);
		void createScreen(string,string);
		void swapScreen(string);
		void flush();
		string getCurrentScreen();
	
};

#endif