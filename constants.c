/**
 * Monkey-Pirate-Robot-Ninja-Zombie game
 * constants.c
 * Authors: Joshua Meneghini and Jonathan Hills
 * jam357 and jhi57
 */

#include "pio.h"

/** 
 * The three differenct ASCII characters for W L and D.
 */
#define WIN 87
#define LOSE 76
#define DRAW 68

uint16_t blinker_count = 0;
/**Player number 0 for p2 and 1 for p1**/
int player_num = 0;
/**The choice the player made to play with**/
char player_choice = 'M';
/**The choice opponent chose to play with**/
char opponent_choice = 0;
/**When choice is sent by p2, changed to 1**/
int sent = 0;
/**When received by p1 and p2, changed to 1**/
int received = 0;
/**W, L or D after compared**/
int result = 0;
/**Variable storing the previous column to display the bitmap**/
int previous_col;

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

