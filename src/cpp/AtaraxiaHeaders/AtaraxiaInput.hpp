#ifndef ATARAXIAINPUT
#define ATARAXIAINPUT

#include <SDL3/SDL.h>

namespace input {
    inline const bool* keyboard_state = nullptr;
    
    inline void update() {
        keyboard_state = (const bool*)SDL_GetKeyboardState(NULL);
    }
    
    inline bool is_key_pressed(SDL_Scancode key) {
        return keyboard_state && keyboard_state[key];
    }
    
    //This binds traditional WASD and arrow keys
    inline bool up() 
    { 
        return is_key_pressed(SDL_SCANCODE_W) || 
        is_key_pressed(SDL_SCANCODE_UP); 
    }
    inline bool down() 
    { 
        return is_key_pressed(SDL_SCANCODE_S) || 
        is_key_pressed(SDL_SCANCODE_DOWN); 
    }
    inline bool left() 
    { 
        return is_key_pressed(SDL_SCANCODE_A) || 
        is_key_pressed(SDL_SCANCODE_LEFT); 
    }
    inline bool right() 
    { 
        return is_key_pressed(SDL_SCANCODE_D) || 
        is_key_pressed(SDL_SCANCODE_RIGHT); 
    }
    inline bool n() 
    { 
        return is_key_pressed(SDL_SCANCODE_N); 
    }
    inline bool c() 
    { 
        return is_key_pressed(SDL_SCANCODE_C); 
    }
}

#endif