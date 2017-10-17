/**
 * Paper Scissors Rock game  
 * authors: Joshua Meneghini and Jonathan Hills
 * jam357 and jhi57
 */

#include "init.h"
#include "setup.h"
#include "character.h"
#include "constants.h"
#include "common_functions.h"
#include "sending.h"

static int previous_col;

static const uint8_t bitmap[] =
{
    0x30, 0x46, 0x40, 0x46, 0x30
};

static void display_column1 (uint8_t row_pattern, uint8_t current_column)
{
    pio_output_high(cols[previous_col]);
    int current_row;
    for (current_row = 0; current_row < 7; current_row++)
    {
        if ((row_pattern >> current_row) & 1)
        {
            pio_output_low(rows[current_row]);
        }
        else
        {
            pio_output_high(rows[current_row]);
        }
    }
    pio_output_low(cols[current_column]);
}

int main (void)
{
    game_init ();
    
    uint8_t current_column = 0;    
    tinygl_text("Monkey-Pirate-Robot-Ninja-Zombie");
    
    while (1)
    {
        button_update ();
        pacer_wait ();
        
        display_column1 (bitmap[current_column], current_column);
        previous_col = current_column;
        current_column++;
    
        if (current_column > (LEDMAT_COLS_NUM - 1))
        {
            current_column = 0;
        }        
        if (button_push_event_p (BUTTON1)) {
            break;
        }   
    }
    while (1)
    {
        pacer_wait();
        tinygl_update ();
        navswitch_update ();
        button_update ();
        
        if (button_push_event_p (BUTTON1)) {
            tinygl_clear ();
            break;
        }
        
    }
    
    /*TODO*/
    game_setup ();
    choose_action();
    send_choice();
    // opponentChoice = receive();
    // compare(choice, opponentChoice);
    return 0;
}
