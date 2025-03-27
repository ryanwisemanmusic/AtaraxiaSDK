#include "AtaraxiaMain.hpp"
#define SDL_MAIN_USE_CALLBACKS
#include "player.hpp"

namespace player {
    inline int last_direction = 0;

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

    void update(float delta_time)
    {
        last_tick = current_tick;
        current_tick = SDL_GetTicks();
        delta_time = (current_tick - last_tick) / 1000.0f;
        const bool *keyboard_state = (const bool*)SDL_GetKeyboardState(NULL);
        bool is_moving = false;

        float prev_x = player_sprite_position.x;
        float prev_y = player_sprite_position.y;

        //Map offset
        float adjusted_x = player_sprite_position.x - 20.0f; 
        float adjusted_y = player_sprite_position.y - 10.0f;
        int current_grid_x = static_cast<int>(adjusted_x / 48.0f);
        int current_grid_y = static_cast<int>(adjusted_y / 48.0f);

        // Calculate target grid position based on movement
        int target_grid_x = current_grid_x;
        int target_grid_y = current_grid_y;

        if (keyboard_state[SDL_SCANCODE_W]) 
        {
            target_grid_y = static_cast<int>(
                (adjusted_y - 50 * delta_time) / 48.0f);
            last_direction = 3;
            is_moving = true;
        }
        if (keyboard_state[SDL_SCANCODE_S]) {
            target_grid_y = static_cast<int>(
                (adjusted_y + 100 * delta_time) / 48.0f);
            last_direction = 0;
            is_moving = true;
        }
        if (keyboard_state[SDL_SCANCODE_A]) {
            target_grid_x = static_cast<int>(
                (adjusted_x - 100 * delta_time) / 48.0f);
            last_direction = 1;
            is_moving = true;
        }
        if (keyboard_state[SDL_SCANCODE_D]) {
            target_grid_x = static_cast<int>(
                (adjusted_x + 100 * delta_time) / 48.0f);
            last_direction = 2;
            is_moving = true;
        }

        // Check if target position is blocked with adjusted boundaries
        bool is_blocked = false;
        
        // Pond collision check
        if ((target_grid_x == 3 || target_grid_x == 4) && 
            (target_grid_y == 1 || target_grid_y == 2)) 
            {
            is_blocked = true;
        }
        
        if ((target_grid_x == 5|| 
             target_grid_x == 6) && 
            (target_grid_y == 5 || target_grid_y == 6)) 
            {
            is_blocked = true;
        }

        // Only update position if not blocked
        if (!is_blocked) {
            if (keyboard_state[SDL_SCANCODE_W]) {
                player_sprite_position.y -= 50 * delta_time;
            }
            if (keyboard_state[SDL_SCANCODE_S]) {
                player_sprite_position.y += 100 * delta_time;
            }
            if (keyboard_state[SDL_SCANCODE_A]) {
                player_sprite_position.x -= 100 * delta_time;
            }
            if (keyboard_state[SDL_SCANCODE_D]) {
                player_sprite_position.x += 100 * delta_time;
            }
        } else {
            is_moving = false;
        }

        int grid_x = static_cast<int>(player_sprite_position.x / 48.0f);
        int grid_y = static_cast<int>(player_sprite_position.y / 48.0f);
        
        int prev_grid_x = static_cast<int>(prev_x / 48.0f);
        int prev_grid_y = static_cast<int>(prev_y / 48.0f);
        
        if (grid_x != prev_grid_x || grid_y != prev_grid_y) {
            SDL_Log("Player moved to grid position: (%d, %d) - World position: (%.2f, %.2f)", 
                grid_x, grid_y, player_sprite_position.x, player_sprite_position.y);
        }

        if (is_moving) 
        {
            current_sprite_col = 1; 
        } else {
            current_sprite_col = 0; 
        }
        
        current_sprite_row = last_direction;
    }

    void render(SDL_Renderer* renderer)
    {
        SDL_SetTextureScaleMode(player_texture, SDL_SCALEMODE_NEAREST);
        
        if (SDL_FRect* sprite = getPlayerSprite(current_sprite_col, current_sprite_row))
        {
            SDL_RenderTexture(
                renderer, player_texture, 
                sprite, &player_sprite_position);
        }
        else
        {
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
