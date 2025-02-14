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

/*We have to call upon an external C function for anything that
exists outside of C++ libraries.*/
extern "C" void cocoaBaseMenuBar();

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
