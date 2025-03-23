#pragma once
#define MAX_ENTITIES 100

#include <SDL3/SDL.h>

typedef struct Entity
{
    void (*quit)(void);
    void (*handle_events)(SDL_Event*);
    void (*update)(float delta_time);
    void (*render)(SDL_Renderer*);
} Entity;

Entity init_player(SDL_Renderer* renderer);