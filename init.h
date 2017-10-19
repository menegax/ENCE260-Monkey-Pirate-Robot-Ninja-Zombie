/**
 * Monkey-Pirate-Robot-Ninja-Zombie game
 * init.h
 * Authors: Joshua Meneghini and Jonathan Hills
 * jam357 and jhi57
 */

#ifndef INIT_H
#define INIT_H

#include "system.h"
#include "navswitch.h"
#include "pacer.h"
#include "ir_uart.h"
#include "tinygl.h"
#include "button.h"
#include "../fonts/font5x7_1.h"

#define PACER_RATE 500
#define MESSAGE_RATE 20

/**
 * Initialising modules; navswitch, pacer, ir_uart, button, led's, tinygl etc
 **/
void game_init(void);

#endif
