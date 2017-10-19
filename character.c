/**
 * Monkey-Pirate-Robot-Ninja-Zombie game
 * character.c
 * Authors: Joshua Meneghini and Jonathan Hills
 * jam357 and jhi57
 */

#include "constants.h"
#include "common_functions.h"

/**Determines which option the player chooses from M, R, Z, P and N**/
void choose_action(void)
{
    navswitch_init();
    button_init();
    tinygl_text_mode_set(TINYGL_TEXT_MODE_STEP);
    char buffer[2]; 
    /**creates a buffer which contains the player's choice of character and the null terminator**/
    
    while(1) { 
        pacer_wait();
        navswitch_update();
        tinygl_update();
        button_update();
        buffer[0] = player_choice;
        buffer[1] = '\0';
        tinygl_text(buffer);
        /**when navswitch is moved, the character must update, this function is in common_functions**/
        navswitch_moved(); 
        /**when pressed, go back to the main game**/
        if(button_push_event_p (BUTTON1)){ 
            break;
        }
    }
}

