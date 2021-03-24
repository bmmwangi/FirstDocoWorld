/*******************************************************************
* SimpleEatBehavior.cpp
* Programming Assignment 1: DOCO Simulated World
* Author: Benson Mwangi
* Date: October 2014
*
* This program is entirely my own work
*******************************************************************/

#include "SimpleEatBehavior.h"
#include "DocoWorld.h"

using namespace std;

SimpleEatBehavior::SimpleEatBehavior(DocoWorld *dwPtr) : EatBehavior(dwPtr)
{
	docoWorldPtr = dwPtr;
}

SimpleEatBehavior::~SimpleEatBehavior()
{
}

void SimpleEatBehavior::eat(Doco *d)
{
	int food = docoWorldPtr->getCellGrid()[d->getXPosition()][d->getYPosition()].getFoodAmount();// get food from the new cell
	d->setEnergyLevel(d->getEnergyLevel() + 50*food);// energy gained is 50 times food amount
	docoWorldPtr->getCellGrid()[d->getXPosition()][d->getYPosition()].setFoodAmount(0);
}