#include "system.h"
#include "navswitch.h"
#include "pacer.h"
#include "ir_uart.h"
#include "tinygl.h"
#include "../fonts/font5x7_1.h"

#define LOOP_RATE 1000
#define MESSAGE_RATE 20

void game_init(void)
{
    system_init ();
    navswitch_init();
    pacer_init (LOOP_RATE);
    ir_uart_init();

    tinygl_init (LOOP_RATE);
    tinygl_font_set (&font5x7_1);
    tinygl_text_speed_set (MESSAGE_RATE);
    tinygl_text_mode_set (TINYGL_TEXT_MODE_SCROLL);
}
