/*
 * game.cpp
 *
 *  Created on: Mar 26, 2017
 *      Author: Alexander Green, Qiao Ren
 *		 Group: 15
 */

#include <game.h>
#include <ghost.h>


//#include <board.h>

Game::Game() {
	
	// 0: path
	// 1: wall
	// 2: ghost house
	// 3: energizer on path
	
	map =
	{{
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,3,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,3,1},
	{1,0,1,1,1,1,0,1,1,1,1,1,0,1,1,0,1,1,1,1,1,0,1,1,1,1,0,1},
	{1,0,1,1,1,1,0,1,1,1,1,1,0,1,1,0,1,1,1,1,1,0,1,1,1,1,0,1},
	{1,0,1,1,1,1,0,1,1,1,1,1,0,1,1,0,1,1,1,1,1,0,1,1,1,1,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,1,1,1,1,0,1,1,0,1,1,1,1,1,1,1,1,0,1,1,0,1,1,1,1,0,1},
	{1,0,1,1,1,1,0,1,1,0,1,1,1,1,1,1,1,1,0,1,1,0,1,1,1,1,0,1},
	{1,0,0,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,0,1,1,1,1,1,0,1,1,0,1,1,1,1,1,0,1,1,1,1,1,1},
	{1,1,1,1,1,1,0,1,1,1,1,1,0,1,1,0,1,1,1,1,1,0,1,1,1,1,1,1},
	{1,1,1,1,1,1,0,1,1,0,0,0,0,0,0,0,0,0,0,1,1,0,1,1,1,1,1,1},
	{1,1,1,1,1,1,0,1,1,0,1,1,1,2,2,1,1,1,0,1,1,0,1,1,1,1,1,1},
	{0,0,0,0,0,0,0,0,0,0,1,1,2,2,2,2,1,1,0,0,0,0,0,0,0,0,0,0},
	{1,1,1,1,1,1,0,1,1,0,1,1,1,1,1,1,1,1,0,1,1,0,1,1,1,1,1,1},
	{1,1,1,1,1,1,0,1,1,0,0,0,0,0,0,0,0,0,0,1,1,0,1,1,1,1,1,1},
	{1,1,1,1,1,1,0,1,1,1,1,1,0,1,1,0,1,1,1,1,1,0,1,1,1,1,1,1},
	{1,1,1,1,1,1,0,1,1,1,1,1,0,1,1,0,1,1,1,1,1,0,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,0,0,1},
	{1,0,1,1,1,1,0,1,1,0,1,1,1,1,1,1,1,1,0,1,1,0,1,1,1,1,0,1},
	{1,0,1,1,1,1,0,1,1,0,1,1,1,1,1,1,1,1,0,1,1,0,1,1,1,1,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,1,1,1,1,0,1,1,1,1,1,0,1,1,0,1,1,1,1,1,0,1,1,1,1,0,1},
	{1,0,1,1,1,1,0,1,1,1,1,1,0,1,1,0,1,1,1,1,1,0,1,1,1,1,0,1},
	{1,0,1,1,1,1,0,1,1,1,1,1,0,1,1,0,1,1,1,1,1,0,1,1,1,1,0,1},
	{1,3,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,3,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
	}};


	ghosts = {&inky, &pinky, &blinky, &clyde};

	characters = {&pacman, &inky, &pinky, &blinky, &clyde};

	setGhosts();

	over = false;


}


Game::~Game() {}


int Game::getLives() {
	return lives;
}


void Game::killPacman() {	// lose a life and a new PAC-MAN walks on stage
	lives--;

	if (lives < 0)			// game over
	{
		// become a white ghost and float up
		pacman.c.type = SCAREDINV;
		pacman.c.y--;
		over = true;
	}
	else
	{
		pacman.c.x = 29;		// walk on stage through portal
		pacman.c.y = 13;
		pacman.c.px = 29;		// walk on stage through portal
		pacman.c.py = 13;
		pacman.c.dir = RIGHT;
	}
}


void Game::ghostCollision() {
	for (auto elem : ghosts)
	{
		if (energizedtimer > 0)
		{
			elem->reset();
		}
		else
		{
			killPacman();	
			elem->reset();
		}
	}
}


int Game::getScore() {
	return score;
}


void Game::increaseScore(Type foodtype) {
	int increment;
	switch (foodtype) {
		case DOT: increment = 10; break;
		case ENERGIZER: increment = 100; break;
		case 1 ... 6: increment= 500; break;
		case 7 ... 12: increment= 200; break;
	}
	score += increment;
	fruitcounter += increment;
	if ((fruitcounter > 1000) and !fruitset)
	{
		int fruitx, fruity;

		while(!fruitset)
		{
			GameObjectStruct fruit;
			fruit.type = Type(rand() % 6 + 7);
			fruitx = rand() % 26 +1;
			fruity = rand() % 26 +1;
			if (map[fruity][fruitx] == 4)
			{
				fruit.x = fruitx;
				fruit.y = fruity;
				fruit.dir = UP;
				food.push_back(fruit);
				fruitset = true;
			}
		}
		fruitset = false;
		fruitcounter = 0;
	}
}

// check whether the character could move in the supplied direction
bool Game::checkWall(int mapx, int mapy, Direction d) {
	switch (d) {
		case LEFT: mapx--; break;
		case RIGHT: mapx++; break;
		case DOWN: mapy++; break;
		case UP: mapy--; break;
	}
	bool wall = map[round(mapy)][round(mapx)] == 1;
	return wall;
}


