/**
 * All constants required for the program
 * 
 * Authors: Jono Hills and Josh Meneghini
 */

#include "pio.h"

uint16_t blinker_count = 0;
int playerNum = 0;
char playerChoice = 'M';
char opponentChoice = 0;
int sent = 0;
int received = 0;
int result = 0;

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

