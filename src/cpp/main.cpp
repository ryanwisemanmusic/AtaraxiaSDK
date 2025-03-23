/*
Author: Ryan Wiseman

This is a barebones approach to windowing via SDL3. Any
intenseive windowing required will require some major refactoring
*/

#define SDL_MAIN_USE_CALLBACKS
//Ataraxia Headers
#include "AtaraxiaMain.hpp"
#include "AtaraxiaText.hpp"
#include "AtaraxiaGraphics.hpp"
#include "AtaraxiaAudio.hpp"
#include "AtaraxiaVideo.hpp"
#include "AtaraxiaDatabase.hpp"

#include "quit.hpp"
#include "appevent.hpp"
#include "iterate.hpp"
#include "init.hpp"

void render()
{
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer); 
    renderText("AtaraxiaSDK", 180, 250, cMagenta);
    SDL_RenderPresent(renderer);
}