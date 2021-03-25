/*******************************************************************
* Location.cpp
* Programming Assignment 1: DOCO Simulated World
* Author: Benson Mwangi
* Date: October 2014
*
* This program is entirely my own work
*******************************************************************/

#include "Location.h"

Location::Location(int x, int y)
{
	this->x = x;
	this->y = y;
}


Location::~Location()
{
}

//------------------------------------------------
// returns instance's x location
//------------------------------------------------
int Location::getX()
{
	return this->x;
}

//------------------------------------------------
// returns instance's y location
//------------------------------------------------
int Location::getY()
{
	return this->y;
}
