/* 
 * sending the character chosen to the opponent's board
 * Authors: Joshua Meneghini and Jonathan Hills
 */

#include "constants.h"
#include "common_functions.h"

void send_choice (void)
{
    if (playerNum == 0) {
        ir_uart_putc(playerChoice);
        sent = 1;
    }
    else {
        compare(playerChoice, opponentChoice);
        if (result == 'W') {
            ir_uart_putc(76);
        } else if (result == 'L') {
            ir_uart_putc(87);
        } else {
            ir_uart_putc(68);
        }
    }
}
