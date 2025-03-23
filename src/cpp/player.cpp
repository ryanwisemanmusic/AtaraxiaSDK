#include <SDL3/SDL_main.h>
#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3/SDL_video.h>
#include <SDL3/SDL_surface.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_audio.h>

#include "globalVariables.hpp"
#include "entity.hpp"

static void quit()
{

}

static void handle_events(SDL_Event* event)
{

}

static void update(float delta_time)
{
    const bool *keyboard_state = SDL_GetKeyboardState(NULL);
    if (keyboard_state[SDL_SCANCODE_W])
    {
        position.y -= 50 * delta_time;
    }

    if (keyboard_state[SDL_SCANCODE_S])
    {
        position.y += 50 * delta_time;
    }

    if (keyboard_state[SDL_SCANCODE_A])
    {
        position.x -= 50 * delta_time;
    }

    if (keyboard_state[SDL_SCANCODE_D])
    {
        position.x += 50 * delta_time;
    }
    
}

static void render(SDL_Renderer* renderer)
{
    SDL_FRect player_position = {position.x, position.y, 15, 18};
    SDL_SetTextureScaleMode(spright_texture, SDL_SCALEMODE_NEAREST);
    SDL_RenderTexture(renderer, spright_texture, &spright_portion, &player_position);
}

Entity init_player(SDL_Renderer* renderer)
{
    const char* path = "assets/images/char_spritesheet.png";
    spright_texture = IMG_LoadTexture(renderer, path);

    Entity player = 
    {
        .quit = quit, 
        .handle_events = handle_events, 
        .update = update, 
        .render = render
    };
    return player;
}
