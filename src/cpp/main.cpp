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
#include "compressor.hpp"

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
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        camera::render(renderer);
        UPDATE_ENTITIES(entities_tile, entities_count_tile, game_time::delta_time);
        UPDATE_ENTITIES(entities, entities_count, game_time::delta_time);
        RENDER_ENTITIES(entities_tile, entities_count_tile, renderer);
        RENDER_ENTITIES(entities, entities_count, renderer);
        
        SDL_SetRenderViewport(renderer, NULL);
        SDL_SetRenderLogicalPresentation(renderer, 480, 480, SDL_LOGICAL_PRESENTATION_LETTERBOX);
        two_d_tiles::init_tile(); 
    }

    else if (currentScene == SceneState::NETWORK_TEST)
    {
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255);
        renderText("Network Test", 200, 20, cMagenta);
    }

    else if (currentScene == SceneState::COMPRESSOR)
    {
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 50, 100, 50, 255);
        renderText("Compressor", 200, 20, cMagenta);
        
        // Draw compressor parameter sliders
        SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);
        
        // Threshold slider (-60dB to 0dB)
        SDL_FRect thresholdSlider = {100, 100, 400, 30};
        SDL_RenderFillRect(renderer, &thresholdSlider);
        SDL_SetRenderDrawColor(renderer, 255, 100, 100, 255);
        float thresholdKnobPosition = 250 + (compressor.getThreshold() / 60.0f * 200.0f); // Map -60 to 0 to position
        SDL_FRect thresholdKnob = {thresholdKnobPosition, 95, 10, 40};
        SDL_RenderFillRect(renderer, &thresholdKnob);
        renderText("Threshold", 100, 75, cWhite);
        
        // Ratio slider (1:1 to 20:1)
        SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);
        SDL_FRect ratioSlider = {100, 180, 400, 30};
        SDL_RenderFillRect(renderer, &ratioSlider);
        SDL_SetRenderDrawColor(renderer, 100, 255, 100, 255);
        float ratioKnobPosition = 100 + ((compressor.getRatio() - 1) / 19.0f * 400.0f); // Map 1-20 to position
        SDL_FRect ratioKnob = {ratioKnobPosition, 175, 10, 40};
        SDL_RenderFillRect(renderer, &ratioKnob);
        renderText("Ratio", 100, 155, cWhite);
        
        // Attack slider (0ms to 100ms)
        SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);
        SDL_FRect attackSlider = {100, 260, 400, 30};
        SDL_RenderFillRect(renderer, &attackSlider);
        SDL_SetRenderDrawColor(renderer, 100, 100, 255, 255);
        float attackKnobPosition = 100 + (compressor.getAttack() / 100.0f * 400.0f); // Map 0-100 to position
        SDL_FRect attackKnob = {attackKnobPosition, 255, 10, 40};
        SDL_RenderFillRect(renderer, &attackKnob);
        renderText("Attack", 100, 235, cWhite);
        
        // Release slider (0ms to 1000ms)
        SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);
        SDL_FRect releaseSlider = {100, 340, 400, 30};
        SDL_RenderFillRect(renderer, &releaseSlider);
        SDL_SetRenderDrawColor(renderer, 255, 255, 100, 255);
        float releaseKnobPosition = 100 + (compressor.getRelease() / 1000.0f * 400.0f); // Map 0-1000 to position
        SDL_FRect releaseKnob = {releaseKnobPosition, 335, 10, 40};
        SDL_RenderFillRect(renderer, &releaseKnob);
        renderText("Release", 100, 315, cWhite);
        
        // Draw input/output level meters
        SDL_SetRenderDrawColor(renderer, 50, 50, 50, 255);
        SDL_FRect inputMeter = {100, 400, 180, 30};
        SDL_FRect outputMeter = {320, 400, 180, 30};
        SDL_RenderFillRect(renderer, &inputMeter);
        SDL_RenderFillRect(renderer, &outputMeter);
        
        // Simulate input level (would be actual audio level in real implementation)
        float simulatedInputLevel = 0.7f; // 70% (simulated)
        SDL_SetRenderDrawColor(renderer, 255, 150, 50, 255);
        SDL_FRect inputLevelRect = {100, 400, 180 * simulatedInputLevel, 30};
        SDL_RenderFillRect(renderer, &inputLevelRect);
        
        // Simulate output level (would be processed audio level)
        float outputLevel = simulatedInputLevel * compressor.computeGainReduction(simulatedInputLevel);
        SDL_SetRenderDrawColor(renderer, 50, 200, 50, 255);
        SDL_FRect outputLevelRect = {320, 400, 180 * outputLevel, 30};
        SDL_RenderFillRect(renderer, &outputLevelRect);
        
        renderText("Input", 100, 375, cWhite);
        renderText("Output", 320, 375, cWhite);
        
        // Instructions
        renderText("Press 1-4 to select parameter, Up/Down to adjust", 100, 450, cWhite);
    }

    SDL_RenderPresent(renderer);
    /*When you render your entities accordingly, it needs to be
    in order of last layer to first. Whatever rendering of entities gets
    called first will be the most underlying layer, aka, the bottom layer*/
    
}
