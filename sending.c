/* 
 * sending the character chosen to the opponent's board
 * Authors: Joshua Meneghini and Jonathan Hills
 */

#include "constants.h"
#include "common_functions.h"

void send_choice (void)
{
    if (getPlayer == 0) {
        if (playerChoice == 'M') {
            ir_uart_putc(1);
        }
        else if (playerChoice  == 'R') {
            ir_uart_putc(2);
        }
        else if (playerChoice  == 'P') {
            ir_uart_putc(3);
        }
        else if (playerChoice  == 'N') {
            ir_uart_putc(4);
        }
        else if (playerChoice  == 'Z') {
            ir_uart_putc(5);
        }
    }
    else {
        compare(playerChoice, opponentChoice);
        if (result == 6) {
            ir_uart_putc(8);
        } else if (result == 8) {
            ir_uart_putc(6);
        } else {
            ir_uart_putc(result);
        }
    }
}
