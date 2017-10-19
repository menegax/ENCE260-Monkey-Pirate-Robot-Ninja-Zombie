/**
 * Monkey-Pirate-Robot-Ninja-Zombie game
 * init.c
 * Authors: Joshua Meneghini and Jonathan Hills
 * jam357 and jhi57
 */

#include "system.h"
#include "navswitch.h"
#include "pacer.h"
#include "ir_uart.h"
#include "tinygl.h"
#include "button.h"
#include "../fonts/font5x7_1.h"
#include "pio.h"

#define LOOP_RATE 500
#define MESSAGE_RATE 20

/**
 * Initialising modules; navswitch, pacer, ir_uart, button, led's, tinygl etc
 **/
void game_init(void)
{
    system_init ();
    navswitch_init();
    pacer_init (LOOP_RATE);
    ir_uart_init();
    button_init ();
        
    pio_config_set(LEDMAT_ROW1_PIO, PIO_OUTPUT_LOW);
    pio_config_set(LEDMAT_ROW2_PIO, PIO_OUTPUT_LOW);
    pio_config_set(LEDMAT_ROW3_PIO, PIO_OUTPUT_LOW);
    pio_config_set(LEDMAT_ROW4_PIO, PIO_OUTPUT_LOW);
    pio_config_set(LEDMAT_ROW5_PIO, PIO_OUTPUT_LOW);
    pio_config_set(LEDMAT_ROW6_PIO, PIO_OUTPUT_LOW);
    pio_config_set(LEDMAT_ROW7_PIO, PIO_OUTPUT_LOW);
    pio_config_set(LEDMAT_COL1_PIO, PIO_OUTPUT_LOW);   
    pio_config_set(LEDMAT_COL2_PIO, PIO_OUTPUT_LOW);           
    pio_config_set(LEDMAT_COL3_PIO, PIO_OUTPUT_LOW);           
    pio_config_set(LEDMAT_COL4_PIO, PIO_OUTPUT_LOW);                   
    pio_config_set(LEDMAT_COL5_PIO, PIO_OUTPUT_LOW); 

    tinygl_init (LOOP_RATE);
    tinygl_font_set (&font5x7_1);
    tinygl_text_speed_set (MESSAGE_RATE);
    tinygl_text_mode_set (TINYGL_TEXT_MODE_SCROLL);
}
