/*******************************************************************
* WorldView.cpp
* Programming Assignment 1: DOCO Simulated World
* Author: Benson Mwangi
* Date: October 2014
*
* This program is entirely my own work
*******************************************************************/

#include <iostream>
#include <iomanip>
#include "WorldView.h"
#include "windows.h"

using namespace std;

//------------------------------------------------
// Default constructor
//------------------------------------------------
WorldView::WorldView(DocoWorld *dwp)
{
	docoWorld = dwp;		// pointer to a doco world
	width = docoWorld->getWidth();
	height = docoWorld->getHeight();
	buffer_size = width*height*2 + 250;//size of print butter
	buffer = new char[buffer_size];
}

//------------------------------------------------
// Default destructor
//------------------------------------------------
WorldView::~WorldView()
{
	delete[] buffer;//clean up memory
}

//------------------------------------------------
// renderDocWorld prints out the doco world
//------------------------------------------------
void WorldView::renderDocoWorld()
{
	char *next_char = &buffer[0];
	system("CLS"); //clear console output
	cout << setw(3) << "";
	cout << "Doco World Simulation will run for 60 seconds." << endl;

	*next_char++ = ' ';						// pad with space
	*next_char++ = ' ';						// pad with space
	for(int i=0; i< width; i++){
		*next_char++ = ' ';					// pad with space
		itoa(i/10, next_char++, 10);		// pad number with a '0'
	}
	*next_char++  = '\n';					//

	*next_char++ = ' ';						// pad with space
	*next_char++ = ' ';						// pad with space
	for(int i=0; i< width; i++){
		*next_char++ = ' ';					// pad with space
		itoa(i%10, next_char++, 10);		// pad number with a '0'
	}
	*next_char++  = '\n';					// end header

	for (int row=0; row<width; row++)		// loop through each cell
	{										// add row numbering
		if (row < 10){						//
			itoa(row/10, next_char++, 10);	// pad number with a '0' for (0-9)
			itoa(row, next_char++, 10);		// print number
		}else{
			itoa(row/10, next_char++, 10);	// print number as two chars
			itoa(row%10, next_char++, 10);
		}
		for (int col=0; col<height; col++) 	//
		{
			*next_char++ = ' ';				//pad with space
			*next_char++ = docoWorld->getCellGrid()[row][col].toString();// print cell
		}
		*next_char++ = '\n'; 				//next row
	}
	cout.write(buffer, (next_char - &buffer[0])); //show the world!
}
