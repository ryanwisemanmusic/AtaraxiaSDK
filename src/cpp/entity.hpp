#pragma once
#define MAX_ENTITIES 100

#include <SDL3/SDL.h>

typedef struct
{
    void(*quit)(void);
    void(*handle_events)(SDL_Event*);
    void(*update)(void);
    void(*render)(SDL_Renderer*);
} Entity;

inline int entities_count = 0;
Entity entities[MAX_ENTITIES];
