#ifndef ATARAXIAGAME
#define ATARAXIAGAME
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3/SDL_render.h>
#include <SDL3_image/SDL_image.h>
#include "AtaraxiaMain.hpp"


void loadPlayerTexture()
{
    const char path[] = "assets/images/char_spritesheet.png";
    player_texture = IMG_LoadTexture(renderer, path);

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
