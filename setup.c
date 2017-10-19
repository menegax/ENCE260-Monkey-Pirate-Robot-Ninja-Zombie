/**
 * Monkey-Pirate-Robot-Ninja-Zombie game
 * setup.c
 * Authors: Joshua Meneghini and Jonathan Hills
 * jam357 and jhi57
 */

#include "constants.h"
#include "common_functions.h"

#define NUM 0

/**Assigns each board a player number**/
void player_setup(void) 
{
    int playerChoice = 1;
    blinker_count = 0;
    
    while (1) {
        pacer_wait();
        button_update ();
        navswitch_update ();
        tinygl_update();

        if(playerChoice == 1) {
            tinygl_text("1");
        } else if (playerChoice == 2) {
            tinygl_text("2");
        }

        if(navswitch_push_event_p (NAVSWITCH_NORTH) || navswitch_push_event_p (NAVSWITCH_SOUTH)) {
            if(playerChoice == 1) {
                playerChoice = 2;
            } else {
                playerChoice = 1;
            }
        } else if(navswitch_push_event_p (NAVSWITCH_PUSH)) {
            if (playerChoice == 1) {
                setPlayer();
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
        //Once chosen, assign the board a number and go back to game
        if (button_push_event_p (BUTTON1)) {
            tinygl_clear ();
            player_setup();
            break;
        }

    }
}
    

