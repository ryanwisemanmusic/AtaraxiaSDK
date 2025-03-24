/*
Author: Ryan Wiseman

This is where we render everything in the main screen.
*/

#define SDL_MAIN_USE_CALLBACKS
//Ataraxia Headers
#include "AtaraxiaMain.hpp"
#include "AtaraxiaText.hpp"
#include "AtaraxiaGraphics.hpp"
#include "AtaraxiaAudio.hpp"
#include "AtaraxiaVideo.hpp"
#include "AtaraxiaDatabase.hpp"
#include "entity.hpp"
#include "AtaraxiaMacros.hpp"
#include "player_entity.hpp"
//#include "AtaraxiaGame.hpp"

#include "quit.hpp"
#include "appevent.hpp"
#include "iterate.hpp"
#include "init.hpp"

// Remove these lines as they're already defined in entity.hpp
// Entity entities[MAX_ENTITIES];
// int entities_count = 0;

void render()
{
    SDL_RenderClear(renderer); 
    SDL_SetRenderDrawColor(renderer, 155, 255, 255, 255);
    
    RENDER_ENTITIES(entities, entities_count, renderer);
    
    renderText("AtaraxiaSDK", 180, 250, cMagenta);
    SDL_RenderPresent(renderer);
}
