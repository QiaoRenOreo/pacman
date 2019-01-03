/*
 * ghost.cpp
 *
 *  Created on: Mar 27, 2017
 *      Author: Alexander Green, Qiao Ren
 *		 Group: 15
 */

#include <ghost.h>

Ghost::Ghost() {
	c.type = BLINKY;
	c.x = 12;
	c.y = 13;
	c.dir = UP;
	mymode = SCATTER;
}

Ghost::~Ghost() {

}

void Ghost::reset() // put the ghost back in the house
{
	c.x = 13;
	c.y = 13;
}

