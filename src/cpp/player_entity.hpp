#ifndef PLAYER_ENTITY
#define PLAYER_ENTITY

#include "AtaraxiaMain.hpp"
#include "entity.hpp"

// Function declarations
void player_quit();
void player_handle_events(SDL_Event* event);
void player_update();
void player_render(SDL_Renderer* renderer);
void init_player_entity();

#endif 