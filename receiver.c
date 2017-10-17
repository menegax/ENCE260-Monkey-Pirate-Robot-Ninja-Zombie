#include "constants.h"

/**Reads input from the opposite board. **/
void receive_option(void)
{   
    if (getPlayer() == 1) {
        //The opponents choice
        if (ir_uart_read_ready_p()) {
            opponentChoice = ir_uart_getc();
        }
    } else {
        //The game result
        if (ir_uart_read_ready_p()) {
            result = ir_uart_getc();
        }
    }
}
