/**
 * Monkey-Pirate-Robot-Ninja-Zombie game
 * character.c
 * Authors: Joshua Meneghini and Jonathan Hills
 * jam357 and jhi57
 */


#include "constants.h"
#include "common_functions.h"



/**Determines which option the player chooses**/
void choose_action(void)
{
    navswitch_init();
    button_init();
    tinygl_text_mode_set(TINYGL_TEXT_MODE_STEP);
    char buffer[2];
    while(1) {
        pacer_wait();
        navswitch_update();
        tinygl_update();
        button_update();
        buffer[0] = playerChoice;
        buffer[1] = '\0';
        tinygl_text(buffer);
        navswitch_moved();
        if(button_push_event_p (BUTTON1)){
            break;
        }
    }
}

