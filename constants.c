/**
 * All constants required for the program
 * 
 * Authors: Jono Hills and Josh Meneghini
 */

#include "pio.h"

#define BLINK_RATE 200

uint8_t x_pos = 2;
uint8_t y_pos = 3;
uint8_t prev_pos_x = 0;
uint8_t current_column = 0;
uint16_t blinker_count = 0;
uint16_t ships = 0;
int playerNum = 0;
char playerChoice = 'M';

uint8_t shipmap[] =
{
    0x0, 0x0, 0x0, 0x0, 0x0
};

uint8_t navswitch_map[] =
{
    0x0, 0x0, 0x0, 0x0, 0x0
};

uint8_t emptymap[] =
{
    0x0, 0x0, 0x0, 0x0, 0x0
};

const pio_t rows[] =
{
    LEDMAT_ROW1_PIO, LEDMAT_ROW2_PIO, LEDMAT_ROW3_PIO,
    LEDMAT_ROW4_PIO, LEDMAT_ROW5_PIO, LEDMAT_ROW6_PIO,
    LEDMAT_ROW7_PIO
};

const pio_t cols[] =
{
    LEDMAT_COL1_PIO, LEDMAT_COL2_PIO, LEDMAT_COL3_PIO,
    LEDMAT_COL4_PIO, LEDMAT_COL5_PIO
};

