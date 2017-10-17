#include "constants.h"

/**Reads input from the opposite board. **/
void receive_option(void)
{   
    if (playerNum == 1) {
        //The opponents choice
        if (ir_uart_read_ready_p()) {
            opponentChoice = ir_uart_getc();
            if (opponentChoice != 0){
                received = 1;
            }
        }
    } else {
        //The game result
        if (ir_uart_read_ready_p()) {
            result = ir_uart_getc();
            if (result != 0) {
                received = 1;
                sent = 1;
            }
        }
    }
}
