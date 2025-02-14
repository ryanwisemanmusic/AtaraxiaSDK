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

//Load Obj-C functions here
extern "C" void cocoaBaseMenuBar();
extern "C" void openSDLAboutWindow();

/* This approach will be how you create additional windows inside of SDL.
   Usually, we will stick to the main window itself, it just is useful
   if you get to something like Finder menus, in case you need to do something
   useful like importing a file. */
extern "C" void openSDLWindowAboutMenu()
{
    SDL_Window *aboutWindow = SDL_CreateWindow(
        "About AtaraxiaSDK", SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED, 500, 400, SDL_WINDOW_SHOWN);
    
    // Error check for failed window creation
    if (!aboutWindow)
    {
        std::cerr << "Cannot create the About Window requested: " 
                  << SDL_GetError() << std::endl;
        return;
    }

    SDL_Renderer *aboutRenderer = SDL_CreateRenderer(
        aboutWindow, -1, SDL_RENDERER_ACCELERATED);
    
    // Error check for failed renderer creation
    if (!aboutRenderer)
    {
        std::cerr << "Failed to create the renderer (About Window). \n"
                  << "Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(aboutWindow);
        return;
    }

    SDL_SetRenderDrawColor(aboutRenderer, 200, 200, 200, 255);
    SDL_RenderClear(aboutRenderer);
    SDL_RenderPresent(aboutRenderer);
    
    SDL_Event event;
    bool aboutRunning = true;
    while (aboutRunning)
    {
        // Fetch new events from SDL
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                aboutRunning = false;
            }
            else if (event.type == SDL_WINDOWEVENT)
            {
                if (event.window.event == SDL_WINDOWEVENT_CLOSE && 
                    event.window.windowID == SDL_GetWindowID(aboutWindow))
                {
                    aboutRunning = false;
                }
            }
        }

        SDL_Delay(10);
    }

    SDL_DestroyRenderer(aboutRenderer);
    SDL_DestroyWindow(aboutWindow);
}


int main(void)
{
    /*Our window and renderer is treated as null.
    Since they are destructable objects, it is better to
    define them into null*/
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    /*This is how you can initialize the application*/
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_CreateWindowAndRenderer(
        1280, 720, 0, &window, &renderer);
    
    /*We will be using Obj-C only for menuing related to the SDL
    application. I'm keeping it simple for the sake of not
    giving you a difficult ass Obj-C project that more useful than not*/
    cocoaBaseMenuBar();

    /*This sets */
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
    bool quit = false;

            //Event handler
            SDL_Event e;

            //While application is running
            while (!quit)
            {
                //Handle events on queue
                while( SDL_PollEvent( &e ) != 0 ) // poll for event
                {
                    //User requests quit
                    if( e.type == SDL_QUIT ) // unless player manually quits
                    {
                        quit = true;
                    }
                }
            }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return (0);
}
