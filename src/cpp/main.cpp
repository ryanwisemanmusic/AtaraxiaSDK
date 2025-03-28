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
#include "AtaraxiaMacros.hpp"
#include "AtaraxiaTime.hpp"
#include "Ataraxia2DCamera.hpp"

//Related Windowing actions
#include "quit.hpp"
#include "appevent.hpp"
#include "iterate.hpp"
#include "init.hpp"

//Entity Headers
#include "entity.hpp"
#include "player.hpp"
#include "mapTile.hpp"

/*
This is where the main logic resides for all visible elements
This is your main rendering window, where you'll put all elements related
to what you want to see on screen.
*/

void render()
{

    if (currentScene == SceneState::MAIN_MENU)  
    {
        SDL_RenderClear(renderer); 
        SDL_SetRenderDrawColor(renderer, 155, 255, 255, 255);
        renderText("AtaraxiaSDK", 180, 250, cMagenta); 
    }
    
    else if (currentScene == SceneState::GAME)
    {
        SDL_RenderClear(renderer);
        
        camera::render(renderer);
        UPDATE_ENTITIES(entities_tile, entities_count_tile, game_time::delta_time);
        UPDATE_ENTITIES(entities, entities_count, game_time::delta_time);
        RENDER_ENTITIES(entities_tile, entities_count_tile, renderer);
        RENDER_ENTITIES(entities, entities_count, renderer);
        
        SDL_SetRenderViewport(renderer, NULL);
        SDL_SetRenderLogicalPresentation(renderer, 480, 480, SDL_LOGICAL_PRESENTATION_LETTERBOX);
        two_d_tiles::init_tile(); 
    }

    SDL_RenderPresent(renderer);
    /*When you render your entities accordingly, it needs to be
    in order of last layer to first. Whatever rendering of entities gets
    called first will be the most underlying layer, aka, the bottom layer*/
    
}
