#include "player_entity.hpp"

// Global player data
static SDL_Texture* player_texture = nullptr;
static SDL_FRect player_sprite_portion = {17, 14, 15, 18};
static SDL_FRect player_position = {250, 250, 15, 18};

void player_quit() {
    if (player_texture) {
        SDL_DestroyTexture(player_texture);
        player_texture = nullptr;
    }
}

void player_handle_events(SDL_Event* event) {
    // Handle any player-specific events here
}

void player_update() {
    const bool* keyboard_state = SDL_GetKeyboardState(NULL);

    if (keyboard_state[SDL_SCANCODE_W]) {
        player_position.y -= 1;
    }
    if (keyboard_state[SDL_SCANCODE_S]) {
        player_position.y += 1;
    }
    if (keyboard_state[SDL_SCANCODE_A]) {
        player_position.x -= 1;
    }
    if (keyboard_state[SDL_SCANCODE_D]) {
        player_position.x += 1;
    }
}

void player_render(SDL_Renderer* renderer) {
    if (!player_texture) return;
    
    SDL_SetTextureScaleMode(player_texture, SDL_SCALEMODE_NEAREST);
    SDL_RenderTexture(renderer, player_texture, &player_sprite_portion, &player_position);
}

void init_player_entity() {
    // Load texture
    const char path[] = "assets/images/char_spritesheet.png";
    player_texture = IMG_LoadTexture(renderer, path);
    
    if (!player_texture) {
        SDL_Log("Player texture could not be loaded! SDL error: %s\n", SDL_GetError());
        return;
    }
    
    // Set up entity
    Entity player_entity = {
        .quit = player_quit,
        .handle_events = player_handle_events,
        .update = player_update,
        .render = player_render
    };
    
    // Add to entities array
    entities[entities_count++] = player_entity;
} 