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
#include "AtaraxiaGame.hpp"


#include "quit.hpp"
#include "appevent.hpp"
#include "iterate.hpp"
#include "init.hpp"

void render()
{
    SDL_RenderClear(renderer); 
    SDL_SetRenderDrawColor(renderer, 155, 255, 255, 255);
    SDL_RenderTexture(
        renderer, player_texture, 
        &player_sprite_portion, &player_sprite_position);
    renderText("AtaraxiaSDK", 180, 250, cMagenta);
    SDL_RenderPresent(renderer);
}
