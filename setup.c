#include "constants.h"
#include "common_functions.h"

#define NUM 0

void game_setup (void) 
{
    
    navswitch_map[2] = 0b11100;
    current_column = 0;
    x_pos = 2;
    y_pos = 3;
    
    blinker_count = 0;
    while (1 && ships < 3) 
    {
        button_update ();
        navswitch_update ();
        
        display_threeline ();
        display_shipmap ();
        display_emptymap ();
        
        upd_column ();
        
        navswitch_moved (NUM);
    
        if (button_push_event_p (BUTTON1)) {
            if (!(navswitch_map[x_pos] & shipmap[x_pos])) {
                shipmap[x_pos] |= navswitch_map[x_pos];
                ships++;
            }
        }
    }
}
