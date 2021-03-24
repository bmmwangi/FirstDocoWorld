/*******************************************************************
* SimpleMoveBehavior.cpp
* Programming Assignment 1: DOCO Simulated World
* Author: Benson Mwangi
* Date: October 2014
*
* This program is entirely my own work
*******************************************************************/
#include "SimpleMoveBehavior.h"
#include "DocoWorld.h"

using namespace std;


SimpleMoveBehavior::SimpleMoveBehavior(DocoWorld *dwPtr) : MoveBehavior(dwPtr)
{
	docoWorldPtr = dwPtr;
}

//------------------------------------------------
// returns pointer to the vector holding docos
//------------------------------------------------
SimpleMoveBehavior::~SimpleMoveBehavior()
{
}

//------------------------------------------------
// returns pointer to the vector holding docos
//------------------------------------------------
void SimpleMoveBehavior::move(Doco *d)
{
	int xPos = d->getXPosition(); 							// doco's current x position
	int yPos = d->getYPosition(); 							// doco's current y position
	int newXPos, newYPos, newHeading = -1; 					// doco's new (x, y) and heading

	//  get valid headings based on doco's position
	vector <int> vHeading = scanCells(xPos, yPos);			// get valid headings

	//	if current heading is still valid, keep it
	if(checkCurrentHeading(d->getHeading(), vHeading)){
		newHeading = d->getHeading();
	}

	// override current heading & move towards largest amount of food!
	if(doFoodSniff(xPos, yPos, vHeading) != -1){
		newHeading = doFoodSniff(xPos, yPos, vHeading);
	}

	// if there's no food + current heading is invalid, pick a random heading
	if (newHeading == -1 )
	{
		int index = rand() % int (vHeading.size());
		newHeading = vHeading[index];		        			// choose new heading
	}

	// get x, y coordinates of new cell
	getXYLocation(xPos, yPos, newHeading, &newXPos, &newYPos);

	//if doco has energy, effect the move
	if(d->getEnergyLevel() >= 10) {
		d->setHeading(newHeading);								  //set docos heading
		d->setXPosition(newXPos);   							  // set doco's new x,y position
		d->setYPosition(newYPos);
		d->setEnergyLevel( d->getEnergyLevel()-10 ); 			  // use 10 energy units
		docoWorldPtr->getCellGrid()[xPos][yPos].setDoco(nullptr); // vacate old cell
		docoWorldPtr->getCellGrid()[newXPos][newYPos].setDoco(d); // occupy new cell
	}
}