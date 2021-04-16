/*******************************************************************
* DocoWorld.cpp
* Programming Assignment 1: DOCO Simulated World
* Author: Benson Mwangi
* Date: October 2014
*
* This program is entirely my own work
*******************************************************************/
#include "DocoWorld.h"

using namespace std;

//------------------------------------------------
// Default constructor
//------------------------------------------------
DocoWorld::DocoWorld(DataParser *dp)
{
	dparser = dp;
	wWidth = dparser->getDOCOWorldWidth();	// doco-world width
	wHeight = dparser->getDOCOWorldHeight();	// doco-world height
	docoCount = dparser->getDOCOCount();		//
	foodCount = dparser->getFoodCount();		//
	cellGrid = new Cell*[wHeight]; 		// wHeight is number of rows of Cells
	docos = new vector<Doco*>;			// initialize vector of Docos
	createCellGrid(); 					// create the cell-grid
	addFoodPellets(foodCount);			// initialize food pellets
	addDocos();							// add docos
	srand(time(0));						// random seed
}

//------------------------------------------------
// Default destructor
//------------------------------------------------
DocoWorld::~DocoWorld(void)
{
	delete docos;
	for (int row=0;row<wHeight; row++) //for each row
		delete[] cellGrid[row]; // recover col mem
	delete [] cellGrid;//finally, recover row mem
}

//------------------------------------------------
// return the integer width of doco world
//------------------------------------------------
int DocoWorld::getWidth(){
	return wWidth;
}

//------------------------------------------------
// return the integer height of doco world
//------------------------------------------------
int DocoWorld::getHeight(){
	return wHeight;
}

//-------------------------------------------------------------
// create a grid of cells as pointer to pointer of Cell objects
//-------------------------------------------------------------
void DocoWorld::createCellGrid()
{
	for (int row=0;row<wHeight; row++){   //for each row
		cellGrid[row] = new Cell[wWidth]; //create columns
	}
}

//------------------------------------------------
// add food pellets to the world at random locations
//------------------------------------------------
void DocoWorld::addFoodPellets(int food)
{
	int x, y;
	if (food > 0) {
		x =  rand() % wWidth; // get a random x position
		y =  rand() % wHeight; // get a random y position
		if(cellGrid[x][y].getFoodAmount() <= 3 && cellGrid[x][y].getDoco() == NULL)
		{
			cellGrid[x][y].setFoodAmount(cellGrid[x][y].getFoodAmount()+1);//add new food to current cell food
			food--; // reduce food amount
		}
		addFoodPellets(food);//place more food
	} else {
		return;//no more food to place
	}
}

//-------------------------------------------------------
// populate the world with docos
//-------------------------------------------------------
void DocoWorld::addDocos()
{
	int x, y; // x and y co-ordiantes of each doco
	for(int i=0; i<docoCount; i++)
	{
		dparser->getDOCOData(nullptr, &x, &y); 	// get docos x, y co-ords
		Doco *doco = new Doco(x, y);		// create doco with given x,y co-ords
		doco->setHeading(rand() % 8); 		// initialize a random heading
		docos->push_back(doco);				// store doco
		cellGrid[x][y].setDoco(doco);		//place doco on cell grid
	}
}

//------------------------------------------------
// returns a pointer to the grid of cells
//------------------------------------------------
Cell **DocoWorld::getCellGrid()
{
	return cellGrid; //return a pointer to pointer of cells
}

//------------------------------------------------
// returns pointer to the vector holding docos
//------------------------------------------------
vector <Doco*> *DocoWorld::getDocos()
{
	return docos; //return a pointer to vector of docos
}

//------------------------------------------------
// update the state of the Doco world
//------------------------------------------------
void DocoWorld::updateWorld(void)
{
	//1) move the living docos
	vector <Doco*>::iterator it = docos->begin();
	while(it != docos->end()) {
		if(it.operator *()->getEnergyLevel() <= 0) {//docos with zero energy are dead! Remove from world
			cellGrid[it.operator* ()->getXPosition()][it.operator* ()->getYPosition()].setDoco(NULL);
			delete *it;
			it = docos->erase(it);
		}
		else {
			it.operator *()->move(this);//tell doco to move
			it.operator *()->eat(this);//tell doco to eat after every move
			++it;
		}
	}

	//2) add random amount of food
	int moreFood = (rand() % 10)+1; // get random number of food pellets (1 - 10)
	addFoodPellets(moreFood);		// add it to the world
}

