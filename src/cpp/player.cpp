#include "AtaraxiaMain.hpp"
#define SDL_MAIN_USE_CALLBACKS
#include "player.hpp"

namespace player {
    void loadPlayerTexture()
    {
        const char path[] = "assets/images/char_spritesheet.png";
        player_texture = IMG_LoadTexture(renderer, path);

        //Autoscale
        SDL_SetTextureScaleMode(player_texture, SDL_SCALEMODE_NEAREST);

        if (!player_texture) 
        {
            SDL_Log("Player texture could not be loaded! SDL error: %s\n", 
                SDL_GetError());
            SDL_Quit();
        }
        else
        {
            SDL_Log("Player texture loaded successfully");
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
        // Handle any player-specific events here
    }

    void update()
    {
        const bool *keyboard_state = SDL_GetKeyboardState(NULL);

        if (keyboard_state[SDL_SCANCODE_W])
        {
            player_sprite_position.y -= 0.1;
        }
        if (keyboard_state[SDL_SCANCODE_S])
        {
            player_sprite_position.y += 0.1;
        }
        if (keyboard_state[SDL_SCANCODE_A])
        {
            player_sprite_position.x -= 0.1;
        }
        if (keyboard_state[SDL_SCANCODE_D])
        {
            player_sprite_position.x += 0.1;
        }
    }

    void render(SDL_Renderer* renderer)
    {
        SDL_SetTextureScaleMode(player_texture, SDL_SCALEMODE_NEAREST);
        SDL_RenderTexture(
            renderer, player_texture, 
            &player_sprite_portion, &player_sprite_position);
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