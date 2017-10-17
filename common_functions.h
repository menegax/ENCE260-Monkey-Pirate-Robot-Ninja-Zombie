#ifndef COMMON_FUNCTIONS_H
#define COMMON_FUNCTIONS_H

#include "constants.h"
#include "init.h"

/**Used to display bitmap*/
void display_column (uint8_t row_pattern, uint8_t current_column);

/**Used to limit cursor movement*/
char navswitch_moved ();

/**Function to display cursor with blinking effect*/
void display_threeline (void);

/**Set current column for display_column*/
void upd_column (void);

/**Function to display ship map*/
void display_shipmap (void);

/**Function to display empty map*/
void display_emptymap (void);

/**Compares the two options to decide on a winner and displays winner**/
void compare(char playerChoice, char opponentChoice);

/**Returns if the board is player 1 or 2**/
int getPlayer(void);

/**Sets a board to be player 1**/
void setPlayer(void);

#endif
