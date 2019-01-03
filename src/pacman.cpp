/*
 * pacman.cpp
 *
 *  Created on: Mar 26, 2017
 *      Author: Alexander Green, Qiao Ren
 *		 Group: 15
 */

#include <pacman.h>


Pacman::Pacman() {
//	GameObjectStruct pacman;
		c.x = 29;	// walk on stage through portal
		c.y = 13;
		c.type = PACMAN;
		c.dir = RIGHT;
}

Pacman::~Pacman() {

}


