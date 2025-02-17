/*
Author: Ryan Wiseman

This is a barebones approach to windowing via SDL. Any
intenseive windowing required will require some major refactoring
*/
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

extern "C" void cocoaBaseMenuBar();
extern "C" void openSDLAboutWindow();

int main(void)
{
    SDL_Log("INFO: Starting SDL application...");

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "ERROR: SDL failed to initialize! %s", SDL_GetError());
        return 1;
    }
    SDL_Log("INFO: SDL initialized successfully.");

    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;
    SDL_CreateWindowAndRenderer(1280, 720, 0, &window, &renderer);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);

    
    if (!window || !renderer)
    {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "ERROR: Failed to create SDL window/renderer: %s", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    SDL_Log("INFO: SDL window and renderer created.");

    cocoaBaseMenuBar();

    SDL_Log("INFO: Entering main loop...");

    bool quit = false;
    SDL_Event e;

    while (!quit)
    {
        while (SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_QUIT)
            {
                SDL_Log("INFO: Quit event received.");
                quit = true;
            }
        }
    }

    SDL_Log("INFO: Shutting down SDL...");
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    SDL_Log("INFO: SDL application closed.");

    return 0;
}


