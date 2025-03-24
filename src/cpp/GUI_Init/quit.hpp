#ifndef QUIT
#define QUIT

#define SDL_MAIN_USE_CALLBACKS

#include "AtaraxiaMain.hpp"
#include "entity.hpp"
#include "AtaraxiaMacros.hpp"

void SDL_AppQuit(void *appstate, SDL_AppResult result)
{
    (void)appstate;
    (void)result; 
    
    QUIT_ENTITIES(entities, entities_count);
    
    SDL_DestroyRenderer(renderer);
    renderer = NULL;
    SDL_DestroyWindow(window);
    window = NULL;
    SDL_QuitSubSystem(SDL_INIT_VIDEO);
    SDL_QuitSubSystem(SDL_INIT_AUDIO);
}

#endif