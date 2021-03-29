/*******************************************************************
* WorldView.cpp
* Programming Assignment 1: DOCO Simulated World
* Author: Benson Mwangi
* Date: October 2014
*
* This program is entirely my own work
*******************************************************************/


#include <iostream>
#include <string>
#include <iomanip>
#include "WorldView.h"
#include "DocoWorld.h"
#include "windows.h"

using namespace std;

//------------------------------------------------
// Default constructor
//------------------------------------------------
WorldView::WorldView(DocoWorld *dw)
{
	docoWorld = dw;		// pointer to a doco world
	width = docoWorld->getWidth();
	height = docoWorld->getHeight();
}

//------------------------------------------------
// Default destructor
//------------------------------------------------
WorldView::~WorldView()
{
	//
}

//------------------------------------------------
// renderDocWorld prints out the doco world
//------------------------------------------------
void WorldView::renderDocoWorld()
{
	static char buffer[2040];
	char *next_char = &buffer[0];
	system("CLS"); //clear console output
	cout << setw(3) << "";
	cout << "Doco World Simulation will run for 60 seconds." << endl;
	printEdge();//print border

	for (int row=0; row<width; row++)		// loop through each cell
	{	//add row numbering to print buffer
		if (row < 10){
			itoa(row/10, next_char++, 10);	// pad number with a '0'
			itoa(row, next_char++, 10);		// print number
		}else{
			itoa(row/10, next_char++, 10);	// print
			itoa(row%10, next_char++, 10);	// print number
		}

		// add doco world state to print buffer
		for (int col=0; col<height; col++) 	//
		{
			*next_char++ = ' ';//pad with space
			if (docoWorld->getCellGrid()[row][col].getDoco() != NULL)
				*next_char++ = docoWorld->getCellGrid()[row][col].getDoco()->toString();// print doco
			else if(docoWorld->getCellGrid()[row][col].getFoodAmount() != 0 )
				*next_char++ =  '.';													// print food
			else
				*next_char++ = docoWorld->getCellGrid()[row][col].toString();			// print unoccupied cell
		}
		*next_char++ = '\n'; ///next row
	}
	cout << buffer << endl; //print all!
}

//------------------------------------------------
// prints top edge of the doco world
//------------------------------------------------
void WorldView::printEdge(){
	cout << setw(2) << "";
	for(int i=0; i< width; i++)
		cout << setw(2) << i/10;
	cout << endl;
	cout << setw(2) << "";
	for(int i=0; i< width; i++)
		cout << setw(2) << i%10;
	cout << endl;
}
