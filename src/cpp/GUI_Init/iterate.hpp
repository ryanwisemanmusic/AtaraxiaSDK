#ifndef ITERATE
#define ITERATE

#define SDL_MAIN_USE_CALLBACKS

#include "AtaraxiaMain.hpp"
#include "AtaraxiaText.hpp"
#include "AtaraxiaGraphics.hpp"
#include "AtaraxiaAudio.hpp"
#include "AtaraxiaVideo.hpp"
#include "AtaraxiaDatabase.hpp"

void render();

SDL_AppResult SDL_AppIterate(void *appstate)
{
    (void)appstate; 
    render();
    return SDL_APP_CONTINUE; 
}

#endif