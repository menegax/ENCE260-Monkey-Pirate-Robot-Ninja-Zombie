/**
 * Monkey-Pirate-Robot-Ninja-Zombie game
 * methods.c
 * Authors: Joshua Meneghini and Jonathan Hills
 * jam357 and jhi57
 */

#include "constants.h"


/**Check if the button is pressed*/
uint8_t button_pressed_p (void)
{
    return pio_input_get(BUTTON_PIO);
}
