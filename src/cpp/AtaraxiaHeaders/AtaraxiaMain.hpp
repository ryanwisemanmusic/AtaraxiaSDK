#ifndef ATARAXIAMAIN
#define ATARAXIAMAIN

//Main SDL3 Headers
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3/SDL_render.h>

//Native Headers
#include <iostream>
#include <array>

//Global variables
inline SDL_Window* window = nullptr;
inline SDL_Renderer* renderer = nullptr;
constexpr int ScreenWidth = 600;
constexpr int ScreenHeight = 600;

#endif
