#ifndef ENTITY
#define ENTITY

#include <SDL3/SDL.h>

#define MAX_ENTITIES 100

typedef struct {
    void (*quit)(void);
    void (*handle_events)(SDL_Event*);
    void (*update)(void);
    void (*render)(SDL_Renderer*);
} Entity;

extern int entities_count;
extern Entity entities[MAX_ENTITIES];

#endif 