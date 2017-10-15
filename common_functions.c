/*
common functions
created by Joshua Meneghini and Jonathan Hills
*/

#include "constants.h"
#include "init.h"
#include "tinygl.h"


/**Used to display bitmap*/
void display_column (uint8_t row_pattern, uint8_t current_column)
{
    int i;
    for (i = 0; i < 5; i++) {
        pio_output_high (cols[i]);
    }
    pio_output_low (cols[current_column]);

    uint8_t current_row;
    for (current_row = 0; current_row < 7; current_row++) {
        if ((row_pattern >> current_row) & 1) {
            pio_output_low (rows[current_row]);
        }
        else {
            pio_output_high (rows[current_row]);
        }
    }
}

/**Used to limit cursor movement*/
void navswitch_moved (uint8_t num)
{
    if (navswitch_push_event_p (NAVSWITCH_NORTH) && y_pos > (1 - num)) {
        navswitch_map[x_pos] = navswitch_map[x_pos] >> 1;
        y_pos--;
    }

    if (navswitch_push_event_p (NAVSWITCH_SOUTH) && y_pos < (5 + num)) {
        navswitch_map[x_pos] = navswitch_map[x_pos] << 1;
        y_pos++;
    }

    if (navswitch_push_event_p (NAVSWITCH_EAST) && x_pos < 4) {
        prev_pos_x = navswitch_map[x_pos];
        navswitch_map[x_pos] &= 0;
        x_pos++;
        navswitch_map[x_pos] = prev_pos_x;
    }

    if (navswitch_push_event_p (NAVSWITCH_WEST) && x_pos > 0) {
        prev_pos_x = navswitch_map[x_pos];
        navswitch_map[x_pos] &= 0;
        x_pos--;
        navswitch_map[x_pos] = prev_pos_x;
    }
}

/**Function to display cursor with blinking effect*/
void display_threeline (void)
{
    if (blinker_count < (BLINK_RATE / 2)) {
        display_column (navswitch_map[current_column], current_column);
        pacer_wait ();
    }
    blinker_count = (blinker_count + 1) % (BLINK_RATE);
}

/**Set current column for display_column*/
void upd_column (void)
{
    current_column++;

    if (current_column > (LEDMAT_COLS_NUM - 1)) {
        current_column = 0;
    }
}

/**Function to display ship map*/
void display_shipmap (void)
{
    display_column (shipmap[current_column], current_column);
    pacer_wait ();
}

/**Function to display empty map*/
void display_emptymap (void)
{
    display_column (emptymap[current_column], current_column);
    pacer_wait ();
}

/**Compares the two options to decide on a winner and displays winner**/
void compare(char playerChoice, char opponentChoice)
{
    tinygl_text_mode_set(TINYGL_TEXT_MODE_SCROLL);
    
    if (playerChoice == opponentChoice) {
        tinygl_text("DRAW");
    } else if (playerChoice == 'S' && opponentChoice == 'P') {
        tinygl_text("YOU WIN!");
    } else if (playerChoice == 'P' && opponentChoice == 'R') {
        tinygl_text("YOU WIN!");
    } else if (playerChoice == 'R' && opponentChoice == 'S') {
        tinygl_text("YOU WIN!");
    } else {
        tinygl_text("YOU LOSE!");
    }
    //Could expand this to return a 1 for a win or 0 otherwise and display a count of all wins
}
