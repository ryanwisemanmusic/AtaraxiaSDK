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
    if (event->type == SDL_EVENT_QUIT) 
    {
        return SDL_APP_SUCCESS;
    }

    if (event->type == SDL_EVENT_MOUSE_BUTTON_DOWN)
    {
        int x = event->button.x;
        int y = event->button.y;
        if (currentScene == SceneState::MAIN_MENU)
        {
            currentScene = SceneState::GAME;
            
        }
        return SDL_APP_CONTINUE;
    }
    return SDL_APP_CONTINUE;
}

#endif