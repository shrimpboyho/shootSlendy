#include <iostream>
#include <Windows.h>
#include <MMSystem.h>

using namespace std;

int main(){
	std::cout << "Shoot Slenderman!" << endl;
	PlaySound(TEXT("theme.wav"), NULL, SND_SYNC);
	system("pause");
	return 0;
}