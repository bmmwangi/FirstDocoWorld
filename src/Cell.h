/*******************************************************************
* Cell.h
* Programming Assignment 1: DOCO Simulated World
* Author: Benson Mwangi
* Date: October 2014
*
* This program is entirely my own work
*******************************************************************/
#ifndef CELL_H
#define CELL_H

using namespace std;

#include "Doco.h"

class Cell
{
	private:
		int xPosition;				// x position of the cell
		int yPosition;				// y location of the cell
		int foodAmount;				// amount of food in cell
		Doco *doco;					// pointer to occupying doco

	public:
		Cell();						// constructor
		~Cell();					// destructor

		void setXPosition(int x);	// set the X position of the cell
		void setYPosition(int y);	// set the Y position of the cell
		void setFoodAmount(int f); 	// set the amount of food held in cell
		void setDoco(Doco *d); 		// set pointer to doco

		int getXPosition();			// return X position of the cell
		int getYPosition();			// return Y position of the cell
		int getFoodAmount();		// return food amount in cell
		Doco *getDoco();			// return pointer to occupying doco
		char toString();			// return char representing empty cell
};
#endif