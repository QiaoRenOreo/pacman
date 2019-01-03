/*
 * ghost.h
 *
 *  Created on: Mar 27, 2017
 *      Author: Alexander Green, Qiao Ren
 *		 Group: 15
 */

#ifndef INCLUDE_GHOST_H_
#define INCLUDE_GHOST_H_

#include "character.h"

enum mode {
	SCATTER,
	CHASE,
//	FRIGHTENED
};

class Ghost : public Character {
public:
	Ghost();
	virtual ~Ghost();

	void reset();

	mode mymode;

};

#endif /* INCLUDE_GHOST_H_ */
