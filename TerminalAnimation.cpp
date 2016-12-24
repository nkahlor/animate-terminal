#include "TerminalAnimation.h"

void TerminalAnimation::ANSICode(int num, char command)
{
	std::stringstream ss;
	int strSize;
	ss<<"\33["; //add escape sequence to string
	ss<<num; //add number component
	ss<<command; //specify the command
	strSize = ss.str().length(); //the length of the command

	const char *code = (char*) malloc (strSize * sizeof(char)); //char array of size of the command
	code = const_cast<char*>(ss.str().c_str()); //cast the string from the sstream into the char array

	write(1,code,strlen(code)); //writes the code to the console
}
/* sets the color of the text on the console, or resets the color to default */
void TerminalAnimation::SetConsoleTextAttribute(int color)
{
	ANSICode(color,'m'); //changes the color of the text
}
/* sets the position of the cursor on the console */
void TerminalAnimation::SetConsoleCursorPosition(int xCoord,int yCoord)
{
	std::stringstream ss;
	ss<<"\33["<<xCoord<<";"<<yCoord<<"f";
	const char *code = (char*)malloc(8*sizeof(char)); //char array of size 8
	code = const_cast<char*>(ss.str().c_str());
	write(1,code,strlen(code));
}
