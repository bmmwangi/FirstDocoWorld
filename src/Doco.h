/*******************************************************************
* Doco.h
* Programming Assignment 1: DOCO Simulated World
* Author: Benson Mwangi
* Date: October 2014
*
* This program is entirely my own work
*******************************************************************/
#ifndef DOCO_H
#define DOCO_H

#include <vector>
#include <stdlib.h>						/* srand, rand */
#include "Location.h"
#include "Directions.h"

using namespace std;
using namespace directions;

class DocoWorld;

class Doco
{
	private:
		int xPosition;				  // doco x position
		int yPosition;				  // doco y position
		int energyLevel; 			  // doco energy level
		int heading; 				  // current direction of movement
		char movement;				  // doco style of movement (HORIZONTAL, VERTICAL, OR DIAGONAL)

	public:
		Doco(int x, int y);				// parameterised constructor
		Doco(void);					 	// default constructor
		~Doco();					 	// destructor
		void setXPosition(int x);		// setters
		void setYPosition(int y);
		void setEnergyLevel(int e);
		void setHeading(int h);
		void setMovement(char m);		// set movement style

		int getXPosition();				// getters
		int getYPosition();				//
		int getEnergyLevel();			//
		int getHeading();				//
		char getMovement();				//
		void eat(DocoWorld *dwp); 	    // doco can eat to increase its energy level
		void move(DocoWorld *dwp);		// doco can move around in the doco-world
		void getXYLocation(int heading, int *x, int *y);
		void pickNewCell(int heading, vector <int> vHeading, DocoWorld *dwp);
		char toString();
};
#endif
