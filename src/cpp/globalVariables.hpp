#ifndef GLOBALVARIABLES
#define GLOBALVARIABLES

#include <SDL3/SDL_main.h>
#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3/SDL_video.h>
#include <SDL3/SDL_surface.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_audio.h>
#include <sqlite3.h>
#include <iostream>
#include <array>

#include "SDLColors.h"

// Window Globals
inline SDL_Window* window = nullptr;
inline SDL_Renderer* renderer = nullptr;
constexpr int ScreenWidth = 600;
constexpr int ScreenHeight = 600;

// Text globals
inline TTF_Font* font = nullptr;
extern std::string fontPath;

// Global variable for audio device
inline SDL_AudioDeviceID audioDevice = 0;
inline SDL_AudioStream* audioStream = nullptr;
inline Uint8* audioBuffer = nullptr;
inline Uint32 audioLength = 0;

//Sprite globals
inline SDL_Texture* player_texture;

#endif // GLOBALVARIABLES
