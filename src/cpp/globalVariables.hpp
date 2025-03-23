#ifndef GLOBALVARIABLES
#define GLOBALVARIABLES
/*Macro definitions*/
#define MAX_ENTITIES 100
#define RENDER_ENTITIES(entities, entities_count, renderer) \
for (int i = 0; i < entities_count; i++) \
{ \
    entities[i].render(renderer); \
}
#define UPDATE_ENTITIES(entities, entities_count) \
for (int i = 0; i < entities_count; i++) \
{ \
    entities[i].update(); \
}
#define QUIT_ENTITIES(entities, entities_count) \
for (int i = 0; i < entities_count; i++) \
{ \
    entities[i].quit(); \
}
#define HANDLE_EVENTS_ENTITIES(entities, entities_count) \
for (int i = 0; i < entities_count; i++) \
{ \
    entities[i].handle_events(event); \
}


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
#include "entity.hpp"

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
inline static SDL_Texture* spright_texture = nullptr;
inline static SDL_FRect spright_portion = {17, 14, 15, 18};

//Spright position globals
typedef struct 
{
    float x, y;
} Position;

inline Position position = {0, 0};
inline SDL_FRect player_position = {position.x, position.y, 15, 18};

//Entity globals
inline Entity entities[MAX_ENTITIES];
inline int entities_count = 0;

#endif // GLOBALVARIABLES