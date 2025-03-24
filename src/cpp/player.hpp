#ifndef PLAYER
#define PLAYER

#include "AtaraxiaMain.hpp"

inline SDL_FRect create_sprite_portion(float x, float y, float w, float h)
{
    SDL_FRect portion = {
        x, y, w, h
    };
    return portion;
}

inline SDL_FRect create_sprite_position(float x, float y, float w, float h)
{
    SDL_FRect position = {
        x, y, w, h
    };
    return position;
}

inline SDL_FRect player_sprite_portion = create_sprite_portion(17, 14, 15, 18);
inline SDL_FRect player_sprite_position = create_sprite_position(250, 250, 15, 18);


void player_quit();
void player_handle_events();
void player_update();
void player_render();
void init_player();

#endif

