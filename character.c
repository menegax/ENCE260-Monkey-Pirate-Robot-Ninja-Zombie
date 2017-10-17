/**
 * Chooses, displays and returns a character to send.
 **/


#include "constants.h"
#include "common_functions.h"



/**Determines which option the player chooses**/
char choose_action(void)
{
    char choice = 'M';
    navswitch_init();
    button_init();

    while(1) {
        pacer_wait();
        navswitch_update();
        tinygl_update();
        button_update();

        if(choice == 'M') {
            tinygl_text("M");
        } 
        else if(choice == 'R') {
            tinygl_text("R");
        } 
        else if(choice == 'P') {
            tinygl_text("P");
        } 
        else if(choice == 'N') {
            tinygl_text("N");
        }
        else if(choice == 'Z') {
            tinygl_text("Z");
        }
        
        choice = navswitch_moved();
        
        
        if(button_push_event_p (BUTTON1)){
            return choice;
        }
    }
}

