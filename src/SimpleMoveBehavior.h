/*******************************************************************
* SimpleMoveBehavior.h
* Programming Assignment 1: DOCO Simulated World
* Author: Benson Mwangi
* Date: October 2014
*
* This program is entirely my own work
*******************************************************************/
#ifndef SIMPLEMOVEBEHAVIOR_H
#define SIMPLEMOVEBEHAVIOR_H

#include "MoveBehavior.h"

using namespace std;

class SimpleMoveBehavior : public MoveBehavior{
public:
	SimpleMoveBehavior(DocoWorld *dwPtr);
	~SimpleMoveBehavior();
	void move(Doco *d);//implements the way doco moves
};
#endif