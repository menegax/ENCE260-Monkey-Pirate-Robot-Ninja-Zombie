/* 
 * sending the character chosen to the opponent's board
 * Authors: Joshua Meneghini and Jonathan Hills
 */

#include "constants.h"

void send_choice (void)
{
    if (ir_uart_read_ready_p ())
    {
        if (ir_uart_getc () == 0x47) {
            ir_uart_putc(0x55);
            player = 2;
            break;
        }
    }
}
