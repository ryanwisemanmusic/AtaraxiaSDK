/*
Author: Ryan Wiseman

This is a barebones approach to windowing via SDL3. Any
intenseive windowing required will require some major refactoring
*/

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
/*Third party image library for SDL3*/
#include <SDL3_ttf/SDL_ttf.h>
#include <SDL3_image/SDL_image.h>
/*Header for SQLite, if you aren't using local
databases, this can be deleated.*/
#include <sqlite3.h>

//Universal libraries
#include <iostream>
#include <array>

//App headers
#include "gameScores.h"
#include "SDLColors.h"


//App headers
#include "gameScores.h"

SDL_Window *window;
SDL_Renderer *renderer;
constexpr int ScreenWidth = 600;
constexpr int ScreenHeight = 600;

extern "C" void cocoaBaseMenuBar();
extern "C" void openSDLWindowAboutMenu();

bool init();


int main(int argc, char* argv[]) {
    (void)argc; 
    (void)argv; 

    (void)argc; 
    (void)argv; 

    //SDL_Window *window;  
    bool done = false;

    /* 
    It took me about 12 hours to fix the problem with my call to 
    bool init. So this is some good progress!!!!
    */
    if (!init()) {
        SDL_Log("Unable to initialize program!\n");
        return 1;
    }

    // Add Cocoa base menu bar
    cocoaBaseMenuBar();

    while (!done) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                done = true;
            }
        }
    }

    SDL_DestroyWindow(window);

    SDL_Quit();
    return 0;
}

bool init()
{
    SDL_Init(SDL_INIT_VIDEO);
    
    window = SDL_CreateWindow(
        "AtaraxiaSDK", ScreenWidth,
        ScreenHeight, SDL_WINDOW_OPENGL);
    
    if (window == NULL)
    {
        SDL_Log("Window can't be creted! SDL error: %s\n",
        SDL_GetError());
        SDL_Quit();
        return false;
    }

    renderer = SDL_CreateRenderer(window, 0);
    if (!renderer)
    {
        SDL_Log("Renderer could not be created! SDL error: %s\n",
        SDL_GetError());
        SDL_Quit();
        return false;
    }
    /*
    if (SDL_SetRenderVSync(renderer, true) != 0)
    {
        SDL_Log("Failed to enable VSync! SDL: Error %s\n",
        SDL_GetError());
    }
    */
    return true;
}
