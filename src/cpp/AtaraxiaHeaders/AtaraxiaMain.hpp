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

//Global variables
inline SDL_Window* window = nullptr;
inline SDL_Renderer* renderer = nullptr;

constexpr int ScreenWidth = 600;
constexpr int ScreenHeight = 600;

//DeltaTime
inline Uint64 last_tick = 0;
inline Uint64 current_tick = 0;
inline float delta_time;

inline bool stopPlayerAction;

#endif