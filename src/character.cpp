/*
 * character.cpp
 *
 *  Created on: Mar 28, 2017
 *      Author: Alexander Green, Qiao Ren
 *		 Group: 15
 */

#include <character.h>

Character::Character() {
	// TODO Auto-generated constructor stub

}

Character::~Character() {
	// TODO Auto-generated destructor stub
}

void Character::goDirection() {
	c.px = c.x;	// store previous coordinates for tweening and ghost collision
	c.py = c.y;
	switch (c.dir) {
		case LEFT: c.x--; break;
		case RIGHT: c.x++; break;
		case DOWN: c.y++; break;
		case UP: c.y--; break;
	}

	if (c.x < -1) {
		c.x = 28;
		c.px = 28;
		c.dir = LEFT;
	}
	else if (c.x > 28) {
		c.x = -1;
		c.px = -1;
		c.dir = RIGHT;
	}


}
