// File Name: ShapeAnimator.h
// Name of Author: Nicholas Kahlor
// Course Number and Name: CSE 220, Programming for Computer Engineering
// Semester: Fall 2016
// Lab Project Number: 2
// Time Spent: Too long
#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
#include "TerminalAnimation.h"

using namespace std;
// A shape has a direction and is able to move in that direction.
// The move is a virtual member function.
class Shape
{
	private:
		int dRow;
		int dCol;
	public:
		virtual void setDirection(int,int);
		void getDirection(int&,int&);
		virtual void move() = 0; //pure virtual move function
		virtual ~Shape();
};
// A SimpleShape can be drawn at a given position in a specified color
// A SimpleShape inherits from Shape class
class SimpleShape : public Shape
{
private:
	int rowPos;
	int colPos;
	int color;
public:
	void getPosition(int &row,int &col);
	void setPosition(int row,int col);
	int getColor();
	void setColor(int c);
	virtual void move();
	virtual void draw() = 0; //pure virtual function
	virtual ~SimpleShape(); //destructor

};
// A Box is a rectangular type of shape
// A Box inherits from SimpleShape
class Box : public SimpleShape
{
private:
	int width;
	int height;

public:
	Box(int rowPos,int colPos,int width, int height);	//constructor

	virtual void draw();
	virtual ~Box();			//destructor
};
// A Tent is an isosceles triangle whose horizontal base has a
// given length and whose height is half the length of the base.
// The position of the triangle is the left endpoint of the base
// A Tent inherits from SimpleShape
class Tent : public SimpleShape
{
private:
	int baseLength;
public:
	Tent(int baseRowPos,int baseColPos,int baseLength);
	virtual void draw();
	virtual ~Tent(); //destructor
};
// A ComplexShape is made up of simpler shapes. It is represented
// as a vector of pointers to the simpler shapes that make it up
// A ComplexShape inherits from Shape

class ComplexShape : public Shape
{
public:
    ComplexShape(Shape ** shapeCollection, int shapesCount);
    virtual void move();
    virtual ~ComplexShape();
private:
    vector<Shape *> shapes;
};

