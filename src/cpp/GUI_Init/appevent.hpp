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
        if (keyboard_state[SDL_SCANCODE_Q])
        {
        }
    }
    return SDL_APP_CONTINUE;
}

#endif
