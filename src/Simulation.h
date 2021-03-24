/*******************************************************************
* Simulation.h
* Programming Assignment 1: DOCO Simulated World
* Author: Benson Mwangi
* Date: October 2014
*
* This program is entirely my own work
*******************************************************************/

#ifndef SIMULATION_H
#define SIMULATION_H

using namespace std;

#include <string.h>
#include <stdlib.h>				/* srand, rand */
#include <time.h>				/* time */
#include <sys/types.h>			// needed for the _ftime() function
#include <sys/timeb.h>			// contains definition of timeb struct
#include "DataParser.h"			// parses XML data file
#include "DocoWorld.h"
#include "WorldView.h"

class Simulation
{
	private:
		char filename[64];		// pointer to a filename
		DataParser *dataParser;	// pointer to a data parser
		DocoWorld *docoWorld;	// pointer to a doco world instance
		WorldView *worldView;	// renders the firstDocoWorld
		struct timeb tStruct;
		double thisTime;
		double outputTime;
		bool done; 				// while loop flag

	public:
		Simulation();			// constructor
		~Simulation();			// destructor
		void start();			// start the simulation
};
#endif