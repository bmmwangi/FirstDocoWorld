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
	int newXPos, newYPos, newHeading = -1; 					// doco's new (x, y) and heading
	int xPos = xPosition; 									// save doco's current position
	int yPos = yPosition;

	//  get valid headings based on doco's position
	vector <int> vHeading = scanSurroundings(dwp);			// get valid headings

	// if current heading is still valid,
	newHeading = checkCurrentHeading(vHeading); // continue in same heading

	// override heading, go towards largest amount of food!
	if(smellFood(dwp, vHeading) != -1){//
		newHeading = smellFood(dwp, vHeading);
	}

	// if no food is found in surrounding cells
	// and current heading is invalid, pick new heading
	if (newHeading == -1 )
	{
		int index = rand() % int (vHeading.size());
		newHeading = vHeading[index];// pick at random from valid headings
	}

	// determine final x, y coordinates to move to
	getXYLocation(newHeading, &newXPos, &newYPos);

	//if doco has energy, effect the move
	if(energyLevel >= 10) {
		heading  = newHeading;								// doco's new heading
		xPosition = newXPos;   							// doco's new x position
		yPosition = newYPos;								// doco's new y position
		energyLevel -= 10;									// use 10 energy-units to move
		dwp->getCellGrid()[xPos][yPos].setDoco(nullptr); // vacate old cell
		dwp->getCellGrid()[newXPos][newYPos].setDoco(this); // occupy new cell
	}
}

/* Scans for existence of valid cells around the current cell of occupation...
 * when this method is called, it returns headings that lead to valid cells
 * that DOCO MAY move to, adding them to a vector of valid headings. */
vector <int> Doco::scanSurroundings(DocoWorld *dwp)
{
	vector<int> validHeading; // vector of headings doco can take
	int x=-1;
	int y=-1; //initialize temp x, y to invalid values

	// for each direction, check if there is a cell and if the cell is unoccupied
	for (auto heading : {NORTH, NORTHEAST, EAST, SOUTHEAST, SOUTH, SOUTHWEST, WEST, NORTHWEST})
	{ //get cell coordinates given doco position & heading
		getXYLocation(heading, &x, &y);
		if(x >= 0 && x < dwp->getWidth() && y >= 0 && y < dwp->getHeight())
		{//x and y values must be within the doco world boundaries to be valid
			if(dwp->getCellGrid()[x][y].getDoco() == nullptr)//cell is un-occupied
			{
				validHeading.push_back(heading);// heading is valid, add to container
			}
		}
	}
	return validHeading;
}

/* smellFood scans for food in cells next to current x,y location and
 * returns the heading with largest amount of food. If no food is found
 * -1 is returned*/
int Doco::smellFood(DocoWorld *dwp, vector<int> vHeading)
{
	int food = 0;
	int x = -1;
	int y = -1;
	int fHeading =-1;

	for(int i=0; i<int (vHeading.size()); i++)
	{
		getXYLocation(vHeading[i], &x, &y);
		if(food < dwp->getCellGrid()[x][y].getFoodAmount())
		{
			food = dwp->getCellGrid()[x][y].getFoodAmount();// cell's food amount;
			fHeading = vHeading[i]; 						//food heading; move towards food
		}
	}
	return fHeading;
}

/* Checks if current doco heading is still valid and
 * returns heading if it is. Otherwise returns -1 (invalid heading)*/
int Doco::checkCurrentHeading(vector<int> vHeading)
{
	for(int i=0; i< int (vHeading.size()); i++)
	{
		if(vHeading[i] == heading){
			return heading; // heading is valid!
		}
	}
	return -1;
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
//eat - replenishes doco's energy level
//------------------------------------------------
char Doco::toString(){
	return '*'; //doco representation
}
