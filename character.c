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
    tinygl_text_mode_set(TINYGL_TEXT_MODE_STEP);

    while(1) {
        pacer_wait();
        navswitch_update();
        tinygl_update();
        button_update();
        char buffer[2];

        if(choice == 'M') {
            buffer[0] = choice;
            buffer[1] = '\0';
            tinygl_text(buffer);
        } 
        else if(choice == 'R') {
            buffer[0] = choice;
            buffer[1] = '\0';
            tinygl_text(buffer);
        } 
        else if(choice == 'P') {
            buffer[0] = choice;
            buffer[1] = '\0';
            tinygl_text(buffer);
        } 
        else if(choice == 'N') {
            buffer[0] = choice;
            buffer[1] = '\0';
            tinygl_text(buffer);
        }
        else if(choice == 'Z') {  
            buffer[0] = choice;
            buffer[1] = '\0';
            tinygl_text(buffer);
        }
        
        choice = navswitch_moved();
        
        
        if(button_push_event_p (BUTTON1)){
            return choice;
        }
    }
}

