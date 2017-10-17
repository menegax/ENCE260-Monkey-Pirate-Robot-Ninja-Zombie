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
