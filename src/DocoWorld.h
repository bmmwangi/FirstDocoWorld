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
#include "Cell.h"
#include "Doco.h"

using namespace std;

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
		DocoWorld(int width, int height); // constructor
		~DocoWorld(void);				  // destructor

		void createCellGrid();			  // create cell-grid
		void addFoodPellets(int food);	  // add food pellets
		void addDoco(Doco *d); 			  // add a doco to the world
		void updateWorld();				  // update the state of the world
		int getWidth(); 				  // return width of doco world
		int getHeight(); 				  // return height of doco world
		vector <Doco*> *getDocos();		  // return the Docos
		Cell** getCellGrid();  			  // return Cells grid layout of the doco world
};
#endif
