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

//Related Windowing actions
#include "quit.hpp"
#include "appevent.hpp"
#include "iterate.hpp"
#include "init.hpp"

//Entity Headers
#include "entity.hpp"
#include "player.hpp"

/*
This is where the main logic resides for all visible elements
This is your main rendering window, where you'll put all elements related
to what you want to see on screen.
*/

void render()
{
    SDL_RenderClear(renderer); 
    SDL_SetRenderDrawColor(renderer, 155, 255, 255, 255);
    
    RENDER_ENTITIES(entities, entities_count, renderer);
    
    renderText("AtaraxiaSDK", 180, 250, cMagenta);
    SDL_RenderPresent(renderer);
}
