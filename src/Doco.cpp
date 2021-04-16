/*******************************************************************
* Doco.cpp
* Programming Assignment 1: DOCO Simulated World
* Author: Benson Mwangi
* Date: October 2014
*
* This program is entirely my own work
*******************************************************************/
#include <iostream>
#include "Doco.h"
#include "DocoWorld.h"

//----------------------------------------------------
// constructor with params
//----------------------------------------------------
Doco::Doco(int x, int y)
{
	xPosition = x;	//x coordinate of doco
	yPosition = y;	//y coordinate of doco
	heading = 0; //
	energyLevel = 500;	// initialize energy level at 500
	movement = '\0';//movement style is random
}

//--------------------------------------------------------------
//default constructor
//--------------------------------------------------------------
Doco::Doco(void)
{
	xPosition = 0;	//
	yPosition = 0;	//
	heading = 0; //
	energyLevel = 500;	// initialize energy level at 500
	movement = '\0';//movement style is random
}

//------------------------------------------------
// default destructor
//------------------------------------------------
Doco::~Doco(void)
{
}

//------------------------------------------------
// getMovement returns the docos movement
//------------------------------------------------
void Doco::setMovement(char m)
{
	this->movement = m;
}

//------------------------------------------------
// setEnergyLevel sets energy level of doco
//------------------------------------------------
void Doco::setEnergyLevel(int f)
{
	this->energyLevel = f;
}

//------------------------------------------------
// setXPosition sets the x position of doco
//------------------------------------------------
void Doco::setXPosition(int x)
{
	xPosition = x;
}

//------------------------------------------------
// setYPosition sets the y position of the doco
//------------------------------------------------
void Doco::setYPosition(int y)
{
	this->yPosition = y;
}

void Doco::setHeading(int h)
{
	heading = h;
}

//------------------------------------------------
// getXPosition returns the x position of doco
//------------------------------------------------
int Doco::getXPosition()
{
	return xPosition; //return address of the x position
}

//------------------------------------------------
// getYPosition returns the y position of doco
//------------------------------------------------
int Doco::getYPosition()
{
	return yPosition; //return address of the x position
}

//------------------------------------------------
// default destructor
//------------------------------------------------
int Doco::getEnergyLevel()
{
	return energyLevel;
}

//------------------------------------------------
// getHeading returns the heading of the doco
//------------------------------------------------
int Doco::getHeading()
{
	return heading;
}

//------------------------------------------------
// getMovement returns the docos movement
//------------------------------------------------
char Doco::getMovement()
{
	return movement;
}


/*------------------------------------------------
 *  move moves the doco to a new cell
 *
------------------------------------------------*/
void Doco::move(DocoWorld *dwp)
{
	int x =-1; 					// possible x, y co-ords of cell...
	int y =-1; 					// initialize to invalid values
	int food = 0; 				// indicate when food is 'sniffed'
	int foodHeading =-1;		// heading towards food or -1 if no food is found
	int currentHeading =-1; 	// current heading or -1 if current heading is invalid
	int newHeading =-1; 		// doco's final heading
	vector <int> validHeading; 	// vector of all valid headings doco can take

	// scan all headings for a valid heading (i.e. heading that leads to a cell doco can occupy)
	for (auto h : {NORTH, NORTHEAST, EAST, SOUTHEAST, SOUTH, SOUTHWEST, WEST, NORTHWEST})
	{
		//given a heading, generate a cell's co-ordinates
		getXYLocation(h, &x, &y);

		// x and y values must be within the doco world boundaries
		if(x >= 0 && x < dwp->getWidth() && y >= 0 && y < dwp->getHeight())
		{
			if(dwp->getCellGrid()[x][y].getDoco() == nullptr) //if cell is un-occupied
			{
				// if cell has more food than previously found food..
				if(food < dwp->getCellGrid()[x][y].getFoodAmount())
				{
					food = dwp->getCellGrid()[x][y].getFoodAmount();// save food amount;
					foodHeading = h; 								// set as new food heading
				}

				// if current heading is also a valid heading
				if(heading == h)
				{
					currentHeading = h; // set as current heading
				}
				validHeading.push_back(h); // save all valid headings for later check
			}
		}
	}

	// if current heading is still valid,
	if(currentHeading != -1){//
		newHeading = currentHeading;
	}

	// override current heading, go for largest amount of food!
	if(foodHeading != -1){//
		newHeading = foodHeading;
	}

	// determine final cell to move to
	pickNewCell(newHeading, validHeading, dwp);
}

/* getXYLocation method gets current heading, and returns
 * new X, Y positions by setting values into pointed vars.*/
void Doco::getXYLocation(int heading, int *x, int *y)
{
	switch(heading)
	{
		case NORTH:
			*x = xPosition; *y = yPosition-1;//go north
			break;
		case NORTHEAST:
			*x = xPosition+1; *y = yPosition-1;//go north-east
			break;
		case EAST:
			*x = xPosition+1; *y = yPosition;//go east
			break;
		case SOUTHEAST:
			*x = xPosition+1; *y = yPosition+1; //go south-east
			break;
		case SOUTH:
			*x = xPosition; *y = yPosition+1; //go south
			break;
		case SOUTHWEST:
			*x = xPosition-1; *y = yPosition+1; //go south-west
			break;
		case WEST:
			*x = xPosition-1; *y = yPosition; //go west
			break;
		case NORTHWEST:
			*x = xPosition-1; *y = yPosition-1; //go north-west
	}
}

//------------------------------------------------
//eat - increases doco's energy level
//------------------------------------------------
void Doco::eat(DocoWorld *dwp){
	int food = dwp->getCellGrid()[xPosition][yPosition].getFoodAmount();// new cell's food amount
	dwp->getCellGrid()[xPosition][yPosition].setFoodAmount(0);			// no more food in cell
	energyLevel += 50*food;												// energy gain is 50 for each food unit
}

//------------------------------------------------
// prints doco's representation
//------------------------------------------------
char Doco::toString(){
	return '*'; // doco representation
}

//------------------------------------------------
// determines the final cell to move to
//------------------------------------------------
void Doco::pickNewCell(int h, vector<int> vHeading, DocoWorld *dwp)
{
	int x = -1;
	int y = -1;
	int xPos = xPosition;
	int yPos =  yPosition;

	// if no food is found in surrounding cells and
	// current heading is invalid, pick new heading at random
	if (h == -1 )
	{
		int index = rand() % int (vHeading.size());
		h = vHeading[index];// pick at random from valid headings
	}

	// determine final x, y coordinates to move to
	getXYLocation(h, &x, &y);

	//if doco has energy, effect the move
	if(energyLevel >= 10) {
		heading  = h;								// doco's new heading
		xPosition = x;   							// doco's new x position
		yPosition = y;								// doco's new y position
		energyLevel -= 10;									// use 10 energy-units to move
		dwp->getCellGrid()[xPos][yPos].setDoco(nullptr); // vacate old cell
		dwp->getCellGrid()[x][y].setDoco(this); // occupy new cell
	}
}
