// File Name: ShapeAnimator.h
// Name of Author: Nicholas Kahlor
// Course Number and Name: CSE 220, Programming for Computer Engineering
// Semester: Fall 2016
// Lab Project Number: 2
// Time Spent: Too long

#include "ShapeAnimator.h"
//*************************************************************
// Moves a simple shape one step by erasing the shape         *
// at its current position, changing its position, and then   *
// redrawing the shape at its new position.                   *
//*************************************************************
TerminalAnimation CONTROL;
/* setters and getters for shape */
void Shape::getDirection(int &row, int &col)
{
	row = this->dRow;
	col = this->dCol;
}
void Shape::setDirection(int row, int col)
{
	this->dRow = row;
	this->dCol = col;
}
/* setters and getters for simple shape */
void SimpleShape::getPosition(int &row, int &col)
{
	col = this->colPos;
	row = this->rowPos;
}
void SimpleShape::setPosition(int row, int col)
{
	this->colPos = col;
	this->rowPos = row;
}
int SimpleShape::getColor()
{
	return this->color;
}
void SimpleShape::setColor(int c)
{
	this->color = c;
}
void SimpleShape::move()
{
    int dRow, dCol; // Direction of motion
    int savedColor = color;
    color = 30;      // Drawing in color 30 erases the shape (if background is black)
    this->getDirection(dRow,dCol);
    this->setColor(color);
    this->setPosition(this->rowPos,this->colPos);
    this->draw(); //object erased

    this->setColor(savedColor);  //return saved color
    this->setPosition(this->rowPos+dRow,this->colPos+dCol); //add directional offset
    this->draw();
}
//***********************************
// Draws a tent at its position     *
//***********************************
void Tent::draw()
{
    int rowPos, colPos;

    int currentLength = baseLength;
    // Set the color attribute
    CONTROL.SetConsoleTextAttribute(this->getColor());
    this->getPosition(rowPos,colPos);
    int baseColPos = colPos;
    // Draw the lines that form the tent beginning with
    // the base and moving up toward the point
    for (int r = 0; r < baseLength; r++)
    {
       for(int j = 0; j < currentLength;j++)
       {
    	   CONTROL.SetConsoleCursorPosition(rowPos,colPos+r); //each pass increases column position by 1
    	   write(1,"#",1); 		// increments cursor position
    	   colPos++;
       }
       currentLength -= 2;
       colPos = baseColPos;  //reset column position
       rowPos--;
    }
}
//**********************************
// Draws a box shape               *
//**********************************
void Box::draw()
{
   int rowPos, colPos;
   this->getPosition(rowPos,colPos);
   int baseColPos = colPos;
    // Set the color attribute for the box
   CONTROL.SetConsoleTextAttribute(this->getColor());
    // Draw the lines that make up the  box
    for (int r = 0; r < height; r++)
    {
        for(int j = 0; j < width; j++)
        {
        	CONTROL.SetConsoleCursorPosition(rowPos,colPos);
	       	write(1, "*", 1);
        	colPos++;
        }
        colPos = baseColPos;
        rowPos++;
    }
}
//***********************************************
// Box Constructor sets the color, position,    *
// dimensions for a box shape, and draws        *
// the box at its initial position              *
//***********************************************
Box::Box(int rowPos,int colPos,int width, int height)
{
	this->width = width;
	this->height = height;
	setPosition(rowPos,colPos);
    setColor(6+30);	//cyan
}

//***********************************************
// Constructor sets the color for a Tent shape, *
// sets the position of the tent as well as the *
// length of its base and draws it at its       *
// initial position                             *
//***********************************************
Tent::Tent(int baseRowPos,int baseColPos,int baseLength)
{
	setPosition(baseRowPos,baseColPos);
	this->baseLength = baseLength;
   	setColor(5+30);	//red
}

/* Destructors */
Shape::~Shape(){}
SimpleShape::~SimpleShape(){}
Box::~Box(){}
Tent::~Tent(){}

//*********************************************************************
// Constructor builds a complex shape by assembling a vector of       *
// constituent shapes                                                 *
//*********************************************************************

ComplexShape::ComplexShape(Shape ** shapeCollection, int shapesCount)
{
    Shape *p;
    for (int k = 0; k < shapesCount; k++)
    {
        p = shapeCollection[k];
        shapes.push_back(p);
    }
}

//**************************************
// Moves a complex shape by moving the *
// constituent shapes                  *
//**************************************
void ComplexShape::move()
{
	shapes[1]->move();
	shapes[0]->move();

}
ComplexShape::~ComplexShape(){}
