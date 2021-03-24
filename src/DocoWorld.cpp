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
	docoCount = dp->getDOCOCount(); //
	wWidth = dp->getDOCOWorldWidth();//
	wHeight = dp->getDOCOWorldHeight();//
	foodCount = dp->getFoodCount();//
	cellGrid = new Cell*[wHeight]; // wHeight defines number of rows of Cells
	docos = new vector<Doco*>;// initialize vector of Docos

	createCellArray(); // create the cells array
	addFoodPellets(foodCount); // add initial amount of food pellets
	addDocos(dp); //let there be Docos! ... populate the world with docos
}

//------------------------------------------------
// Default destructor
//------------------------------------------------
DocoWorld::~DocoWorld(void)
{
	for (int row=0;row<wHeight; row++) //for each row
		delete[] cellGrid[row]; //delete columns
	delete [] cellGrid;//delete rows
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
void DocoWorld::createCellArray()
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
// add docos to the world in predetermined cell locations
//-------------------------------------------------------
void DocoWorld::addDocos(DataParser *dp)
{
	int x, y; // x and y co-ordiantes of each doco
	for(int i=0; i<docoCount; i++)
	{
		dp->getDOCOData(nullptr, &x, &y);//get docos x, y co-ords
		Doco *d = new Doco(x,y);//create doco with given x,y co-ords
		d->setHeading(rand() % 8); // initialize a random heading
		d->setEatBehavior(new SimpleEatBehavior(this));// set doco's 'eat' behavior
		d->setMoveBehavior(new SimpleMoveBehavior(this));// set doco's 'move' behavior
		docos->push_back(d);// store doco
		cellGrid[x][y].setDoco(d);//place doco on cell grid
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
	//1) add random amount of food
	int moreFood = (rand() % 10)+1; // get random number of food pellets (1 - 10)
	addFoodPellets(moreFood);		// add it to the world

	//2) move the living docos
	vector<Doco*>::iterator it = docos->begin();
	while(it != docos->end()) {
		if(it.operator *()->getEnergyLevel() == 0) {//docos with zero energy are dead!
			cellGrid[it.operator* ()->getXPosition()][it.operator* ()->getYPosition()].setDoco(NULL);
			delete *it;
			it = docos->erase(it);
		}
		else {
			it.operator *()->move();//tell doco to move
			++it;
		}
	}
}

