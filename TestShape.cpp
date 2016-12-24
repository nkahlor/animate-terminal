// File Name: ShapeAnimator.h
// Name of Author: Nicholas Kahlor
// Course Number and Name: CSE 220, Programming for Computer Engineering
// Semester: Fall 2016
// Lab Project Number: 2
// Time Spent: Too long

#include "ShapeAnimator.h"
#include "TerminalAnimation.h"

int main()
{
    // Create a tent and a box according to the requirements
	TerminalAnimation CONTROL;
	Box *box = new Box(5,65,4,7);
	Tent *tent = new Tent(11,5,13);

    // Draw the tent and the box
	box->draw();
	tent->draw();
	//set their directions
	box->setDirection(0,-1);
	tent->setDirection(0,1);

    // Tent moves straight up
    // Box moves horizontally to the right

    // Simultaneously move the tent and the box
    for (int k = 0; k < 12; k++)
    {
        usleep(75*1000);
        tent->move();
        box->move();
    }

    // Move the box farther to the right
    for (int k = 0; k < 25; k++)
    {
        usleep(75*1000);
        box->move();
    }
    Shape *myShapes[] = {tent, box};

    // Create a complex shape composed of the tent and the box
    // Hints: you need to plug in above myShapes array
    ComplexShape *complex = new ComplexShape(myShapes,2);

    // Set directions for the two shapes
    // tent moving direction is straight right

    tent->setDirection(0,1);
    // box moving direction is straight up

    box->setDirection(1,0);
    // Move the complex shape: this will move both the tent and the box

    for (int k = 0; k < 12; k++)
    {
    	complex->move();
        usleep(75*1000);
    }
    // Continue moving the box by itself

    box->setDirection(0,1);
    for (int k = 0; k < 36; k ++)
    {
    	box->move();
        usleep(75*1000);
    }

	CONTROL.SetConsoleCursorPosition(100,100);
	CONTROL.SetConsoleTextAttribute(0);
	std::cout<<std::endl;
    return 0;
}

