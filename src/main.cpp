/*
 * main.cpp
 *
 *  Created on: Jan 29, 2015
 *      Author: frits
 *       Group: TA's
 */

#include "UI.h"
#include "GameObjectStruct.h"
#include <SDL2/SDL.h>
#include <vector>
#include "game.h"
#include "character.h"
#include "pacman.h"
#include "ghost.h"
#include "main.h"
#include <iostream>
#include <unistd.h>
#include <chrono>
#include <thread>


int main(int argc, char* argv[]) {

	Game game;



	Direction dir;

	// Create a new ui object
	UI ui(game.map); // <-- use map from your game objects.

	game.setFood();


	// Start timer for game update, call this function every 100 ms.
	timer_id = SDL_AddTimer(100, gameUpdate, (void *)nullptr);



	/* Put game init code here */

	bool quit = false;

	while (!quit){
		// set timeout to limit frame rate
		Uint32 timeout = SDL_GetTicks();

		// Handle the input
		while (SDL_PollEvent(&e)){
			// Quit button.
			if (e.type == SDL_QUIT){
				quit = true;
			}

			// All keydown events
			if (e.type == SDL_KEYDOWN){
				// set potential PAC-MAN directions depending on button pressed
	            switch (e.key.keysym.sym)
	            {
	            case SDLK_LEFT:   dir = LEFT; break;
	            case SDLK_RIGHT:  dir = RIGHT; break;
	            case SDLK_UP:     dir = UP; break;
	            case SDLK_DOWN:   dir = DOWN; break;
	            case SDLK_ESCAPE: quit= true; break;
	            }
				// check whether direction from input is valid
	    		if (!game.checkWall(game.pacman.c.x, game.pacman.c.y, dir)) {
	    			game.pacman.c.dir = dir;

	    		}
			}
		}


		game.charMove();

		game.checkCollision();


		// Set the score
		ui.setScore(game.getScore()); /* <-- Put your code in the setter */

		// Set the amount of lives
		ui.setLives(game.getLives()); /* <-- Put your code in the setter */

		// Render the scene




		for (ui.tween = 0; ui.tween<4; ui.tween++)
		{
			ui.update(game.setObjects()); /* <-- Put your code in the update function (e.g. game->getStructs()) */
			std::this_thread::sleep_for(std::chrono::milliseconds(50));
		}

		if (game.over)
		{
			std::cout << "GAME OVER!" << std::endl;
			std::this_thread::sleep_for(std::chrono::milliseconds(500));
			quit = true;
		}

		game.timer();

		while (!SDL_TICKS_PASSED(SDL_GetTicks(), timeout)) {
			/* ... do work until timeout has elapsed */
		}
	}

	SDL_RemoveTimer(int(timer_id));

    return 0;
}


Uint32 gameUpdate(Uint32 interval, void *param)
{
	/** Do game loop update here **/
	return interval;
}
