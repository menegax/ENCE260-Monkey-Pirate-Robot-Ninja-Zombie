/**
 * Monkey-Pirate-Robot-Ninja-Zombie game
 * sending.c
 * Authors: Joshua Meneghini and Jonathan Hills
 * jam357 and jhi57
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
