/*
 * character.h
 *
 *  Created on: Mar 28, 2017
 *      Author: Alexander Green, Qiao Ren
 *		 Group: 15
 */

#ifndef INCLUDE_CHARACTER_H_
#define INCLUDE_CHARACTER_H_

#include "GameObjectStruct.h"
#include <iostream>



class Character {
public:
	Character();
	virtual ~Character();
	GameObjectStruct c;
	void goDirection();


};

#endif /* INCLUDE_CHARACTER_H_ */
