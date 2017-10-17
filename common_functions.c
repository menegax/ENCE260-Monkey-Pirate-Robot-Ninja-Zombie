/**
 * Monkey-Pirate-Robot-Ninja-Zombie game
 * common_functions.c
 * Authors: Joshua Meneghini and Jonathan Hills
 * jam357 and jhi57
 */

#include "constants.h"
#include "init.h"
#include "tinygl.h"
#include "tinygl.h"

/**Used to limit cursor movement*/
void navswitch_moved (void)
{
    if (navswitch_push_event_p (NAVSWITCH_NORTH)) {
        playerChoice = 'M';
    }
    if (navswitch_push_event_p (NAVSWITCH_SOUTH)) {
        playerChoice = 'R';
    }
    if (navswitch_push_event_p (NAVSWITCH_EAST)) {
       playerChoice = 'N';
    }
    if (navswitch_push_event_p (NAVSWITCH_WEST)) {
        playerChoice = 'P';
    }
    if (navswitch_push_event_p (NAVSWITCH_PUSH)) {
        playerChoice = 'Z';
    } 
}

/**Compares the two options to decide on a winner and displays winner**/
void compare(char playerChoice, char opponentChoice)
{
    tinygl_text_mode_set(TINYGL_TEXT_MODE_SCROLL);
    if (opponentChoice == 'M' || opponentChoice == 'N' ||opponentChoice == 'R' || opponentChoice == 'Z' || opponentChoice == 'P'){
        if (playerChoice == opponentChoice) {
            result = 'D';
        } else if ((playerChoice == 'M' && opponentChoice == 'N') || (playerChoice == 'M' && opponentChoice == 'R')) {
            result = 'W';
        } else if ((playerChoice == 'R' && opponentChoice == 'N') || (playerChoice == 'R' && opponentChoice == 'Z')) {
            result = 'W';
        } else if ((playerChoice == 'P' && opponentChoice == 'R') || (playerChoice == 'P' && opponentChoice == 'M')) {
            result = 'W';
        } else if ((playerChoice == 'N' && opponentChoice == 'P') || (playerChoice == 'N' && opponentChoice == 'Z')) {
            result = 'W';
        } else if ((playerChoice == 'Z' && opponentChoice == 'P') || (playerChoice == 'Z' && opponentChoice == 'M')) {
            result = 'W';
        } else {
            result = 'L';
        }
    }
    //Could expand this to return a 1 for a win or 0 otherwise and display a count of all wins
}

void win_or_lose(int outcome) 
{
    tinygl_text_mode_set(TINYGL_TEXT_MODE_STEP);
    if (outcome == 87) {
        tinygl_text("W");
    }
    else if (outcome == 76) {
        tinygl_text("L");
    }
    else if (outcome == 68) {
        tinygl_text("D");
    }
} 

/**Returns if the board is player 1 or 2**/
int getPlayer(void)
{
    if (playerNum == 1) {
        return 1;
    } else {
        return 0;
    }
}

/**Sets a board to be player 1**/
void setPlayer(void)
{
    playerNum = 1;
}
