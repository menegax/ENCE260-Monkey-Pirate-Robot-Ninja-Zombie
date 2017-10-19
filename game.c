/**
 * Monkey-Pirate-Robot-Ninja-Zombie game
 * game.c
 * Authors: Joshua Meneghini and Jonathan Hills
 * jam357 and jhi57
 */

#include "init.h"
#include "setup.h"
#include "character.h"
#include "constants.h"
#include "common_functions.h"
#include "sending.h"
#include "receiver.h"

static const uint8_t bitmap[] =
{
    0x30, 0x46, 0x40, 0x46, 0x30
};

int main (void)
{
    /**Initialises the game**/
    game_init ();
    uint8_t current_column = 0;
    
    while (1)
    {
        button_update ();
        pacer_wait ();
        /**Calls the function to display bitmap smiley face in common_functions**/
        display_column (bitmap[current_column], current_column);
        previous_col = current_column;
        current_column++;
    
        if (current_column > (LEDMAT_COLS_NUM - 1))
        {
            current_column = 0;
        }
        /**When button is pressed stop displaying the smiley face**/
        if (button_push_event_p (BUTTON1)) {
            break;
        }   
    }
    
    /**Displays the game title**/
    tinygl_text("Monkey-Pirate-Robot-Ninja-Zombie");
    
    while (1)
    {
        pacer_wait();
        tinygl_update ();
        navswitch_update ();
        button_update ();
        /**when button is pressed stop displaying the game title**/
        if (button_push_event_p (BUTTON1)) {
            tinygl_clear ();
            break;
        }
    }
    
    /**Enter the game setup phase to choose player numbers**/
    game_setup ();
    
    /**The game phase**/
    while (1) {
        if (received == 0) {
            /**Choose the character option to play with**/
            choose_action();
        }
        
        while(1){
            button_update();
            tinygl_update();
            /**Player 2 sends their choice to player 1**/
            if (player_num == 0 && sent == 0){
                send_choice();  
            } 
            /**Player 1 receives player 2's choice**/
            if (player_num == 1 && received == 0) {
                receive_option();
            }
            /**Player 1 sends information on whether player 2 won or not**/
            if (player_num == 1 && received == 1){
                send_choice();
            } 
            /**Player 2 receives information on whether they won or not**/
            if (player_num == 0) {
                receive_option();
            }
            /**Once received, display whether each player won or not**/
            if (received == 1){
                win_or_lose(result); 
            }
            /**When pressed, reset all variables and start game phase again**/
            if (button_push_event_p (BUTTON1)) {
                player_choice = 'M';
                opponent_choice = 0;
                sent = 0;
                received = 0;
                result = 0;
                break;
            }   
        }
    }
    
    return 0;
}
