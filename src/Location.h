/*******************************************************************
* Location.h
* Programming Assignment 1: DOCO Simulated World
* Author: Benson Mwangi
* Date: October 2014
*
* This program is entirely my own work
*******************************************************************/
#ifndef LOCATION_H
#define LOCATION_H

class Location
{
	private:
		int x;
		int y;

	public:
		Location(int x, int y);
		~Location(void);
		int getX(void);
		int getY(void);
};
#endif
