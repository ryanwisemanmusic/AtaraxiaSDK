/*
Author: Ryan Wiseman

This is where we initialize all and everything our project means. If you
need to work with a new library, you either add it to my custom headers
or you incorporate it here. The reason why you need all headers so that 
even if you externally reference something, it needs a surrounding header.
*/

#ifndef INIT
#define INIT

#include "AtaraxiaMain.hpp"
#include "AtaraxiaText.hpp"
#include "AtaraxiaGraphics.hpp"
#include "AtaraxiaAudio.hpp"
#include "AtaraxiaVideo.hpp"
#include "AtaraxiaDatabase.hpp"
#include "AtaraxiaGame.hpp"
#include "player.hpp"
#include "mapTile.hpp"

SDL_AppResult SDL_AppInit(void **appstate, int argc, char **argv)
{
    (void)appstate; 
    (void)argc;
    (void)argv;
    
    TTF_Init();
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Init(SDL_INIT_AUDIO);

    cocoaBaseMenuBar();

    if (!SDL_Init(SDL_INIT_VIDEO))
    {
        SDL_Log("Cannot initialize video: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }
    if (!SDL_Init(SDL_INIT_AUDIO))
    {
        SDL_Log("Cannot initialize audio: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    window = SDL_CreateWindow(
        "AtaraxiaSDK", 
        ScreenWidth, 
        ScreenHeight, 
        SDL_WINDOW_OPENGL);

    if (!window) 
    {
        SDL_Log("Window can't be created! SDL error: %s\n", 
        SDL_GetError());
        SDL_Quit();
        return SDL_APP_FAILURE;
    }
    
    renderer = SDL_CreateRenderer(window, NULL);

    if (!renderer) {
        SDL_Log("Renderer could not be created! SDL error: %s\n", 
            SDL_GetError());
        SDL_Quit();
        return SDL_APP_FAILURE;
    }

    std::string fontPath = "assets/fonts/ArianaVioleta.ttf";
    font = TTF_OpenFont(fontPath.c_str(), 50);
    if (!font) 
    {
        SDL_Log("Cannot load font!");
    }
    
    /*This is where you initilaize the existence of players, tiles,
    anything graphical. YOU MUST DO THIS OR YOU WILL NOT RENDER
    ANYTHING.
    
    It is easiest if you stick to my schema on how I call to this, mainly
    since it works well.*/
    player::init_player();
    two_d_tiles::init_tile();

    return SDL_APP_CONTINUE;
}

#endif