#ifndef ITERATE
#define ITERATE

#define SDL_MAIN_USE_CALLBACKS

#include "AtaraxiaMain.hpp"
#include "AtaraxiaText.hpp"
#include "AtaraxiaGraphics.hpp"
#include "AtaraxiaAudio.hpp"
#include "AtaraxiaVideo.hpp"
#include "AtaraxiaDatabase.hpp"
#include "entity.hpp"
#include "AtaraxiaMacros.hpp"
#include "player.hpp"

void render();

SDL_AppResult SDL_AppIterate(void *appstate)
{
    (void)appstate; 
    game_time::update();
    UPDATE_ENTITIES(entities, entities_count, game_time::delta_time);
    render();
    
    return SDL_APP_CONTINUE; 
}

#endif