void Game::setFood()
{
	GameObjectStruct foodobj;

	// place a DOT at all 1s and an ENERGIZER at all 3s
	for(int i=1; i<map.size()-1;i++)
	{
		for(int j=1; j<map[i].size()-1;j++)
		{
			if(map[i][j]!=1)
			{
				if(map[i][j]==0)
				{
					foodobj.type = DOT;
				}
				else if(map[i][j]==3)
				{
					foodobj.type = ENERGIZER;
				}
				else
				{
					continue;
				}

				foodobj.x = j;
				foodobj.y = i;
				foodobj.dir = UP;
				food.push_back(foodobj);
			}

		}
	}
	// put all 'food' items in 'objects' for rendering
	for (auto elem : food)
	{
		objects.push_back(elem);
	}
}


void Game::checkCollision()
{
	int index = 0;
	for (auto elem : food)
	{
		if (pacman.c.x == elem.x and pacman.c.y == elem.y)
		{
			increaseScore(elem.type);
			food.erase(food.begin() + index);
			map[elem.y][elem.x]=4;	// set potential fruit location
			if(elem.type == ENERGIZER)
			{
				energize();
			}
		}
		index++;
	}

	for (auto elem : ghosts)
	{
		if ((pacman.c.x == elem->c.x and pacman.c.y == elem->c.y)
				or (pacman.c.x == elem->c.px and pacman.c.y == elem->c.py))
		{
			if (energizedtimer > 0)
			{
				increaseScore(elem->c.type);
				elem->reset();
				elem->c.type = SCAREDINV;
				setGhosts();
			}
			else
			{
				killPacman();
				setGhosts();
			}
		}
	}
}


void Game::setGhosts()
{
	int counter = -1;
	Type firstType = BLINKY;
	int startx = 12;
	int starty = 13;
	for (auto elem : ghosts)
	{
		counter++;
		if (elem->c.type == SCARED)
		{
			continue;

		}
		elem->c.type = Type(firstType+counter);
		elem->c.x = startx+counter;
		elem->c.y = starty;
		elem->mymode = SCATTER;
	}

}


// coordinate movement of all characters
void Game::charMove()
{
	// can PAC-MAN continue on his path?
	if (!checkWall(pacman.c.x, pacman.c.y, pacman.c.dir))
	{
		// yes, continue
		pacman.goDirection();
	}
	else
	{
		// no, stop
		pacman.c.px = pacman.c.x;
		pacman.c.py = pacman.c.y;
	}
	for (auto elem : ghosts)
	{
		if (elem->mymode == SCATTER)
		{
			map[12][13] = 0; // open ghost house, so ghosts can escape
			map[12][14] = 0;

			int scatterx = 10;
			int scattery = 7;
			if (elem->c.type == INKY or elem->c.type == CLYDE)
			{
				scatterx = 19;
			}
			elem->c.dir = pathFinding(elem->c.x, elem->c.y, scatterx, scattery);
			if (elem->c.y == scattery)
			{
				elem->mymode = CHASE;
			}
		}
		else if (elem->mymode == CHASE)
		{
			elem->c.dir = pathFinding(elem->c.x, elem->c.y, pacman.c.x, pacman.c.y);

			map[12][13] = 1; // wall off ghost house, so ghosts can't go back in
			map[12][14] = 1;
		}
		elem->goDirection();
	}
}


std::vector<GameObjectStruct> Game::setObjects()
{
	std::vector<GameObjectStruct> objects;

	for (auto elem : food)
	{
		objects.push_back(elem);
	}

	objects.push_back(pacman.c);
	objects.push_back(inky.c);
	objects.push_back(pinky.c);
	objects.push_back(blinky.c);
	objects.push_back(clyde.c);

	return objects;
}


void Game::energize()
{
	energizedtimer = 200;
	for (auto elem : ghosts)
	{
		elem->c.type = SCARED;
	}
}


void Game::timer()	// energized timer
{
	int counter = 0;
	for (auto elem : ghosts)
	{
		if (energizedtimer > 0)
		{
			energizedtimer--;
			if (energizedtimer < 50 and energizedtimer % 10)
			{
				if (elem->c.type == SCARED)
					{
					elem->c.type = SCAREDINV;
					}
				else if (elem->c.type == SCAREDINV)
				{
					elem->c.type = SCARED;
				}
			}


		}
		if (energizedtimer < 1)
		{
			elem->c.type = Type(BLINKY+counter);
			counter++;
		}
	}

}

Direction Game::pathFinding(int startx, int starty, int targetx, int targety)
{
	int distx;
	int disty;
	int dist;
	int shortest = 1000;		// shortest path to target (for CHASE mode)
	int longest = 0;			// farthest tile from target (for SCARED mode)

	Direction d;
	Direction best;
	for (int i = 0; i<4; i++)	// cycle through all directions
	{
		int potx = startx;
		int poty = starty;
		d = Direction(i);
		switch (d)
		{
			case LEFT: potx--; break;
			case RIGHT: potx++; break;
			case DOWN: poty++; break;
			case UP: poty--; break;
		}
		if (!checkWall(startx, starty, d))
		{
			distx = abs(targetx - potx);	// distance to target along x axis
			disty = abs(targety - poty);	// distance to target along y axis
			dist = 	distx + disty;	// take both distances into account
			if (dist < shortest)
			{
				shortest = dist;
				best = d;

			}
			if ((energizedtimer > 0) and (dist > longest))
			{
				longest = dist;
				best = d;
			}
		}
	}
	return best;
}
