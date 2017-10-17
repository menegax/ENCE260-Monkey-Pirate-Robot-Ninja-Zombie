#ifndef GAME_H
#define GAME_H

#include "pio.h"

#define BLINK_RATE 200

uint8_t x_pos;
uint8_t y_pos;
uint8_t prev_pos_x;
uint8_t current_column;
uint16_t blinker_count;
uint16_t ships;
int playerNum;
char playerChoice;
char opponentChoice;
int reusult;

uint8_t shipmap[5];

uint8_t emptymap[5];

uint8_t navswitch_map[5];

const pio_t rows[7];

const pio_t cols[5];

#endif
