/*******************************************************************
* EatBehavior.h
* Programming Assignment 1: DOCO Simulated World
* Author: Benson Mwangi
* Date: October 2014
*
* This program is entirely my own work
*******************************************************************/
#ifndef EATBEHAVIOR_H
#define EATBEHAVIOR_H

using namespace std;

class Doco;
class DocoWorld;

class EatBehavior
{
	protected:
	DocoWorld *docoWorldPtr;// pointer to cell grid

	public:
		EatBehavior(DocoWorld *dwPtr); // constructor
		virtual ~EatBehavior(){};	   // destructor
		virtual void eat(Doco *d) = 0; //virtual move
};
#endif