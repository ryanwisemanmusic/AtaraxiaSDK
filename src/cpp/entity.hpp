#pragma once
#define MAX_ENTITIES 100

#include <SDL3/SDL.h>
#include "globalVariables.hpp"

typedef struct Entity
{
    void (*quit)(void);
    void (*handle_events)(SDL_Event*);
    void (*update)(void);
    void (*render)(SDL_Renderer*);
} Entity;

Entity init_player(SDL_Renderer* renderer);