/**
 * All helper methods required by the various parts of the program.
 * 
 * Authors: Jono Hills and Josh Meneghini
 * 
 */

#include "constants.h"


/**Check if the button is pressed*/
uint8_t button_pressed_p (void)
{
    return pio_input_get(BUTTON_PIO);
}
