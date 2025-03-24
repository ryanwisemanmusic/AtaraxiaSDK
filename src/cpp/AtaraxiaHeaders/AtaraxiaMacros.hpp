#ifndef ATARAXIAMACROS
#define ATARAXIAMACROS

#include "SDL3/SDL.h"
#define MAX_ENTITIES 100

#define RENDER_ENTITIES(entities, entities_count, renderer) \
for (int i = 0; i < entities_count; i++) \
{ \
    entities[i].render(renderer); \
}
#define UPDATE_ENTITIES(entities, entities_count) \
for (int i = 0; i < entities_count; i++) \
{ \
    entities[i].update(); \
}
#define QUIT_ENTITIES(entities, entities_count) \
for (int i = 0; i < entities_count; i++) \
{ \
    entities[i].quit(); \
}
#define HANDLE_EVENTS_ENTITIES(entities, entities_count) \
for (int i = 0; i < entities_count; i++) \
{ \
    entities[i].handle_events(event); \
}

SDL_Event* event;


#endif