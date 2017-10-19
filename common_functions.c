/**
 * Monkey-Pirate-Robot-Ninja-Zombie game
 * common_functions.c
 * Authors: Joshua Meneghini and Jonathan Hills
 * jam357 and jhi57
 */

#include "constants.h"
#include "init.h"
#include "tinygl.h"
#include "tinygl.h"

/**
 * Used to limit cursor movement and update the plauerChoice character
 * that is displayed
 */
void navswitch_moved (void)
{
    if (navswitch_push_event_p (NAVSWITCH_NORTH)) {
        playerChoice = 'M'; 
    }
    if (navswitch_push_event_p (NAVSWITCH_SOUTH)) {
        playerChoice = 'R'; 
    }
    if (navswitch_push_event_p (NAVSWITCH_EAST)) {
       playerChoice = 'N';
    }
    if (navswitch_push_event_p (NAVSWITCH_WEST)) {
        playerChoice = 'P';
    }
    if (navswitch_push_event_p (NAVSWITCH_PUSH)) {
        playerChoice = 'Z';
    } 
}

/**
 * Compares the two options to decide on a winner and updates the result
 * variable from constants to pass to the opponent's board
 **/
void compare(char playerChoice, char opponentChoice)
{
    tinygl_text_mode_set(TINYGL_TEXT_MODE_SCROLL);
    if (opponentChoice == 'M' || opponentChoice == 'N' ||opponentChoice == 'R' || opponentChoice == 'Z' || opponentChoice == 'P'){
        if (playerChoice == opponentChoice) {
            result = 'D';
        } else if ((playerChoice == 'M' && opponentChoice == 'N') || (playerChoice == 'M' && opponentChoice == 'R')) {
            result = 'W';
        } else if ((playerChoice == 'R' && opponentChoice == 'N') || (playerChoice == 'R' && opponentChoice == 'Z')) {
            result = 'W';
        } else if ((playerChoice == 'P' && opponentChoice == 'R') || (playerChoice == 'P' && opponentChoice == 'M')) {
            result = 'W';
        } else if ((playerChoice == 'N' && opponentChoice == 'P') || (playerChoice == 'N' && opponentChoice == 'Z')) {
            result = 'W';
        } else if ((playerChoice == 'Z' && opponentChoice == 'P') || (playerChoice == 'Z' && opponentChoice == 'M')) {
            result = 'W';
        } else {
            result = 'L';
        }
    }
}

/**
 * Display the characters W, D or L for the win, loss or draw
 **/
void win_or_lose(int outcome) 
{
    tinygl_text_mode_set(TINYGL_TEXT_MODE_STEP);
    if (outcome == 87) {
        tinygl_text("W");
    } else if (outcome == 76) {
        tinygl_text("L");
    } else if (outcome == 68) {
        tinygl_text("D");
    }
} 

/**
 * Returns if the board is player 1 or 2
 **/
int getPlayer(void)
{
    if (playerNum == 1) {
        return 1;
    } else {
        return 0;
    }
}

/**
 * Sets a board to be player 1
 **/
void setPlayer(void)
{
    playerNum = 1;
}

/**
 * Displays the bitmap smiley face at the beginning of the game
 **/
void display_column (uint8_t row_pattern, uint8_t current_column)
{
    pio_output_high(cols[previous_col]);
    int current_row;
    
    for (current_row = 0; current_row < 7; current_row++)
    {
        if ((row_pattern >> current_row) & 1) {
            pio_output_low(rows[current_row]);
        } else {
            pio_output_high(rows[current_row]);
        }
    }
    
    pio_output_low(cols[current_column]);
}
