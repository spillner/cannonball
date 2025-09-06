#pragma once

#include "globals.hpp"
#include "sdl2/audio.hpp"

namespace cannonball
{
    extern Audio audio;

    // Frame counter
	extern int frame;

    // Tick Logic. Used when running at non-standard > 30 fps
    extern bool tick_frame;

    // Millisecond Time Per Frame
    extern double frame_ms;

    // FPS Counter
    extern int fps_counter;

    // Engine Master State
    extern int state;
    extern int last_nonmenu_state;
    
    enum
    {
        STATE_BOOT,
        STATE_INIT_MENU,
        STATE_MENU,
        STATE_INIT_GAME,
        STATE_GAME,
        STATE_CONFIRM_QUIT,
        STATE_QUIT
    };
}

int main(int argc, char* argv[]);
