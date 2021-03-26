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

#include "SimpleEatBehavior.h"
#include "SimpleMoveBehavior.h"
#include "Location.h"

using namespace std;

class Doco
{
	private:
		int xPosition;				  // doco x position
		int yPosition;				  // doco y position
		int energyLevel; 			  // doco energy level
		int heading; 				  // current direction of movement
		char movement;				  // doco style of movement (HORIZONTAL, VERTICAL, OR DIAGONAL)
		EatBehavior *eBehavior;	  	  // doco has 'eat' behavior
		MoveBehavior *mBehavior;  	  // doco has a 'move' behavior

	public:
		Doco(int x, int y);				// parameterised constructor
		Doco(void);					 	//default constructor
		~Doco();					 	// destructor
		void setXPosition(int x);		// setters
		void setYPosition(int y);
		void setEnergyLevel(int e);
		void setHeading(int h);
		void setMovement(char m);			// set movement style
		void setEatBehavior(EatBehavior *eb);	// set eating behavior
		void setMoveBehavior(MoveBehavior *mb);	// set movement behavior

		int getXPosition();				// getters
		int getYPosition();				//
		int getEnergyLevel();			//
		int getHeading();				//
		char getMovement();				//
		Location move();					// doco can move to new cell
		void eat(); 					// doco can eat to increase its energy level
		MoveBehavior *getMoveBehavior();//returns pointer to move-behavior
		EatBehavior *getEatBehavior();	//returns pointer to eat-behavior
		char toString();
};
#endif
