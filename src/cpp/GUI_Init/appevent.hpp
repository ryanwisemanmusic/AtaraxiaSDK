#ifndef APPEVENT
#define APPEVENT

#define SDL_MAIN_USE_CALLBACKS

#include "AtaraxiaMain.hpp"
#include "AtaraxiaText.hpp"
#include "AtaraxiaGraphics.hpp"
#include "AtaraxiaAudio.hpp"
#include "AtaraxiaVideo.hpp"
#include "AtaraxiaDatabase.hpp"
#include "AtaraxiaGame.hpp"
#include "compressor.hpp"

inline SceneState currentScene = SceneState::MAIN_MENU;

SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event)
{
    (void)appstate;
    (void)event; 
    const bool *keyboard_state = (const bool*)SDL_GetKeyboardState(NULL);
    if (event->type == SDL_EVENT_QUIT) 
    {
        return SDL_APP_SUCCESS;
    }

    if (event->type == SDL_EVENT_MOUSE_BUTTON_DOWN)
    {
        [[maybe_unused]] int x = event->button.x;
        [[maybe_unused]] int y = event->button.y;
        if (currentScene == SceneState::MAIN_MENU)
        {
            currentScene = SceneState::GAME;
            
        }
        return SDL_APP_CONTINUE;
    }

    if (event->type == SDL_EVENT_KEY_DOWN)
    {
        if (keyboard_state[SDL_SCANCODE_N])
        {
            currentScene = SceneState::NETWORK_TEST;
        }
    }

    if (event->type == SDL_EVENT_KEY_DOWN)
    {
        if (keyboard_state[SDL_SCANCODE_C])
        {
            currentScene = SceneState::COMPRESSOR;
        }
    }
    
    // Compressor parameter controls
    if (currentScene == SceneState::COMPRESSOR)
    {
        static int selectedParam = 0;
        
        if (event->type == SDL_EVENT_KEY_DOWN)
        {
            // Select parameter
            if (keyboard_state[SDL_SCANCODE_1]) selectedParam = 0;
            if (keyboard_state[SDL_SCANCODE_2]) selectedParam = 1;
            if (keyboard_state[SDL_SCANCODE_3]) selectedParam = 2;
            if (keyboard_state[SDL_SCANCODE_4]) selectedParam = 3;
            
            // Adjust parameter
            if (keyboard_state[SDL_SCANCODE_UP])
            {
                switch (selectedParam)
                {
                    case 0: 
                    compressor.setThreshold(
                        compressor.getThreshold() + 1.0f); 
                    break;
                    case 1: 
                    compressor.setRatio(
                        compressor.getRatio() + 0.5f); 
                        break;
                    case 2: compressor.setAttack(
                        compressor.getAttack() + 1.0f); 
                        break;
                    case 3: compressor.setRelease(
                        compressor.getRelease() + 10.0f); 
                        break;
                }
            }
            if (keyboard_state[SDL_SCANCODE_DOWN])
            {
                switch (selectedParam)
                {
                    case 0: compressor.setThreshold(
                        compressor.getThreshold() - 1.0f); 
                        break;
                    case 1: compressor.setRatio(
                        std::max(1.0f, compressor.getRatio() - 0.5f)); 
                        break;
                    case 2: compressor.setAttack(
                        std::max(0.1f, compressor.getAttack() - 1.0f)); 
                        break;
                    case 3: compressor.setRelease(
                        std::max(1.0f, compressor.getRelease() - 10.0f)); 
                        break;
                }
            }
        }
    }
    
    return SDL_APP_CONTINUE;
}

#endif
