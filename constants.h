/**
 * Monkey-Pirate-Robot-Ninja-Zombie game
 * constants.h
 * Authors: Joshua Meneghini and Jonathan Hills
 * jam357 and jhi57
 */

#ifndef GAME_H
#define GAME_H

#include "pio.h"

uint16_t blinker_count;
int playerNum;
char playerChoice;
char opponentChoice;
int received;
int sent;
int result;

const pio_t rows[7];

const pio_t cols[5];

#endif
