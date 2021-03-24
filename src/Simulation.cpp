/*******************************************************************
* Simulation.cpp
* Programming Assignment 1: DOCO Simulated World
* Author: Benson Mwangi
* Date: October 2014
*
* This program is entirely my own work
*******************************************************************/

#include <iostream>
#include <cctype>
#include "Simulation.h"

using namespace std;

//------------------------------------------------
// Default constructor
//------------------------------------------------
Simulation::Simulation(void)
{
	strcpy(filename, "src/DOCOData01.xml");	// get data filename
	dataParser = new DataParser(filename);	// initialize dParser
	docoWorld = new DocoWorld(dataParser);	// initialize doco world
	worldView = new WorldView(docoWorld);	// create world view
	done = false;
	outputTime = 0.0d;
	thisTime = 0.0d;
}

//------------------------------------------------
// Default destructor
//------------------------------------------------
Simulation::~Simulation(void)
{
	//
}

//--------------------------------------
// run()
// starts the application
//--------------------------------------
void Simulation::start(void)
{
	ftime(&tStruct); // Get start time
	thisTime = tStruct.time + (((double)(tStruct.millitm)) / 1000.0); // Convert to double
	outputTime = thisTime + 1.0; // Set next 1 second interval time

	worldView->renderDocoWorld();// display doco world

	int duration = 60;
	do // Start display loop
	{
		ftime(&tStruct); // Get the current time
		thisTime = tStruct.time + (((double)(tStruct.millitm)) / 1000.0); // Convert to double

		// Check for 1 second interval to print status to screen
		if(thisTime >= outputTime)
		{
			docoWorld->updateWorld();//update state of the doco world
			worldView->renderDocoWorld();// display doco world
			outputTime += 1.0; // Set time for next 1 second interval
			duration--;
		}
	} while(duration > 0); // run for duration"
}

// program entry point
int main(int argc, char **argv)
{
	Simulation *sim = new Simulation();
	sim->start();

	return 0;
}