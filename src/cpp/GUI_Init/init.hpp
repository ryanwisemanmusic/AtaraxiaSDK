#ifndef INIT
#define INIT


#include "AtaraxiaMain.hpp"
#include "AtaraxiaText.hpp"
#include "AtaraxiaGraphics.hpp"
#include "AtaraxiaAudio.hpp"
#include "AtaraxiaVideo.hpp"
#include "AtaraxiaDatabase.hpp"
#include "AtaraxiaGame.hpp"
#include "player_entity.hpp"

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
    
    // Initialize player entity
    init_player_entity();

    return SDL_APP_CONTINUE;
}

#endif