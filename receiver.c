/**
 * Monkey-Pirate-Robot-Ninja-Zombie game
 * receiver.c
 * Authors: Joshua Meneghini and Jonathan Hills
 * jam357 and jhi57
 */

#include "constants.h"
#include "ir_uart.h"

/**Reads input from the opposite board. **/
void receive_option(void)
{   
    /**Player 1 receives player 2's choice else, player 2 receives game result**/
    if (player_num == 1) {
        /**The opponents choice**/
        if (ir_uart_read_ready_p ()) {
            opponent_choice = ir_uart_getc ();
            if (opponent_choice != 0){
                received = 1;
            }
        }
    } else {
        /**The game result**/
        if (ir_uart_read_ready_p ()) {
            result = ir_uart_getc();
            if (result != 0) {
                received = 1;
                sent = 1;
            }
        }
    }
}
