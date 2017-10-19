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
        player_choice = 'M'; 
    }
    if (navswitch_push_event_p (NAVSWITCH_SOUTH)) {
        player_choice = 'R'; 
    }
    if (navswitch_push_event_p (NAVSWITCH_EAST)) {
       player_choice = 'N';
    }
    if (navswitch_push_event_p (NAVSWITCH_WEST)) {
        player_choice = 'P';
    }
    if (navswitch_push_event_p (NAVSWITCH_PUSH)) {
        player_choice = 'Z';
    } 
}

/**
 * Compares the two options to decide on a winner and updates the result
 * variable from constants to pass to the opponent's board
 **/
void compare(char player_choice, char opponent_choice)
{
    tinygl_text_mode_set(TINYGL_TEXT_MODE_SCROLL);
    if (opponent_choice == 'M' || opponent_choice == 'N' ||opponent_choice == 'R' || opponent_choice == 'Z' || opponent_choice == 'P'){
        if (player_choice == opponent_choice) {
            result = 'D';
        } else if ((player_choice == 'M' && opponent_choice == 'N') || (player_choice == 'M' && opponent_choice == 'R')) {
            result = 'W';
        } else if ((player_choice == 'R' && opponent_choice == 'N') || (player_choice == 'R' && opponent_choice == 'Z')) {
            result = 'W';
        } else if ((player_choice == 'P' && opponent_choice == 'R') || (player_choice == 'P' && opponent_choice == 'M')) {
            result = 'W';
        } else if ((player_choice == 'N' && opponent_choice == 'P') || (player_choice == 'N' && opponent_choice == 'Z')) {
            result = 'W';
        } else if ((player_choice == 'Z' && opponent_choice == 'P') || (player_choice == 'Z' && opponent_choice == 'M')) {
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
    if (outcome == WIN) {
        tinygl_text("W");
    } else if (outcome == LOSS) {
        tinygl_text("L");
    } else if (outcome == DRAW) {
        tinygl_text("D");
    }
} 

/**
 * Sets a board to be player 1
 **/
void set_player(void)
{
    player_num = 1;
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
