/**
 * Monkey-Pirate-Robot-Ninja-Zombie game
 * common_functions.h
 * Authors: Joshua Meneghini and Jonathan Hills
 * jam357 and jhi57
 */

#ifndef COMMON_FUNCTIONS_H
#define COMMON_FUNCTIONS_H

#include "constants.h"
#include "init.h"
#include "tinygl.h"

/**
 * Used to limit cursor movement and update the plauerChoice character
 * that is displayed
 */
void navswitch_moved (void);

/**
 * Compares the two options to decide on a winner and updates the result
 * variable from constants to pass to the opponent's board
 **/
void compare(char playerChoice, char opponentChoice);

/**
 * Display the characters W, D or L for the win, loss or draw
 **/
void win_or_lose(int outcome) ;

/**
 * Returns if the board is player 1 or 2
 **/
int getPlayer(void);

/**
 * Sets a board to be player 1
 **/
void setPlayer(void);

/**
 * Displays the bitmap smiley face at the beginning of the game
 **/
void display_column (uint8_t row_pattern, uint8_t current_column);

#endif
