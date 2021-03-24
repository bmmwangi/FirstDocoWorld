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
#include <vector>
#include "DataParser.h"
#include "Cell.h"
#include "Doco.h"

using namespace std;
using namespace directions;

class DocoWorld
{
	private:
		int docoCount;				      // population
		int wWidth;					      // width of world
		int wHeight; 				      // height/length of world
		int foodCount; 				      // amount of available food
		Cell **cellGrid;				  // pointer to pointer of Cell objects
		vector <Doco*> *docos; 		      // pointer to vector holding pointers to Docos

	public:
		DocoWorld(DataParser *dp);		  // constructor
		~DocoWorld(void);				  // destructor

		void createCellArray();			  // create cell-grid
		void addFoodPellets(int f);		  // add food pellets
		void addDocos(DataParser *dp);    // method places docos in predefined positions/cells
		void updateWorld();				  // update the state of the world
		int getWidth(); 				  // return width of doco world
		int getHeight(); 				  // return height of doco world
		vector <Doco*> *getDocos();		  // return the Docos
		Cell** getCellGrid();  			  // return Cells grid layout of the doco world
};
#endif
