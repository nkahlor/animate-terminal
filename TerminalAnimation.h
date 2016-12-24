#ifndef TERMINALANIMATION_H
#define TERMINALANIMATION_H

#include <cstring>
#include <string>
#include <unistd.h>
#include <iostream>
#include <sstream>

class TerminalAnimation
{
private:
	void ANSICode(int num, char command);
public:
	void SetConsoleCursorPosition(int xCoord,int yCoord);
	void SetConsoleTextAttribute(int color);
};

#endif
