#include "AtaraxiaMain.hpp"
#define SDL_MAIN_USE_CALLBACKS
#include "player.hpp"

namespace player {
    inline int last_direction = 0; // 0=down, 1=left, 2=right, 3=up

    void loadPlayerTexture()
    {
        const char* path = PLAYER_TEXTURES.at("player").c_str();
        player_texture = IMG_LoadTexture(renderer, path);

        //Autoscale
        SDL_SetTextureScaleMode(player_texture, SDL_SCALEMODE_NEAREST);

        if (!player_texture) 
        {
            SDL_Log("Player texture '%s' could not be loaded! SDL error: %s\n", 
                path, SDL_GetError());
            SDL_Quit();
        }
        else
        {
            SDL_Log("Player texture '%s' loaded successfully", path);
        }
    }

    void quit()
    {
        if (player_texture) {
            SDL_DestroyTexture(player_texture);
            player_texture = nullptr;
        }
    }

    void handle_events(SDL_Event* event)
    {
    }

    void update()
    {
        const bool *keyboard_state = (const bool*)SDL_GetKeyboardState(NULL);
        bool is_moving = false;

        // Check movement keys and update position
        if (keyboard_state[SDL_SCANCODE_W])
        {
            player_sprite_position.y -= 1;
            last_direction = 3; 
            is_moving = true;
        }
        if (keyboard_state[SDL_SCANCODE_S])
        {
            player_sprite_position.y += 1;
            last_direction = 0; // Down
            is_moving = true;
        }
        if (keyboard_state[SDL_SCANCODE_A])
        {
            player_sprite_position.x -= 1;
            last_direction = 1; 
            is_moving = true;
        }
        if (keyboard_state[SDL_SCANCODE_D])
        {
            player_sprite_position.x += 1;
            last_direction = 2; 
            is_moving = true;
        }

        if (is_moving) {
            current_sprite_col = 1; 
        } else {
            // Use standing frame
            current_sprite_col = 0; 
        }
        
        current_sprite_row = last_direction;
        
    }

    void render(SDL_Renderer* renderer)
    {
        SDL_SetTextureScaleMode(player_texture, SDL_SCALEMODE_NEAREST);
        
        SDL_Log("Rendering sprite: col=%d, row=%d", current_sprite_col, current_sprite_row);
        
        if (SDL_FRect* sprite = getPlayerSprite(current_sprite_col, current_sprite_row))
        {
            SDL_RenderTexture(
                renderer, player_texture, 
                sprite, &player_sprite_position);
        }
        else
        {
            SDL_Log("Failed to get sprite at col=%d, row=%d", current_sprite_col, current_sprite_row);
        }
    }

    void init_player()
    {
        loadPlayerTexture();
        
        // Create player entity
        Entity player_entity = {
            .quit = quit,
            .handle_events = handle_events,
            .update = update,
            .render = render
        };
        
        // Add to entities array
        entities[entities_count++] = player_entity;
    }
}
