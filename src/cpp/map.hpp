#ifndef MAP
#define MAP

#include "AtaraxiaMain.hpp"

inline SDL_FRect create_tile_portion(float x, float y, float w, float h)
{
    SDL_FRect portion = {
        x, y, w, h
    };
    return portion;
}

inline SDL_FRect create_tile_position(float x, float y, float w, float h)
{
    SDL_FRect position = {
        x, y, w, h
    };
    return position;
}

inline SDL_FRect player_sprite_portion = create_tile_portion(17, 14, 15, 18);
inline SDL_FRect player_sprite_position = create_tile_position(250, 250, 15, 18);


void tile_quit();
void tile_handle_events();
void tile_update();
void tile_render();
void init_tile();

#endif