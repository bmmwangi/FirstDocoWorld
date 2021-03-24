/*******************************************************************
* SimpleEatBehavior.h
* Programming Assignment 1: DOCO Simulated World
* Author: Benson Mwangi
* Date: October 2014
*
* This program is entirely my own work
*******************************************************************/
#ifndef SIMPLEEATBEHAVIOR_H
#define SIMPLEEATBEHAVIOR_H

#include "EatBehavior.h"

using namespace std;

class SimpleEatBehavior : public EatBehavior {
public:
	SimpleEatBehavior(DocoWorld *dwPtr);
	~SimpleEatBehavior();
	void eat(Doco *d);
};
#endif