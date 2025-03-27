#ifndef ATARAXIATIME
#define ATARAXIATIME

#include <SDL3/SDL.h>

namespace game_time {
    inline Uint64 last_tick = 0;
    inline Uint64 current_tick = 0;
    inline float delta_time = 0.0f;
    
    inline void update() {
        last_tick = current_tick;
        current_tick = SDL_GetTicks();
        delta_time = (current_tick - last_tick) / 1000.0f;
    }
}

#endif
