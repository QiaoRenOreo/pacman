/*
 * game.h
 *
 *  Created on: Mar 26, 2017
 *      Author: Alexander Green, Qiao Ren
 *		 Group: 15
 */

#ifndef INCLUDE_GAME_H_
#define INCLUDE_GAME_H_

#include<vector>
#include<array>
#include "GameObjectStruct.h"
#include <cmath>
#include "character.h"
#include "ghost.h"
#include "pacman.h"






class Game {
public:
	Game();
	virtual ~Game();

	int getLives();
	void ghostCollision();
	void killPacman();

	int getScore();
	void increaseScore(Type food);

	bool checkWall(int mapx, int mapy, Direction d);

	void setFood();
	void checkCollision();

	void setGhosts();
	void charMove();

	void energize();
	void timer();	// energized timer

	std::vector<std::vector<int>> map;

	std::vector<GameObjectStruct> food;

	Pacman pacman;

	std::vector<Ghost *> ghosts;
	Ghost inky;
	Ghost pinky;
	Ghost blinky;
	Ghost clyde;

	std::vector<Character *> characters;

	std::vector<GameObjectStruct> setObjects();

	Direction pathFinding(int startx, int starty, int targetx, int targety);

	bool over;	// game over




private:
	int score = 0;
	int lives = 3;	// spare lives
	int energizedtimer = 0;
	bool fruitset = false;
	int fruitcounter = 0;



	std::vector<GameObjectStruct> objects;




};

#endif /* INCLUDE_GAME_H_ */
