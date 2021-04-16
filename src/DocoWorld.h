/*******************************************************************
* DocoWorld.h
* Programming Assignment 1: DOCO Simulated World
* Author: Benson Mwangi
* Date: October 2014
*
* This program is entirely my own work
*******************************************************************/
#ifndef DOCOWORLD_H
#define DOCOWORLD_H

#include <stdlib.h>						/* srand, rand */
#include <ctime>
#include <vector>
#include "DataParser.h"					// parses XML data file
#include "Cell.h"
#include "Doco.h"

using namespace std;

class DocoWorld
{
	private:
		DataParser *dparser;			// data parse
		int docoCount;				    // population
		int wWidth;					    // width of world
		int wHeight; 				    // height/length of world
		int foodCount; 				    // amount of available food
		Cell **cellGrid;				// pointer to pointer of Cell objects
		vector <Doco*> *docos; 		    // pointer to vector holding pointers to Docos

	public:
		DocoWorld(DataParser *dp);		// constructor
		~DocoWorld(void);				// destructor

		void createCellGrid();			// create cell-grid
		void addFoodPellets(int food);	// add food pellets
		void addDocos(); 				// add a doco to the world
		void updateWorld();				// update the state of the world
		int getWidth(); 				// return width of doco world
		int getHeight(); 				// return height of doco world
		vector <Doco*> *getDocos();		// return the Docos
		Cell** getCellGrid();  			// return Cells grid layout of the doco world
};
#endif
