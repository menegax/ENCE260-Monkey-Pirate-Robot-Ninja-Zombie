/**
 * Chooses, displays and returns a character to send.
 **/


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
        
/*
        if(playerChoice == 'M') {

        } 
        else if(playerChoice == 'R') {
            buffer[0] = playerChoice;
            buffer[1] = '\0';
            tinygl_text(buffer);
        } 
        else if(playerChoice == 'P') {
            buffer[0] = playerChoice;
            buffer[1] = '\0';
            tinygl_text(buffer);
        } 
        else if(playerChoice == 'N') {
            buffer[0] = playerChoice;
            buffer[1] = '\0';
            tinygl_text(buffer);
        }
        else if(playerChoice == 'Z') {  
            buffer[0] = playerChoice;
            buffer[1] = '\0';
            tinygl_text(buffer);
        }*/
        
        if(button_push_event_p (BUTTON1)){
            break;
        }
    }
}

