/*******************************************************************
* MoveBehavior.h
* Programming Assignment 1: DOCO Simulated World
* Author: Benson Mwangi
* Date: October 2014
*
* This program is entirely my own work
*******************************************************************/
#ifndef MOVEBEHAVIOR_H
#define MOVEBEHAVIOR_H

#include <vector>
#include "Directions.h"
#include "Location.h"

using namespace directions;
using namespace std;

class Cell;
class Doco;
class DocoWorld;

class MoveBehavior
{
	protected:
		DocoWorld *docoWorldPtr;  // pointer to cell grid

	public:
		MoveBehavior(DocoWorld *dwPtr);  // constructor
		virtual ~MoveBehavior(){};	// destructor
		virtual Location move(Doco *d) = 0; //virtual move
		void getXYLocation(int xPos, int yPos, int h, int *newXPos, int *newYPos);
		vector <int> scanCells(int x, int y); // scans cells around given x, y coordinates
		int doFoodSniff(int x, int y, vector <int> vHeading);// returns int heading towards most food or -1
		bool checkCurrentHeading(int heading, vector <int> vHeading);//returns true if current heading is valid
};
#endif
