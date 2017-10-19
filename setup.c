/**
 * Monkey-Pirate-Robot-Ninja-Zombie game
 * setup.c
 * Authors: Joshua Meneghini and Jonathan Hills
 * jam357 and jhi57
 */

#include "constants.h"
#include "common_functions.h"

/**Assigns each board a player number**/
void player_setup(void) 
{
    int player_choice = 1;
    blinker_count = 0;
    
    while (1) {
        pacer_wait();
        button_update ();
        navswitch_update ();
        tinygl_update();

        if(player_choice == 1) {
            tinygl_text("1");
        } else if (player_choice == 2) {
            tinygl_text("2");
        }

        if(navswitch_push_event_p (NAVSWITCH_NORTH) || navswitch_push_event_p (NAVSWITCH_SOUTH)) {
            if(player_choice == 1) {
                player_choice = 2;
            } else {
                player_choice = 1;
            }
        } else if(navswitch_push_event_p (NAVSWITCH_PUSH)) {
            if (player_choice == 1) {
                set_player();
            }
            break;
        }
    }
}


/**
 * Planning phase function (Step 1)
 **/
void game_setup (void)
{
    tinygl_text("CHOOSE PLAYER");
    blinker_count = 0;
    
    while (1) {
        pacer_wait();
        button_update ();
        navswitch_update ();
        tinygl_update();
        /**Once chosen, assign the board a number and go back to game**/
        if (button_push_event_p (BUTTON1)) {
            tinygl_clear ();
            player_setup();
            break;
        }

    }
}
    

