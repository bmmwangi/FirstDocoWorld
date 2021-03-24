/*******************************************************************
* WorldView.h
* Programming Assignment 1: DOCO Simulated World
* Author: Benson Mwangi
* Date: October 2014
*
* This program is entirely my own work
*******************************************************************/
#ifndef WORLDVIEW_H
#define WORLDVIEW_H

#include <sys/types.h> // needed for the _ftime() function
#include <sys/timeb.h> // contains definition of _timeb struct
#include <time.h> // needed for other time functions and structures
#include "DocoWorld.h"


class WorldView
{
	private: 
		DocoWorld *docoWorld;// pointer to a doco world
		int width;
		int height;

	public:
		WorldView(DocoWorld *dw);//
		~WorldView();//
		void renderDocoWorld();	//
		void printEdge();
};
#endif