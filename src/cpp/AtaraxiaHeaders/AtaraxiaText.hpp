#ifndef ATARAXIATEXT
#define ATARAXIATEXT

#include "AtaraxiaMain.hpp"
#include <SDL3_ttf/SDL_ttf.h>
#include "SDLColors.h"

//Global variables
inline TTF_Font* font = nullptr;

void renderText(const char* message, int x, int y, SDL_Color color) 
{
    if (!font) 
    {
        SDL_Log("Cannot load font!");
        return;
    }
    size_t messageLength = strlen(message);
    SDL_Surface* textSurface = TTF_RenderText_Solid(
        font, message, messageLength, color);
    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(
        renderer, textSurface);
    int textW = textSurface->w; 
    int textH = textSurface->h;
    SDL_DestroySurface(textSurface);
    if (!textTexture) {
        SDL_Log("Texture creation failed!");
        return;
    }
    SDL_FRect destRect = 
    { 
        static_cast<float>(x), static_cast<float>(y), 
        static_cast<float>(textW), static_cast<float>(textH) 
    };
    SDL_RenderTexture(renderer, textTexture, nullptr, &destRect);
}

#endif