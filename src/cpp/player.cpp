#include "AtaraxiaMain.hpp"
#define SDL_MAIN_USE_CALLBACKS
#include "player.hpp"
#include "AtaraxiaInput.hpp"

namespace player {
    // Define the variables declared in the header
    float player_adjusted_x = 0.0f;
    float player_adjusted_y = 0.0f;
    int player_current_grid_x = 0;
    int player_current_grid_y = 0;
    int player_target_grid_x = 0;
    int player_target_grid_y = 0;
    bool player_is_moving = false;
    
    // Your existing variables
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
        // Update input state
        input::update();
        
        player_is_moving = false;

        float prev_x = player_sprite_position.x;
        float prev_y = player_sprite_position.y;

        //Map offset
        player_adjusted_x = player_sprite_position.x - 20.0f; 
        player_adjusted_y = player_sprite_position.y - 10.0f;
        player_current_grid_x = static_cast<int>(player_adjusted_x / 48.0f);
        player_current_grid_y = static_cast<int>(player_adjusted_y / 48.0f);

        // Calculate target grid position based on movement
        player_target_grid_x = player_current_grid_x;
        player_target_grid_y = player_current_grid_y;

        if (input::up()) 
        {
            player_target_grid_y = static_cast<int>(
                (player_adjusted_y - 50 * delta_time) / 48.0f);
            last_direction = 3;
            player_is_moving = true;
        }
        if (input::down()) {
            player_target_grid_y = static_cast<int>(
                (player_adjusted_y + 100 * delta_time) / 48.0f);
            last_direction = 0;
            player_is_moving = true;
        }
        if (input::left()) {
            player_target_grid_x = static_cast<int>(
                (player_adjusted_x - 100 * delta_time) / 48.0f);
            last_direction = 1;
            player_is_moving = true;
        }
        if (input::right()) {
            player_target_grid_x = static_cast<int>(
                (player_adjusted_x + 100 * delta_time) / 48.0f);
            last_direction = 2;
            player_is_moving = true;
        }

        // Use the new move_player function
        move_player(delta_time);

        int grid_x = static_cast<int>(player_sprite_position.x / 48.0f);
        int grid_y = static_cast<int>(player_sprite_position.y / 48.0f);
        
        int prev_grid_x = static_cast<int>(prev_x / 48.0f);
        int prev_grid_y = static_cast<int>(prev_y / 48.0f);
        
        if (grid_x != prev_grid_x || grid_y != prev_grid_y) {
            SDL_Log("Player moved to grid position: (%d, %d) - World position: (%.2f, %.2f)", 
                grid_x, grid_y, player_sprite_position.x, player_sprite_position.y);
        }

        if (player_is_moving) 
        {
            current_sprite_col = 1; 
        } else {
            current_sprite_col = 0; 
        }
        
        current_sprite_row = last_direction;

        // Update the exposed variables
        player_x = player_sprite_position.x;
        player_y = player_sprite_position.y;
        player_grid_x = static_cast<int>(player_sprite_position.x / 48.0f);
        player_grid_y = static_cast<int>(player_sprite_position.y / 48.0f);
        player_direction = last_direction;
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

    // Our calling for this function in other code files will be:
    // player::player_tracker()
    void player_tracker()
    {
        // Check if grid position has changed
        if (player_grid_x != player_prev_grid_x || player_grid_y != player_prev_grid_y) {
            player_grid_changed = true;
            SDL_Log("Player tracker: Grid position changed to (%d, %d) - World position: (%.2f, %.2f)", 
                    player_grid_x, player_grid_y, player_x, player_y);
            
            // Update previous grid position
            player_prev_grid_x = player_grid_x;
            player_prev_grid_y = player_grid_y;
        } else {
            player_grid_changed = false;
        }
        
        // You can still log general tracking info if needed
        // SDL_Log("Player tracker: Position (%.2f, %.2f), Moving: %s, Direction: %d", 
        //        player_x, player_y, player_is_moving ? "true" : "false", player_direction);
    }

    bool is_position_blocked(int grid_x, int grid_y)
    {
        // Pond collision check
        if ((grid_x == 3 || grid_x == 4) && 
            (grid_y == 1 || grid_y == 2)) 
        {
            return true;
        }
        
        if ((grid_x == 5 || grid_x == 6) && 
            (grid_y == 5 || grid_y == 6)) 
        {
            return true;
        }
        
        return false;
    }

    void move_player(float delta_time)
    {
        bool is_blocked = is_position_blocked(player_target_grid_x, player_target_grid_y);
        
        if (!is_blocked) {
            if (input::up()) {
                player_sprite_position.y -= 50 * delta_time;
            }
            if (input::down()) {
                player_sprite_position.y += 100 * delta_time;
            }
            if (input::left()) {
                player_sprite_position.x -= 100 * delta_time;
            }
            if (input::right()) {
                player_sprite_position.x += 100 * delta_time;
            }
        } else {
            player_is_moving = false;
        }
    }
}
