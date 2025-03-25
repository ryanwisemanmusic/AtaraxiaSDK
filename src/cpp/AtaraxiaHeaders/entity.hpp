#ifndef ENTITY
#define ENTITY

#include <SDL3/SDL.h>

//Player / NPC entitites
#define MAX_ENTITIES 100

//Tile Map entities
#define MAX_ENTITIES_TILE 50000

typedef struct {
    void (*quit)(void);
    void (*handle_events)(SDL_Event*);
    void (*update)(void);
    void (*render)(SDL_Renderer*);
} Entity;

extern int entities_count;
extern int entities_count_tile;

//Player / NPC Entities
extern Entity entities[MAX_ENTITIES];
//Tile Map Entities
extern Entity entities_tile[MAX_ENTITIES_TILE];

#endif 