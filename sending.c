/* 
 * sending the character chosen to the opponent's board
 * Authors: Joshua Meneghini and Jonathan Hills
 */

#include "constants.h"
#include "common_functions.h"

void send_choice (void)
{
    if (playerNum == 0) {
        if (playerChoice == 'M') {
            ir_uart_putc('M');
        }
        else if (playerChoice  == 'R') {
            ir_uart_putc('R');
        }
        else if (playerChoice  == 'P') {
            ir_uart_putc('P');
        }
        else if (playerChoice  == 'N') {
            ir_uart_putc('N');
        }
        else if (playerChoice  == 'Z') {
            ir_uart_putc('Z');
        }
    }
    else {
        compare(playerChoice, opponentChoice);
        if (result == 'W') {
            ir_uart_putc(76);
        } else if (result == 'L') {
            ir_uart_putc(87);
        } else {
            ir_uart_putc('D');
        }
    }
}
