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
		int width;				// width of doco world
		int height;				// height of doco world
		int buffer_size;		// print buffer size
		char *buffer;			// represents state of doco world

	public:
		WorldView(DocoWorld *dw);//
		~WorldView();//
		void renderDocoWorld();	//
};
#endif
