/**
 * Monkey-Pirate-Robot-Ninja-Zombie game
 * setup.h
 * Authors: Joshua Meneghini and Jonathan Hills
 * jam357 and jhi57
 */

#ifndef SETUP_H
#define SETUP_H

#include "constants.h"
#include "common_functions.h"

/**Used in move_cursor to define border for cursor*/
#define NUM 0

/**Assigns each board a player number**/
void player_setup(void);

/**Planning phase function (Step 1)*/
void game_setup (void);

#endif
