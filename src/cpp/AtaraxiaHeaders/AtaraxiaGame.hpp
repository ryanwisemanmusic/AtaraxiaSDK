#ifndef ATARAXIAGAME
#define ATARAXIAGAME
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3/SDL_render.h>
#include <SDL3_image/SDL_image.h>
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

void loadPlayerTexture()
{
    const char path[] = "assets/images/char_spritesheet.png";
    player_texture = IMG_LoadTexture(renderer, path);

    //Autoscale
    SDL_SetTextureScaleMode(player_texture, SDL_SCALEMODE_NEAREST);

    if (!player_texture) 
    {
        SDL_Log("Player texture could not be loaded! SDL error: %s\n", 
            SDL_GetError());
        SDL_Quit();
    }
    else
    {
        SDL_Log("Player texture loaded successfully");
    }
}

#endif
