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
	cout << setw(3) << "";
	cout << "Doco World Simulation will run for 60 seconds." << endl;
	printEdge();//print border

	for (int row=0; row<width; row++)// loop through each cell
	{
		if (row < 10)
			cout << row/10;	//pad digit with a space
		cout << row;		// print number
		for (int col=0; col<height; col++) //
		{
			if (docoWorld->getCellGrid()[row][col].getDoco() != NULL)
				cout << setw(2) << '*';
			else if(docoWorld->getCellGrid()[row][col].getFoodAmount() != 0 )
				cout << setw(2) << '.';
			else// cell is empty, occupied or has food and renders accordingly
				cout << setw(2) << docoWorld->getCellGrid()[row][col].toString();
		}
		cout << endl; //move to next row
	}
}

//------------------------------------------------
// prints top edge of the doco world
//------------------------------------------------
void WorldView::printEdge(){
	cout << setw(2) << " ";
	for(int i=0; i< width; i++)
		cout << setw(2) << i/10;
	cout << endl;
	cout << setw(2) << " ";
	for(int i=0; i< width; i++)
		cout << setw(2) << i%10;
	cout << endl;
}
