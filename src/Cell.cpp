/*******************************************************************
* Cell.h
* Programming Assignment 1: DOCO Simulated World
* Author: Benson Mwangi
* Date: October 2014
*
* This program is entirely my own work
*******************************************************************/

#include "Cell.h"

//------------------------------------------------
// default constructor
//------------------------------------------------
Cell::Cell()
{
	xPosition = 0; 	// cell x position
	yPosition = 0;	// cell y position
	foodAmount = 0; // initial food amount is zero
	doco = nullptr;	// initialize doco to null
}

//------------------------------------------------
// default destructor
//------------------------------------------------
Cell::~Cell(void)
{
}
//------------------------------------------------
// set x position of cell
//------------------------------------------------
void Cell::setXPosition(int x)
{
	xPosition = x;
}

//------------------------------------------------
// set Y position of cell
//------------------------------------------------
void Cell::setYPosition(int y)
{
	yPosition = y;
}

//------------------------------------------------
// sets the amount of food in cell
//------------------------------------------------
void Cell::setFoodAmount(int f)
{
	foodAmount =  f;
}

//------------------------------------------------
// set pointer of occupying doco for this cell
//------------------------------------------------
void Cell::setDoco(Doco *d){
	doco = d;
}

//------------------------------------------------
// return x position of cell
//------------------------------------------------
int Cell::getXPosition()
{
	return xPosition; 
}

//------------------------------------------------
// return Y position of cell
//------------------------------------------------
int Cell::getYPosition()
{
	return yPosition; 
}

//------------------------------------------------
// return amount of food in cell
//------------------------------------------------
int Cell::getFoodAmount()
{
	return foodAmount;
}

//------------------------------------------------
// return occupying doco
//------------------------------------------------
Doco *Cell::getDoco(){
	return doco;
}

//------------------------------------------------
// return appropriate char representation of cell
//------------------------------------------------
char Cell::toString(){
	if (this->doco != nullptr)
		return this->doco->toString();// occupying doco
	else if(this->foodAmount != 0 )
		return '.';					  // food
	else
		return '-'; 				  // unoccupied cell
}
