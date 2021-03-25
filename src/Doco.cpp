/*******************************************************************
* Doco.cpp
* Programming Assignment 1: DOCO Simulated World
* Author: Benson Mwangi
* Date: October 2014
*
* This program is entirely my own work
*******************************************************************/

#include "Doco.h"

//----------------------------------------------------
//parameterised constructor
//----------------------------------------------------
Doco::Doco(int x, int y)
{
	xPosition = x;	//x coordinate of doco
	yPosition = y;	//y coordinate of doco
	heading = 0; //
	energyLevel = 500;	// initialize energy level at 500
	movement = '\0';//movement style is random
	eBehavior = nullptr; // pointer to eat-behavior
	mBehavior = nullptr; // pointer to move-behavior
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
	eBehavior = nullptr; // pointer to eat-behavior
	mBehavior = nullptr; // pointer to move-behavior
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

//------------------------------------------------
//setMoveBehavior - set doco's move behavior
//------------------------------------------------
void Doco::setMoveBehavior(MoveBehavior *mb)
{
	mBehavior = mb;// set movement behavior
}

//------------------------------------------------
// set doco's eat behavior
//------------------------------------------------
void Doco::setEatBehavior(EatBehavior *eb)
{
	eBehavior = eb;// set eating behavior
}

//------------------------------------------------
// return doco's move-behavior
//------------------------------------------------
MoveBehavior *Doco::getMoveBehavior()
{
	return mBehavior;//returns pointer to move-behavior
}

//------------------------------------------------
// return doco's eat behavior
//------------------------------------------------
EatBehavior *Doco::getEatBehavior()
{
	return eBehavior;	//returns pointer to eat-behavior
}

/*------------------------------------------------
 *  move moves the doco to a new cell
 *
------------------------------------------------*/
Location Doco::move()
{
	return mBehavior->move(this);// delegate move to behavior instance
}

//------------------------------------------------
//eat - replenishes doco's energy level
//------------------------------------------------
void Doco::eat(){
	eBehavior->eat(this);// delegate to behavior object
}
