#ifndef ATARAXIAMAIN
#define ATARAXIAMAIN

//Main SDL3 Headers
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3/SDL_render.h>
#include <SDL3_image/SDL_image.h>

//Native Headers
#include <iostream>
#include <array>
#include <algorithm>

#include "AtaraxiaTime.hpp"

#include "compressor.hpp"

//Global variables
inline SDL_Window* window = nullptr;
inline SDL_Renderer* renderer = nullptr;
inline Compressor compressor(-20.0f, 4.0f, 5.0f, 50.0f, 44100.0f);

constexpr int ScreenWidth = 600;
constexpr int ScreenHeight = 600;

inline bool stopPlayerAction;

#endif
