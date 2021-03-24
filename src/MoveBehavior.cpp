/*******************************************************************
* MoveBehavior.cpp
* Programming Assignment 1: DOCO Simulated World
* Author: Benson Mwangi
* Date: October 2014
*
* This program is entirely my own work
*******************************************************************/
#include "MoveBehavior.h"
#include "DocoWorld.h"

//------------------------------------------------
// constructor
//------------------------------------------------
MoveBehavior::MoveBehavior(DocoWorld *dwPtr)
{
	docoWorldPtr = dwPtr;
}

/* Scans for existence of valid cells around the current cell of occupation...
 * when this method is called, it returns headings that lead to valid cells
 * that DOCO MAY move to, adding them to a vector of valid headings. */
vector <int> MoveBehavior::scanCells(int xPosition, int yPosition)
{
	vector<int> validHeading; // vector of headings doco can take
	int x=-1;
	int y=-1; //initialize temp x, y to invalid values

	// for each direction, check if there is a cell and if the cell is unoccupied
	for (auto heading : {NORTH, NORTHEAST, EAST, SOUTHEAST, SOUTH, SOUTHWEST, WEST, NORTHWEST})
	{ //get cell coordinates given doco position & heading
		getXYLocation(xPosition, yPosition, heading, &x, &y);
		if(x >= 0 && x < docoWorldPtr->getWidth() && y >= 0 && y < docoWorldPtr->getHeight())
		{//x and y values must be within the doco world boundaries to be valid
			if(docoWorldPtr->getCellGrid()[x][y].getDoco() == nullptr)//cell is un-occupied
			{
				validHeading.push_back(heading);// heading is valid, add to container
			}
		}
	}
	return validHeading;
}

/* Checks if current doco heading is still valid and
 * returns true if is. Otherwise returns false*/
bool MoveBehavior::checkCurrentHeading(int hd, vector<int> vHeading)
{
	bool flag = false;
	for(int i=0; i< int (vHeading.size()); i++)
	{
		if(vHeading[i] == hd){
			flag = true; // heading is valid!
			break;
		}
	}
	return flag;
}

/* doFoodSniff scans for food in cells next to current x,y location and
 * returns the heading with largest amount of food. If no food is found
 * -1 is returned*/
int MoveBehavior::doFoodSniff(int xPos, int yPos, vector<int> vHeading)
{
	int food = 0;
	int x = -1;
	int y = -1;
	int fHeading =-1;

	for(int i=0; i<int (vHeading.size()); i++)
	{
		getXYLocation(xPos, yPos, vHeading[i], &x, &y);
		if(food < docoWorldPtr->getCellGrid()[x][y].getFoodAmount())
		{
			food = docoWorldPtr->getCellGrid()[x][y].getFoodAmount();//get cell's food amount;
			fHeading = vHeading[i]; //re-set heading; move towards food
		}
	}
	return fHeading;
}

/* getXYLocation method gets current x-postion, current y-position, current heading
 * and pointer to new X and Y positions that will be set after method returns.*/
void MoveBehavior::getXYLocation(int xPosition, int yPosition, int heading, int *x, int *y)
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