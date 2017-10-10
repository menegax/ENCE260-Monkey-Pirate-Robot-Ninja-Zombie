/**
 * Battleship game 
 * authors: Joshua Meneghini and Jonathan Hills
 * jam357 and ...??
 */

#include "init.h"

int main (void)
{
    game_init ();

    tinygl_text("Josh and Jono's game :)");
    while (1)
    {
        pacer_wait();
        
        tinygl_update ();
    }
}
