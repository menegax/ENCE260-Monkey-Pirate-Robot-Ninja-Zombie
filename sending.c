/**
 * Monkey-Pirate-Robot-Ninja-Zombie game
 * sending.c
 * Authors: Joshua Meneghini and Jonathan Hills
 * jam357 and jhi57
 */

#include "constants.h"
#include "common_functions.h"

/**Sends input to the opposite board. **/
void send_choice (void)
{
    /**Player 2 sends their choice to player 1 else, player 1 sends game result**/
    if (playerNum == 0) {
        ir_uart_putc(playerChoice);
        sent = 1;
    } else {
        compare(playerChoice, opponentChoice);
        if (result == 'W') {
            ir_uart_putc(LOSE);
        } else if (result == 'L') {
            ir_uart_putc(WIN);
        } else {
            ir_uart_putc(DRAW);
        }
    }
}
