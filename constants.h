/**
 * Monkey-Pirate-Robot-Ninja-Zombie game
 * constants.h
 * Authors: Joshua Meneghini and Jonathan Hills
 * jam357 and jhi57
 */

#ifndef GAME_H
#define GAME_H

#include "pio.h"

/** 
 * The three differenct ASCII characters for W L and D.
 */
#define WIN 87
#define LOSE 76
#define DRAW 68

uint16_t blinker_count;
/**player number 0 for p2 and 1 for p1**/
int player_num;
/**the choice the player made to play with**/
char player_choice;
/**the choice opponent chose to play with**/
char opponent_choice;
/**when choice is sent by p2, changed to 1**/
int sent;
/**when received by p1, changed to 1**/
int received;
/**W, L or D after compared**/
int result;
/**variable storing the previous column to display the bitmap**/
int previous_col;

const pio_t rows[7];

const pio_t cols[5];

#endif
